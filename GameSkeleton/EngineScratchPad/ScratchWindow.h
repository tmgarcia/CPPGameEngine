#pragma once

#include <Qt\qapplication.h>
#include <Qt\qboxlayout.h>
#include <Qt\qmainwindow.h>
#include "GeneralGLWindow.h"
#include "DebugMenu\DebugMenu.h"
#include "MathTools\TransformationMatrixMaker.h"
#include "MathTools\Random.h"
#include "GraphicObjects\BlinkingEyeGroup.h"
#include <Qt\qdockwidget.h>
#include "RendererHelper.h"

#include <iostream>

using std::cout;
using std::endl;

const GLuint WINDOW_WIDTH = 1300;
const GLuint WINDOW_HEIGHT = 900;



class ScratchWindow : public QMainWindow
{
	Q_OBJECT

	QTimer updateTimer;

public:
	ScratchWindow()
	{

		this->show();
		//this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);

		cameraFrozen = false;
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

		setup();

		this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
		
	}
	~ScratchWindow()
	{

	}

protected:
	bool cameraFrozen;
	DebugMenu* dMenu;
	RendererHelper* renderHelper;
	void setup();
	void setupGeometry();
	void setupGameObjects();
	void setupTextures();
	Camera camera;
	void keyPressEvent(QKeyEvent *event);
	void keyMove();
	void updateShaderInfo();
	uchar* createNoiseTexture(float frequency);
private:
	struct Tree
	{
		void things();
		bool empty;
		GameObject* treeObject;
		GameObject* creepObject;
		void resetTransforms(mat4 rotation, mat4 worldToProjectionmatrix)
		{
			treeObject->rotationMatrix = rotation*glm::rotate(90.0f, vec3(1,0,0));
			treeObject->modelToWorldMatrix = treeObject->translationMatrix * treeObject->rotationMatrix;
			treeObject->fullTransformMatrix = worldToProjectionmatrix * treeObject->modelToWorldMatrix; 
			creepObject->rotationMatrix = rotation*glm::rotate(90.0f, vec3(1,0,0));
			creepObject->modelToWorldMatrix = treeObject->translationMatrix * creepObject->rotationMatrix;
			creepObject->fullTransformMatrix = worldToProjectionmatrix * treeObject->modelToWorldMatrix; 
		}
	};
	QList<Tree*> trees;
	void setupTreeTextures(Tree* tree, bool creeping);
private slots:
	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void keyReleaseReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

