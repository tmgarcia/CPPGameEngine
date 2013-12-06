#include "Enemy.h"

//Vector3D* enemyPoints[] = 
//{
//	new Vector3D(0.0f, -14.0f),
//	new Vector3D(12.0f, -10.0f),
//
//	new Vector3D(17.0f, 2.0f),
//	new Vector3D(12.0f, 16.0f),
//
//	new Vector3D(0.0f, 20.0f),
//	new Vector3D(-12.0f, 16.0f),
//
//	new Vector3D(-17.0f, 2.0f),
//	new Vector3D(-12.0f, -10.0f),
//};

Vector3D* enemyPoints[] = 
{
	new Vector3D(-10, -15),
	new Vector3D(10, -15),
	new Vector3D(10, 15),
	new Vector3D(-10, 15),
};


void Enemy::draw(Core::Graphics& g, Vector3D shipPosition)
{
	g.SetColor(RGB(200,50,50));
	g.DrawString((int)position.x-3, (int)position.y-5, "E");
	const unsigned int NUM_E_POINTS = sizeof(enemyPoints) / sizeof(*enemyPoints);
	Matrix3D rotator1 = rotate(orientation1);
	Matrix3D transform1 = translate(position.x, position.y) * rotator1;
	for(unsigned int i = 0; i<NUM_E_POINTS; i++)
	{
		const Vector3D& t1 = transform1 * *enemyPoints[i];
		const Vector3D& t2 = transform1 * *enemyPoints[(i+1) % NUM_E_POINTS];
		g.DrawLine(t1.x, t1.y, t2.x, t2.y);
	}

	Matrix3D rotator2 = rotate(orientation2);
	Matrix3D transform2 = translate(position.x, position.y) * rotator2;
	for(unsigned int i = 0; i<NUM_E_POINTS; i++)
	{
		const Vector3D& t1 = transform2 * *enemyPoints[i];
		const Vector3D& t2 = transform2 * *enemyPoints[(i+1) % NUM_E_POINTS];
		g.DrawLine(t1.x, t1.y, t2.x, t2.y);
	}

	Matrix3D transform3 = translate(position.x, position.y) * rotator1 * scale(0.4f,0.4f);
	for(unsigned int i = 0; i<NUM_E_POINTS; i++)
	{
		const Vector3D& t1 = transform3 * *enemyPoints[i];
		const Vector3D& t2 = transform3 * *enemyPoints[(i+1) % NUM_E_POINTS];
		g.DrawLine(t1.x, t1.y, t2.x, t2.y);
	}

	Matrix3D transform4 = translate(position.x, position.y) * rotator2 * scale(0.4f,0.4f);
	for(unsigned int i = 0; i<NUM_E_POINTS; i++)
	{
		const Vector3D& t1 = transform4 * *enemyPoints[i];
		const Vector3D& t2 = transform4 * *enemyPoints[(i+1) % NUM_E_POINTS];
		g.DrawLine(t1.x, t1.y, t2.x, t2.y);
	}

	shipPosition;
	//g.SetColor(RGB(255,100,100));
	//const unsigned int NUM_E_POINTS = sizeof(enemyPoints) / sizeof(*enemyPoints);
	//Vector3D ptm = shipPosition-position;
	//Vector3D bmt = ptm.normalized(); //b
	//Vector3D bmtperp = bmt.perpCCW(); //a
	//rotation = Matrix3D(bmtperp.x, bmt.x, 0.0f, bmtperp.y, bmt.y, 0.0f, 0.0f, 0.0f, 1.0f);
	//Matrix3D transform = translate(position.x, position.y) * rotation;
	//for(unsigned int i = 0; i<NUM_E_POINTS; i++)
	//{
	//	const Vector3D& t1 = transform * *enemyPoints[i];
	//	const Vector3D& t2 = transform * *enemyPoints[(i+1) % NUM_E_POINTS];
	//	g.DrawLine(t1.x, t1.y, t2.x, t2.y);
	//}
}

void Enemy::update(float dt)
{
	orientation1 +=4*dt;
	orientation2 -=4*dt;
	/*float velocityScale = 100;
	Vector3D acc = Vector3D(0, velocityScale, 0);
	Vector3D dir = rotation*acc;
	position = position + dir * dt;*/
}