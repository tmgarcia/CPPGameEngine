#pragma once
#include "Core.h"
#include "Vector3D.h"
#include "GearSystem.h"
#include "Random.h"
#include "ScreenInfo.h"
#include "Matrix3D.h"
#include "DebugMemory.h"

class Enemy
{
public:
	Random generator;
	float health;
	Vector3D position;
	Vector3D velocity;
	float orientation1;
	float orientation2;
	void clear();
	void draw(Core::Graphics& g, Vector3D shipPosition);
	void update(float dt);
	Matrix3D rotation;

	Enemy(Vector3D position): position(position)
	{
		orientation1 = 0;
		orientation2 = 0;
	}
	~Enemy(){}
};

