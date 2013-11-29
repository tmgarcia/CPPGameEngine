#pragma once
#include "Core.h"
#include "Vector3D.h"
#include "GearSystem.h"
#include "Random.h"
#include "ScreenInfo.h"

class Enemy
{
public:
	Random generator;
	float health;
	Vector3D position;
	Vector3D velocity;
	float orientation;
	void draw(Core::Graphics& g, Vector3D shipPosition);
	void update(float dt);
	void createEnemy();
	//GearSystem* gears;
	int assignedGear;
	Matrix3D rotation;

	Enemy()
	{
		//this->gears = gears;
		createEnemy();
		position = Vector3D(generator.randomIntRange(0,(float)SCREEN_WIDTH), generator.randomIntRange(0,(float)SCREEN_HEIGHT));
	}
};

