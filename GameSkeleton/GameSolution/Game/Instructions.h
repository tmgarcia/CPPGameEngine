#pragma once
#include "Core.h"
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Timer.h"


class Instructions
{
public:
	CStopWatch timer;
	void draw(Core::Graphics& g);
	Instructions(){timer.Start();}
};