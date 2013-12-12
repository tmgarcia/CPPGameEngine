#pragma once
#include "Core.h"
#include "Vector3D.h"
#include "DebugMemory.h"

class Walls
{
public:
	void draw(Core::Graphics& g);
	bool collided(Vector3D position);
	Vector3D collidedNormal;
	void clear();
	Walls(){}
	~Walls()
	{
		clear();
	}
};

