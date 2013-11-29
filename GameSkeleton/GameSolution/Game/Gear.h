#pragma once
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Core.h"
class Gear
{
public:
	//116 w & h
	Gear(float gscale = 1, float offset = 4, float rotationalSpeed = 0.1f) : gscale(gscale), offset(offset), rotationalSpeed(rotationalSpeed){orientation = 0;}
	float gscale;
	float offset;
	Vector3D draw(Core::Graphics& g, Vector3D parentPos);
	void update(float dt);
	float orientation;
	float rotationalSpeed;
	Vector3D position;
};