#include "Walls.h"
#include "Vector2D.h"
#include "Vector3D.h"

Vector3D* wallShape[] =
{
	new Vector3D(400, 50, 0),
	new Vector3D(750, 300, 0),
	new Vector3D(400, 550, 0),
	new Vector3D(50, 300, 0),
};
const unsigned int NUM_WALL_POINTS = 4;


void Walls::clear()
{
	for(int i=0; i< NUM_WALL_POINTS; i++)
	{
		delete wallShape[i];
	}
}

void Walls::draw(Core::Graphics& g)
{
	g.SetColor(RGB(255, 100, 255));
	for(unsigned int i = 0; i< NUM_WALL_POINTS; i++)
	{
		const Vector3D& w1 = *wallShape[i];
		const Vector3D& w2 = *wallShape[(i+1) % NUM_WALL_POINTS];
		g.DrawLine(w1.x, w1.y, w2.x, w2.y);
	}
}

bool Walls::collided(Vector3D shipPosition)
{
	bool collided = false;
	const unsigned int NUM_WALLPOINTS = 4;
	for(unsigned int i = 0; i< NUM_WALLPOINTS; i++)
	{
		Vector3D wallVertexOne = *wallShape[i];
		Vector3D wallToShip = shipPosition - wallVertexOne;
		Vector3D wallVertexTwo = *wallShape[(i+1) % NUM_WALLPOINTS];
		Vector3D wall = wallVertexTwo - wallVertexOne;
		Vector3D wallNormal = wall.perpCW();
		float dotResult = dot(wallToShip, wallNormal);
		if(dotResult<0)
		{
			collided = true;
			collidedNormal = wallNormal.normalized();
		}
	}
	return collided;
}