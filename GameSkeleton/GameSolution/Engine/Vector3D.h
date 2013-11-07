#pragma once

struct Vector3D
{
	float x;
	float y;
	float z;

	Vector3D(float x=0, float y=0, float z=0) : x(x), y(y), z(z) {}

	operator float*()
	{
		return &x;
	}
};