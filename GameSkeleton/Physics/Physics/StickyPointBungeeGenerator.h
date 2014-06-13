#pragma once

#include "ParticleForceGenerator.h"
#include "Particle.h"

class StickyPointBungeeGenerator : public ParticleForceGenerator
{
	

public:

	vec3 point;
	float springConstant;
	float restLength;
	vec3 lastForce;

	StickyPointBungeeGenerator(vec3 point = vec3(), float springConstant = 1, float restLength = 1): point(point), springConstant(springConstant), restLength(restLength)
	{}

	virtual void updateForce(Particle *particle, float duration);
};

