#pragma once

#include "GeneralGLWindow.h"
#include "ParameterType.h"
#include <Qt\qapplication.h>


const GLuint WINDOW_WIDTH = 1920;
const GLuint WINDOW_HEIGHT = 1080;

class ClientGLWindow : public QObject
{
	Q_OBJECT

	QTimer myTimer;

public:
	ClientGLWindow()
	{
		QObject::connect(&meWindow, SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
		QObject::connect(&meWindow, SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));
		connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
		myTimer.start(0);
		meWindow.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		meWindow.move(0,0);
		meWindow.show();
		setup();
	}
protected:
	void setup();
	void setupGeometries();
	void setupGeometryVertexArrayInfo(GeometryInfo* geometry);
	void setupShaders();
	void addLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix);
	void addBrightLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix);
	void addDarkLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix);
	void addJustLightingShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix);
	void addPassThroughShaderUniforms(RenderableInfo* renderable, float* fullTransform);
	void addJustTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform);
	void setupTransforms();
	void setupRenderables();
	void setupTextures();
	void setupShaderUniforms();
	void updateShaderUniforms();
	GeneralGLWindow meWindow;

private slots:
	void myUpdate();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

