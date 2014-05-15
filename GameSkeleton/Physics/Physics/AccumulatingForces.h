#pragma once
#include "PhysicsGui\GuiBase.h"
#include "Particle.h"

class AccumulatingForces : public GuiBase
{
	Particle gravityParticle;
	Particle keyboardParticle;
	Particle accumulatedParticle;

public:
	void initialize();
	void newFrame();
	void vectorGraphicMouseDrag(uint vectorGraphicINdex, const glm::vec3& dragDelta);
	glm::vec3 getUserDirection();
	AccumulatingForces(){}
	~AccumulatingForces(){}
};

