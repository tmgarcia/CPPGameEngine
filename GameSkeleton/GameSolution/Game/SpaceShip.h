#pragma once
#include "Vector2D.h"
#include "Vector3D.h"
#include "Core.h"
#include "Missile.h"
#include "Turret.h"


class SpaceShip
{
public:
	SpaceShip() {missilesLaunched = 0;}
	Vector3D position;
	Vector3D velocity;
	Missile* missiles[50];
	Turret gun;
	float missilesLaunched;
	float orientation;
	void draw(Core::Graphics&);
	void update(float dt);
	void resetPosition(Vector3D newPosition);
	Vector3D getPosition();
	void bounceOffWall(Vector3D collidedNormal);
	void reverseXVelocity();
	void reverseYVelocity();
	void wrap();
};