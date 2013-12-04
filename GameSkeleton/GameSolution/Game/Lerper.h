#pragma once
#include "Core.h"
#include "Vector3D.h"
#include "Matrix3D.h"

class Lerper
{
public:
	Vector3D position;
	void draw(Core::Graphics& g);
	void update(float dt);
};

