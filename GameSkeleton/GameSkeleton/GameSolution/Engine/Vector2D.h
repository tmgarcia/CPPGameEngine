#include "Math.h" 
#include <iostream>
#ifndef VECTOR2D_H
#define VECTOR2D_H
using std::cout;
using std::endl;
struct Vector2D
{
	float x;
	float y;
	Vector2D(float x = 0, float y = 0) : x(x), y(y) {}
	
	operator float*()
	{
		return &x;
	}

	inline float length() const
	{
		return sqrt((this->x*this->x)+(this->y*this->y));
	}
	inline float lengthSquared() const
	{
		return (this->x*this->x)+(this->y*this->y);
	}
	inline Vector2D perpCW()
	{
		//return Vector2D(y, x*-1);
		return Vector2D(y*-1, x);
	}
	inline Vector2D perpCCW()
	{
		//return Vector2D(y*-1, x);
		return Vector2D(y, x*-1);
	}
	inline Vector2D normalized()
	{
		if(length()!=0)
			return Vector2D(1/length() * x, 1/length() * y);
		else
			return Vector2D(0, 0);
	}
	inline float selfDot()
	{
		return x*x + y*y;
	}
	inline float dot(const Vector2D& right)
	{
		return x*right.x + y*right.y;
	}
	inline Vector2D projectOnto(const Vector2D& right)
	{
		return Vector2D((dot(right)*right.x)/right.lengthSquared(), (dot(right)*right.y)/right.lengthSquared());
	}
};

inline std::ostream& operator<<(std::ostream& stream, const Vector2D& right)
{
	cout << "{" << right.x << ", " << right.y << "}";
	return stream;
}


inline Vector2D operator+(const Vector2D& left, const Vector2D& right)
{
	return Vector2D(left.x + right.x, left.y + right.y);
}

inline Vector2D operator-(const Vector2D& left, const Vector2D& right)
{
	return Vector2D(left.x + (-1*right.x), left.y + (-1*right.y));
}

inline Vector2D operator*(float scalar, const Vector2D& right)
{
	return Vector2D(scalar * right.x, scalar * right.y);
}

inline Vector2D operator*(const Vector2D& left, float scalar)
{
	return Vector2D(left.x * scalar, left.y * scalar);
}

inline Vector2D operator/(const Vector2D& left, float scalar)
{
	return Vector2D(left.x/scalar, left.y/scalar);
}

inline float dot(const Vector2D& left, const Vector2D& right)
{
	return left.x*right.x + left.y*right.y;
}


inline Vector2D LERP(const Vector2D& left, const Vector2D& right, float beta)
{
	return ((1-beta)*left) + (beta*right);
}

#endif