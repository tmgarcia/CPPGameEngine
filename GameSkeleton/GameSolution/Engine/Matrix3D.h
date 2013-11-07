#pragma once
#include "Vector3D.h"

struct Matrix3D
{
	union
	{
		float values[3][3];
		struct
		{
			float ax;
			float bx;
			float cx;
			float ay;
			float by;
			float cy;
			float az;
			float bz;
			float cz;
		};
	};
	Matrix3D(float ax = 1, float bx = 0, float cx = 0, float ay = 0, float by = 1, float cy = 0, float az = 0, float bz = 0, float cz = 1) : ax(ax), bx(bx), cx(cx), ay(ay), by(by), cy(cy), az(az), bz(bz), cz(cz){}
};

inline Matrix3D operator*(const Matrix3D& left, const Matrix3D&right)
{
	Matrix3D result;
		result.ax = left.ax*right.ax + left.bx*right.ay + left.cx*right.az;
		result.ay = left.ay*right.ax + left.by*right.ay + left.cy*right.az;
		result.az = left.az*right.ax + left.bz*right.ay + left.cz*right.az;
		result.bx = left.ax*right.bx + left.bx*right.by + left.cx*right.bz;
		result.by = left.ay*right.bx + left.by*right.by + left.cy*right.bz;
		result.bz = left.az*right.bx + left.bz*right.by + left.cz*right.bz;
		result.cx = left.ax*right.cx + left.bx*right.cy + left.cx*right.cz;
		result.cy = left.ay*right.cx + left.by*right.cy + left.cy*right.cz;
		result.cz = left.az*right.cx + left.bz*right.cy + left.cz*right.cz;

	return result;
}

inline Vector3D operator*(const Matrix3D& left, const Vector3D&right)
{
	return Vector3D(
			left.ax*right.x + left.bx*right.y + left.cx*right.z, 
			left.ay*right.x + left.by*right.y + left.cy*right.z,
			left.az*right.x + left.bz*right.y + left.cz*right.z); 
}

inline Matrix3D scale(float sx, float sy)
{
	Matrix3D scaled;
	scaled.ax = sx;
	scaled.by = sy;

	return scaled;
}

inline Matrix3D rotate(float angle)
{
	Matrix3D rotated;
	float s = sin(angle);
	float c = cos(angle);
	rotated.ax = c;
	rotated.ay = s;
	rotated.bx = -s;
	rotated.by = c;
	return rotated;
}

inline Matrix3D translate(float tx, float ty)
{
	Matrix3D translated;
	translated.cx = tx;
	translated.cy = ty;
	return translated;
}