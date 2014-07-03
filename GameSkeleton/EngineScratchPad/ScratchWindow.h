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
		//GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setCentralWidget(&GeneralGLWindow::getInstance());
		GeneralGLWindow::getInstance().show();

		GeneralGLWindow::getInstance();

		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));
		cubePosX = 2;
		cubePosZ = 0;
		dMenu->addFloatSlider("CubeTab",&cubePosX, -5, 5, "float cube x");
		dMenu->addIntSlider("CubeTab",&cubePosZ, -5, 5, "int cube z");

		spherePosX = -2;
		spherePosZ = 0;
		dMenu->addFloatSlider("SphereTab",&spherePosX, -5, 5, "float sphere x");
		dMenu->addIntSlider("SphereTab",&spherePosZ, -5, 5, "int sphere z");

		setup();


		//this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
	}
	~ScratchWindow()
	{

	}
protected:
	DebugMenu* dMenu;
	float cubePosX;
	int cubePosZ;
	float spherePosX;
	int spherePosZ;
	void setup();
	Camera camera;
	void keyPressEvent(QKeyEvent *event);
	void updateShaderInfo();
private slots:
	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

