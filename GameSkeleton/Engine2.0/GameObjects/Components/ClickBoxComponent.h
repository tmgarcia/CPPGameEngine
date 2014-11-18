#pragma once
#include "../Component.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\transform.hpp>
#include <Qt\qobject.h>
#include <QtGUI\qmouseevent>


using glm::vec3;
using glm::vec4;
using glm::mat4;
#include "ExportHeader.h"

class DECL_DLL_EXPORT ClickBoxComponent : public QObject, public Component
{
	Q_OBJECT

public:
	ClickBoxComponent();

	float width;//x axis
	float height;//y axis
	float length;//z axis

	vec3 boxOrigin;

	void update();
	void cleanup();

public slots:
	void mouseClickReaction(QMouseEvent* e);

signals:
	void LeftClicked();
	void RightClicked();

private:
	bool isWithinBox(vec3 point);
	bool isWithinWidth(float x);
	bool isWithinHeight(float y);
	bool isWithinLength(float z);
};

