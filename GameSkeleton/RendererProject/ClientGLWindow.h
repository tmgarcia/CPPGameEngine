#pragma once
#include "GeneralGLWindow.h"

class ClientGLWindow : public QGLWidget
{
public:
	void initializeGL();
	void setup();
	void paintGL();
	void setLightingAndTextureUniforms(RenderableInfo* renderable);
};

