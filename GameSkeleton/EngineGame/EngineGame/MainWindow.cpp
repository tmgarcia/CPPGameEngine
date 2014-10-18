#include "MainWindow.h"
#include "Assets\Geometry.h"
#include "Assets\Material.h"
#include "Assets\Presets\Materials\PassThroughMat.h"
#include "GameObjects\Entity.h"
#include "GameObjects\Components\RendererComponent.h"
#include "GameObjects\Components\PhysicsComponent.h"
#include "ControllerComponent.h"
#include "ConsolePrinter.h"
#include "Janitor.h"

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;
Entity* cubeEntity;

void MainWindow::setup()
{
	ConsolePrinter::getInstance();

	camera.setPosition(vec3(0,5,5));
	camera.setViewDirection(vec3(0,-1,-1));

	GeneralGLWindow::getInstance().WINDOW_HEIGHT = WINDOW_HEIGHT;
	GeneralGLWindow::getInstance().WINDOW_WIDTH = WINDOW_WIDTH;

	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	Geometry* cube = Geometry::Cube();
	Material* mat = new PassThroughMat();
	RendererComponent* cubeRender = new RendererComponent();
	PhysicsComponent* physics = new PhysicsComponent();
	physics->damping = 0.001f;
	ControllerComponent* control = new ControllerComponent();

	cubeEntity = new Entity();
	cubeEntity->update(worldToProjectionMatrix);

	cubeEntity->addComponent(physics);
	cubeEntity->addComponent(control);
	cubeEntity->addComponent(cubeRender);

	cubeRender->setData(cube, true, true, PRIORITY_1, mat);
	//dMenu->addFloatSlider("tab", &(control->speed), 1, 1000, "speed");
	//dMenu->addDisplay("tab", &(fps), "FPS");
}
void MainWindow::update()
{
	GameClock::getInstance().newFrame();
	//ConsolePrinter::getInstance().print(GameClock::getInstance().dt(), "dt: ");


	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	KeyInput::getInstance().update();

	cubeEntity->update(worldToProjectionMatrix);

	GeneralGLWindow::getInstance().repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	keyPressReaction(event);
}

void MainWindow::cleanup()
{
	updateTimer.stop();
	cubeEntity->cleanup();
	delete cubeEntity;
	dMenu->cleanup();
	delete dMenu;
	Janitor::cleanupEngine();
}

void MainWindow::keyPressReaction(QKeyEvent* e)
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
	//case Qt::Key::Key_0:
	//	cameraFrozen = !cameraFrozen;
	//	break;
	}
	update();
}
void MainWindow::keyReleaseReaction(QKeyEvent* e)
{
	//ConsolePrinter::getInstance().print("key release reaction");
	//switch(e->key())
	//{
	//case Qt::Key::Key_W:
	//	wDown = false;
	//	break;
	//case Qt::Key::Key_S:
	//	sDown = false;
	//	break;
	//case Qt::Key::Key_A:
	//	aDown = false;
	//	break;
	//case Qt::Key::Key_D:
	//	dDown = false;
	//	break;
	////case Qt::Key::Key_R:
	////	rDown = false;
	////	break;
	////case Qt::Key::Key_F:
	////	fDown = false;
	////	break;
	//}
	//update();
}
void MainWindow::keyMove()
{
	//ConsolePrinter::getInstance().print("key move");
	//if(wDown)
	//{
	//	camera.moveForward();
	//}
	//if(sDown)
	//{
	//	camera.moveBackward();
	//}
	//if(aDown)
	//{
	//	camera.strafeLeft();
	//}
	//if(dDown)
	//{
	//	camera.strafeRight();
	//}
	//if(rDown)
	//{
	//	camera.moveUp();
	//}
	//if(fDown)
	//{
	//	camera.moveDown();
	//}
}
void MainWindow::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), 0));
	update();
}