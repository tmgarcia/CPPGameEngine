#pragma once
#include "PhysicsGui\GuiBase.h"

class VelocityAcceleration : public GuiBase
{
public:
	void initialize();
	void newFrame();
	void vectorGraphicMouseDrag(uint vectorGraphicINdex, const glm::vec3& dragDelta);
	glm::vec3 getUserDirection();
	VelocityAcceleration(){}
	~VelocityAcceleration(){}
};

