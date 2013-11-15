#pragma once
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Core.h"
class Gear
{
public:
	//116 w & h
	Gear(float gscale = 1, float offset = 4) : gscale(gscale), offset(offset){orientation = 0;}
	float gscale;
	float offset;
	Vector3D draw(Core::Graphics& g, Vector3D parentPos);
	void update(float dt);
	float orientation;
};