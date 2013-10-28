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

	float length()
	{
		return sqrt((this->x*this->x)+(this->y*this->y));
	}
	float lengthSquared()
	{
		return (this->x*this->x)+(this->y*this->y);
	}
	Vector2D perpCW()
	{
		return Vector2D(y, x*-1);
	}
	Vector2D perpCCW()
	{
		return Vector2D(y*-1, x);
	}
	Vector2D normalized()
	{
		return Vector2D(1/length() * x, 1/length() * y);
	}
	Vector2D dot()
	{
		return x*x + y*y;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2D& right)
{
	cout << "{" << right.x << ", " << right.y << "}";
	return stream;
}


Vector2D operator+(const Vector2D& left, const Vector2D& right)
{
	return Vector2D(left.x + right.x, left.y + right.y);
}

Vector2D operator-(const Vector2D& left, const Vector2D& right)
{
	return Vector2D(left.x + (-1*right.x), left.y + (-1*right.y));
}

Vector2D operator*(float scalar, const Vector2D& right)
{
	return Vector2D(scalar * right.x, scalar * right.y);
}

Vector2D operator*(const Vector2D& left, float scalar)
{
	return Vector2D(left.x * scalar, left.y * scalar);
}

Vector2D operator/(const Vector2D& left, float scalar)
{
	return Vector2D(left.x/scalar, left.y/scalar);
}

float dot(const Vector2D& left, const Vector2D& right)
{
	return left.x*right.x + left.y*right.y;
}


Vector2D LERP(const Vector2D& left, const Vector2D& right, float beta)
{
	return ((1-beta)*left) + (beta*right);
}

#endif