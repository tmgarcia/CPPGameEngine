#pragma once
#include <QtOpenGL\qglwidget>

class CoolGLWindow : public QGLWidget
{
protected:
	void initializeGL();
	void paintGL();
	void sendDataToHardware();
	void compileShaders();
public:
	
};

