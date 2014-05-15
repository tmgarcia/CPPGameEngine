#pragma once

#include "ParticleForceGenerator.h"

class ParticleKeyboardForceGenerator : public ParticleForceGenerator
{
	float keyboardAccelerationMultiplier;

public:
	ParticleKeyboardForceGenerator(const float keyboardAccelerationMultiplier = 2) : keyboardAccelerationMultiplier(keyboardAccelerationMultiplier){}

	virtual void updateForce(Particle *particle, float duration);

private:
	vec3 getUserDirection();
};

