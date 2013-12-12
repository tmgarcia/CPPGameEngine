#include "Engine.h"
#include "Core.h"
#include "ScreenInfo.h"
#include "Control.h"
#include "Profiler.h"
#include <stdlib.h>
#include <time.h>
#include "Assert.h"
#include "DebugMemory.h"


using Core::RGB;
bool running=true;
Control con;

bool Update( float dt)
{
	if(running)
	{
		if( Core::Input::IsPressed( Core::Input::KEY_ESCAPE ) )
			running = false;
		con.update(dt);
	}
	return !running;
}

void Draw( Core::Graphics& graphics)
{
	con.draw(graphics);
}

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	//char* a = new char[500];
	//a[-1] = 0;
	LOG(Info, "Info <TEST_INFO>");
	LOG(Warning, "Warning <TEST_WARNING>");
	LOG(Error, "Error <TEST_ERROR>");
	LOG(Severe, "Severe<TEST_SEVERE>");
	//Assert((false), "It just didn't work.");
	Core::Init( "Example", SCREEN_WIDTH, SCREEN_HEIGHT);
	profiler.initialize("gameprofile.csv");
	Core::RegisterUpdateFn( Update);
	Core::RegisterDrawFn( Draw );
	Core::GameLoop();
	con.~Control();
	profiler.shutdown();
	END_LOG
}

