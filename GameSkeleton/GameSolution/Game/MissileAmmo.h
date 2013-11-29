#pragma once

#include "Missile.h"
#include <vector>
#include "Core.h"
using std::vector;

const int MAX_MISSILES = 500;

class MissileAmmo
{
public:
	vector<Missile*> missiles;
	unsigned int numActiveMissiles;
	void draw(Core::Graphics& g);
	void update(float dt);
	void addMissile(Missile* m);
	void deleteMissile(int i);
	Vector3D getMissilePosition(int i);
	MissileAmmo()
	{
		numActiveMissiles = 0;
	}
	~MissileAmmo()
	{
		missiles.clear();
	}
};

