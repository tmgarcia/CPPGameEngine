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
	Matrix3D rotation;

	Enemy(Vector3D position): position(position){}
};

