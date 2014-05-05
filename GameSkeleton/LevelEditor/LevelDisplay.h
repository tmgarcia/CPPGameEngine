#pragma once

#include <Qt\qapplication.h>
#include <Qt\qtimer.h>
#include "GeneralGLWindow.h"
#include "NodeContainer.h"

//const GLuint WINDOW_WIDTH = 900;
//const GLuint WINDOW_HEIGHT = 900;

class LevelDisplay : public QObject
{
	Q_OBJECT

//	QTimer updateTimer;

public:
	LevelDisplay();
	~LevelDisplay(void);
	void loadLevelMap(QString fileName);
	void saveLevel(QString fileName);
	void loadLevel(QString fileName);
	void setup();
	GLuint windowHeight;
	GLuint windowWidth;

private:
	void setupLevelGeometry();
	void updateLevelProjectionView();
	void setupDebugShapes();
	void setupForNewLevel();
	bool aNodeIsSelected;
	bool levelLoaded;
	bool cameraFrozen;
	Camera camera;
	NodeContainer nodes;

//private slots:
//	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
	void mouseClickReaction(QMouseEvent* e);
};

