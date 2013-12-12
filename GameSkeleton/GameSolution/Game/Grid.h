#pragma once
#include "Vector3D.h"
#include "Core.h"
#include "GridCell.h"
#include "ScreenInfo.h"
#include "EnemyLegion.h"
#include "DebugMemory.h"

using::Core::RGB;

class Grid
{
public:
	int numRows;
	int numColumns;
	RGB wallColor;
	void buildCells();
	void buildWalls();
	bool playerCompileErrors;
	bool playerCompile;
	EnemyLegion enemies;
	Vector3D collidedEnemy;
	int collisionDirection; //0 for horizontal (collided x) 1 for vertical (collided y)
	void draw(Core::Graphics& g);
	bool update(Vector3D shipPosition, float dt);
	bool enemyCollisionCheck(Vector3D colliderPosition, int type, int buffer);//type - 0=nonlethal 1=lethal
	void addEnemyAt(int i, int j);
	bool wallCollision(Vector3D colliderPosition, float buffer);
	void clear();
	Grid(RGB wallColor, int numRows=10, int numColumns=10) : wallColor(wallColor), numRows(numRows), numColumns(numColumns)
	{
		buildCells();
		buildWalls();
		playerCompile = false;
		playerCompileErrors = false;
	}
	~Grid()
	{
		clear();	
	}
};

