#pragma once

#include <Qt\qapplication.h>
#include "DebugShapes.h"


const GLuint WINDOW_WIDTH = 1920;
const GLuint WINDOW_HEIGHT = 1080;

class Controller : public QObject
{
	Q_OBJECT

	QTimer myTimer;

public:
	Controller()
	{
		GeneralGLWindow::getInstance();
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));
		connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
		myTimer.setInterval(1);
		myTimer.start(0);
		GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		GeneralGLWindow::getInstance().move(0,0);
		GeneralGLWindow::getInstance().show();
		setup();
	}
protected:
	void setup();
	void setupGeometries();
	void setupGeometryVertexArrayInfo(GeometryInfo* geometry);
	void setupReadInGeometryVertexArrayInfo(GeometryInfo* geometry);
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
	void setupDebugShapes();

private slots:
	void myUpdate();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

