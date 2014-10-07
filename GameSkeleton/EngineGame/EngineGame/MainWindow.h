#pragma once

#include <Qt\qapplication.h>
#include <Qt\qboxlayout.h>
#include <Qt\qmainwindow.h>
#include "GeneralGLWindow.h"
#include "Time\GameClock.h"
#include "DebugMenu\DebugMenu.h"
#include <Qt\qdockwidget.h>
#include "Input\KeyInput.h"
#include "KeyMap.h"
#include "InputActions.h"

#include <iostream>

using std::cout;
using std::endl;

const GLuint WINDOW_WIDTH = 1300;
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
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyReleased(QKeyEvent*)), this, SLOT(keyReleaseReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));

		GameClock::getInstance();

		KeyMap* keyMap = new KeyMap();
		KeyInput::getInstance();
		KeyInput::getInstance().initialize(keyMap, InputActions::INPUT_ACT_MAX);

		setup();

		this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
	}
	
protected:

private:
	DebugMenu* dMenu;
	void setup();
	Camera camera;
	void keyPressEvent(QKeyEvent *event);
	void keyMove();
private slots:
	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void keyReleaseReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

