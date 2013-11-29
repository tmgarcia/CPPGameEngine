#pragma once
#include "Vector2D.h"
#include "Vector3D.h"
#include "Core.h"
#include "Missile.h"
#include "Turret.h"
#include "MissileAmmo.h"


class SpaceShip
{
public:
	SpaceShip(MissileAmmo* ammo, Vector3D start) {this->ammo = ammo; position = start;}
	Vector3D position;
	Vector3D velocity;
	MissileAmmo* ammo;
	Turret gun;
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