#include "Engine.h"
#include "Core.h"
#include "SpaceShip.h"
#include "ScreenInfo.h"
//using Core::Graphics;



//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT= 600;
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

