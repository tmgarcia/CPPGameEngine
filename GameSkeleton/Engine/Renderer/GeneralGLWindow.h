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

#include "PassInfo.h"
#include "BufferInfo.h"
#include "GeometryInfo.h"
#include "RenderableInfo.h"
#include "TextureInfo.h"
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
	GeneralGLWindow(){}
	GeneralGLWindow(GeneralGLWindow const&);
	GeneralGLWindow& operator = (GeneralGLWindow const&);
	static GeneralGLWindow* theInstance;

public:
	void debugMethod();
	GLuint WINDOW_WIDTH;
	GLuint WINDOW_HEIGHT;
	static GeneralGLWindow& getInstance();

	GeometryInfo* addGeometry(
		const void* verts, GLuint vertexDataSize,
		ushort* indices, GLuint numIndices,
		GLenum indexingMode);//lines, triangles, point, etc

	ShaderInfo* createShaderInfo(
		const char* vertexShaderFilename,
		const char* fragmentShaderFilename);

	void modifyTextureData(TextureInfo* textureToModify, const uchar* bytes, uint width, uint height);
	TextureInfo* addTexture(const char* fileName);
	TextureInfo* addTexture(const uchar* bytes, uint width, uint height);
	TextureInfo* addTexture(uint width, uint height);
	TextureInfo* addCubeMap(const char* fileNames[6] );//pos x, neg x, pos y, neg y, pos z, neg z

	RenderableInfo* addRenderable(
		GeometryInfo* whatGeometry,
		mat4 whereMatrix,
		ShaderInfo* howShaders,
		bool visible,
		PriorityLevel priority,
		bool depthEnabled = true,
		TextureInfo* diffuseMap = NULL,
		TextureInfo* alphaMap = NULL,
		TextureInfo* normalMap = NULL,
		TextureInfo* ambientOcclusionMap = NULL,
		TextureInfo* cubeMap = NULL);

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
	void addPassUniformParameter(
		PassInfo* renderable,
		const char* name,
		ParameterType parameterType,
		const float* value);

	PassInfo* addPass(
		bool addAllPreviousRenderables,
		bool setAsCurrentPass);
	TextureInfo* storePassColorTexture(PassInfo* pass, uint width,uint height);
	TextureInfo* storePassDepthTexture(PassInfo* pass, uint width,uint height);

	void setCurrentPass(
		PassInfo* passToMakeCurrent);

	void unsetCurrentPass();

	void initializeGL();

	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent* e);
	void setupFrameBuffer(PassInfo* pass);

	void saveTexture(TextureInfo* texture, QString fileName);

private:
	void drawPass(PassInfo* pass);
	void drawRenderables(RenderableInfo* renderablesArray[], GLuint numRenderabelsToDraw, PassInfo* pass = NULL);
	void sendRenderableToShader(RenderableInfo* renderable, PassInfo* pass = NULL);

	void loadTextureFromFile(const char* filename, GLenum target=GL_TEXTURE_2D);
	void loadTextureFromBytes(const uchar* bytes, uint width, uint height);
	std::string readShaderCode(const char *filename);
	GLuint getNextAvailableBufferIndex(GLuint dataSize);

protected:
	void paintGL();
	void mouseMoveEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);
	void resizeEvent(QResizeEvent* e);

signals:
	void keyPressed(QKeyEvent* e);
	void keyReleased(QKeyEvent* e);
	void mouseMoved(QMouseEvent* e);
	void mouseClicked(QMouseEvent* e);
};
