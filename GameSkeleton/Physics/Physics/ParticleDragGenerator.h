#pragma once

#include "ParticleForceGenerator.h"

class ParticleDragGenerator : public ParticleForceGenerator
{
public:
	float highSpeed;
	float lowSpeed;

	ParticleDragGenerator(float high=0, float low=0) : highSpeed(high), lowSpeed(low){}

	virtual void updateForce(Particle *particle, float duration);
};

