#pragma once

#include "ParticleForceGenerator.h"
#include "Particle.h"

class ParticleSpringGenerator : public ParticleForceGenerator
{
	Particle *other;
	

public:

	float springConstant;
	float restLength;

	ParticleSpringGenerator(Particle *other = new Particle(), float springConstant = 1, float restLength = 1): other(other), springConstant(springConstant), restLength(restLength)
	{}

	virtual void updateForce(Particle *particle, float duration);
};

