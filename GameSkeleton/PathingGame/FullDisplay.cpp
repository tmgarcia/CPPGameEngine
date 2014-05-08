#include "FullDisplay.h"
#include <Qt\qmenu.h>
#include <Qt\qmenubar.h>
#include <Qt\qfiledialog.h>
#include <Qt\qtoolbar.h>
#include <Qt\qlabel.h>

#include "DebugSlider.h"
#include "GeneralGLWindow.h"

GLuint WINDOW_WIDTH = 1400;
GLuint WINDOW_HEIGHT= 900;

FullDisplay::FullDisplay()
{
	mapIsLoaded = false;
	testCharacterLoaded = false;
	levelIsLoaded = false;
	this->showMaximized();

	QMenu* fileMenu = menuBar()->addMenu("File");
	QAction* action;

	fileMenu->addAction(action = new QAction("Load Level File", this));
	//action->setShortcut(QKeySequence::Open);
	connect(action, SIGNAL(triggered()), this, SLOT(loadLevel()));

	fileMenu->addAction(action = new QAction("Path Test Character", this));
	connect(action, SIGNAL(triggered()), this, SLOT(startCharacter()));

	QToolBar* debugToolBar = addToolBar("Tools");
	//debugToolBar->setAllowedAreas(Qt::TopToolBarArea);
	debugToolBar->setAllowedAreas(Qt::AllToolBarAreas);

	debugToolBar->addAction(action = new QAction(QIcon("../Resources/Icons/play-icon.png"),"Play",this));
	connect(action, SIGNAL(triggered()), this, SLOT(startCharacter()));

	debugToolBar->addAction(action = new QAction(QIcon("../Resources/Icons/camera-to-player-icon.png"),"Toggle Camera/Player view",this));
	connect(action, SIGNAL(triggered()), &gameWindow, SLOT(toggleCameraPlayerView()));

	debugToolBar->addAction(action = new QAction(QIcon("../Resources/Icons/path-nodes-icon.png"),"Highlight Path Nodes",this));
	connect(action, SIGNAL(triggered()), &gameWindow, SLOT(togglePathNodes()));

	debugToolBar->addAction(action = new QAction(QIcon("../Resources/Icons/path-connections-icon.png"),"Highlight Path Connections",this));
	connect(action, SIGNAL(triggered()), &gameWindow, SLOT(togglePathConnections()));

	debugToolBar->addAction(action = new QAction(QIcon("../Resources/Icons/all-nodes-icon.png"),"Highlight All Nodes",this));
	connect(action, SIGNAL(triggered()), &gameWindow, SLOT(toggleAllNodes()));
	
	DebugSlider* speedSlider = new DebugSlider(0.01f, 5.0f, true);
	speedSlider->setValue(0.5f);
	speedSlider->setFixedWidth(300);
	QLabel* speedLabel = new QLabel("Speed:");

	debugToolBar->addWidget(speedLabel);
	debugToolBar->addWidget(speedSlider);
	speedSlider->setValue(0.5f);
	//QObject::connect(ambientR, SIGNAL(valueChanged(float)), display, SLOT(setAmbientColorRed(float)));
	connect(speedSlider, SIGNAL(valueChanged(float)), &gameWindow, SLOT(setCharacterSpeed(float)));

	GeneralGLWindow::getInstance();
	GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	setCentralWidget(&GeneralGLWindow::getInstance());
	GeneralGLWindow::getInstance().show();

	gameWindow.windowWidth = WINDOW_WIDTH;
	gameWindow.windowHeight = WINDOW_HEIGHT;
	gameWindow.setup();

	this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	this->move(300, 0);
}

void FullDisplay::highlightPathNodes()
{
	gameWindow.togglePathNodes();
}

void FullDisplay::highlightPathConnections()
{
	gameWindow.togglePathConnections();
}

void FullDisplay::highlightAllNodes()
{
	gameWindow.toggleAllNodes();
}

void FullDisplay::cameraToPlayerView()
{
	gameWindow.toggleCameraPlayerView();
}

void FullDisplay::loadLevel()
{
	QString targetLevel = QFileDialog::getOpenFileName(this, "Open Level", "../Resources/GameLevels", "Level Files (*.tlvl)");
	if(targetLevel == "")
	{
		return;
	}
	else
	{
		gameWindow.loadLevel(targetLevel);
		levelIsLoaded = true;
	}
}

void FullDisplay::startCharacter()
{
	if(levelIsLoaded && !testCharacterLoaded)
	{
		gameWindow.loadTestCharacter();
	}
}

void FullDisplay::keyPressEvent(QKeyEvent *event)
{
	GeneralGLWindow::getInstance().keyPressEvent(event);
}

FullDisplay::~FullDisplay(void)
{
}
