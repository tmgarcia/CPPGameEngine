#pragma once

#include "GeneralGLWindow.h"
#include "ParameterType.h"
#include <Qt\qapplication.h>


const GLuint WINDOW_WIDTH = 900;
const GLuint WINDOW_HEIGHT = 900;

class ClientGLWindow 
{
public:
	ClientGLWindow()
	{
		meWindow.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		meWindow.show();
		setup();
	}
protected:
	void setup();
	void setupGeometries();
	void setupGeometryVertexArrayInfo(GeometryInfo* geometry);
	void setupShaders();
	void addLightingAndTextureShaderUniforms(RenderableInfo* renderable);
	void addPassThroughShaderUniforms(RenderableInfo* renderable);
	void setupTransforms();
	void setupRenderables();
	void setupTextures();
	GeneralGLWindow meWindow;
};

