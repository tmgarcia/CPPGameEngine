#pragma once
#include <vector>
#include "ParticleEffect.h"
#include "Vector3D.h"
#include "Core.h"
#include "Random.h"
#include "Matrix3D.h"
using std::vector;
using Core::RGB;

const int MAX_EFFECTS = 5;


class ParticleSystem
{
public:
	unsigned int numActiveEffects;
	ParticleSystem()
	{
		numActiveEffects = 0;
	}
	vector<ParticleEffect*> effectList;
	void draw(Core::Graphics& g);
	void update(float dt);
	void addNewEffect(Vector3D origin, RGB color, int numParticles, int effectType, float orientation);
	void deleteEffect(int i);
};

