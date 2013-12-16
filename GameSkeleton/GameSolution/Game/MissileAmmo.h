#pragma once

#include "Missile.h"
#include "DebugMemory.h"
#include <vector>
#include "Core.h"
#include "Grid.h"
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
	void clearOut();
	Vector3D getMissilePosition(int i);
	Grid* grid;
	MissileAmmo(Grid* grid): grid(grid)
	{
		numActiveMissiles = 0;
	}
	~MissileAmmo()
	{
		clearOut();
		missiles.clear();
	}
};

