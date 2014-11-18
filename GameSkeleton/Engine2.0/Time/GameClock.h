#pragma once
#include "Clock.h"

#include "ExportHeader.h"

class DECL_DLL_EXPORT GameClock
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

