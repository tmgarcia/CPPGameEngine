#pragma once
#include "Core.h"
#include "Vector3D.h"

class Walls
{
public:
	void draw(Core::Graphics& g);
	bool collided(Vector3D position);
	Vector3D collidedNormal;
};

