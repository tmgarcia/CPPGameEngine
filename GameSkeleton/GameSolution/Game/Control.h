#pragma once
#include "Vector3D.h"
#include "Core.h"
#include "Lerper.h"
#include "GearSystem.h"
#include "ScreenInfo.h"
#include "Walls.h"
#include "Instructions.h"
#include "ParticleSystem.h"
#include "BinaryWaveEffect.h"
#include "BubbleEffect.h"
#include "OpeningSplash.h"
#include "SpaceShip.h"
#include "Profiler.h"
#include "Timer.h"
#include "EnemyLegion.h"
#include "MissileAmmo.h"
#include "ExplosionEffect.h"
#include "LerperTrainEffect.h"
#include "Grid.h"
#include "Random.h"
#include "CollideWallEffect.h"
#include "windows.h"
#include "mmsystem.h"
#include "playsoundapi.h"

class Control
{
	void drawSplash(Core::Graphics& g);
	void updateSplash(float dt);
public:
	Walls wall;
	Instructions instructs;
	ParticleSystem particleSyst;
	Lerper lerp;
	CStopWatch timer;
	CStopWatch enemyTimer;
	CStopWatch musicTimer;
	void Control::collisionCheck();
	Random generator;
	bool splashRunning;
	bool splashDraw;
	bool musicPlaying;
	int collisionType; //1=bouncing, 2=walls, 3=wrapping
	void fillGrid();
	void draw(Core::Graphics& g);
	void update(float dt);
	void playMusic();
	Control()
	{
		musicPlaying = false;
		collisionType=1; 
		splashRunning = true; 
		splashDraw = true;
		particleSyst.addNewEffect(new OpeningSplash(Vector3D(1,0), RGB(20,20,200), 2500));
		fillGrid();
		//PlaySound(TEXT("HourChime.wav"),NULL, SND_FILENAME | SND_ASYNC );
	}
};

