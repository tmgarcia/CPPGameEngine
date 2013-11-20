#include "Engine.h"
#include "Core.h"
#include "SpaceShip.h"
#include "ScreenInfo.h"
#include "Random.h"
#include "ParticleEffect.h"
//using Core::Graphics;
using Core::RGB;



//ParticleEffect troll(Vector3D(0,1), RGB(0, 0, 255),200);

SpaceShip meShip;
bool Update( float dt)
{
	if( Core::Input::IsPressed( Core::Input::KEY_ESCAPE ) )
		return true;
//	troll.update(dt);
	meShip.update(dt);
	return false;
}
void Draw( Core::Graphics& graphics)
{
//	troll.draw(graphics);
	//graphics.SetColor( RGB(255, 255, 0) );
	//graphics.DrawString( SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 - 20, "Hello World");
	//graphics.DrawLine(10,10,400,300);
	meShip.draw(graphics);
}

int main()
{
	meShip.position = Vector3D(75, 300);
	Core::Init( "Example", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn( Update);
	Core::RegisterDrawFn( Draw );
	Core::GameLoop();
//	Engine::sampleFunctionThatReturnsTrue();
}

