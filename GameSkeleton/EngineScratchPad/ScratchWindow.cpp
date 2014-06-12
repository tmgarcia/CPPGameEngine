#include "ScratchWindow.h"
#include "GameObjects\GameLevel.h"

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

void ScratchWindow::setup()
{
	loadLevel();
}

void ScratchWindow::loadLevel()
{
	QString fileName = "../Resources/GameLevels/dataMaze.tlvl";
	GameLevel::getInstance();
	//GameLevel::getInstance().update(camera.getPosition, worldToProjectionMatrix);
	GameLevel::getInstance().loadLevel(fileName);
	camera.resetPosition();
	DebugNodeContainer::getInstance().hideAllNodes();
}

void ScratchWindow::update()
{
	GeneralGLWindow::getInstance().repaint();
}

void ScratchWindow::keyPressReaction(QKeyEvent* e)
{
	switch(e->key())
	{
	case Qt::Key::Key_W:
		camera.moveForward();
		break;
	case Qt::Key::Key_S:
		camera.moveBackward();
		break;
	case Qt::Key::Key_A:
		camera.strafeLeft();
		break;
	case Qt::Key::Key_D:
		camera.strafeRight();
		break;
	case Qt::Key::Key_R:
		camera.moveUp();
		break;
	case Qt::Key::Key_F:
		camera.moveDown();
		break;
	}
	//updateShaderUniforms();

	GeneralGLWindow::getInstance().repaint();
}

void ScratchWindow::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	//updateShaderUniforms();
	GeneralGLWindow::getInstance().repaint();
}