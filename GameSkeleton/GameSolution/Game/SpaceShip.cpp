#include "SpaceShip.h"



//Vectors that make up the ship's shape
Vector2D* shipPoints[] =
{
	new Vector2D(16.0f, 32.0f),
	new Vector2D(16.0f, -20.0f),
	new Vector2D(12.0f, -20.0f),
	new Vector2D(12.0f, -28.0f),
	new Vector2D(2.0f, -28.0f),
	new Vector2D(2.0f, -32.0f),
	new Vector2D(-2.0f, -32.0f),
	new Vector2D(-2.0f, -28.0f),
	new Vector2D(-12.0f, -28.0f),
	new Vector2D(-12.0f, -20.0f),
	new Vector2D(-16.0f, -20.0f),
	new Vector2D(-16.0f, 32.0f),
};

//Arbitrary wall points (to be changed & added to)
Vector2D* meWall[] = 
{
	//T Shape
	/*new Vector2D(100.0f, 50.0f),
	new Vector2D(700.0f, 50.0f),
	new Vector2D(700.0f, 200.0f),
	new Vector2D(500.0f, 200.0f),
	new Vector2D(500.0f, 550.0f),
	new Vector2D(300.0f, 550.0f),
	new Vector2D(300.0f, 200.0f),
	new Vector2D(100.0f, 200.0f),*/

	//Square
	/*new Vector2D(100, 100),
	new Vector2D(700, 100),
	new Vector2D(700, 500),
	new Vector2D(100, 500),*/

	//Diamond
	new Vector2D(400, 50),
	new Vector2D(750, 300),
	new Vector2D(400, 550),
	new Vector2D(50, 300),
};

Vector2D* lerpPoints[] = 
{
	new Vector2D(100.0f, 100.0f),
	new Vector2D(700.0f, 100.0f),
	new Vector2D(700.0f, 500.0f),
	new Vector2D(100.0f, 500.0f),
};

Vector2D lerperPosition = *lerpPoints[0];
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

Vector2D* lerperPoints[] = 
{
	new Vector2D(0.0f, 0.0f),
	new Vector2D(25.0f, 0.0f),
	new Vector2D(25.0f, 25.0f),
	new Vector2D(0.0f, 25.0f),

};

//Draw Spaceship and arbitrary wall
void SpaceShip::draw(Core::Graphics& g)
{
	g.SetBackgroundColor(RGB(25,25,25));


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


	g.SetColor(RGB(100, 100, 255));
	const unsigned int NUM_POINTS = sizeof(shipPoints) / sizeof(*shipPoints);
	for(unsigned int i = 0; i< NUM_POINTS; i++)
	{
		const Vector2D& p1 = position + *shipPoints[i];
		const Vector2D& p2 = position + *shipPoints [(i+1) % NUM_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
	if(walls)
	{
		g.SetColor(RGB(255, 100, 255));
		const unsigned int NUM_WALL_POINTS = sizeof(meWall) / sizeof(*meWall);
		for(unsigned int i = 0; i< NUM_WALL_POINTS; i++)
		{
			const Vector2D& w1 = *meWall[i];
			const Vector2D& w2 = *meWall [(i+1) % NUM_WALL_POINTS];
			g.DrawLine(w1.x, w1.y, w2.x, w2.y);
		}
	}
	g.SetColor(RGB(255, 255, 100));
	const unsigned int NUM_LERPER_POINTS = sizeof(lerperPoints) / sizeof(*lerperPoints);
	for(unsigned int i = 0; i< NUM_LERPER_POINTS; i++)
	{
		const Vector2D& l1 = lerperPosition + *lerperPoints[i];
		const Vector2D& l2 = lerperPosition + *lerperPoints[(i+1) % NUM_LERPER_POINTS];
		g.DrawLine(l1.x, l1.y, l2.x, l2.y);
	}

}

//SpaceShip update
void SpaceShip::update(float dt)
{
	//Switching between wrapping and bouncing
	if(Core::Input::IsPressed('1'))
	{
		bouncing = true;
		wrapping = false;
		walls = false;
		position = Vector2D(800/2, 600/2);
	}
	if(Core::Input::IsPressed('2'))
	{
		bouncing = false;
		wrapping = true;
		walls = false;
		position = Vector2D(800/2, 600/2);
	}
	if(Core::Input::IsPressed('3'))
	{
		bouncing = false;
		wrapping = false;
		walls = true;
		position = Vector2D(800/2, 600/2);
	}

	//Rotate right
	if(Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{
		const unsigned int NUM_POINTS = sizeof(shipPoints) / sizeof(*shipPoints);
		for(unsigned int i = 0; i< NUM_POINTS; i++)
		{
			*shipPoints[i] = (*shipPoints[i]).rotate(0.03f);
		}
	}

	//Rotate left
	if(Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		const unsigned int NUM_POINTS = sizeof(shipPoints) / sizeof(*shipPoints);
		for(unsigned int i = 0; i< NUM_POINTS; i++)
		{
			*shipPoints[i] = (*shipPoints[i]).rotate(-0.03f);
		}
	}

	float velocityScale = 50;

	//WASD movement controls
	if(Core::Input::IsPressed('D'))
	{
		velocity.x += dt * velocityScale;
	}
	if(Core::Input::IsPressed('A'))
	{
		velocity.x -= dt * velocityScale;
	}
	if(Core::Input::IsPressed('S'))
	{
		velocity.y += dt * velocityScale;
	}
	if(Core::Input::IsPressed('W')
	{
		velocity.y -= dt * velocityScale;
	}
	position = position + velocity * dt;

	//Collision with walls
	if(walls)
	{
		const unsigned int NUM_WALLPOINTS = sizeof(meWall) / sizeof(*meWall);
		for(unsigned int i = 0; i< NUM_WALLPOINTS; i++)
		{
			Vector2D wallVertexOne = *meWall[i];
			Vector2D wallToShip = position - wallVertexOne;
			Vector2D wallVertexTwo = *meWall[(i+1) % NUM_WALLPOINTS];
			Vector2D wall = wallVertexTwo - wallVertexOne;
			Vector2D wallNormal = wall.perpCW();
			float dotResult = dot(wallToShip, wallNormal);
			if(dotResult<0)
			{
				Vector2D normalizedNormal = wallNormal.normalized();
				Vector2D projectedVector = velocity.projectOnto(normalizedNormal);
				velocity = velocity+(-2*projectedVector);
			}
		}
	}
	if(bouncing)
	{
		if(position.x <0)
			velocity.x *= -1;
		if(position.x > 800)
			velocity.x *= -1;
		if(position.y <0)
			velocity.y *= -1;
		if(position.y > 600)
			velocity.y *= -1;
	}
	
	//Wrap from one side of the screen to the other
	else
	{
	if(position.x <0-32)
		position.x = 800+16;
	if(position.x > 800+16)
		position.x  = 0-16;
	if(position.y <0-32)
		position.y = 600+32;
	if(position.y > 600+32)
		position.y = 0-32;
	}
	lerpTheLerper(dt);
}