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
#include "ShaderUniformParameter.h"

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
const GLuint MAX_NUM_GEOMETRIES = 10;
const GLuint MAX_NUM_SHADERS = 10;
const GLuint MAX_NUM_TEXTURES = 10;
const GLuint MAX_NUM_RENDERABLES = 10;
const GLuint BUFFER_SIZE = 1000000;

BufferInfo bufferInfos[MAX_NUM_BUFFERS];
GeometryInfo geometryInfos[MAX_NUM_GEOMETRIES];
ShaderInfo shaderInfos[MAX_NUM_SHADERS];
TextureInfo textureInfos[MAX_NUM_TEXTURES];
RenderableInfo renderableInfos[MAX_NUM_RENDERABLES];

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


	GeometryInfo* addGeometry(
		const void* verts, GLuint vertexDataSize,
		ushort* indices, GLuint numIndices,
		GLenum indexingMode);//lines, triangles, point, etc

	ShaderInfo* createShaderInfo(
		const char* vertexShaderFilename,
		const char* fragmentShaderFilename);

	TextureInfo* addTexture(const char* fileName);

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

	void sendRenderableUniformsToShader(
		RenderableInfo* renderable); 
private:
	void loadTextureBitmap(const char* filename);
	std::string readShaderCode(const char *filename);
	GLuint getNextAvailableBufferIndex(GLuint dataSize);

};
