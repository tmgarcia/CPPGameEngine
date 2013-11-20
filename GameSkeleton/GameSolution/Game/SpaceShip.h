#ifndef Engine_Spaceship_H
#define Engine Spaceship_H
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

class SpaceShip
{
public:
	SpaceShip(bool walls = true) : walls(walls){missilesLaunched = 0; }
	Vector3D position;
	Vector3D velocity;
	Missile* missiles[50];
	Turret gun;
	Lerper lerp;
	Walls wall;
	Instructions i;
	ParticleSystem ps;
	float missilesLaunched;
	float orientation;
	bool bouncing;
	bool wrapping;
	bool walls;
	void draw(Core::Graphics&);
	void update(float dt);

};



#endif