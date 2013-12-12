#pragma once
#include <vector>
#include "ParticleEffect.h"
#include "DebugMemory.h"
#include "Core.h"
using std::vector;

const int MAX_EFFECTS = 100;


class ParticleSystem
{
public:
	unsigned int numActiveEffects;
	vector<ParticleEffect*> effectList;
	void draw(Core::Graphics& g);
	void update(float dt);
	void addNewEffect(ParticleEffect* pe);
	void deleteEffect(int i);
	ParticleSystem()
	{
		numActiveEffects = 0;
	}
	~ParticleSystem()
	{
		effectList.clear();
	}
};

