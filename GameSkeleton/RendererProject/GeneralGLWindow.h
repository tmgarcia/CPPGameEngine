#pragma once
#include <GL\glew.h>
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
#include <glm\glm.hpp>


#include "BufferInfo.h"
#include "GeometryInfo.h"
#include "RenderableInfo.h"
#include "TextureInfo.h"
#include "ShaderInfo.h"
#include "ShaderUniformParameter.h"
#include "ParameterType.h"

using std::cout;
using std::endl;


using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;


class GeneralGLWindow: public QGLWidget
{
public:

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
		mat4 whereMatrix,
		ShaderInfo* howShaders,
		TextureInfo* texture = NULL);

	void addShaderStreamedParameter(
		GeometryInfo* geometry,
		uint layoutLocation, 
		ParameterType parameterType,
		uint bufferOffset,
		uint bufferStride);

	
	void addRenderableUniformParameter(
		RenderableInfo* renderable,
		const char* name,
		ParameterType parameterType,
		const float* value);

	void sendRenderableToShader(
		RenderableInfo* renderable);

	void initializeGL();
private:
	void loadTextureBitmap(const char* filename);
	std::string readShaderCode(const char *filename);
	GLuint getNextAvailableBufferIndex(GLuint dataSize);

protected:
	void paintGL();
};
