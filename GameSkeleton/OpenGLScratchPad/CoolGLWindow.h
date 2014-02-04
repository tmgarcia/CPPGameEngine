#pragma once
#include <QtOpenGL\qglwidget>
#include <qt\qtimer.h>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"

using glm::vec3;
using glm::mat3;
using glm::mat4;
class CoolGLWindow : public QGLWidget
{
	Q_OBJECT

	QTimer myTimer;
protected:
	void initializeGL();
	void transformShapes();
	void transformColumns();
	void transformWalls();
	void continuousTransforms();
	void paintGL();
	void sendDataToHardware();
	void compileShaders();
	void updatePlayer(vec3 position, GLfloat angle, bool isP1);
	void updateHill();
	std::string readShaderCode(const char *filename);
	void mouseMoveEvent(QMouseEvent*);

private slots:
	void myUpdate();

public slots:
	void setObjectColorRed(float newValue);
	void setObjectColorGreen(float newValue);
	void setObjectColorBlue(float newValue);
	void setAmbientColorRed(float newValue);
	void setAmbientColorGreen(float newValue);
	void setAmbientColorBlue(float newValue);
	void setLightPositionX(float newValue);
	void setLightPositionY(float newValue);
	void setLightPositionZ(float newValue);
	void setDiffusionIntensity(float newValue);
	void setSpecularColorRed(float newValue);
	void setSpecularColorGreen(float newValue);
	void setSpecularColorBlue(float newValue);
	void setSpecularExponent(float newValue);

public:
	void keyPressEvent(QKeyEvent*);

};

