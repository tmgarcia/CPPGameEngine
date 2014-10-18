#pragma once
#include "Clock.h"

class __declspec(dllexport) GameClock
{
	GameClock()
	{
		clock = new Clock();
	}
	GameClock(GameClock const&);
	GameClock& operator = (GameClock const&);
	static GameClock* theInstance;
	Clock* clock;
public:
	static GameClock& getInstance();
	void newFrame();
	float dt();
	static void cleanup();
};

