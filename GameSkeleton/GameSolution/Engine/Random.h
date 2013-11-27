#pragma once
#include <stdlib.h>
#include "Vector2D.h"

const float TWO_PI = 2 * 3.14159f;

class Random
{
public:
	float randomFloat()
	{
		return (float)rand()/RAND_MAX;
	}
	Vector3D randomUnitVector()
	{
		float angle = TWO_PI*randomFloat();
		Vector3D vec(cos(angle), sin(angle));
		return vec;
	}
	Vector3D randomUnitVectorRange(float minAngle, float maxAngle)
	{
		float angle = randomIntRange(minAngle,maxAngle);
		Vector3D vec(cos(angle), sin(angle));
		return vec;
	}
	float randomIntRange(float min, float max)
	{
		return randomFloat() * (max*(min+1))+min;
	}
};