#pragma once
#include "Math.h" 
#include <iostream>

struct Vector3D
{
	float x;
	float y;
	float z;

	Vector3D(float x=0, float y=0, float z=1) : x(x), y(y), z(z) {}

	operator float*()
	{
		return &x;
	}

		inline float length() const
	{
		return sqrt((x*x)+(y*y)+(z*z));
	}
	inline float lengthSquared() const
	{
		return (x*x)+(y*y)+(z*z);
	}
	inline Vector3D perpCW()
	{
		return Vector3D(y*-1, x);
	}
	inline Vector3D perpCCW()
	{
		return Vector3D(y, x*-1);
	}
	inline Vector3D normalized()
	{
		if(length()!=0)
			return Vector3D(1/length() * x, 1/length() * y, 1/length() * z);
		else
			return Vector3D(0, 0, 0);
	}
	inline float selfDot()
	{
		return x*x + y*y;
	}
	inline float dot(const Vector3D& right)
	{
		return x*right.x + y*right.y;
	}
	inline Vector3D projectOnto(const Vector3D& right)
	{
		return Vector3D((dot(right)*right.x)/right.lengthSquared(), (dot(right)*right.y)/right.lengthSquared(), (dot(right)*right.z)/right.lengthSquared());
	}
};

inline Vector3D operator+(const Vector3D& left, const Vector3D& right)
{
	return Vector3D(left.x + right.x, left.y + right.y, left.z + right.z);
}

inline Vector3D operator-(const Vector3D& left, const Vector3D& right)
{
	return Vector3D(left.x + (-1*right.x), left.y + (-1*right.y), left.z + (-1*right.z));
}

inline Vector3D operator*(float scalar, const Vector3D& right)
{
	return Vector3D(scalar * right.x, scalar * right.y, scalar * right.z);
}

inline Vector3D operator*(const Vector3D& left, float scalar)
{
	return Vector3D(left.x * scalar, left.y * scalar, left.z * scalar);
}

inline Vector3D operator/(const Vector3D& left, float scalar)
{
	return Vector3D(left.x/scalar, left.y/scalar, left.z/scalar);
}

inline float dot(const Vector3D& left, const Vector3D& right)
{
	return left.x*right.x + left.y*right.y + left.z*right.z;
}


inline Vector3D LERP(const Vector3D& left, const Vector3D& right, float beta)
{
	return ((1-beta)*left) + (beta*right);
}