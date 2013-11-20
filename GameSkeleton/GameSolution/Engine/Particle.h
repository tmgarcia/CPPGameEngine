#pragma once
#include "Vector3D.h"
#include "Core.h"
using Core::RGB;


class Particle
{
public:
	RGB color;
	Vector3D position;
	Vector3D velocity;
	float size;
	float lifetime;
	float orientation;
};