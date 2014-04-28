#pragma once

#include <Qt\qapplication.h>
#include <Qt\qtimer.h>
#include "AStarData\EditorNodeContainer.h"
#include "AStarData\EditorNode.h"
#include "Character.h"
#include <Qt\qtimer.h>

class GameWindow : public QObject
{
	Q_OBJECT

	QTimer timer;

public:
	GameWindow();
	~GameWindow();
	void loadLevelMap(QString filename);
	void setup();
	void GameWindow::loadLevel(QString filename);
	GLuint windowHeight;
	GLuint windowWidth;
	void loadTestCharacter();

private:
	void setupCharacterPath(EditorNode* start);
	void setupLevelGeometry();
	void setupCharacterGeometry();
	void updateLevelProjectionView();
	void setupDebugShapes();
	bool levelLoaded;
	bool testCharacterLoaded;
	EditorNode* currentCharacterGoal;
	Camera camera;
	EditorNodeContainer nodes;
	Character character;
	int frames;

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);

private slots:
	void update();
};

