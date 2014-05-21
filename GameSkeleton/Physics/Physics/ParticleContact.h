#pragma once
#include "Particle.h"

class ParticleContact
{
public:
	Particle* particle[2];

	float restitution;
	float calculateSeparatingVelocity() const;
	float penetration;
	void resolve(float dt);

	vec3 contactNormal;

protected:


private:
	vec3 particleMovement[2];
	void resolveVelocity(float dt);

	void resolveInterpenetration(float dt);
};

