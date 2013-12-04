#include "SpaceShip.h"
#include "Matrix3D.h"


Vector3D* shipPoints[] = 
{
	new Vector3D(0.0f, -24.0f),
	new Vector3D(10.0f, -20.0f),
	new Vector3D(12.0f, -10.0f),
	new Vector3D(17.0f, -10.0f),
	new Vector3D(22.0f, -6.0f),
	new Vector3D(22.0f, 1.0f),
	new Vector3D(17.0f, 6.0f),
	new Vector3D(15.0f, 12.0f),
	new Vector3D(16.0f, 18.0f),
	new Vector3D(13.0f, 23.0f),
	new Vector3D(6.0f, 23.0f),
	new Vector3D(0.0f, 20.0f),
	new Vector3D(-6.0f, 23.0f),
	new Vector3D(-13.0f, 23.0f),
	new Vector3D(-16.0f, 18.0f),
	new Vector3D(-15.0f, 12.0f),
	new Vector3D(-17.0f, 6.0f),
	new Vector3D(-22.0f, 1.0f),
	new Vector3D(-22.0f, -6.0f),
	new Vector3D(-17.0f, -10.0f),
	new Vector3D(-12.0f, -10.0f),
	new Vector3D(-10.0f, -20.0f),
};

Vector3D* shellPoints[] = 
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


void SpaceShip::draw(Core::Graphics& g)
{
	//Drawing the Ship
	g.SetColor(RGB(255, 255, 255));
	const unsigned int NUM_POINTS = sizeof(shipPoints) / sizeof(*shipPoints);
	const Matrix3D transform = translate(position.x, position.y) * rotate(orientation);
	for(unsigned int i = 0; i< NUM_POINTS; i++)
	{
		const Vector3D& p1 = transform * *shipPoints[i];
		const Vector3D& p2 = transform * *shipPoints [(i+1) % NUM_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
	g.SetColor(RGB(0, 250, 250));
	const unsigned int NUM_SH_POINTS = sizeof(shellPoints) / sizeof(*shellPoints);
	for(unsigned int i = 0; i< NUM_SH_POINTS; i++)
	{
		const Vector3D& p1 = transform * *shellPoints[i];
		const Vector3D& p2 = transform * *shellPoints [(i+1) % NUM_SH_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}

	gun.draw(g, position);

	ammo->draw(g);
}

//SpaceShip update
void SpaceShip::update(float dt)
{
	//Missile shooting
	if(Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		ammo->addMissile(new Missile(gun.tip, gun.turnTurret));
	}

	ammo->update(dt);

	//Rotate right
	if(Core::Input::IsPressed('D'))
	{
		orientation += .05f;
	}

	//Rotate left
	if(Core::Input::IsPressed('A'))
	{
		orientation -= .05f;
	}

	//WASD movement controls
	float velocityScale = 50;
	Vector3D acc = Vector3D(0, velocityScale, 0);
	Vector3D dir = rotate(orientation)*acc;
	if(Core::Input::IsPressed('S'))
	{
		velocity = velocity + dt*dir;
	}
	if(Core::Input::IsPressed('W'))
	{
		velocity = velocity - dt*dir;
	}
	position = position + velocity * dt;
}

void SpaceShip::resetPosition(Vector3D newPosition)
{
	position = newPosition;
}
Vector3D SpaceShip::getPosition()
{
	return position;
}
void SpaceShip::bounceOffWall(Vector3D collidedNormal)
{
	Vector3D projectedVector = velocity.projectOnto(collidedNormal);
	velocity = velocity+(-2*projectedVector);
}
void SpaceShip::reverseXVelocity()
{
	velocity.x *= -1;
}
void SpaceShip::reverseYVelocity()
{
	velocity.y *= -1;
}
void SpaceShip::wrap()
{
	if(position.x <0-32)
		position.x = SCREEN_WIDTH+16;
	if(position.x > SCREEN_WIDTH+16)
		position.x  = 0-16;
	if(position.y <0-32)
		position.y = SCREEN_HEIGHT+32;
	if(position.y > SCREEN_HEIGHT+32)
		position.y = 0-32;
}