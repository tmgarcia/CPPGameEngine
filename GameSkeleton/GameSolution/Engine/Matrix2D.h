#pragma once
#include "Vector2D.h"

struct Matrix2D
{
	Vector2D a;
	Vector2D b;
	Matrix2D(Vector2D a, Vector2D b) : a(a), b(b) {}
};

inline Vector2D operator*(const Matrix2D& op, const Vector2D& v)
{
	return Vector2D((op.a.x * v.x) + (op.b.x * v.y), (op.a.y * v.x) + (op.b.y * v.y));
}

