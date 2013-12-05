#include "Engine.h"
#include "Core.h"
#include "ScreenInfo.h"
#include "Control.h"
#include "Profiler.h"
#include <stdlib.h>
#include <time.h>

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
	Core::Init( "Example", SCREEN_WIDTH, SCREEN_HEIGHT);
	profiler.initialize("gameprofile.csv");
	Core::RegisterUpdateFn( Update);
	Core::RegisterDrawFn( Draw );
	Core::GameLoop();
	profiler.shutdown();
}

