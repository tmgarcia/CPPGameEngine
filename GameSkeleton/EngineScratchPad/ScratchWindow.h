#pragma once

#include <Qt\qapplication.h>
#include <Qt\qboxlayout.h>
#include <Qt\qmainwindow.h>
#include "GeneralGLWindow.h"
#include "DebugMenu\DebugMenu.h"
#include "MathTools\TransformationMatrixMaker.h"
#include "MathTools\Random.h"
#include "GraphicObjects\BlinkingEyeGroup.h"
#include <Qt\qdockwidget.h>
#include "RendererHelper.h"

#include <iostream>

using std::cout;
using std::endl;

const GLuint WINDOW_WIDTH = 1300;
const GLuint WINDOW_HEIGHT = 900;

class ScratchWindow : public QMainWindow
{
	Q_OBJECT

	QTimer updateTimer;

public:
	ScratchWindow()
	{
		this->show();
		cameraFrozen = false;
		connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
		updateTimer.setInterval(1);
		updateTimer.start(0);

		QDockWidget* menuDock = new QDockWidget("Debug", this);
		menuDock->setAllowedAreas(Qt::TopDockWidgetArea);
		menuDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
		dMenu = new DebugMenu();

		dMenu->setParent(menuDock);
		menuDock->setWidget(dMenu);
		addDockWidget(Qt::TopDockWidgetArea, menuDock);

		GeneralGLWindow::getInstance();
		setCentralWidget(&GeneralGLWindow::getInstance());
		GeneralGLWindow::getInstance().show();

		GeneralGLWindow::getInstance();

		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));

		setup();

		this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
	}
	~ScratchWindow()
	{

	}
protected:
	bool cameraFrozen;
	DebugMenu* dMenu;
	RendererHelper* renderHelper;
	void setup();
	void setupGeometry();
	void setupTransforms();
	void setupTextures();
	void setupRenderables();
	Camera camera;
	void keyPressEvent(QKeyEvent *event);
	void updateShaderInfo();
private slots:
	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

