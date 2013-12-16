#pragma once
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Core.h"
#include "Gear.h"
#include "DebugMemory.h"

class GearSystem
{
public:
	GearSystem(Vector3D origin): origin(origin) 
	{
		NUM_GEARS = sizeof(gears)/sizeof(gears[0]);
		buildSystem();
	}
	~GearSystem()
	{
		clearGears();
	}
	Gear gears[5];
	void buildSystem();
	Vector3D origin;
	void draw(Core::Graphics& g);
	void update(float dt);
	void clearGears();
	void createGear(unsigned int i, float rotationalSpeed);
	int getNumGears();
	Vector3D getIndexedGearPosition(int i);
	unsigned int NUM_GEARS;
};