#ifndef Engine_Spaceship_H
#define Engine Spaceship_H
#include "Vector2D.h"
#include "Core.h"

class SpaceShip
{
public:
	SpaceShip(bool bouncing = true) : bouncing(bouncing) {}
	Vector2D position;
	Vector2D velocity;
	bool bouncing;
	bool wrapping;
	bool walls;
	void draw(Core::Graphics&);
	void update(float dt);
};



#endif