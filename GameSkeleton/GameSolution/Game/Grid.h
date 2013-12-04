#pragma once
#include "Vector3D.h"
#include "Core.h"
#include "GridCell.h"
#include "ScreenInfo.h"
#include "EnemyLegion.h"

using::Core::RGB;

class Grid
{
public:
	int numRows;
	int numColumns;
	RGB wallColor;
	void buildCells();
	void buildWalls();
	EnemyLegion enemies;
	Vector3D collidedEnemy;
	int collisionDirection; //0 for horizontal (collided x) 1 for vertical (collided y)
	void draw(Core::Graphics& g);
	bool update(Vector3D shipPosition);
	bool enemyCollisionCheck(Vector3D colliderPosition);
	void addEnemyAt(int i, int j);
	Grid(RGB wallColor, int numRows=10, int numColumns=10) : wallColor(wallColor), numRows(numRows), numColumns(numColumns)
	{
		buildCells();
		buildWalls();
	}
	~Grid(void);
};

