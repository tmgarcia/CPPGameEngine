#include "Engine.h"
#include "Core.h"
#include "SpaceShip.h"
#include "ScreenInfo.h"
#include "Random.h"
#include "ParticleEffect.h"
#include "Control.h"

using Core::RGB;

Control con;

bool Update( float dt)
{
	if( Core::Input::IsPressed( Core::Input::KEY_ESCAPE ) )
		return true;
	con.update(dt);
	return false;
}

void Draw( Core::Graphics& graphics)
{
	con.draw(graphics);
}

int main()
{
	Core::Init( "Example", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( Update);
	Core::RegisterDrawFn( Draw );
	Core::GameLoop();
}

