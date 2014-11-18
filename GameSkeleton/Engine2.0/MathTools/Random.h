#pragma once
#include <stdlib.h>

const float TWO_PI = 2 * 3.14159f;

#include "ExportHeader.h"

class DECL_DLL_EXPORT Random
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