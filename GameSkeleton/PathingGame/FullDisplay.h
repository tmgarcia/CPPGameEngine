#pragma once

#include <QtGui\qwidget>
#include <QtGui\qmainwindow.h>

#include "GameWindow.h"




class FullDisplay : public QMainWindow
{
	Q_OBJECT

public:
	FullDisplay();
	~FullDisplay();

private:
	GameWindow gameWindow;
	bool mapIsLoaded;
	bool levelIsLoaded;
	bool testCharacterLoaded;
	//bool currentSaved;
	void keyPressEvent(QKeyEvent *event);

private slots:
	void loadLevel();
	void startCharacter();
	void highlightPathNodes();
	void highlightPathConnections();
	void highlightAllNodes();
	void cameraToPlayerView();
	//void saveLevel();
	//void saveLevelAs();

};

