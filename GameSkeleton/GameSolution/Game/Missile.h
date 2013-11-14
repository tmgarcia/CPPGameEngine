#pragma once
#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Core.h"
#include "ScreenInfo.h"

struct Missile
{
	Missile(Vector3D origin = Vector3D(0,0), Matrix3D orientation = Matrix3D()) : origin(origin), orientation(orientation) {position = origin; firing=true;}
	Vector3D origin;
	Vector3D position;
	Matrix3D orientation;
	bool firing;
	void draw(Core::Graphics& g);
	void update(float dt);
	
};

