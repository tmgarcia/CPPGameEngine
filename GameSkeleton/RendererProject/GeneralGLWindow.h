#pragma once
#include <QtOpenGL\qglwidget>
#include <GL\glew.h>
#include <qt\qtimer.h>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
#include <Qt\qdebug.h>
#include <fstream>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
#include "ShapeData.h"
#include "ShapeGenerator.h"
#include <iostream>

#include "BufferInfo.h"
#include "GeometryInfo.h"
#include "RenderableInfo.h"
#include "TextureInfo.h"
#include "ShaderInfo.h"

using std::cout;
using std::endl;


using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;

GLuint currentNumBuffers = 0;
GLuint currentGeometryIndex = 0;
GLuint currentShaderIndex = 0;
GLuint currentRenderIndex = 0;
GLuint currentTextureIndex = 0;

const GLuint MAX_NUM_BUFFERS = 10;
const GLuint BUFFER_SIZE = 1000000;

class GeneralGLWindow : public QGLWidget
{
public:
	enum ParameterType
	{
		// These values matter:
		PT_FLOAT = sizeof(float) * 1,
		PT_VEC2 = sizeof(float) * 2,
		PT_VEC3 = sizeof(float) * 3,
		PT_VEC4 = sizeof(float) * 4,
		PT_MAT3 = sizeof(float) * 9,
		PT_MAT4 = sizeof(float) *16,
	};

	BufferInfo bufferInfos[MAX_NUM_BUFFERS];
	GeometryInfo geometryInfos[10];
	ShaderInfo shaderInfos[10];
	TextureInfo textureInfos[10];
	RenderableInfo renderableInfos[10];


	GeometryInfo* addGeometry(
		const void* verts, GLuint vertexDataSize,
		ushort* indices, GLuint numIndices,
		GLenum indexingMode);//lines, triangles, point, etc

	GLuint getNextAvailableBufferIndex(GLuint dataSize);


	ShaderInfo* createShaderInfo(
		const char* vertexShaderFilename,
		const char* fragmentShaderFilename);

	std::string readShaderCode(const char *filename);

	TextureInfo* addTexture(const char* fileName);

	void loadTextureBitmap(const char* filename);

	RenderableInfo* addRenderable(
		GeometryInfo* whatGeometry,
		const mat4& whereMatrix,
		ShaderInfo* howShaders,
		TextureInfo* texture = NULL);

	void addShaderStreamedParameter(
		GeometryInfo* geometry,
		uint layoutLocation, 
		GeneralGLWindow::ParameterType parameterType,
		uint bufferOffset,
		uint bufferStride);

	
	void addRenderableUniformParameter(
		RenderableInfo* renderable,
		const char* name,
		GeneralGLWindow::ParameterType parameterType,
		const float* value);

};

void clientSideCode()
{
	GeneralGLWindow meWindow;
	Neumont::ShapeData sphere = Neumont::ShapeGenerator::makeSphere(10);
	meWindow.addGeometry(sphere.verts, sphere.vertexBufferSize(), sphere.indices, sphere.numIndices, GL_TRIANGLES);
	//or make it so you can do 
	//meWindow.addGeometry(sphere);
	//Override method?
	meWindow.createShaderInfo(meShaderVertexFileName, meShaderFragmentFileName);
	
}