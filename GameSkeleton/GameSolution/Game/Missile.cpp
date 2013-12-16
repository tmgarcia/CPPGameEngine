#include "Missile.h"

Vector3D missilePoints[] = 
{
	Vector3D(0.0f, -5.0f),
	Vector3D(3.5f, -3.5f),
	Vector3D(5.0f, 0.0f),
	Vector3D(3.5f, 3.5f),
	Vector3D(0.0f, 5.0f),
	Vector3D(-3.5f, 3.5f),
	Vector3D(-5.0f, 0.0f),
	Vector3D(-3.5f, -3.5f),
};
Vector3D whitePoints[] = 
{
	Vector3D(-2.0f, -3.0f),
	Vector3D(-1.3f, -2.1f),
	Vector3D(-1.0f, 0.0f),
	Vector3D(-1.3f, 2.1f),
	Vector3D(-2.0f, 3.0f),
	Vector3D(-2.7f, 2.1f),
	Vector3D(-3.0f, -0.0f),
	Vector3D(-2.7f, -2.1f),
};
const unsigned int NUM_POINTS = sizeof(missilePoints) / sizeof(missilePoints[0]);

void Missile::draw(Core::Graphics& g)
{
	if(firing)
	{
		g.SetColor(RGB(100, 100, 200));
		const Matrix3D transform = translate(position.x, position.y) * orientation;
		for(unsigned int i = 0; i< NUM_POINTS; i++)
		{
			const Vector3D& p1 = transform * missilePoints[i];
			const Vector3D& p2 = transform * missilePoints [(i+1) % NUM_POINTS];
			g.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}

		g.SetColor(RGB(255, 255, 255));
		for(unsigned int i = 0; i< NUM_POINTS; i++)
		{
			const Vector3D& p1 = transform * whitePoints[i];
			const Vector3D& p2 = transform * whitePoints [(i+1) % NUM_POINTS];
			g.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}

bool Missile::update(float dt)
{
	if(firing)
	{
		float fireVelocity = 200;
		Vector3D acc = Vector3D(fireVelocity, 0, 0);
		Vector3D dir = (orientation * acc).perpCCW();
		position = position + (dt * dir);

		if(position.x <0 || position.x > SCREEN_WIDTH || position.y <0 || position.y > SCREEN_HEIGHT)
			firing = false;
	}
	return firing;
}