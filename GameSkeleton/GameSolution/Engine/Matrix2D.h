#pragma once
#include "Vector2D.h"

struct Matrix2D
{
	union
	{
		float values[2][2];
		struct
		{
			float ax;
			float bx;
			float ay;
			float by;
		};
	};
	Matrix2D(float ax = 1, float bx = 0, float ay = 0, float by = 1) : ax(ax), bx(bx), ay(ay), by(by){}
};

inline Vector2D operator*(const Matrix2D& op, const Vector2D& v)
{
	return Vector2D((op.ax * v.x) + (op.bx * v.y), (op.ay * v.x) + (op.by * v.y));
}

