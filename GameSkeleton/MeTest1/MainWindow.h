#include <Qt\qt_windows.h>
#include <Qt\qwidget.h>
#pragma once
class MainWindow : QWidget
{
protected:
	void paintGL();
	void sendDataToHardware();
public:
	void initializeGL();
	
};

