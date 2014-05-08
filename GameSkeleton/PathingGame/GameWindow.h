#pragma once

#include <Qt\qapplication.h>
#include <Qt\qtimer.h>
#include "AStarData\Nodes\DebugNodeContainer.h"
#include "AStarData\Nodes\DebugNode.h"
#include "Entities\NonPlayerCharacter.h"
#include "GameObjects\GameLevel.h"
#include <Qt\qtimer.h>
#include "GameObjects\Flag.h"

class GameWindow : public QObject
{
	Q_OBJECT

	QTimer timer;

public:
	GameWindow();
	~GameWindow();
	void setup();
	void GameWindow::loadLevel(QString filename);
	GLuint windowHeight;
	GLuint windowWidth;
	void loadTestCharacter();

private:
	void setupCharacterPath(DebugNode* start);
	void setupLevelGeometry();
	void setupCharacterGeometry();
	void updateLevelProjectionView();
	void setupDebugShapes();
	void resetNodeHighlighting();
	DebugNode* getNewFlagLocation();
	bool cameraFrozen;
	bool levelLoaded;
	bool testCharacterLoaded;
	bool pathHighlighted;
	bool pathConnectionsHighlighted;
	bool allNodesHighlighted;
	bool cameraFollowingPlayer;
	DebugNode* currentCharacterGoal;
	Camera camera;
	Flag flag;
	NonPlayerCharacter character;
	int frames;

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
	void togglePathNodes();
	void togglePathConnections();
	void toggleAllNodes();
	void toggleCameraPlayerView();
	void setCharacterSpeed(float s);

private slots:
	void update();
};

