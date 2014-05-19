#pragma once

#include "ParticleForceGenerator.h"

class ParticleGravityGenerator : public ParticleForceGenerator
{

public:
	vec3 gravity;
	ParticleGravityGenerator(const vec3 &gravity = vec3(0,-1,0)) : gravity(gravity)
	{}

	virtual void updateForce(Particle *particle, float duration);

};

