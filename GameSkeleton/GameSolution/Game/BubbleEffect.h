#pragma once
#include "ParticleEffect.h"


class BubbleEffect : public ParticleEffect
{
public:
	float orientation;
	void buildParticles();
	bool update(float dt);
	void draw(Core::Graphics& g);
	BubbleEffect(Vector3D origin, RGB color, int numParticles, float orientation = 0) : ParticleEffect(origin, color, numParticles), orientation(orientation)
	{
		buildParticles();
	}
};