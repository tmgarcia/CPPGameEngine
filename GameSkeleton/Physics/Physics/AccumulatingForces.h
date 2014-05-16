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
	AccumulatingForces(){}
	~AccumulatingForces(){}
};

