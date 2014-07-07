#pragma once
#include <Qt\qapplication.h>
#include <Qt\qboxlayout.h>
#include <Qt\qmainwindow.h>
#include <Qt\qdockwidget.h>
#include "GeneralGLWindow.h"
#include "DebugMenu\DebugMenu.h"
#include "GraphicObjects\BlinkingEyeGroup.h"

#include <iostream>

using std::cout;
using std::endl;

const GLuint WINDOW_WIDTH = 1500;
const GLuint WINDOW_HEIGHT = 900;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	QTimer updateTimer;

public:
	MainWindow()
	{
		this->show();
		cameraFrozen = false;
		connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
		updateTimer.setInterval(1);
		updateTimer.start(0);
		ConsolePrinter::getInstance();

		QDockWidget* menuDock = new QDockWidget("Debug", this);
		menuDock->setAllowedAreas(Qt::TopDockWidgetArea);
		menuDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
		dMenu = new DebugMenu();

		dMenu->setParent(menuDock);
		menuDock->setWidget(dMenu);
		addDockWidget(Qt::TopDockWidgetArea, menuDock);

		GeneralGLWindow::getInstance();
		GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setCentralWidget(&GeneralGLWindow::getInstance());
		GeneralGLWindow::getInstance().show();

		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));

		setup();

		this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
	}

	struct GameObject
	{
		RenderableInfo* renderable;

		mat4 modelToWorld;
		mat4 rotation;
		mat4 fullTransform;
		vec3 position;
		float angle;
		vec3 rotateAxis;
		void setupTransforms(float angl, vec3 axis, vec3 pos, mat4 worldToProjectionMatrix)
		{
			angle = angl;
			rotateAxis = axis;
			position = pos;
			updateTransforms(worldToProjectionMatrix);
		}
		void updateTransforms(mat4 worldToProjectionMatrix)
		{
			rotation = glm::rotate(angle, rotateAxis);
			modelToWorld = glm::translate(position) * rotation;
			fullTransform = worldToProjectionMatrix * modelToWorld;
		}
	};

protected:
	DebugMenu* dMenu;
	void setup();
	void setupGeometry();
	void setupTransforms();
	void setupTextures();
	void setupRenderables();
	void addLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix);
	void setupReadInGeometryVertexArrayInfo(GeometryInfo* geometry);
	Camera camera;
	void keyPressEvent(QKeyEvent* event);
	void updateShaderInfo();
	bool cameraFrozen;
private slots:
	void update();
public slots:
	void mouseMoveReaction(QMouseEvent* e);

};

