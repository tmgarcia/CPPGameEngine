#pragma once
#include "Core.h"
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Timer.h"


class Instructions
{
public:
	CStopWatch timer;
	int instructionType; //0=intro instructions 1=pause instructions
	void draw(Core::Graphics& g, int type);
	Instructions(){timer.Start();}
};