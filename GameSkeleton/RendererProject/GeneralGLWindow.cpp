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
#include "Camera.h"
#include <QtGUI\qmouseevent>
#include <QtGUI\qkeyevent>
#include <GL\GL.h>
#include <QtOpenGL\qglwidget>
#include <qt\qtimer.h>
#include <iostream>

GLuint currentNumBuffers = 0;
GLuint currentGeometryIndex = 0;
GLuint currentShaderIndex = 0;
GLuint currentRenderIndex = 0;
GLuint currentTextureIndex = 0;

const GLuint MAX_NUM_BUFFERS = 10;
const GLuint MAX_NUM_GEOMETRIES = 10;
const GLuint MAX_NUM_SHADERS = 10;
const GLuint MAX_NUM_TEXTURES = 10;
const GLuint MAX_NUM_RENDERABLES = 10;
const GLuint BUFFER_SIZE = 1000000;

BufferInfo* bufferInfos[MAX_NUM_BUFFERS];
GeometryInfo* geometryInfos[MAX_NUM_GEOMETRIES];
ShaderInfo* shaderInfos[MAX_NUM_SHADERS];
TextureInfo* textureInfos[MAX_NUM_TEXTURES];
RenderableInfo* renderableInfos[MAX_NUM_RENDERABLES];

void GeneralGLWindow::initializeGL()
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glEnable( GL_TEXTURE_2D );
}

void GeneralGLWindow::paintGL()
{
	cout<< "Painting" <<endl;
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0,0,width(), height());

	for(uint i = 0; i < currentRenderIndex; i++)
	{
		sendRenderableToShader(renderableInfos[i]);
		glBindVertexArray(renderableInfos[i]->whatGeometry->vertexArrayID);
		glDrawElements(renderableInfos[i]->whatGeometry->indexingMode, renderableInfos[i]->whatGeometry->numIndices, GL_UNSIGNED_SHORT, (void*)renderableInfos[i]->whatGeometry->indexDataOffset);
	}
}

GeometryInfo* GeneralGLWindow::addGeometry(
		const void* verts, GLuint vertexDataSize,
		ushort* indices, GLuint numIndices,
		GLenum indexingMode)
{
	cout<<"Getting Buffer"<<endl;
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
	
	cout<<"Creating Geometry"<<endl;
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
	cout<<"Creating Shader Info"<<endl;

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
	cout<<"Adding Texture"<<endl;

	textureInfos[currentTextureIndex] = new TextureInfo();
	TextureInfo* ret = textureInfos[currentTextureIndex];
	glGenTextures(1, &(ret->textureID));
	glBindTexture(GL_TEXTURE_2D, ret->textureID);
	loadTextureBitmap(fileName);
	currentTextureIndex++;
	return ret;
}

void GeneralGLWindow::loadTextureBitmap(const char* filename)
{
	int width, height;
	QImage image = QImage(filename);
	image = QGLWidget::convertToGLFormat(image);
	width = image.width();
	height = image.height();
	uchar* imagePixels = image.bits();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imagePixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

RenderableInfo* GeneralGLWindow::addRenderable(
	GeometryInfo* whatGeometry,
	mat4 whereMatrix,
	ShaderInfo* howShaders,
	TextureInfo* texture)
{
	cout<<"Creating Renderable"<<endl;

	renderableInfos[currentRenderIndex] = new RenderableInfo();
	RenderableInfo* ret = renderableInfos[currentRenderIndex];
	ret->whatGeometry = whatGeometry;
	ret->whereMatrix = whereMatrix;
	ret->howShaders = howShaders;
	ret->texture = texture;
	currentRenderIndex++;
	return ret;
}

void GeneralGLWindow::addShaderStreamedParameter(
		GeometryInfo* geometry,
		uint layoutLocation, 
		ParameterType parameterType,
		uint bufferOffset,
		uint bufferStride)
{
	cout<<"Adding Vertex attribs"<<endl;
	cout<<"	"<< layoutLocation<<endl;

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
	cout<<"Adding Uniform parameter"<<endl;
	renderable->uniformParameters[renderable->numUniformParameters].name = name;
	renderable->uniformParameters[renderable->numUniformParameters].parameterType = parameterType;
	renderable->uniformParameters[renderable->numUniformParameters].value = value;
	renderable->numUniformParameters++;
}

void GeneralGLWindow::sendRenderableToShader(RenderableInfo* renderable)
{
	cout<<"Sending Renderable To Shader"<<endl;
	glLinkProgram(renderable->howShaders->programID);
	glUseProgram(renderable->howShaders->programID);

	if(renderable->texture != NULL)
		glBindTexture(GL_TEXTURE_2D, renderable->texture->textureID);

	for(uint i=0; i<renderable->numUniformParameters;i++)
	{
		GLint uniformLocation = glGetUniformLocation(renderable->howShaders->programID, renderable->uniformParameters[i].name);
		
		cout<<  renderable->uniformParameters[i].name << endl;

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