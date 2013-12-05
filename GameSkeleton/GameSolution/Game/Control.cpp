#include "Control.h"

GearSystem ge1 = GearSystem(Vector3D(200, 200, 1));
GearSystem ge2 = GearSystem(Vector3D(400, 400, 1));

Grid grid = Grid(RGB(0,200,200),10,10);


MissileAmmo ammo(&grid);
SpaceShip ship = SpaceShip(&ammo, Vector3D((float)SCREEN_WIDTH-50, (float)SCREEN_HEIGHT-50));



void Control::fillGrid()
{
	unsigned int numEnemies = 10;
	for(unsigned int i = 0; i<numEnemies; i++)
	{
		grid.addEnemyAt((int)generator.randomIntRange(1,9), (int)generator.randomIntRange(1,9));
	}
}

void Control::collisionCheck()
{
	for(unsigned int i=0; i < ammo.numActiveMissiles; i++)
	{
		if(grid.enemyCollisionCheck(ammo.getMissilePosition(i)))
		{
			particleSyst.addNewEffect( new ExplosionEffect(grid.collidedEnemy,RGB(20,100,20),50));
		}
	}
}

void Control::drawPause(Core::Graphics& g)
{
	pauseSyst.draw(g);
	g.SetBackgroundColor(RGB(20,20,100));
	instructs.draw(g, 1);
	if(!paused)
	{
		pauseDraw = false;
	}
}

void Control::updatePause(float dt)
{
	pauseSyst.update(dt);
	pauseDraw = true;
	if(Core::Input::IsPressed('U'))
	{
		paused = false;
	}
	dt;
}

void Control::drawIntro(Core::Graphics& g)
{
	pauseSyst.draw(g);
	instructs.draw(g, 0);
	if(!introDraw)
	{
		introRunning= false;
	}
}
void Control::updateIntro(float dt)
{
	pauseSyst.update(dt);
	if( Core::Input::IsPressed( Core::Input::BUTTON_SPACE ) )
		{
			introDraw = false;
		}
}

void Control::drawSplash(Core::Graphics& g)
{
	g.SetColor(RGB(255,255,255));
	g.DrawString(415, 515, "PRESS ENTER TO BEGIN");

	if(!splashDraw)
	{
		splashRunning = false;
		/*PlaySound(NULL,0,0);*/
		introRunning = true;
		introDraw = true;
		pauseSyst.addNewEffect(new OpeningSplash2(Vector3D(1,0),(RGB(0,0,0)),2000));
	}
	particleSyst.draw(g);
}

void Control::updateSplash(float dt)	
{
	if( Core::Input::IsPressed( Core::Input::BUTTON_ENTER ) )
	{
		splashDraw = false;
	}
	dt;
	particleSyst.update(dt);
}

void Control::draw(Core::Graphics& g)
{
	if(splashRunning)
	{
		drawSplash(g);
	}
	else if(introRunning)
	{
		drawIntro(g);
	}
	else if(pauseDraw)
	{
		drawPause(g);
	}
	else
	{
		g.SetBackgroundColor(RGB(0,0,10));
		timer.Start();
		profiler.addEntry("Instructions Draw", timer.Interval());
		ge1.draw(g);
		ge2.draw(g);
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
	}
}

void Control::update(float dt)
{
	if(splashRunning)
	{
		updateSplash(dt);
	}
	else if(introRunning)
	{
		updateIntro(dt);
	}
	else if (paused)
	{
		updatePause(dt);
	}
	else
	{
		profiler.newFrame();
		timer.Start();
		if(Core::Input::IsPressed('P'))
		{
			paused = true;
		}
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
		ge1.update(dt);
		ge2.update(dt);
		profiler.addEntry("Gear System Update", timer.Interval());
		lerp.update(dt);
		particleSyst.addNewEffect(new LerperTrainEffect(lerp.position,1));
		profiler.addEntry("Lerper Update", timer.Interval());
		particleSyst.update(dt);
		profiler.addEntry("ParticleSystem Update", timer.Interval());
		timer.Stop();
		if(grid.update(ship.position, dt))
		{
			if(grid.collisionDirection==0)
			{
				particleSyst.addNewEffect(new CollideWallEffect(ship.position,RGB(255,255,255),50,&grid));
				ship.position.y+=2;
				ship.reverseYVelocity();
			}
			else if(grid.collisionDirection==1)
			{
				particleSyst.addNewEffect(new CollideWallEffect(ship.position,RGB(255,255,255),50,&grid));
				ship.position.y-=2;
				ship.reverseYVelocity();
			}
			if(grid.collisionDirection==2)
			{
				particleSyst.addNewEffect(new CollideWallEffect(ship.position,RGB(255,255,255),50,&grid));
				ship.position.x+=2;
				ship.reverseXVelocity();
			}
			else if(grid.collisionDirection==3)
			{
				particleSyst.addNewEffect(new CollideWallEffect(ship.position,RGB(255,255,255),50,&grid));
				ship.position.x-=2;
				ship.reverseXVelocity();
			}
		}
		collisionCheck();
	}
}
//void Control::playMusic()
//{
//	if(!musicPlaying)
//	{
//		musicTimer.Start();
//		PlaySound(TEXT("HourChime.wav"),NULL, SND_FILENAME | SND_ASYNC );
//		musicPlaying = true;
//	}
//	if(musicPlaying&&musicTimer.getElapsedTime()>90)
//	{
//
//	}
//}