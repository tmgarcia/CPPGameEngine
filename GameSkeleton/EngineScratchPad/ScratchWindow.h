#pragma once

#include <Qt\qapplication.h>
#include "GeneralGLWindow.h"

const GLuint WINDOW_WIDTH = 1000;
const GLuint WINDOW_HEIGHT = 800;

class ScratchWindow : public QObject
{
	Q_OBJECT

	QTimer updateTimer;

public:
	ScratchWindow()
	{
		GeneralGLWindow::getInstance();
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));
		connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
		updateTimer.setInterval(1);
		updateTimer.start(0);
		GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		GeneralGLWindow::getInstance().show();
		setup();
	}
	~ScratchWindow()
	{

	}
protected:
	void setup();
	Camera camera;
	void loadLevel();

private slots:
	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

