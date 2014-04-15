#include "FullDisplay.h"

#include <QtGui\QHboxlayout>
#include <QtGui\QVboxlayout>
#include <Qt\qmenu.h>
#include <Qt\qmenubar.h>
#include <Qt\qfiledialog.h>

#include "GeneralGLWindow.h"

GLuint WINDOW_WIDTH = 1400;
GLuint WINDOW_HEIGHT= 900;

FullDisplay::FullDisplay()
{
	this->showMaximized();
	QMenu* fileMenu = menuBar()->addMenu("File");
	QAction* action;

	fileMenu->addAction(action = new QAction("Load Object File", this));
	//action->setShortcut(QKeySequence::Open);
	connect(action, SIGNAL(triggered()), this, SLOT(loadObj()));

	fileMenu->addAction(action = new QAction("Load Level File", this));
	//action->setShortcut(QKeySequence::Open);
	connect(action, SIGNAL(triggered()), this, SLOT(loadLevel()));

	fileMenu->addAction(action = new QAction("Save Current Level", this));
	action->setShortcuts(QKeySequence::Save);
	connect(action, SIGNAL(triggered()), this, SLOT(saveLevel()));

	fileMenu->addAction(action = new QAction("Save Current Level as...", this));
	action->setShortcuts(QKeySequence::Save);
	connect(action, SIGNAL(triggered()), this, SLOT(saveLevelAs()));

	GeneralGLWindow::getInstance();
	GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	setCentralWidget(&GeneralGLWindow::getInstance());
	GeneralGLWindow::getInstance().show();

	levelDisplay.windowWidth = WINDOW_WIDTH;
	levelDisplay.windowHeight = WINDOW_HEIGHT;
	levelDisplay.setup();
	levelDisplay.loadLevelMap("../Resources/Models/baseLevel.obj");

	this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	//this->move(500, 0);

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
		levelDisplay.loadLevelMap(targetObj);
		levelIsLoaded = true;
	}

}

void FullDisplay::loadLevel()
{
	QString targetObj = QFileDialog::getOpenFileName(this, "Open Level", ".", "Level Files (*.tlvl)");

}

void FullDisplay::saveLevel()
{
	if(currentSaved)
	{
		
	}
	else
	{
		saveLevelAs();
	}
}
void FullDisplay::saveLevelAs()
{
	QString saveName = QFileDialog::getSaveFileName(this, "Save Level", ".", "Level Files (*.tlvl)");
	currentSaved = true;
}

void FullDisplay::keyPressEvent(QKeyEvent *event)
{
	GeneralGLWindow::getInstance().keyPressEvent(event);
}

FullDisplay::~FullDisplay()
{

}
