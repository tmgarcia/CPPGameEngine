#pragma once
#include "ParticleEffect.h"


class OpeningSplash2 : public ParticleEffect
{
public:
	void buildParticles();
	bool update(float dt);
	bool splashing;
	void draw(Core::Graphics& g);
	OpeningSplash2(Vector3D origin, RGB color, int numParticles) : ParticleEffect(origin, color, numParticles)
	{
		buildParticles();
		splashing = true;
	}
};

