#include "MainWindow.h"
#include "Assets\Geometry.h"
#include "Assets\Material.h"
#include "Assets\Presets\Materials\PassThroughMat.h"
#include "Assets\Presets\Materials\LightingAndTextureMat.h"
#include "Assets\Presets\Materials\OffsetTextureMat.h"
#include "GameObjects\Entity.h"
#include "GameObjects\Components\RendererComponent.h"
#include "GameObjects\Components\HoloRenderercomponent.h"
#include "GameObjects\Components\PhysicsComponent.h"
#include "GameObjects\Components\ClickBoxComponent.h"
#include "CellStateComponent.h"
#include "ControllerComponent.h"
#include "ConsolePrinter.h"
#include "Janitor.h"
#include "SceneManager.h"

bool wDown=false;
bool sDown=false;
bool aDown=false;
bool dDown=false;
bool rDown=false;
bool fDown=false;

//Entity* testEntity;
void MainWindow::SetupGame()
{
	ConsolePrinter::getInstance();

	GeneralGLWindow::getInstance().WINDOW_HEIGHT = WINDOW_HEIGHT;
	GeneralGLWindow::getInstance().WINDOW_WIDTH = WINDOW_WIDTH;

	SceneManager::getInstance();
	SceneManager::getInstance().camera.setPosition(vec3(0,10,1));
	SceneManager::getInstance().camera.setViewDirection(vec3(0,-6,-1));
	SceneManager::getInstance().WINDOW_HEIGHT = WINDOW_HEIGHT;
	SceneManager::getInstance().WINDOW_WIDTH = WINDOW_WIDTH;
	SceneManager::getInstance().LIGHT_POSITION = vec3(0,10,0);
	SceneManager::getInstance().LIGHT_AMBIENTCOLOR = vec3(0.8f,0.8f,0.8f);
	SceneManager::getInstance().LIGHT_DIFFUSIONINTENSITY = 1.0f;
	SceneManager::getInstance().LIGHT_SPECULARCOLOR = vec4(1,1,1,1);
	SceneManager::getInstance().LIGHT_SPECULAREXPONENT = 10;
	SceneManager::getInstance().update();

	grid.setupGrid();


	//Geometry* cube = new Geometry("Assets/Models/CellCover.bin");
	////RendererComponent* cubeRender = new RendererComponent();
	//HoloRenderercomponent* holoRenderer = new HoloRenderercomponent();
	//ControllerComponent* control = new ControllerComponent();

	//testEntity = new Entity();
	//testEntity->transform.position = vec3(0,0.501f,0);
	//testEntity->update();

	//testEntity->addComponent(control);
	//testEntity->addComponent(holoRenderer);
	////holoRenderer->useAlpha = false;
	////holoRenderer->holoAlpha = false;
	//holoRenderer->holoDiffuse = false;
	//holoRenderer->holoIncrement = 0.001f;
	//holoRenderer->diffuseMap = GeneralGLWindow::getInstance().addTexture("Assets/Textures/scrollingCodeDiffuse.png");
	//holoRenderer->alphaMap = GeneralGLWindow::getInstance().addTexture("Assets/Textures/scrollingCodeAlpha.png");
	//holoRenderer->setData(cube, true, true, PRIORITY_1);
	

	//dMenu->addFloatSlider("tab", &(SceneManager::getInstance().LIGHT_SPECULAREXPONENT), 0, 5, "Spec exp");
	//dMenu->addFloatSlider("tab", &(SceneManager::getInstance().LIGHT_DIFFUSIONINTENSITY), 0, 5, "diffuse");
	//dMenu->addVec3Slider("tab", &(SceneManager::getInstance().camera.viewDirection), -5,5,-5,5,-5,5,"Camera");
}
int frame = 0;
void MainWindow::update()
{
	frame++;
	GameClock::getInstance().newFrame();
	//ConsolePrinter::getInstance().print(GameClock::getInstance().dt(), "dt: ");

	KeyInput::getInstance().update();

	SceneManager::getInstance().update();

	//mat->currentOffset.x += 0.01f;
	//testEntity->update();

	//cubeEntity->update();
	keyMove();
	//if(frame == 50)
	//{
	//	wDown=false;
	//	sDown=false;
	//	aDown=false;
	//	dDown=false;
	//	rDown=false;
	//	fDown=false;
	//}
	
	grid.update();

	GeneralGLWindow::getInstance().repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	keyPressReaction(event);
}

void MainWindow::cleanup()
{
	updateTimer.stop();
	//dMenu->cleanup();
	//delete dMenu;
	Janitor::cleanupEngine();
}

void MainWindow::keyPressReaction(QKeyEvent* e)
{
	//switch(e->key())
	//{
	//case Qt::Key::Key_W:
	//	SceneManager::getInstance().camera.moveForward();
	if(!e->isAutoRepeat())
	{
		e->accept();
		switch(e->key())
		{
		case Qt::Key::Key_W:
			ConsolePrinter::getInstance().print("PRESS: W");
			wDown = true;
			sDown = false;
			break;
		case Qt::Key::Key_S:
			ConsolePrinter::getInstance().print("PRESS: S");
			sDown = true;
			wDown = false;
			break;
		case Qt::Key::Key_A:
			ConsolePrinter::getInstance().print("PRESS: A");
			aDown = true;
			dDown = false;
			break;
		case Qt::Key::Key_D:
			ConsolePrinter::getInstance().print("PRESS: D");
			dDown = true;
			aDown = false;
			break;
		case Qt::Key::Key_R:
			ConsolePrinter::getInstance().print("PRESS: R");
			rDown = true;
			fDown = false;
			break;
		case Qt::Key::Key_F:
			ConsolePrinter::getInstance().print("PRESS: F");
			fDown = true;
			rDown = false;
			break;
		case Qt::Key::Key_0:
			cameraFrozen = !cameraFrozen;
			break;
		}
		update();
	}
}
void MainWindow::keyReleaseReaction(QKeyEvent* e)
{
	//ConsolePrinter::getInstance().print("key release reaction");
	
	if(!e->isAutoRepeat())
	{
		e->accept();
		switch(e->key())
		{
		case Qt::Key::Key_W:
			ConsolePrinter::getInstance().print("RELEASE: W");
			wDown = false;
			break;
		case Qt::Key::Key_S:
			ConsolePrinter::getInstance().print("RELEASE: S");
			sDown = false;
			break;
		case Qt::Key::Key_A:
			ConsolePrinter::getInstance().print("RELEASE: A");
			aDown = false;
			break;
		case Qt::Key::Key_D:
			ConsolePrinter::getInstance().print("RELEASE: D");
			dDown = false;
			break;
		case Qt::Key::Key_R:
			ConsolePrinter::getInstance().print("RELEASE: R");
			rDown = false;
			break;
		case Qt::Key::Key_F:
			ConsolePrinter::getInstance().print("RELEASE: F");
			fDown = false;
			break;
		}
		update();
	}
}
void MainWindow::keyMove()
{
	if(wDown && sDown)
	{
		wDown = false;
		sDown = false;
	}
	if(aDown && dDown)
	{
		aDown = false;
		dDown = false;
	}
	if(rDown && fDown)
	{
		rDown = false;
		fDown = false;
	}
	//ConsolePrinter::getInstance().print("key move");
	if(wDown)
	{
		SceneManager::getInstance().camera.moveForward();
	}
	if(sDown)
	{
		SceneManager::getInstance().camera.moveBackward();
	}
	if(aDown)
	{
		SceneManager::getInstance().camera.strafeLeft();
	}
	if(dDown)
	{
		SceneManager::getInstance().camera.strafeRight();
	}
	if(rDown)
	{
		SceneManager::getInstance().camera.moveUp();
	}
	if(fDown)
	{
		SceneManager::getInstance().camera.moveDown();
	}
}
void MainWindow::mouseMoveReaction(QMouseEvent* e)
{
	if(cameraFrozen)
	{
		SceneManager::getInstance().camera.mouseUpdate(glm::vec2(e->x(), e->y()));
		update();
	}
}


