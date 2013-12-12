#pragma once
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Core.h"
#include "DebugMemory.h"

struct Turret
{
	Matrix3D turnTurret;
	Vector3D tip;
	void draw(Core::Graphics& g, Vector3D shipPosition);
	void clear();
	~Turret(){clear();}
};