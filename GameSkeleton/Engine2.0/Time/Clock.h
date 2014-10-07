#pragma once
#include <Windows.h>

class __declspec(dllexport) Clock
{
	LARGE_INTEGER timeFrequency;
	LARGE_INTEGER lastStartTime;
	LARGE_INTEGER deltaLastLap;
	float deltaTime;
public:
	void start();
	void stop();
	void lap();
	void tick();
	float lastLapTime();
};

