#pragma once
#include "ParticleEffect.h"


class OpeningSplash : public ParticleEffect
{
public:
	void buildParticles();
	bool update(float dt);
	bool splashing;
	void draw(Core::Graphics& g);
	void assignColor(int i, Core::Graphics& g);

	OpeningSplash(Vector3D origin, RGB color, int numParticles) : ParticleEffect(origin, color, numParticles)
	{
		buildParticles();
		splashing = true;
	}
};

