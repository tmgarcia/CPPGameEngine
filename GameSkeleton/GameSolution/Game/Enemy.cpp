#include "Enemy.h"

Vector3D* enemyPoints[] = 
{
	new Vector3D(0.0f, -14.0f),
	new Vector3D(12.0f, -10.0f),
	new Vector3D(17.0f, 2.0f),
	new Vector3D(12.0f, 16.0f),
	new Vector3D(0.0f, 20.0f),
	new Vector3D(-12.0f, 16.0f),
	new Vector3D(-17.0f, 2.0f),
	new Vector3D(-12.0f, -10.0f),
};

void Enemy::createEnemy()
{
	//assignedGear = generator.randomRangedInt(0, (gears->getNumGears()-1));
	assignedGear = 3;
}

void Enemy::draw(Core::Graphics& g, Vector3D shipPosition)
{
	g.SetColor(RGB(255,100,100));
	const unsigned int NUM_E_POINTS = sizeof(enemyPoints) / sizeof(*enemyPoints);
	//Vector3D targetPosition = gears->getIndexedGearPosition(assignedGear);
	//Vector3D ptm = targetPosition-position;
	Vector3D ptm = shipPosition-position;
	Vector3D bmt = ptm.normalized(); //b
	Vector3D bmtperp = bmt.perpCCW(); //a
	rotation = Matrix3D(bmtperp.x, bmt.x, 0.0f, bmtperp.y, bmt.y, 0.0f, 0.0f, 0.0f, 1.0f);
	Matrix3D transform = translate(position.x, position.y) * rotation;
	for(unsigned int i = 0; i<NUM_E_POINTS; i++)
	{
		const Vector3D& t1 = transform * *enemyPoints[i];
		const Vector3D& t2 = transform * *enemyPoints[(i+1) % NUM_E_POINTS];
		g.DrawLine(t1.x, t1.y, t2.x, t2.y);
	}
}

void Enemy::update(float dt)
{
	float velocityScale = 100;
	Vector3D acc = Vector3D(0, velocityScale, 0);
	Vector3D dir = rotation*acc;
	position = position + dir * dt;
}