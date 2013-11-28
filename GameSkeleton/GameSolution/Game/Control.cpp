#include "Control.h"


GearSystem ge = GearSystem(Vector3D(500, 500, 1));

void Control::draw(Core::Graphics& g)
{
	g.SetBackgroundColor(RGB(25,25,30));
	timer.Start();
	instructs.draw(g);
	profiler.addEntry("Instructions Draw", timer.Interval());
	ge.draw(g);
	profiler.addEntry("Gear System Draw", timer.Interval());
	particleSyst.draw(g);
	profiler.addEntry("ParticleSystem Draw", timer.Interval());
	timer.Stop();
	lerp.draw(g);
	timer.Start();
	ship.draw(g);
	profiler.addEntry("Ship Draw", timer.Stop());
	if(collisionType == 2)
		wall.draw(g);
}

void Control::update(float dt)
{
	profiler.newFrame();
	timer.Start();
	if(Core::Input::IsPressed('1'))
	{
		collisionType = 1;
		ship.resetPosition(Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
		particleSyst.addNewEffect(new BinaryWaveEffect(Vector3D(0,1),RGB(100,100,255),100));
	}
	if(Core::Input::IsPressed('2'))
	{
		collisionType = 2;
		ship.resetPosition(Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
		particleSyst.addNewEffect(new BinaryWaveEffect(Vector3D(0,1),RGB(100,100,255),100));
	}
	if(Core::Input::IsPressed('3'))
	{
		collisionType = 3;
		ship.resetPosition(Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
		particleSyst.addNewEffect(new BinaryWaveEffect(Vector3D(0,1),RGB(100,100,255),100));
	}
	if(Core::Input::IsPressed('W'))
	{
		particleSyst.addNewEffect(new BubbleEffect(ship.position,RGB(100,100,255),1,ship.orientation));
	}
	profiler.addEntry("Ship Movement Update", timer.Stop());
	//Wall collision
	if(collisionType == 2)
	{
		if(wall.collided(ship.getPosition()))
		{
			ship.bounceOffWall(wall.collidedNormal);
		}
	}
	else if(collisionType == 1)
	{
		if(ship.position.x <0 || ship.position.x > SCREEN_WIDTH)
			ship.reverseXVelocity();
		if(ship.position.y <0 || ship.position.y > SCREEN_HEIGHT)
			ship.reverseYVelocity();
	}
	else if(collisionType==3)
	{
		ship.wrap();
	}
	ship.update(dt);
	timer.Start();
	ge.update(dt);
	profiler.addEntry("Gear System Update", timer.Interval());
	lerp.update(dt);
	profiler.addEntry("Lerper Update", timer.Interval());
	particleSyst.update(dt);
	profiler.addEntry("ParticleSystem Update", timer.Interval());
	timer.Stop();
}
