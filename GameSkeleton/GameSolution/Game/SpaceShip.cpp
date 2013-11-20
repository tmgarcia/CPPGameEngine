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


GearSystem ge = GearSystem(Vector3D(500, 500, 1));

//DRAW
void SpaceShip::draw(Core::Graphics& g)
{
	g.SetBackgroundColor(RGB(25,25,30));
	i.draw(g);
	//Drawing the Ship
	g.SetColor(RGB(100, 255, 100));
	const unsigned int NUM_POINTS = sizeof(shipPoints) / sizeof(*shipPoints);
	const Matrix3D transform = translate(position.x, position.y) * rotate(orientation);
	for(unsigned int i = 0; i< NUM_POINTS; i++)
	{
		const Vector3D& p1 = transform * *shipPoints[i];
		const Vector3D& p2 = transform * *shipPoints [(i+1) % NUM_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
	g.SetColor(RGB(50, 150, 50));
	const unsigned int NUM_SH_POINTS = sizeof(shellPoints) / sizeof(*shellPoints);
	for(unsigned int i = 0; i< NUM_SH_POINTS; i++)
	{
		const Vector3D& p1 = transform * *shellPoints[i];
		const Vector3D& p2 = transform * *shellPoints [(i+1) % NUM_SH_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}


	lerp.draw(g);
	gun.draw(g, position);
	ge.draw(g);
	ps.draw(g);

	if(walls)
		wall.draw(g);
	if(missilesLaunched>0)
	{
		for(int i = 0; i < (int)missilesLaunched; i++)
		{
			(*missiles[i]).draw(g);
		}
	}
}

//SpaceShip update
void SpaceShip::update(float dt)
{
	//Missile shooting
	if(Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		if(missilesLaunched<20)
		{
			missiles[(int)missilesLaunched] = new Missile(gun.tip, gun.turnTurret);
			missilesLaunched++;
		}
	}
	if(missilesLaunched>0)
	{
		for(int i = 0; i < (int)missilesLaunched; i++)
		{
			(*missiles[i]).update(dt);
		}
	}

	//Switching between wrapping bouncing and the wall
	if(Core::Input::IsPressed('1'))
	{
		bouncing = true;
		wrapping = false;
		walls = false;
		position = Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
		ps.addNewEffect(Vector3D(0,1),RGB(100,100,255),100,3, orientation);
	}
	if(Core::Input::IsPressed('2'))
	{
		bouncing = false;
		wrapping = true;
		walls = false;
		position = Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
		ps.addNewEffect(Vector3D(0,1),RGB(100,100,255),100,3, orientation);
	}
	if(Core::Input::IsPressed('3'))
	{
		bouncing = false;
		wrapping = false;
		walls = true;
		position = Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
		ps.addNewEffect(Vector3D(0,1),RGB(100,100,255),100,3, orientation);
	}

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
		ps.addNewEffect(position,RGB(100,100,255),1,2, orientation);
	}
	position = position + velocity * dt;

	//Wall collision
	if(walls)
	{
		if(wall.collided(position))
		{
			Vector3D projectedVector = velocity.projectOnto(wall.collidedNormal);
			velocity = velocity+(-2*projectedVector);
		}
	}
	//Collision with screen
	else if(bouncing)
	{
		if(position.x <0)
			velocity.x *= -1;
		if(position.x > SCREEN_WIDTH)
			velocity.x *= -1;
		if(position.y <0)
			velocity.y *= -1;
		if(position.y > SCREEN_HEIGHT)
			velocity.y *= -1;
	}
	//Wrap from one side of the screen to the other
	else
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
	ge.update(dt);
	lerp.update(dt);
	ps.update(dt);
}