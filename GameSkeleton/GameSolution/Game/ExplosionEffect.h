#pragma once
#include "ParticleEffect.h"

class ExplosionEffect : public ParticleEffect
{
public:
	void buildParticles();
	bool update(float dt);
	void draw(Core::Graphics& g);
	ExplosionEffect(Vector3D origin, RGB color, int numParticles) : ParticleEffect(origin, color, numParticles)
	{
		buildParticles();
	}
};