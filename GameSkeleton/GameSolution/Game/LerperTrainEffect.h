#pragma once
#include "ParticleEffect.h"


class LerperTrainEffect : public ParticleEffect
{
public:
	float fullLife;
	void buildParticles();
	bool update(float dt);
	void draw(Core::Graphics& g);
	LerperTrainEffect(Vector3D origin, int numParticles) : ParticleEffect(origin, RGB(255,255,255), numParticles)
	{
		fullLife = 1;
		buildParticles();
	}
};