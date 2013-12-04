#pragma once

#include "Enemy.h"
#include <vector>
#include "Core.h"
#include "ParticleSystem.h"
#include "BubbleEffect.h"

using std::vector;

const int MAX_ENEMIES = 50;

class EnemyLegion
{
public:
	vector<Enemy*> troops;
	bool EnemyLegion::checkCollide(Vector3D colliderPosition);
	unsigned int numActiveTroops;
	void draw(Core::Graphics& g, Vector3D shipPosition);
	void update(float dt);
	void addEnemy(Vector3D position);
	void deleteEnemy(int i);
	Vector3D collidedPosition;
	EnemyLegion()
	{
		numActiveTroops = 0;
	}
	~EnemyLegion()
	{
		troops.clear();
	}
};

