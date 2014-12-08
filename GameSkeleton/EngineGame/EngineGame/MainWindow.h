#pragma once

#include <Qt\qapplication.h>
#include <Qt\qboxlayout.h>
#include <Qt\qmainwindow.h>
#include <Qt\qgroupbox.h>
#include <Qt\qradiobutton.h>
#include "GeneralGLWindow.h"
#include "Time\GameClock.h"
#include "DebugMenu\DebugMenu.h"
#include <Qt\qdockwidget.h>
#include "Input\KeyInput.h"
#include "KeyMap.h"
#include "InputActions.h"
#include "GridCellContainer.h"

#include <Windows.h>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

const GLuint WINDOW_WIDTH = 1300;
const GLuint WINDOW_HEIGHT = 900;



class MainWindow : public QMainWindow
{
	Q_OBJECT

	QTimer updateTimer;
	QGroupBox* setupMenu;
public:
	MainWindow()
	{
		createSetupMenu();
		setCentralWidget(setupMenu);
		//prepareForGame();
	}

	void createSetupMenu()
	{
		setupMenu = new QGroupBox("Setup New Game", this);
		QVBoxLayout* mainLayout = new QVBoxLayout();
		setupMenu->setLayout(mainLayout);
		QLabel* setupLabel = new QLabel("Choose a Difficulty");
		mainLayout->addWidget(setupLabel);
		QHBoxLayout* optionsLayout = new QHBoxLayout();
		QVBoxLayout* option1Layout = new QVBoxLayout();
		QLabel* option1Title = new QLabel("Easy");
		QLabel* option1MineCount = new QLabel("10 Mines");
		QLabel* option1GridSize = new QLabel("9 x 9 Grid");
		QRadioButton* option1Button = new QRadioButton();
		option1Layout->addWidget(option1Title);
		option1Layout->addWidget(option1MineCount);
		option1Layout->addWidget(option1GridSize);
		option1Layout->addWidget(option1Button);
		optionsLayout->addLayout(option1Layout);
		QVBoxLayout* option2Layout = new QVBoxLayout();
		QLabel* option2Title = new QLabel("Intermediate");
		QLabel* option2MineCount = new QLabel("40 Mines");
		QLabel* option2GridSize = new QLabel("16 x 16 Grid");
		QRadioButton* option2Button = new QRadioButton();
		option2Layout->addWidget(option2Title);
		option2Layout->addWidget(option2MineCount);
		option2Layout->addWidget(option2GridSize);
		option2Layout->addWidget(option2Button);
		optionsLayout->addLayout(option2Layout);
		QVBoxLayout* option3Layout = new QVBoxLayout();
		QLabel* option3Title = new QLabel("Advanced");
		QLabel* option3MineCount = new QLabel("99 Mines");
		QLabel* option3GridSize = new QLabel("16 x 30 Grid");
		QRadioButton* option3Button = new QRadioButton();
		option3Layout->addWidget(option3Title);
		option3Layout->addWidget(option3MineCount);
		option3Layout->addWidget(option3GridSize);
		option3Layout->addWidget(option3Button);
		optionsLayout->addLayout(option3Layout);
		mainLayout->addLayout(optionsLayout);
		QPushButton* startButton = new QPushButton("Start Game");
		mainLayout->addWidget(startButton);
	}

	void prepareForGame()
	{
		cameraFrozen = false;
		this->show();
		connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
		updateTimer.setInterval(1);
		updateTimer.start(0);

		/*QDockWidget* menuDock = new QDockWidget("Debug", this);
		menuDock->setAllowedAreas(Qt::TopDockWidgetArea);
		menuDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
		dMenu = new DebugMenu();

		dMenu->setParent(menuDock);
		menuDock->setWidget(dMenu);
		addDockWidget(Qt::TopDockWidgetArea, menuDock);*/
		
		GeneralGLWindow::getInstance();
		setCentralWidget(&GeneralGLWindow::getInstance());
		GeneralGLWindow::getInstance().show();

		GeneralGLWindow::getInstance();

		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyReleased(QKeyEvent*)), this, SLOT(keyReleaseReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));

		GameClock::getInstance();

		KeyMap* keyMap = new KeyMap();
		KeyInput::getInstance();
		KeyInput::getInstance().initialize(keyMap, InputActions::INPUT_ACT_MAX);

		SetupGame();

		this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
	}

	~MainWindow()
	{
		std::cout << "DELETING MAINWINDOW" << std::endl;
		cleanup();
	}
	
protected:

private:
	//DebugMenu* dMenu;
	GridCellContainer grid;
	void SetupGame();
	void keyPressEvent(QKeyEvent *event);
	void keyMove();
	void cleanup();
	bool cameraFrozen;
private slots:
	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void keyReleaseReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

