#include "Engine.h"
#include "Core.h"
#include "SpaceShip.h"
#include "ScreenInfo.h"
#include "Random.h"
#include "ParticleEffect.h"

using Core::RGB;

SpaceShip meShip;

bool Update( float dt)
{
	if( Core::Input::IsPressed( Core::Input::KEY_ESCAPE ) )
		return true;
	meShip.update(dt);
	return false;
}

void Draw( Core::Graphics& graphics)
{
	meShip.draw(graphics);
}

int main()
{
	meShip.position = Vector3D(75, 300);
	Core::Init( "Example", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( Update);
	Core::RegisterDrawFn( Draw );
	Core::GameLoop();
}

