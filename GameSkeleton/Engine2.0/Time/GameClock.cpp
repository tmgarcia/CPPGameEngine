#include "GameClock.h"

void GameClock::newFrame()
{
	clock.lap();
}
float GameClock::dt()
{
	return clock.lastLapTime();
}

GameClock* GameClock::theInstance;

GameClock& GameClock::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new GameClock();
	}
	return *theInstance;
}