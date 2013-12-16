#pragma once
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Core.h"
#include "DebugMemory.h"



class Gear
{
public:
	//116 w & h
	Gear(float gscale = 1, float offset = 4, float rotationalSpeed = 0.1f) : gscale(gscale), offset(offset), rotationalSpeed(rotationalSpeed){orientation = 0;}
	~Gear()
	{
		//clear();
	}
	float gscale;
	float offset;
	Vector3D draw(Core::Graphics& g, Vector3D parentPos);
	void update(float dt);
	void clear();
	float orientation;
	float rotationalSpeed;
	Vector3D position;
};