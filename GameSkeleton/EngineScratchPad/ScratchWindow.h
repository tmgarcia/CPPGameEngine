#pragma once

#include <Qt\qapplication.h>
#include <Qt\qboxlayout.h>
#include <Qt\qmainwindow.h>
#include "GeneralGLWindow.h"
#include "DebugMenu\DebugMenu.h"

#include <iostream>

using std::cout;
using std::endl;

const GLuint WINDOW_WIDTH = 1500;
const GLuint WINDOW_HEIGHT = 900;

class ScratchWindow : public QMainWindow
{
	Q_OBJECT

	QTimer updateTimer;

public:
	ScratchWindow()
	{
		this->show();
		cout << "constructing scratch window" << endl;
		
		connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
		updateTimer.setInterval(1);
		updateTimer.start(0);

		//DebugMenu* dMenu = new DebugMenu();
		//mainLayout->addWidget(dMenu);

		GeneralGLWindow::getInstance();
		GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setCentralWidget(&GeneralGLWindow::getInstance());
		GeneralGLWindow::getInstance().show();

		GeneralGLWindow::getInstance();

		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));

		//dMenu->addFloatSlider(&val, 0, 10, "Label");

		setup();

		this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
	}
	~ScratchWindow()
	{

	}
protected:
	float val;
	void setup();
	Camera camera;
	void loadLevel();
	void keyPressEvent(QKeyEvent *event);
	void updateShaderInfo();
	mat4 billboard(vec3 position);
	void blinkEye(RenderableInfo* eye, int stage);
	void checkBlinks();

private slots:
	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

