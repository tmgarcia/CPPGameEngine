#pragma once
#include "Particle.h"
#include "Engine.h"
#include "Core.h"
#include "Random.h"
#include "Matrix3D.h"
using::Core::RGB;

class ParticleEffect
{
public:
	int numParticles;
	int particleType;
	int effectType;
	RGB color;
	Vector3D origin;
	Particle* particles;
	Random generator;
	float orientation;
	void buildParticles();
	ParticleEffect(Vector3D origin, RGB color, int numParticles, int effectType, float orientation = 0) : numParticles(numParticles), origin(origin), color(color), effectType(effectType), orientation(orientation)
	{
		buildParticles();
	}
	bool update(float dt);
	void draw(Core::Graphics& g);
	~ParticleEffect()
	{
		delete []particles;
	}
};