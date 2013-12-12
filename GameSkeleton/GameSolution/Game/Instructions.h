#pragma once
#include "Core.h"
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Timer.h"
#include "DebugMemory.h"


class Instructions
{
public:
	CStopWatch timer;
	int instructionType; //0=intro instructions 1=pause instructions
	void draw(Core::Graphics& g, int type);
	void drawDebugInfo(Core::Graphics& g, size_t counts, size_t size, size_t high);
	void clear();
	Instructions(){timer.Start();}
	~Instructions(){clear();}
};