#pragma once
#include "ParticleEffect.h"
#include "Grid.h"

class CollideWallEffect : public ParticleEffect
{
public:
	void buildParticles();
	bool update(float dt);
	void draw(Core::Graphics& g);
	Grid* grid;
	CollideWallEffect(Vector3D origin, RGB color, int numParticles, Grid* grid) : ParticleEffect(origin, color, numParticles), grid(grid)
	{
		buildParticles();
	}
};