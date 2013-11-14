#include "SpaceShip.h"
#include "Matrix3D.h"


//Ship's shape
Vector3D* shipPoints[] =
{
	new Vector3D(16.0f, 32.0f),
	new Vector3D(16.0f, -20.0f),
	new Vector3D(12.0f, -20.0f),
	new Vector3D(12.0f, -28.0f),
	new Vector3D(2.0f, -28.0f),
	new Vector3D(2.0f, -32.0f),
	new Vector3D(-2.0f, -32.0f),
	new Vector3D(-2.0f, -28.0f),
	new Vector3D(-12.0f, -28.0f),
	new Vector3D(-12.0f, -20.0f),
	new Vector3D(-16.0f, -20.0f),
	new Vector3D(-16.0f, 32.0f),
};

//Wall's shape
Vector3D* meWall[] = 
{
	//Diamond
	new Vector3D(400, 50, 0),
	new Vector3D(750, 300, 0),
	new Vector3D(400, 550, 0),
	new Vector3D(50, 300, 0),
};

//Lerper's lerping direction
Vector3D* lerpPoints[] = 
{
	new Vector3D(100.0f, 100.0f),
	new Vector3D(700.0f, 100.0f),
	new Vector3D(700.0f, 500.0f),
	new Vector3D(100.0f, 500.0f),
};

//Lerper's shape
Vector3D* lerperPoints[] = 
{
	new Vector3D(0.0f, 0.0f),
	new Vector3D(25.0f, 0.0f),
	new Vector3D(25.0f, 25.0f),
	new Vector3D(0.0f, 25.0f),
};

//Lerper pathing
Vector3D lerperPosition = *lerpPoints[0];
unsigned int sourceLerpPoint = 0;
unsigned int destinationLerpPoint = 1;
float alpha = 0.0f;
const unsigned int NUM_LERP_POINTS = sizeof(lerpPoints) / sizeof(*lerpPoints);
void lerpTheLerper(float dt)
{
	lerperPosition = LERP(*lerpPoints[sourceLerpPoint], *lerpPoints[destinationLerpPoint], alpha);
	alpha += dt;
	if(alpha>=1)
	{
		alpha = 0.0f;
		sourceLerpPoint = destinationLerpPoint;
		destinationLerpPoint = (destinationLerpPoint+1) % NUM_LERP_POINTS;
	}
}

GearSystem ge = GearSystem(Vector3D(300, 300, 1));

//DRAW
void SpaceShip::draw(Core::Graphics& g)
{
	g.SetBackgroundColor(RGB(25,25,25));

	//On-screen instructions
	g.SetColor(RGB(150, 150, 150));
	g.DrawString(50, 50, "Instructions");
	g.DrawString(60, 65, "Movement:");
	g.DrawString(90, 75, "^");
	g.DrawString(90, 82, "|");
	g.DrawString(85, 90, "[W]");
	g.DrawString(57, 100, "<-[A] [D]->");
	g.DrawString(85, 110, "[S]");
	g.DrawString(90, 122, "|");
	g.DrawString(90, 130, "v");
	g.DrawString(50, 140, "[<-] Rotate left");
	g.DrawString(50, 150, "[->] Rotate right");
	g.DrawString(150, 50, "[1] Toggle Bouncing");
	g.DrawString(150, 65, "[2] Toggle Wrapping");
	g.DrawString(150, 80, "[3] Toggle Walls");

	//Drawing the Ship
	g.SetColor(RGB(100, 100, 255));
	const unsigned int NUM_POINTS = sizeof(shipPoints) / sizeof(*shipPoints);
	const Matrix3D transform = translate(position.x, position.y) * rotate(orientation);
	for(unsigned int i = 0; i< NUM_POINTS; i++)
	{
		const Vector3D& p1 = transform * *shipPoints[i];
		const Vector3D& p2 = transform * *shipPoints [(i+1) % NUM_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}

	gun.draw(g, position);

	//Drawing the walls
	if(walls)
	{
		g.SetColor(RGB(255, 100, 255));
		const unsigned int NUM_WALL_POINTS = sizeof(meWall) / sizeof(*meWall);
		for(unsigned int i = 0; i< NUM_WALL_POINTS; i++)
		{
			const Vector3D& w1 = *meWall[i];
			const Vector3D& w2 = *meWall [(i+1) % NUM_WALL_POINTS];
			g.DrawLine(w1.x, w1.y, w2.x, w2.y);
		}
	}
	//Drawing the lerper
	g.SetColor(RGB(255, 255, 100));
	const unsigned int NUM_LERPER_POINTS = sizeof(lerperPoints) / sizeof(*lerperPoints);
	for(unsigned int i = 0; i< NUM_LERPER_POINTS; i++)
	{
		const Vector3D& l1 = lerperPosition + *lerperPoints[i];
		const Vector3D& l2 = lerperPosition + *lerperPoints[(i+1) % NUM_LERPER_POINTS];
		g.DrawLine(l1.x, l1.y, l2.x, l2.y);
	}

	if(missilesLaunched>0)
	{
		for(int i = 0; i < (int)missilesLaunched; i++)
		{
			(*missiles[i]).draw(g);
		}
	}
	ge.draw(g);
}

//SpaceShip update
void SpaceShip::update(float dt)
{
	ge.update(dt);
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
	}
	if(Core::Input::IsPressed('2'))
	{
		bouncing = false;
		wrapping = true;
		walls = false;
		position = Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	}
	if(Core::Input::IsPressed('3'))
	{
		bouncing = false;
		wrapping = false;
		walls = true;
		position = Vector3D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
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
	}
	position = position + velocity * dt;

	//Collision with walls
	if(walls)
	{
		const unsigned int NUM_WALLPOINTS = sizeof(meWall) / sizeof(*meWall);
		for(unsigned int i = 0; i< NUM_WALLPOINTS; i++)
		{
			Vector3D wallVertexOne = *meWall[i];
			Vector3D wallToShip = position - wallVertexOne;
			Vector3D wallVertexTwo = *meWall[(i+1) % NUM_WALLPOINTS];
			Vector3D wall = wallVertexTwo - wallVertexOne;
			Vector3D wallNormal = wall.perpCW();
			float dotResult = dot(wallToShip, wallNormal);
			if(dotResult<0)
			{
				Vector3D normalizedNormal = wallNormal.normalized();
				Vector3D projectedVector = velocity.projectOnto(normalizedNormal);
				velocity = velocity+(-2*projectedVector);
			}
		}
	}

	//Collision with screen
	if(bouncing)
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
	lerpTheLerper(dt);


}