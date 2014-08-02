#include <GL\glew.h>
#include "GeneralGLWindow.h"
#include <Qt\qdebug.h>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
#include <time.h>
#include <fstream>
#include "ShapeData.h"
#include "ShapeGenerator.h"
#include "..\Camera.h"
#include <QtGUI\qmouseevent>
#include <QtGUI\qkeyevent>
#include <GL\GL.h>
#include <QtOpenGL\qglwidget>
#include <qt\qtimer.h>
#include <iostream>
#include "../DebugTools/ConsolePrinter.h"

#pragma region OBJECT_VARIABLES
GLuint currentNumBuffers = 0;
GLuint currentGeometryIndex = 0;
GLuint currentShaderIndex = 0;
GLuint currentRenderableIndex = 0;
GLuint currentTextureIndex = 0;
GLuint currentPassIndex = 0;

int activePassIndex = -1;

const GLuint MAX_NUM_BUFFERS = 80;
const GLuint MAX_NUM_GEOMETRIES = 30;
const GLuint MAX_NUM_SHADERS = 10;
const GLuint MAX_NUM_TEXTURES = 100;
const GLuint MAX_NUM_RENDERABLES = 600;
const GLuint MAX_NUM_PASSES = 10;
const GLuint BUFFER_SIZE = 1000000;

BufferInfo* bufferInfos[MAX_NUM_BUFFERS];
GeometryInfo* geometryInfos[MAX_NUM_GEOMETRIES];
ShaderInfo* shaderInfos[MAX_NUM_SHADERS];
TextureInfo* textureInfos[MAX_NUM_TEXTURES];
RenderableInfo* renderableInfos[MAX_NUM_RENDERABLES];
PassInfo* passes[MAX_NUM_PASSES];
#pragma endregion

//GLuint frameBufferID;


void GeneralGLWindow::initializeGL()
{
	setMouseTracking(true);
	glewInit();
	glDisable(GL_CULL_FACE);
	glEnable( GL_TEXTURE_2D );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GeneralGLWindow::debugMethod()
{

}

void GeneralGLWindow::paintGL()
{
	//glBindFramebuffer(GL_DRAW_FRAMEBUFFER, frameBufferID);
	//glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	//glClearColor(0.5f,0.5f,1.0f,0);
	//glViewport(0,0,width(), height());
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	//glClearColor(0.5f,0.5f,1.0f,1);
	glViewport(0,0,width(), height());
	if(currentPassIndex!=0)
	{
		for(int i = 0; i < currentPassIndex; i++)
		{
			drawPass(passes[i]);
		}
	}
	else
	{
		drawRenderables(renderableInfos, currentRenderableIndex);
	}
	//for(uint i = 0; i < currentRenderableIndex; i++)
	//{
	//	if(renderableInfos[i]->visible && renderableInfos[i]->priority == PRIORITY_1)
	//	{
	//		if(renderableInfos[i]->enableDepth)
	//			glEnable(GL_DEPTH_TEST);
	//		else
	//			glDisable(GL_DEPTH_TEST);

	//		sendRenderableToShader(renderableInfos[i]);
	//		glBindVertexArray(renderableInfos[i]->whatGeometry->vertexArrayID);
	//		glDrawElements(renderableInfos[i]->whatGeometry->indexingMode, renderableInfos[i]->whatGeometry->numIndices, GL_UNSIGNED_SHORT, (void*)renderableInfos[i]->whatGeometry->indexDataOffset);
	//	}
	//}
	//for(uint i = 0; i < currentRenderableIndex; i++)
	//{
	//	if(renderableInfos[i]->visible && renderableInfos[i]->priority == PRIORITY_2)
	//	{
	//		if(renderableInfos[i]->enableDepth)
	//			glEnable(GL_DEPTH_TEST);
	//		else
	//			glDisable(GL_DEPTH_TEST);

	//		sendRenderableToShader(renderableInfos[i]);
	//		glBindVertexArray(renderableInfos[i]->whatGeometry->vertexArrayID);
	//		glDrawElements(renderableInfos[i]->whatGeometry->indexingMode, renderableInfos[i]->whatGeometry->numIndices, GL_UNSIGNED_SHORT, (void*)renderableInfos[i]->whatGeometry->indexDataOffset);
	//	}
	//}
}

GeometryInfo* GeneralGLWindow::addGeometry(
	const void* verts, GLuint vertexDataSize,
	ushort* indices, GLuint numIndices,
	GLenum indexingMode)
{
	GLuint nextBuffIndex = getNextAvailableBufferIndex(vertexDataSize);
	BufferInfo* vertBuffer = bufferInfos[nextBuffIndex];
	GLuint vertexDataOffset = BUFFER_SIZE - vertBuffer->remainingSize;
	glBindBuffer(GL_ARRAY_BUFFER, vertBuffer->glBufferID);
	glBufferSubData(GL_ARRAY_BUFFER, BUFFER_SIZE - vertBuffer->remainingSize, vertexDataSize, verts);
	vertBuffer->remainingSize = vertBuffer->remainingSize - vertexDataSize;
	
	GLuint indexDataSize = sizeof(ushort) *numIndices;
	BufferInfo* indexBuffer = bufferInfos[getNextAvailableBufferIndex(indexDataSize)];
	GLuint indexDataOffset = BUFFER_SIZE - indexBuffer->remainingSize;
	glBindBuffer(GL_ARRAY_BUFFER, indexBuffer->glBufferID);
	glBufferSubData(GL_ARRAY_BUFFER, BUFFER_SIZE - indexBuffer->remainingSize, indexDataSize, indices);
	indexBuffer->remainingSize = indexBuffer->remainingSize - indexDataSize;
	
	geometryInfos[currentGeometryIndex] = new GeometryInfo();
	GeometryInfo* ret = geometryInfos[currentGeometryIndex];
	glGenVertexArrays(1, &ret->vertexArrayID);
	glBindVertexArray(ret->vertexArrayID);
	glBindBuffer(GL_ARRAY_BUFFER, vertBuffer->glBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer->glBufferID);
	ret->indexDataOffset = indexDataOffset;
	ret->vertexDataOffset = vertexDataOffset;
	ret->indexingMode = indexingMode;
	ret->numIndices = numIndices;
	currentGeometryIndex++;

	return ret;
}

GLuint GeneralGLWindow::getNextAvailableBufferIndex(GLuint dataSize)
{
	bool foundAvailableBuffer = false;
	GLuint nextAvailableBufferIndex;
	if(currentNumBuffers!=0)
	{
		for(uint i=0; i<currentNumBuffers && !foundAvailableBuffer; i++)
		{
			if(bufferInfos[i]->remainingSize>=dataSize)
			{
				foundAvailableBuffer = true;
				nextAvailableBufferIndex = i;
			}
		}
	}
	if(!foundAvailableBuffer)
	{
		bufferInfos[currentNumBuffers] = new BufferInfo();
		bufferInfos[currentNumBuffers]->remainingSize = BUFFER_SIZE;
		GLuint temp;// = bufferInfos[currentNumBuffers]->glBufferID;
		glewInit();
		glGenBuffers(1, &(temp));
		bufferInfos[currentNumBuffers]->glBufferID = temp;
		glBindBuffer(GL_ARRAY_BUFFER, bufferInfos[currentNumBuffers]->glBufferID);
		glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, 0, GL_STATIC_DRAW);
		nextAvailableBufferIndex = currentNumBuffers;
		currentNumBuffers++;
	}
	return nextAvailableBufferIndex;
}

ShaderInfo* GeneralGLWindow:: createShaderInfo(
		const char* vertexShaderFilename,
		const char* fragmentShaderFilename)
{
	shaderInfos[currentShaderIndex] = new ShaderInfo();
	ShaderInfo* ret = shaderInfos[currentShaderIndex];

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	std::string temp = readShaderCode(fragmentShaderFilename);	
	adapter[0] = temp.c_str();
	glShaderSource(fragShaderID, 1, adapter, 0);

	temp = readShaderCode(vertexShaderFilename);
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);

	glCompileShader(fragShaderID);
	glCompileShader(vertexShaderID);

	GLint compileStatus;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compileStatus);
	if(compileStatus != GL_TRUE)
	{
		ConsolePrinter::getInstance().print("Vertex Shader Error");
		GLint logLength;
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &logLength);
		char* buffer = new char[logLength];
		GLsizei bitBucket;
		glGetShaderInfoLog(vertexShaderID, logLength, &bitBucket, buffer);
		qDebug() << buffer;
		delete [] buffer;
	}

	glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &compileStatus);
	if(compileStatus != GL_TRUE)
	{
		ConsolePrinter::getInstance().print("Fragment Shader Error");
		GLint logLength;
		glGetShaderiv(fragShaderID, GL_INFO_LOG_LENGTH, &logLength);
		char* buffer = new char[logLength];
		GLsizei bitBucket;
		glGetShaderInfoLog(fragShaderID, logLength, &bitBucket, buffer);
		qDebug() << buffer;
		delete [] buffer;
	}

	ret->programID = glCreateProgram();
	glAttachShader(ret->programID, vertexShaderID);
	glAttachShader(ret->programID, fragShaderID);
	glLinkProgram(ret->programID);
	currentShaderIndex++;
	return ret;
}

std::string GeneralGLWindow::readShaderCode(const char *filename)
{
	std::ifstream input(filename);
	if(!input.good())
	{
		cout << "File failed to load: " << filename;
		exit(1);
	}
	return std::string(
		std::istreambuf_iterator<char>(input),
		std::istreambuf_iterator<char>());
}

TextureInfo* GeneralGLWindow::addTexture(const char* fileName)
{

	textureInfos[currentTextureIndex] = new TextureInfo();
	TextureInfo* ret = textureInfos[currentTextureIndex];
	glGenTextures(1, &(ret->textureID));
	glBindTexture(GL_TEXTURE_2D, ret->textureID);
	loadTextureFromFile(fileName);
	currentTextureIndex++;
	return ret;
}

TextureInfo* GeneralGLWindow::addTexture(const uchar* bytes, uint width, uint height)
{
	textureInfos[currentTextureIndex] = new TextureInfo();
	TextureInfo* ret = textureInfos[currentTextureIndex];
	ret->width = width;
	ret->height = height;
	glGenTextures(1, &(ret->textureID));
	glBindTexture(GL_TEXTURE_2D, ret->textureID);
	loadTextureFromBytes(bytes, width, height);
	currentTextureIndex++;
	return ret;
}

TextureInfo* GeneralGLWindow::addTexture(uint width, uint height)
{

	textureInfos[currentTextureIndex] = new TextureInfo();
	TextureInfo* ret = textureInfos[currentTextureIndex];
	ret->width = width;
	ret->height = height;
	glGenTextures(1, &(ret->textureID));
	//glBindTexture(GL_TEXTURE_2D, ret->textureID);//need?
	currentTextureIndex++;
	return ret;
}

TextureInfo* GeneralGLWindow::addCubeMap(const char* fileNames[6])
{
	//pos x, neg x, pos y, neg y, pos z, neg z
	textureInfos[currentTextureIndex] = new TextureInfo();
	TextureInfo* ret = textureInfos[currentTextureIndex];
	glGenTextures(1, &(ret->textureID));
	glBindTexture(GL_TEXTURE_CUBE_MAP, ret->textureID);
	loadTextureFromFile(fileNames[0], GL_TEXTURE_CUBE_MAP_POSITIVE_X);
	loadTextureFromFile(fileNames[1], GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
	loadTextureFromFile(fileNames[2], GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
	loadTextureFromFile(fileNames[3], GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
	loadTextureFromFile(fileNames[4], GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
	loadTextureFromFile(fileNames[5], GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
	currentTextureIndex++;
	return ret;
}

void GeneralGLWindow::modifyTextureData(TextureInfo* textureToModify, const uchar* bytes, uint width, uint height)
{
	glBindTexture(GL_TEXTURE_2D, textureToModify->textureID);
	loadTextureFromBytes(bytes, width, height);
}


void GeneralGLWindow::loadTextureFromFile(const char* filename, GLenum target)
{
	int width, height;
	QImage image = QImage(filename);
	image = QGLWidget::convertToGLFormat(image);
	width = image.width();
	height = image.height();
	uchar* imagePixels = image.bits();
	glTexImage2D(target, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imagePixels);
	if(target == GL_TEXTURE_2D)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}

}

void GeneralGLWindow::loadTextureFromBytes(const uchar* bytes, uint width, uint height)
{
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

RenderableInfo* GeneralGLWindow::addRenderable(
	GeometryInfo* whatGeometry,
	mat4 whereMatrix,
	ShaderInfo* howShaders,
	bool visible,
	PriorityLevel priority,
	bool depthEnabled,
	TextureInfo* diffuseMap,
	TextureInfo* alphaMap,
	TextureInfo* normalMap,
	TextureInfo* ambientOcclusionMap,
	TextureInfo* cubeMap)
{
	renderableInfos[currentRenderableIndex] = new RenderableInfo();
	RenderableInfo* ret = renderableInfos[currentRenderableIndex];
	ret->whatGeometry = whatGeometry;
	ret->whereMatrix = whereMatrix;
	ret->howShaders = howShaders;
	ret->visible = visible;
	ret->priority = priority;
	ret->enableDepth = depthEnabled;
	ret->diffuseMap = diffuseMap;
	ret->alphaMap = alphaMap;
	ret->normalMap = normalMap;
	ret->ambientOcclusionMap = ambientOcclusionMap;
	ret->cubeMap = cubeMap;
	
	ret->usingDiffuseMap = (diffuseMap!=NULL);
	ret->usingAlphaMap = (alphaMap!=NULL);
	ret->usingNormalMap = (normalMap!=NULL);
	ret->usingAmbientOcclusionMap = (ambientOcclusionMap!=NULL);
	ret->usingCubeMap = (cubeMap!=NULL);

	currentRenderableIndex++;

	if(activePassIndex != -1)
	{
		passes[activePassIndex]->renderables[passes[activePassIndex]->numRenderables] = ret;
		passes[activePassIndex]->numRenderables++;
	}

	return ret;
}

void GeneralGLWindow::addShaderStreamedParameter(
		GeometryInfo* geometry,
		uint layoutLocation, 
		ParameterType parameterType,
		uint bufferOffset,
		uint bufferStride)
{
	glBindVertexArray(geometry->vertexArrayID);
	glEnableVertexAttribArray(layoutLocation);
	glVertexAttribPointer(layoutLocation, parameterType/sizeof(float), GL_FLOAT, GL_FALSE, bufferStride, (void*)(geometry->vertexDataOffset+bufferOffset));
}

void GeneralGLWindow::addRenderableUniformParameter(
		RenderableInfo* renderable,
		const char* name,
		ParameterType parameterType,
		const float* value)
{
	renderable->uniformParameters[renderable->numUniformParameters].name = name;
	renderable->uniformParameters[renderable->numUniformParameters].parameterType = parameterType;
	renderable->uniformParameters[renderable->numUniformParameters].value = value;
	renderable->numUniformParameters++;
}

void GeneralGLWindow::setupFrameBuffer(PassInfo* pass)
{
	cout << "SETUP" << endl;
	glGenFramebuffers(1, &(pass->frameBufferID));
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, pass->frameBufferID);
	if(pass->storingColorTexture || pass->storingDepthTexture)
	{
		cout << "STORING THINGS" << endl;
		glActiveTexture(GL_TEXTURE0);
		if(pass->storingColorTexture)
		{
			glGenTextures(1, &(pass->colorTexture->textureID));
			glBindTexture(GL_TEXTURE_2D, pass->colorTexture->textureID);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WINDOW_WIDTH, WINDOW_HEIGHT, 0,GL_RGBA,GL_UNSIGNED_BYTE,0);
			glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,pass->colorTexture->textureID,0);
			GLuint status = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
			if(status!=GL_FRAMEBUFFER_COMPLETE)
			{
				ConsolePrinter::getInstance().print("Frame buffer incomplete - Color");
				qDebug() << "Frame buffer incomplete - Color";
			}
		}
		if(pass->storingDepthTexture)
		{
			glGenTextures(1, &(pass->depthTexture->textureID));
			glBindTexture(GL_TEXTURE_2D, pass->depthTexture->textureID);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32,WINDOW_WIDTH,WINDOW_HEIGHT,0,GL_DEPTH_COMPONENT,GL_FLOAT,0);
			glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, pass->depthTexture->textureID, 0);
			GLuint status = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
			if(status!=GL_FRAMEBUFFER_COMPLETE)
			{
				ConsolePrinter::getInstance().print("Frame buffer incomplete - Depth");
				qDebug() << "Frame buffer incomplete - Depth";
			}
		}
		GLuint status = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
		if(status!=GL_FRAMEBUFFER_COMPLETE)
		{
			qDebug() << "Frame buffer incomplete";
			
		}
	}
}

void GeneralGLWindow::resizeEvent(QResizeEvent* event)
{
	QGLWidget::resizeEvent(event);
	QSize newSize = event->size();
	WINDOW_HEIGHT = newSize.height();
	WINDOW_WIDTH = newSize.width();

	if(currentPassIndex > 0)
	{
		for(int i = 0; i < currentPassIndex; i++)
		{
			setupFrameBuffer(passes[i]);
		}
	}
}

void GeneralGLWindow::drawPass(PassInfo* pass)
{
	//drawRenderables(pass->renderables, pass->numRenderables);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, pass->frameBufferID);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	//glClearColor(0.5f,0.5f,1.0f,0);
	//glViewport(0,0,width(), height());
	drawRenderables(pass->renderables, pass->numRenderables);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	drawRenderables(pass->renderables, pass->numRenderables);
}

void GeneralGLWindow::drawRenderables(RenderableInfo* renderablesArray[], GLuint numRenderabelsToDraw)
{
	for(int priority = 0; priority < 2; priority++)
	{
		for(uint i = 0; i < numRenderabelsToDraw; i++)
		{
			RenderableInfo* currentRenderable = renderablesArray[i];
			if(currentRenderable->visible && currentRenderable->priority == (PriorityLevel)priority)
			{
				if(currentRenderable->enableDepth)
					glEnable(GL_DEPTH_TEST);
				else
					glDisable(GL_DEPTH_TEST);

				sendRenderableToShader(currentRenderable);
				glBindVertexArray(currentRenderable->whatGeometry->vertexArrayID);
				glDrawElements(currentRenderable->whatGeometry->indexingMode, currentRenderable->whatGeometry->numIndices, GL_UNSIGNED_SHORT, (void*)currentRenderable->whatGeometry->indexDataOffset);
			}
		}
	}
}

void GeneralGLWindow::sendRenderableToShader(RenderableInfo* renderable)
{
	GLuint programID = renderable->howShaders->programID;
	glUseProgram(programID);

	if(renderable->usingDiffuseMap)
	{
		GLint diffuseMapLoc = glGetUniformLocation(programID, "diffuseMap");
		glUniform1i(diffuseMapLoc, 0);
		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, renderable->diffuseMap->textureID);
	}
	if(renderable->usingAlphaMap)
	{
		//cout << "ALPHA" << endl;
		GLint alphaMapLoc = glGetUniformLocation(programID, "alphaMap");
		glUniform1i(alphaMapLoc, 1);
		glActiveTexture(GL_TEXTURE0 + 1);
		glBindTexture(GL_TEXTURE_2D, renderable->alphaMap->textureID);
	}
	if(renderable->usingNormalMap)
	{
		//cout << "NORMAL" << endl;
		GLint normalMapLoc = glGetUniformLocation(programID, "normalMap");
		glUniform1i(normalMapLoc, 2);
		glActiveTexture(GL_TEXTURE0 + 2);
		glBindTexture(GL_TEXTURE_2D, renderable->normalMap->textureID);
	}
	if(renderable->usingAmbientOcclusionMap)
	{
		//cout << "NORMAL" << endl;
		GLint ambOcclusionLoc = glGetUniformLocation(programID, "ambientOcclusionMap");
		glUniform1i(ambOcclusionLoc, 3);
		glActiveTexture(GL_TEXTURE0 + 3);
		glBindTexture(GL_TEXTURE_2D, renderable->ambientOcclusionMap->textureID);
	}
	if(renderable->usingCubeMap)
	{
		//cout << "NORMAL" << endl;
		GLint cubeMapLoc = glGetUniformLocation(programID, "cubeMap");
		glUniform1i(cubeMapLoc, 4);
		glActiveTexture(GL_TEXTURE0 + 4);
		glBindTexture(GL_TEXTURE_CUBE_MAP, renderable->cubeMap->textureID);
	}
	GLint uniformLocation = glGetUniformLocation(programID, "hasDiffuseMap");
	glUniform1i(uniformLocation, renderable->usingDiffuseMap);
	uniformLocation = glGetUniformLocation(programID, "hasAlphaMap");
	glUniform1i(uniformLocation, renderable->usingAlphaMap);
	uniformLocation = glGetUniformLocation(programID, "hasNormalMap");
	glUniform1i(uniformLocation, renderable->usingNormalMap);
	uniformLocation = glGetUniformLocation(programID, "hasAmbientOcclusion");
	glUniform1i(uniformLocation, renderable->usingAmbientOcclusionMap);
	uniformLocation = glGetUniformLocation(programID, "hasCubeMap");
	glUniform1i(uniformLocation, renderable->usingCubeMap);

	for(uint i=0; i<renderable->numUniformParameters;i++)
	{
		GLint uniformLocation = glGetUniformLocation(programID, renderable->uniformParameters[i].name);
		
		switch(renderable->uniformParameters[i].parameterType)
		{
		case PT_FLOAT:
			glUniform1f(uniformLocation, *renderable->uniformParameters[i].value);
			break;
		case PT_VEC2:
			glUniform2fv(uniformLocation, 1, renderable->uniformParameters[i].value);
			break;
		case PT_VEC3:
			glUniform3fv(uniformLocation, 1, renderable->uniformParameters[i].value);
			break;
		case PT_VEC4:
			glUniform4fv(uniformLocation, 1,renderable->uniformParameters[i].value);
			break;
		case PT_MAT3:
			glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, renderable->uniformParameters[i].value);
			break;
		case PT_MAT4:
			glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, renderable->uniformParameters[i].value);
			break;
		}
	}
}

PassInfo* GeneralGLWindow::addPass(bool addAllPreviousRenderables,bool setAsCurrentPass)
{
	passes[currentPassIndex] = new PassInfo();
	PassInfo* ret = passes[currentPassIndex];
	ret->index = currentPassIndex;
	if(addAllPreviousRenderables)
	{
		for(int i = 0; i < currentRenderableIndex; i++)
		{
			ret->renderables[i] = renderableInfos[i];
			ret->numRenderables++;
		}
	}
	if(setAsCurrentPass)
	{
		activePassIndex = currentPassIndex;
	}
	currentPassIndex++;
	return ret;
}

TextureInfo* GeneralGLWindow::storePassColorTexture(PassInfo* pass, uint width, uint height)
{
	pass->colorTexture = addTexture(width, height);
	pass->storingColorTexture = true;
	return pass->colorTexture;
}

TextureInfo* GeneralGLWindow::storePassDepthTexture(PassInfo* pass, uint width, uint height)
{
	pass->depthTexture = addTexture(width, height);
	pass->storingDepthTexture = true;
	return pass->depthTexture;
}

void GeneralGLWindow::setCurrentPass(PassInfo* passToMakeCurrent)
{
	activePassIndex = passToMakeCurrent->index;
}

void GeneralGLWindow::unsetCurrentPass()
{
	activePassIndex = -1;
}

void GeneralGLWindow::keyPressEvent(QKeyEvent* e)
{
	emit keyPressed(e);
}

void GeneralGLWindow::mouseMoveEvent(QMouseEvent* e)
{
	emit mouseMoved(e);
}

void GeneralGLWindow::mouseReleaseEvent(QMouseEvent* e)
{
	emit mouseClicked(e);
}

GeneralGLWindow* GeneralGLWindow::theInstance;

GeneralGLWindow& GeneralGLWindow::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new GeneralGLWindow();
	}
	return *theInstance;
}