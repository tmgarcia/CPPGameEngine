#pragma once
#include <QtOpenGL\qglwidget>
#include <qt\qtimer.h>

class CoolGLWindow : public QGLWidget
{
	Q_OBJECT

	QTimer myTimer;
protected:
	void initializeGL();
	void paintGL();
	void sendDataToHardware();
	void compileShaders();
private slots:
	void myUpdate();
public:

};

