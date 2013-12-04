#include "GridCell.h"


void GridCell::addWall(int w)
{
	switch(w)
	{
	case(0): topWall = true;
		break;
	case(1): bottomWall = true;
		break;
	case(2): leftWall = true;
		break;
	case(3): rightWall = true;
		break;
	}
}//0 top 1 bottom 2 left 3 right

bool GridCell::isWithinCell(Vector3D foreignerPosition)
{
	bool isInCell=false;
	if(foreignerPosition.x > position.x
		&& foreignerPosition.x < position.x+width
		&& foreignerPosition.y > position.y
		&& foreignerPosition.y < position.y+height)
	{
		isInCell = true;
	}
	return isInCell;
}

bool GridCell::checkCollision(Vector3D colliderPosition, float buffer)
{
	bool collided = false;
	if(isWithinCell(colliderPosition))
	{
		if(topWall || bottomWall || leftWall || rightWall)
		{
			if(topWall)
			{
				float bottomOfWall = position.y + wallThickness;
				if((colliderPosition.y+buffer) <= bottomOfWall)
				{
					collided = true;
					collisionDirection = 1;
				}
			}
			if(bottomWall)
			{
				float topOfWall = (position.y+height) - wallThickness;
				if((colliderPosition.y+buffer) >= topOfWall)
				{
					collided = true;
					collisionDirection = 1;
				}
			}
			if(leftWall)
			{
				float rightOfWall = position.x + wallThickness;
				if((colliderPosition.x+buffer) <= rightOfWall)
				{
					collided = true;
					collisionDirection = 0;
				}
			}
			if(rightWall)
			{
				float leftOfWall = (position.x+width) - wallThickness;
				if((colliderPosition.x+buffer) >= leftOfWall)
				{
					collided = true;
					collisionDirection = 0;
				}
			}
		}
	}
	return collided;
}

void GridCell::draw(Core::Graphics& g)
{
	if(topWall || bottomWall || leftWall || rightWall)
		{
			g.SetColor(wallColor);
			if(topWall)
			{
				g.DrawLine(position.x,position.y, position.x, position.y + wallThickness);
				g.DrawLine(position.x, position.y + wallThickness, position.x+width, position.y+wallThickness);
				g.DrawLine(position.x+width, position.y+wallThickness, position.x+width, position.y);
				g.DrawLine(position.x+width, position.y, position.x, position.y);
			}
			if(bottomWall)
			{
				g.DrawLine(position.x,position.y+height, position.x, (position.y+height) - wallThickness);
				g.DrawLine(position.x, (position.y+height) - wallThickness, position.x+width, (position.y+height) - wallThickness);
				g.DrawLine(position.x+width, (position.y+height) - wallThickness, position.x+width, position.y+height);
				g.DrawLine(position.x+width, position.y+height, position.x,position.y+height);
			}
			if(leftWall)
			{
				g.DrawLine(position.x, position.y, position.x+wallThickness, position.y);
				g.DrawLine(position.x+wallThickness, position.y, position.x+wallThickness, position.y+height);
				g.DrawLine(position.x+wallThickness, position.y+height, position.x, position.y+height);
				g.DrawLine(position.x, position.y+height, position.x, position.y);
			}
			if(rightWall)
			{
				g.DrawLine(position.x+width, position.y, (position.x+width)-wallThickness, position.y);
				g.DrawLine((position.x+width)-wallThickness, position.y, (position.x+width)-wallThickness, position.y+height);
				g.DrawLine((position.x+width)-wallThickness, position.y+height, position.x+width, position.y+height);
				g.DrawLine(position.x+width, position.y+height, position.x+width, position.y);
			}
		}
}