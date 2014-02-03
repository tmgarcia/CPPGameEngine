#pragma once
#include <GL\glew.h>
#include <QtOpenGL\qgl.h>


class MainWindow : public QGLWidget
{
protected:
	void sendDataToHardware();
	void compileShaders();
	void paintGL();
	void transformModels();
	void keyPressEvent(QKeyEvent* e);
	void mouseMoveEvent(QMouseEvent* e);
public:
	void initializeGL();
};

