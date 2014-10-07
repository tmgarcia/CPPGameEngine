#include "Clock.h"

void Clock::start()
{
	//QueryPerformanceCounter(&timeLastFrame);
	QueryPerformanceCounter(&lastStartTime);
}
void Clock::stop()
{
	LARGE_INTEGER thisTime;
	QueryPerformanceCounter(&thisTime);
	LARGE_INTEGER delta;
	delta.QuadPart = thisTime.QuadPart - lastStartTime.QuadPart;
	deltaTime = ((float)delta.QuadPart) / timeFrequency.QuadPart;
	deltaLastLap.QuadPart = thisTime.QuadPart;
}
void Clock::lap()
{
	stop();
	start();
}
float Clock::lastLapTime()
{
	return deltaTime;
}