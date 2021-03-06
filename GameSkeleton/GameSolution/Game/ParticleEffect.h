#pragma once
#include "Particle.h"
#include "Engine.h"
#include "Core.h"
#include "Random.h"
#include "Matrix3D.h"
#include "DebugMemory.h"
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
	ParticleEffect(Vector3D origin, RGB color, int numParticles) : numParticles(numParticles), origin(origin), color(color){}
	virtual bool update(float dt);
	virtual void draw(Core::Graphics& g);
	bool checkAlive();
	void clear();
	virtual ~ParticleEffect();
};