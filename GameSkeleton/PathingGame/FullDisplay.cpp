#include "FullDisplay.h"
#include <Qt\qmenu.h>
#include <Qt\qmenubar.h>
#include <Qt\qfiledialog.h>

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

	fileMenu->addAction(action = new QAction("Load Map", this));
	connect(action, SIGNAL(triggered()), this, SLOT(loadObj()));

	fileMenu->addAction(action = new QAction("Load Level File", this));
	//action->setShortcut(QKeySequence::Open);
	connect(action, SIGNAL(triggered()), this, SLOT(loadLevel()));

	fileMenu->addAction(action = new QAction("Path Test Character", this));
	connect(action, SIGNAL(triggered()), this, SLOT(startCharacter()));

	GeneralGLWindow::getInstance();
	GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	setCentralWidget(&GeneralGLWindow::getInstance());
	GeneralGLWindow::getInstance().show();

	gameWindow.windowWidth = WINDOW_WIDTH;
	gameWindow.windowHeight = WINDOW_HEIGHT;
	gameWindow.setup();

	this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void FullDisplay::loadLevel()
{
	QString targetLevel = QFileDialog::getOpenFileName(this, "Open Level", "../Resources/GameLevels", "Level Files (*.tlvl)");
	gameWindow.loadLevel(targetLevel);
	levelIsLoaded = true;
}

void FullDisplay::loadObj()
{
	QString targetObj = QFileDialog::getOpenFileName(this, "Open OBJ", "../Resources/Models", "Object Files (*.obj)");
	if(targetObj == "")
	{
		return;
	}
	else
	{
		gameWindow.loadLevelMap(targetObj);
		mapIsLoaded = true;
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
