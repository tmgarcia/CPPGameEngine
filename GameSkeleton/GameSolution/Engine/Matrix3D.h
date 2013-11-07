#pragma once
#include "Vector3D.h"

struct Matrix3D
{
	Vector3D a;
	Vector3D b;
	Vector3D c;
	Matrix3D(Vector3D a = Vector3D(1,0,0), Vector3D b = Vector3D(0,1,0), Vector3D c = Vector3D(0,0,1)) : a(a), b(b), c(c) {}
};

inline Matrix3D operator*(const Matrix3D& left, const Matrix3D&right)
{
	return Matrix3D(
		Vector3D(
			left.a.x*right.a.x + left.b.x*right.a.y + left.c.x*right.a.z,
			left.a.y*right.a.x + left.b.y*right.a.y + left.c.y*right.a.z,
			left.a.z*right.a.x + left.b.z*right.a.y + left.c.z*right.a.z),
		Vector3D(
			left.a.x*right.b.x + left.b.x*right.b.y + left.c.x*right.b.z,
			left.a.y*right.b.x + left.b.y*right.b.y + left.c.y*right.b.z,
			left.a.z*right.b.x + left.b.z*right.b.y + left.c.z*right.b.z),
		Vector3D(
			left.a.x*right.c.x + left.b.x*right.c.y + left.c.x*right.c.z,
			left.a.y*right.c.x + left.b.y*right.c.y + left.c.y*right.c.z,
			left.a.z*right.c.x + left.b.z*right.c.y + left.c.z*right.c.z));
}

inline Vector3D operator*(const Matrix3D& left, const Vector3D&right)
{
	return Vector3D(
			left.a.x*right.x + left.b.x*right.y + left.c.x*right.z, 
			left.a.y*right.x + left.b.y*right.y + left.c.y*right.z,
			left.a.z*right.x + left.b.z*right.y + left.c.z*right.z); 
}

inline Matrix3D scale(float sx, float sy)
{
	Matrix3D scaled;
	scaled.a.x = sx;
	scaled.b.y = sy;

	return scaled;
}

inline Matrix3D rotate(float angle)
{
	Matrix3D rotated;
	float s = sin(angle);
	float c = cos(angle);
	rotated.a.x = c;
	rotated.a.y = s;
	rotated.b.x = -s;
	rotated.b.y = c;
	return rotated;
}

inline Matrix3D translate(float tx, float ty)
{
	Matrix3D translated;
	translated.c.x = tx;
	translated.c.y = ty;
	return translated;
}