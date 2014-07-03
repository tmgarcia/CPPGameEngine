#pragma once
#include <Qt\qapplication.h>
#include <Qt\qboxlayout.h>
#include <Qt\qmainwindow.h>
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
		
		connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
		updateTimer.setInterval(1);
		updateTimer.start(0);

		//DebugMenu* dMenu = new DebugMenu();
		//mainLayout->addWidget(dMenu);

		GeneralGLWindow::getInstance();
		GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setCentralWidget(&GeneralGLWindow::getInstance());
		GeneralGLWindow::getInstance().show();

		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));

		setup();

		this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
	}
protected:
	void setup();
	Camera camera;
	void keyPressEvent(QKeyEvent* event);
	void updateShaderInfo();
	BlinkingEyeGroup* eyes;
private slots:
	void update();
public slots:
	void mouseMoveReaction(QMouseEvent* e);

};

