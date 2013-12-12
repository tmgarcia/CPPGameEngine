#pragma once
#include "Vector2D.h"
#include "Vector3D.h"
#include "Core.h"
#include "Missile.h"
#include "Turret.h"
#include "MissileAmmo.h"
#include "DebugMemory.h"

class SpaceShip
{
public:
	SpaceShip(MissileAmmo* ammo, Vector3D start) {this->ammo = ammo; position = start; fullHealth = 100; health = fullHealth; dead = false;}
	~SpaceShip(){clear();}
	void clear();
	Vector3D position;
	Vector3D velocity;
	MissileAmmo* ammo;
	Turret gun;
	float orientation;
	float health;
	float fullHealth;
	bool dead;
	void draw(Core::Graphics&);
	void update(float dt);
	void resetPosition(Vector3D newPosition);
	Vector3D getPosition();
	void bounceOffWall(Vector3D collidedNormal);
	void loseHealth(float damage);
	void reverseXVelocity();
	void reverseYVelocity();
	void wrap();
};