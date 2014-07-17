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
#include "..\Camera.h"
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
#include "DiffuseMapInfo.h"
#include "AmbientOcclusionMapInfo.h"
#include "AlphaMapInfo.h"
#include "NormalMapInfo.h"
#include "ShaderInfo.h"
#include "ShaderUniformParameter.h"
#include "ParameterType.h"
#include "PriorityLevel.h"

using std::cout;
using std::endl;


using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;


class __declspec(dllexport) GeneralGLWindow: public QGLWidget
{
	Q_OBJECT

private:
	GeneralGLWindow()
	{
	}
	GeneralGLWindow(GeneralGLWindow const&);
	GeneralGLWindow& operator = (GeneralGLWindow const&);
	static GeneralGLWindow* theInstance;

public:
	void debugMethod();

	static GeneralGLWindow& getInstance();

	GeometryInfo* addGeometry(
		const void* verts, GLuint vertexDataSize,
		ushort* indices, GLuint numIndices,
		GLenum indexingMode);//lines, triangles, point, etc

	ShaderInfo* createShaderInfo(
		const char* vertexShaderFilename,
		const char* fragmentShaderFilename);

	DiffuseMapInfo* addDiffuseMap(const char* fileName);
	DiffuseMapInfo* addDiffuseMap(const uchar* bytes, uint width, uint height);
	AlphaMapInfo* addAlphaMap(const char* fileName);
	AlphaMapInfo* addAlphaMap(const uchar* bytes, uint width, uint height);
	NormalMapInfo* addNormalMap(const char* fileName);
	NormalMapInfo* addNormalMap(const uchar* bytes, uint width, uint height);
	AmbientOcclusionMapInfo* addAmbientOcclusionMap(const char* fileName);
	AmbientOcclusionMapInfo* addAmbientOcclusionMap(const uchar* bytes, uint width, uint height);

	RenderableInfo* addRenderable(
		GeometryInfo* whatGeometry,
		mat4 whereMatrix,
		ShaderInfo* howShaders,
		bool visible,
		PriorityLevel priority,
		bool depthEnabled = true,
		DiffuseMapInfo* diffuseMap = NULL,
		AlphaMapInfo* alphaMap = NULL,
		NormalMapInfo* normalMap = NULL,
		AmbientOcclusionMapInfo* ambientOcclusionMap = NULL);

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

	void keyPressEvent(QKeyEvent* e);

private:
	void loadTextureFromFile(const char* filename);
	void loadTextureFromBytes(const uchar* bytes, uint width, uint height);
	std::string readShaderCode(const char *filename);
	GLuint getNextAvailableBufferIndex(GLuint dataSize);

protected:
	void paintGL();
	void mouseMoveEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);

signals:
	void keyPressed(QKeyEvent* e);
	void mouseMoved(QMouseEvent* e);
	void mouseClicked(QMouseEvent* e);
};
