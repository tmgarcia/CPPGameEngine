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
	RGB color;
	Vector3D origin;
	Particle* particles;
	Random generator;
	virtual void buildParticles();
	ParticleEffect(Vector3D origin, RGB color, int numParticles) : numParticles(numParticles), origin(origin), color(color)
	{
		buildParticles();
	}
	virtual bool update(float dt);
	virtual void draw(Core::Graphics& g);
	bool checkAlive();
	~ParticleEffect()
	{
		delete []particles;
	}
};