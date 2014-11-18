#pragma once
#include <Windows.h>
#include "ExportHeader.h"

class DECL_DLL_EXPORT Clock
{
	LARGE_INTEGER timeFrequency;
	LARGE_INTEGER lastStartTime;
	LARGE_INTEGER deltaLastLap;
	float deltaTime;
public:
	void start();
	void stop();
	void lap();
	float lastLapTime();
	Clock()
	{
		QueryPerformanceCounter(&timeFrequency);
	}
};

