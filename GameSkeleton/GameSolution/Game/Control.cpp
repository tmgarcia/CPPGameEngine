#include "Control.h"

GearSystem ge = GearSystem(Vector3D(500, 500, 1));

MissileAmmo ammo;
SpaceShip ship = SpaceShip(&ammo, Vector3D(50, 50));

Grid grid = Grid(RGB(0,200,200),10,10);

void Control::collisionCheck()
{
	for(unsigned int i=0; i < ammo.numActiveMissiles; i++)
	{
		if(grid.enemyCollisionCheck(ammo.getMissilePosition(i)))
		{
			particleSyst.addNewEffect( new ExplosionEffect(grid.collidedEnemy,RGB(255,100,100),50));
		}
	}
}

void Control::drawSplash(Core::Graphics& g)
{
	g.SetColor(RGB(255,255,255));
	g.DrawString(415, 515, "PRESS ENTER TO BEGIN");

	if(!splashDraw)
		splashRunning = false;
	particleSyst.draw(g);
}

void Control::updateSplash(float dt)	
{
	if( Core::Input::IsPressed( Core::Input::BUTTON_ENTER ) )
	{
		splashDraw = false;
	}
	float o = dt;
	o++;
	particleSyst.update(dt);
}

void Control::draw(Core::Graphics& g)
{
	if(splashRunning)
	{
		drawSplash(g);
	}
	else
	{
		g.SetBackgroundColor(RGB(0,0,10));
		timer.Start();
		instructs.draw(g);
		profiler.addEntry("Instructions Draw", timer.Interval());
		ge.draw(g);
		profiler.addEntry("Gear System Draw", timer.Interval());
		particleSyst.draw(g);
		profiler.addEntry("ParticleSystem Draw", timer.Interval());
		timer.Stop();
		grid.draw(g);
		lerp.draw(g);
		timer.Start();
		ship.draw(g);
		profiler.addEntry("Ship Draw", timer.Stop());
		if(collisionType == 2)
			wall.draw(g);
		enemies.draw(g, ship.position);
	}
}

void Control::update(float dt)
{
	if(splashRunning)
	{
		updateSplash(dt);
	}
	else
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
		if(grid.update(ship.position))
		{
			if(grid.collisionDirection==0)
				ship.reverseXVelocity();
			else if(grid.collisionDirection==1)
				ship.reverseYVelocity();
		}
		collisionCheck();
	}
}
