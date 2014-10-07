#pragma once
#include <stdlib.h>

const float TWO_PI = 2 * 3.14159f;

class __declspec(dllexport) Random
{
public:
	static Random& getInstance();
private:
	static Random* theInstance;
	Random(){}
	Random(const Random&);
	Random& operator = (const Random&);
public:
	float randomFloat();
	float randomFloatRange(float min, float max);
};