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
const unsigned int NUM_POINTS = sizeof(shipPoints) / sizeof(*shipPoints);

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
const unsigned int NUM_SH_POINTS = sizeof(shellPoints) / sizeof(*shellPoints);

Vector3D* arrowHead[] =
{
	new Vector3D(-10, -15),
	new Vector3D(-10, -30),
	new Vector3D(-20, -30),
	new Vector3D(0, -40),
	new Vector3D(20, -30),
	new Vector3D(10, -30),
	new Vector3D(10, -15),
};
const unsigned int NUM_A_POINTS = sizeof(arrowHead) / sizeof(*arrowHead);

void SpaceShip::clear()
{
	for(int i = 0; i < NUM_POINTS; i++)
	{
		delete shipPoints[i];
	}

	for(int i = 0; i < NUM_SH_POINTS; i++)
	{
		delete shellPoints[i];
	}
	for(int i = 0; i < NUM_A_POINTS; i++)
	{
		delete arrowHead[i];
	}
}

void SpaceShip::draw(Core::Graphics& g)
{
	//Drawing the Ship
	const Matrix3D transform = translate(position.x, position.y) * rotate(orientation);


	g.SetColor(RGB(50,50,50));
	for(unsigned int i = 0; i< NUM_A_POINTS; i++)
	{
		const Vector3D& p1 = transform * *arrowHead[i];
		const Vector3D& p2 = transform * *arrowHead [(i+1) % NUM_A_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
	float green = (health/fullHealth)*255;
	g.SetColor(RGB(255, green, green));
	for(unsigned int i = 0; i< NUM_POINTS; i++)
	{
		const Vector3D& p1 = transform * *shipPoints[i];
		const Vector3D& p2 = transform * *shipPoints [(i+1) % NUM_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
	g.SetColor(RGB(0, 250, 250));
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
	float velocityScale =60;
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
	if(velocity.x>100)
		velocity.x=100;
	if(velocity.x<-100)
		velocity.x=-100;
	if(velocity.y>100)
		velocity.y=100;
	if(velocity.y<-100)
		velocity.y=-100;
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
	velocity.x *= -.5f;
}
void SpaceShip::reverseYVelocity()
{
	velocity.y *= -.5f;
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

void SpaceShip::loseHealth(float damage)
{
	health-=damage;
	if(health<=0)
		dead = true;
}
