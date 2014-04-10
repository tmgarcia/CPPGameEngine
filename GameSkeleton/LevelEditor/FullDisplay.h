#pragma once

#include <QtGui\qwidget>
#include <QtGui\qmainwindow.h>

#include "LevelDisplay.h"




class FullDisplay : public QMainWindow
{
	Q_OBJECT

public:
	FullDisplay();
	~FullDisplay();

private:
	LevelDisplay levelDisplay;
	bool levelIsLoaded;
	bool currentSaved;
	void keyPressEvent(QKeyEvent *event);

private slots:
	void loadObj();
	void loadLevel();
	void saveLevel();
	void saveLevelAs();

};

