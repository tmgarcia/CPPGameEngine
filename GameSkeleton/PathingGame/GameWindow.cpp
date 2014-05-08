#include "GameWindow.h"
#include "BinReader.h"
#include "DebugShapes.h"
#include "AStarData\PathCreator.h"
#include "AStarData\Path.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

vec3 nonPathNodesColor= vec3(1,0,0);
vec3 pathNodesColor= vec3(0,0.5f,1);
vec3 pathConnectionsColor = vec3(0,0.5f,1);

DebugNode* baseNode;

void GameWindow::setup()
{
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	DebugNodeContainer::getInstance();
	cameraFrozen = false;
	levelLoaded = false;
	testCharacterLoaded = false;
	pathConnectionsHighlighted = false;
	pathHighlighted = false;
	allNodesHighlighted = false;
	cameraFollowingPlayer = false;
	frames = 0;
	timer.setInterval(1);
	timer.start(0);
}

void GameWindow::togglePathNodes()
{
	if(testCharacterLoaded)
	{
		if(pathHighlighted)
		{
			character.hidePathNodes();
			pathHighlighted = false;
			if(allNodesHighlighted)
			{
				DebugNodeContainer::getInstance().highlightAllNodes(nonPathNodesColor);
			}
		}
		else
		{
			character.highlightPathNodes(pathNodesColor);
			pathHighlighted = true;
		}
	}
}
void GameWindow::togglePathConnections()
{
	if(testCharacterLoaded)
	{
		if(pathConnectionsHighlighted)
		{
			character.hidePathConnections();
			pathConnectionsHighlighted = false;
		}
		else
		{
			character.highlightPathConnections(pathConnectionsColor);
			pathConnectionsHighlighted = true;
		}
	}
}
void GameWindow::toggleAllNodes()
{
	if(allNodesHighlighted)
	{
		DebugNodeContainer::getInstance().hideAllNodes();
		allNodesHighlighted = false;
		if(pathHighlighted)
		{
			character.highlightPathNodes(pathNodesColor);
		}
	}
	else
	{
		DebugNodeContainer::getInstance().highlightAllNodes(nonPathNodesColor);
		if(pathHighlighted)
		{
			character.highlightPathNodes(pathNodesColor);
		}
		allNodesHighlighted = true;
	}
}
void GameWindow::toggleCameraPlayerView()
{
	if(testCharacterLoaded)
	{
		if(cameraFollowingPlayer)
		{
			camera.resetPosition();
			character.setVisible(true);
			cameraFollowingPlayer = false;
			cameraFrozen = false;
		}
		else
		{
			camera.setPosition(character.getPosition());
			camera.setViewDirection(vec3(vec4(0.0f, 0.0f, -1.0f, 0.1f)*character.getRotation()));
			character.setVisible(false);
			cameraFollowingPlayer = true;
			cameraFrozen = true;
		}
	}
}

void GameWindow::setCharacterSpeed(float s)
{
	character.setSpeed(s);
}

void GameWindow::loadTestCharacter()
{
	if(!testCharacterLoaded)
	{
		QString fileName = "../Resources/Models/fish.obj";
		character = NonPlayerCharacter(fileName, GameLevel::getInstance().baseNode, worldToProjectionMatrix);
		testCharacterLoaded = true;

		DebugNode* flagNode = getNewFlagLocation();
		//flag = Flag("../Resources/Models/chair1.bin", flagNode, worldToProjectionMatrix);

		character.startPathing(flagNode);
	}
}

DebugNode* GameWindow::getNewFlagLocation()
{
	bool foundLocationForFlag = false;
	DebugNode* flagNode = nullptr;
	while(!foundLocationForFlag)
	{
		flagNode = DebugNodeContainer::getInstance().getRandomNode();
		if(flagNode != character.getBaseNode() && flagNode != character.getCurrentNode())
		{
			cout << "base " << GameLevel::getInstance().baseNode->position.x << "," << GameLevel::getInstance().baseNode->position.y << "," << GameLevel::getInstance().baseNode->position.z<<endl;
			cout << "flag " << flagNode->position.x << "," << flagNode->position.y << "," << flagNode->position.z<<endl;
			foundLocationForFlag = true;
		}
	}
	return flagNode;
}

void GameWindow::loadLevel(QString filename)
{
	if(levelLoaded)
	{
		GameLevel::getInstance().setVisible(false);
	}

	GameLevel::getInstance();
	GameLevel::getInstance().update(camera.getPosition(), worldToProjectionMatrix);
	GameLevel::getInstance().loadLevel(filename);
	levelLoaded = true;
	camera.resetPosition();
	DebugNodeContainer::getInstance().hideAllNodes();
}

void GameWindow::updateLevelProjectionView()
{
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)windowWidth) / windowHeight, 0.1f, 100.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::getInstance();
	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	if(levelLoaded)
	{
		GameLevel::getInstance().update(camera.getPosition(), worldToProjectionMatrix);
	}

	if(testCharacterLoaded)
	{
		character.updateFullTransform(worldToProjectionMatrix);
		//flag.update(worldToProjectionMatrix);
	}
}

void GameWindow::setupDebugShapes()
{

}

void GameWindow::keyPressReaction(QKeyEvent* e)
{
	switch(e->key())
	{
	case Qt::Key::Key_W:
		if(!cameraFrozen)
			camera.moveForward();
		break;
	case Qt::Key::Key_S:
		if(!cameraFrozen)
			camera.moveBackward();
		break;
	case Qt::Key::Key_A:
		if(!cameraFrozen)
			camera.strafeLeft();
		break;
	case Qt::Key::Key_D:
		if(!cameraFrozen)
			camera.strafeRight();
		break;
	case Qt::Key::Key_R:
		if(!cameraFrozen)
			camera.moveUp();
		break;
	case Qt::Key::Key_F:
		if(!cameraFrozen)
			camera.moveDown();
		break;
	case Qt::Key::Key_0:
		cameraFrozen = !cameraFrozen;
		break;
	}
	updateLevelProjectionView();

	GeneralGLWindow::getInstance().repaint();
}

void GameWindow::mouseMoveReaction(QMouseEvent* e)
{
	if(!cameraFrozen)
	{
		camera.mouseUpdate(glm::vec2(e->x(), e->y()));
		updateLevelProjectionView();
		GeneralGLWindow::getInstance().repaint();
	}
}

void GameWindow::update()
{
	frames++;
	//GeneralGLWindow::getInstance().mouse
	if(testCharacterLoaded)
	{
		if(frames%100==0)
			character.updatePathPosition();
		if(cameraFollowingPlayer)
		{
			camera.setPosition(vec3(character.getPosition().x, 0.1f, character.getPosition().z));
			camera.setViewDirection(vec3(vec4(0.0f, 0.0f, -1.0f, 1.0f)*character.getRotation()));
		}

		if(character.hasFlag && !character.isCurrentlyPathing())
		{
			cout << "character has flag" << endl;
			character.startPathing(character.getBaseNode());
			resetNodeHighlighting();
		}
		else if(!character.hasFlag && (!character.isCurrentlyPathing() || frames%1000 == 0))
		{
			cout << "character returned flag" << endl;
			DebugNode* flagNode = getNewFlagLocation();
			flag.setAtNode(flagNode);
			character.setNewPathGoal(flagNode);
			resetNodeHighlighting();
		}
	}
	updateLevelProjectionView();
	GeneralGLWindow::getInstance().repaint();
}
void GameWindow::resetNodeHighlighting()
{
	if(pathHighlighted && allNodesHighlighted)
	{
		DebugNodeContainer::getInstance().highlightAllNodes(nonPathNodesColor);
		character.highlightPathNodes(pathNodesColor);
	}
}
GameWindow::GameWindow()
{

}


GameWindow::~GameWindow(void)
{
}
