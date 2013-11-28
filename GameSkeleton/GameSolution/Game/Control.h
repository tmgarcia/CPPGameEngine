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
#include "SpaceShip.h"
#include "Profiler.h"
#include "Timer.h"


class Control
{
public:
	Walls wall;
	Instructions instructs;
	ParticleSystem particleSyst;
	Lerper lerp;
	SpaceShip ship;
	CStopWatch timer;
	int collisionType; //1=bouncing, 2=walls, 3=wrapping
	void draw(Core::Graphics& g);
	void update(float dt);
	Control(){ship.position=Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2); collisionType=1;}
};

