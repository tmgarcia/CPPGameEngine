#include "Missile.h"



Vector3D* missilePoints[] = 
{
	new Vector3D(0,0),
	new Vector3D(0, 10),
};
void Missile::draw(Core::Graphics& g)
{
	if(firing)
	{
		const unsigned int NUM_POINTS = sizeof(missilePoints) / sizeof(*missilePoints);
		const Matrix3D transform = translate(position.x, position.y) * orientation;
		for(unsigned int i = 0; i< NUM_POINTS; i++)
		{
			const Vector3D& p1 = transform * *missilePoints[i];
			const Vector3D& p2 = transform * *missilePoints [(i+1) % NUM_POINTS];
			g.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}

void Missile::update(float dt)
{
	if(firing)
	{
		float fireVelocity = 50;
		Vector3D acc = Vector3D(fireVelocity, 0, 0);
		Vector3D dir = (orientation * acc).perpCCW();
		position = position + (dt * dir);

		if(position.x <0 || position.x > SCREEN_WIDTH || position.y <0 || position.y > SCREEN_HEIGHT)
			firing = false;
	}
}