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
		buildSystem();
	}
	~GearSystem()
	{
		clearGears();
	}
	static Gear* gears[5];
	void buildSystem();
	Vector3D origin;
	void draw(Core::Graphics& g);
	void update(float dt);
	void clearGears();
	void createGear(int i, float rotationalSpeed);
	int getNumGears();
	Vector3D getIndexedGearPosition(int i);
};