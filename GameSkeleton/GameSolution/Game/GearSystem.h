#pragma once
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Core.h"
#include "Gear.h"

class GearSystem
{
public:
	GearSystem(Vector3D origin): origin(origin) {buildSystem();}
	void buildSystem();
	Vector3D origin;
	void draw(Core::Graphics& g);
	void update(float dt);
	void createGear(int i);
};