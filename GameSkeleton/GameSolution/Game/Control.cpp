#include "Control.h"

GearSystem ge1 = GearSystem(Vector3D(200, 200, 1));
GearSystem ge2 = GearSystem(Vector3D(400, 400, 1));

Grid grid = Grid(RGB(0,200,200),10,10);


MissileAmmo ammo(&grid);
SpaceShip ship = SpaceShip(&ammo, Vector3D((float)SCREEN_WIDTH-50, (float)SCREEN_HEIGHT-50));


void Control::drawRunError(Core::Graphics& g)
{
	g.SetBackgroundColor(RGB(0,0,255));
	g.SetColor(RGB(255,255,255));
	g.DrawString(400,300,"RUNTIME_ERROR");
	g.DrawString(400,315,"AGENT_DEBUGGER:TERMINATED");
}
void Control::updateRunError(float dt)
{
	dt;
}

void Control::drawCompiled(Core::Graphics& g)
{

	if(compiledErrors)
	{
		g.SetBackgroundColor(RGB(0,0,255));
		g.SetColor(RGB(255,255,255));
		g.DrawString(400,300,"COMPILER_ERROR");
		g.DrawString(400,315,"MISSION FAILED");
	}
	else
	{
		g.DrawString(300,385, "CODE DEBUGGED AND COMPILED SUCCESSFULLY");
		g.SetColor(RGB(255,255,255));
		string tStr = std::to_string((int)endTime);
		string tLabel = "Total Time: " + tStr + " seconds";
		char *ttstr = &tLabel[0];
		g.DrawString(300,400, ttstr);
	}

}

void Control::updateCompiled(float dt)
{
	dt;
}

void Control::fillGrid()
{
	unsigned int numEnemies = 10;
	for(unsigned int i = 0; i<numEnemies; i++)
	{
		bool foundGoodLocation = false;
		int iv=0;
		int jv=0;
		while(!foundGoodLocation)
		{
			iv= (int)generator.randomIntRange(1,9);
			jv = (int)generator.randomIntRange(1,9);
			if(!(iv==9&&jv==0) && !(iv==9&&jv==9))
				foundGoodLocation = true;
		}
		grid.addEnemyAt(iv, jv);
	}
}

void Control::collisionCheck()
{
	for(unsigned int i=0; i < ammo.numActiveMissiles; i++)
	{
		if(grid.enemyCollisionCheck(ammo.getMissilePosition(i), 1, 5))
		{
			particleSyst.addNewEffect( new ExplosionEffect(grid.collidedEnemy,RGB(100,20,20),50));
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
	g.SetBackgroundColor(RGB(20,20,100));
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
	else if(compiled || compiledErrors)
	{
		drawCompiled(g);
	}
	else if(playerDead)
	{
		drawRunError(g);
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
		compiled =  grid.playerCompile;
		compiledErrors = grid.playerCompileErrors;
		if(compiled || compiledErrors)
			endTime = gamePlayTimer.Stop();
		if(ship.dead)
			playerDead = true;
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
	else if(compiled || compiledErrors)
	{
		updateCompiled(dt);
	}
	else if(playerDead)
	{
		updateRunError(dt);
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
		if(grid.enemyCollisionCheck(ship.position, 0, 16))
			ship.loseHealth(1);
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