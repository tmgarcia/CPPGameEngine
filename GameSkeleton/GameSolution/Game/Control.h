#pragma once
#include "Vector2D.h"
#include "Vector3D.h"
#include "Core.h"
#include "Missile.h"
#include "Turret.h"
#include "Lerper.h"
#include "GearSystem.h"
#include "ScreenInfo.h"
#include "Walls.h"
#include "Instructions.h"
#include "ParticleSystem.h"
#include "BinaryWaveEffect.h"
#include "BubbleEffect.h"
#include "SpaceShip.h"


class Control
{
public:
	Walls wall;
	Instructions instructs;
	ParticleSystem particleSyst;
	Lerper lerp;
	SpaceShip ship;
	int collisionType; //1=bouncing, 2=walls, 3=wrapping
	void draw(Core::Graphics& g);
	void update(float dt);
	Control(){ship.position=Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2); collisionType=1;}
};

