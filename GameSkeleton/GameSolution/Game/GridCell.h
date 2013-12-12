#pragma once
#include "Vector3D.h"
#include "Core.h"
using::Core::RGB;


class GridCell
{
public:
	RGB wallColor;
	float height;
	float width;
	bool containsEnemy;
	bool topWall;
	bool bottomWall;
	bool leftWall;
	bool rightWall;
	float wallThickness;
	int collisionDirection; //0 top 1 bottom 2 left 3 right
	Vector3D position; //position of the top left corner of the cell
	void addWall(int w); //0 top 1 bottom 2 left 3 right
	bool checkCollision(Vector3D colliderPosition, float buffer);
	void draw(Core::Graphics& g);
	bool isWithinCell(Vector3D foreignerPosition);
	GridCell(Vector3D position, float height, float width, float wallThickness, RGB wallColor): height(height), width(width), wallColor(wallColor), position(position), wallThickness(wallThickness)
	{
		topWall = false;
		bottomWall = false;
		leftWall = false;
		rightWall = false;
	}
	~GridCell(){}
};

