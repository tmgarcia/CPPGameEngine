#include "Grid.h"
#include "Assert.h"

GridCell* cells[10][10];
const unsigned int NUM_CELLS = sizeof(cells) / sizeof(*cells);
void Grid::buildCells()
{
	for(int i = 0; i<numRows; i++)
	{
		for(int j = 0; j<numColumns; j++)
		{
			Vector3D position = Vector3D(((float)(SCREEN_WIDTH)/numColumns)*(j),((float)SCREEN_HEIGHT/numRows)*(i));
			cells[i][j] = new GridCell(position, (float)SCREEN_HEIGHT/numRows, (float)(SCREEN_WIDTH)/numColumns,  4.0f, wallColor);
		}
	}
}

void Grid::addEnemyAt(int i, int j)
{
	Assert(i>=0);
	Assert(i<=9);
	Assert(j>=0);
	Assert(j<=9);
	Vector3D spot = Vector3D(cells[i][j]->position.x+(cells[i][j]->width/2), cells[i][j]->position.y+(cells[i][j]->height/2));
	enemies.addEnemy(spot);
}

bool Grid::enemyCollisionCheck(Vector3D colliderPosition, int type, int buffer)
{
	bool collided=false;
	if(enemies.checkCollide(colliderPosition, type, buffer))
	{
		collidedEnemy = enemies.collidedPosition;
		collided = true;
	}
	return collided;
}

void Grid::draw(Core::Graphics& g)
{
	/*for(int i = 0; i<numRows; i++)
	{
		for(int j = 0; j<numColumns; j++)
		{
			cells[i][j]->draw(g);
		}
	}*/
	if(enemies.numActiveTroops==0)
	{
		g.SetColor(RGB(50,255,50));
	}
	else
		g.SetColor(RGB(200,50,50));
	g.DrawString((int)(cells[9][0]->position.x+(cells[9][0]->width/2))-30,(int)(cells[9][0]->position.y+(cells[9][0]->height/2))-10, "COMPILE");
	g.DrawLine(cells[9][0]->position.x, cells[9][0]->position.y, cells[9][0]->position.x+cells[9][0]->width, cells[9][0]->position.y);
	g.DrawLine(cells[9][0]->position.x+cells[9][0]->width, cells[9][0]->position.y, cells[9][0]->position.x+cells[9][0]->width, cells[9][0]->position.y+cells[9][0]->height);
	enemies.draw(g, Vector3D(100,100));
}

bool Grid::update(Vector3D shipPosition, float dt)
{
	enemies.update(dt);

	if(cells[9][0]->isWithinCell(shipPosition))
	{
		if(enemies.numActiveTroops!=0)
			playerCompileErrors = true;
		else
			playerCompile = true;
	}

	return wallCollision(shipPosition, 16);
}

bool Grid::wallCollision(Vector3D colliderPosition, float buffer)
{
	bool collided = false;
	for(int i = 0; i<numRows; i++)
	{
		for(int j = 0; j<numColumns; j++)
		{
			if(cells[i][j]->checkCollision(colliderPosition, buffer))
			{
				collided = true;
				collisionDirection = cells[i][j]->collisionDirection;
			}
		}
	}

	return collided;
}

void Grid::buildWalls()
{
	cells[0][0]->addWall(0);
	cells[0][0]->addWall(2);
	cells[0][1]->addWall(0);
	cells[0][1]->addWall(1);
	cells[0][2]->addWall(0);
	cells[0][2]->addWall(1);
	cells[0][3]->addWall(0);
	cells[0][4]->addWall(0);
	cells[0][5]->addWall(0);
	cells[0][5]->addWall(1);
	cells[0][6]->addWall(0);
	cells[0][6]->addWall(1);
	cells[0][7]->addWall(0);
	cells[0][7]->addWall(1);
	cells[0][8]->addWall(0);
	cells[0][8]->addWall(3);
	cells[0][9]->addWall(0);
	cells[0][9]->addWall(2);
	cells[0][9]->addWall(3);

	cells[1][0]->addWall(1);
	cells[1][0]->addWall(2);
	cells[1][1]->addWall(0);
	cells[1][1]->addWall(1);
	cells[1][2]->addWall(0);
	cells[1][2]->addWall(3);
	cells[1][3]->addWall(2);
	cells[1][3]->addWall(3);
	cells[1][4]->addWall(2);
	cells[1][4]->addWall(1);
	cells[1][5]->addWall(0);
	cells[1][5]->addWall(3);
	cells[1][6]->addWall(0);
	cells[1][6]->addWall(2);
	cells[1][7]->addWall(0);
	cells[1][7]->addWall(3);
	cells[1][8]->addWall(1);
	cells[1][8]->addWall(2);
	cells[1][9]->addWall(1);
	cells[1][9]->addWall(3);


	cells[2][0]->addWall(0);
	cells[2][0]->addWall(3);
	cells[2][0]->addWall(2);
	cells[2][1]->addWall(0);
	cells[2][1]->addWall(2);
	cells[2][2]->addWall(1);
	cells[2][2]->addWall(3);
	cells[2][3]->addWall(3);
	cells[2][3]->addWall(2);
	cells[2][3]->addWall(1);
	cells[2][4]->addWall(0);
	cells[2][4]->addWall(2);
	cells[2][5]->addWall(3);
	cells[2][6]->addWall(3);
	cells[2][6]->addWall(2);
	cells[2][6]->addWall(1);
	cells[2][7]->addWall(2);
	cells[2][7]->addWall(1);
	cells[2][8]->addWall(1);
	cells[2][8]->addWall(0);
	cells[2][9]->addWall(0);
	cells[2][9]->addWall(3);

	cells[3][0]->addWall(1);
	cells[3][0]->addWall(2);
	cells[3][1]->addWall(3);
	cells[3][1]->addWall(1);
	cells[3][2]->addWall(2);
	cells[3][2]->addWall(0);
	cells[3][3]->addWall(0);
	cells[3][3]->addWall(1);
	cells[3][4]->addWall(3);
	cells[3][4]->addWall(1);
	cells[3][5]->addWall(1);
	cells[3][5]->addWall(2);
	cells[3][6]->addWall(0);
	cells[3][6]->addWall(3);
	cells[3][7]->addWall(2);
	cells[3][7]->addWall(0);
	cells[3][8]->addWall(0);
	cells[3][8]->addWall(3);
	cells[3][9]->addWall(3);
	cells[3][9]->addWall(2);

	cells[4][0]->addWall(2);
	cells[4][0]->addWall(0);
	cells[4][1]->addWall(0);
	cells[4][1]->addWall(1);
	cells[4][3]->addWall(1);
	cells[4][3]->addWall(0);
	cells[4][4]->addWall(0);
	cells[4][5]->addWall(0);
	cells[4][5]->addWall(3);
	cells[4][6]->addWall(1);
	cells[4][6]->addWall(2);
	cells[4][7]->addWall(3);
	cells[4][8]->addWall(1);
	cells[4][8]->addWall(2);
	cells[4][9]->addWall(3);
	cells[4][9]->addWall(1);

	cells[5][0]->addWall(2);
	cells[5][0]->addWall(1);
	cells[5][1]->addWall(0);
	cells[5][1]->addWall(3);
	cells[5][2]->addWall(3);
	cells[5][2]->addWall(2);
	cells[5][3]->addWall(0);
	cells[5][3]->addWall(2);
	cells[5][4]->addWall(3);
	cells[5][4]->addWall(1);
	cells[5][5]->addWall(2);
	cells[5][5]->addWall(3);
	cells[5][6]->addWall(2);
	cells[5][6]->addWall(0);
	cells[5][6]->addWall(1);
	cells[5][7]->addWall(1);
	cells[5][8]->addWall(0);
	cells[5][8]->addWall(1);
	cells[5][9]->addWall(3);
	cells[5][9]->addWall(0);

	cells[6][0]->addWall(2);
	cells[6][0]->addWall(0);
	cells[6][1]->addWall(1);
	cells[6][1]->addWall(3);
	cells[6][2]->addWall(3);
	cells[6][2]->addWall(2);
	cells[6][2]->addWall(1);
	cells[6][3]->addWall(2);
	cells[6][3]->addWall(3);
	cells[6][4]->addWall(0);
	cells[6][4]->addWall(2);
	cells[6][5]->addWall(1);
	cells[6][5]->addWall(3);
	cells[6][6]->addWall(0);
	cells[6][6]->addWall(2);
	cells[6][7]->addWall(3);
	cells[6][7]->addWall(0);
	cells[6][7]->addWall(1);
	cells[6][8]->addWall(2);
	cells[6][8]->addWall(0);
	cells[6][9]->addWall(3);
	cells[6][9]->addWall(1);


	cells[7][0]->addWall(2);
	cells[7][0]->addWall(3);
	cells[7][1]->addWall(2);
	cells[7][1]->addWall(0);
	cells[7][2]->addWall(3);
	cells[7][2]->addWall(0);
	cells[7][3]->addWall(2);
	cells[7][3]->addWall(3);
	cells[7][4]->addWall(2);
	cells[7][4]->addWall(1);
	cells[7][5]->addWall(0);
	cells[7][5]->addWall(1);
	cells[7][5]->addWall(3);
	cells[7][6]->addWall(2);
	cells[7][6]->addWall(1);
	cells[7][7]->addWall(0);
	cells[7][7]->addWall(3);
	cells[7][8]->addWall(2);
	cells[7][8]->addWall(1);
	cells[7][9]->addWall(3);
	cells[7][9]->addWall(0);

	cells[8][0]->addWall(2);
	cells[8][0]->addWall(3);
	cells[8][1]->addWall(3);
	cells[8][1]->addWall(2);
	cells[8][2]->addWall(2);
	cells[8][2]->addWall(1);
	cells[8][3]->addWall(3);
	cells[8][3]->addWall(1);
	cells[8][4]->addWall(2);
	cells[8][4]->addWall(0);
	cells[8][5]->addWall(0);
	cells[8][5]->addWall(1);
	cells[8][6]->addWall(0);
	cells[8][6]->addWall(1);
	cells[8][7]->addWall(1);
	cells[8][7]->addWall(3);
	cells[8][8]->addWall(3);
	cells[8][8]->addWall(2);
	cells[8][8]->addWall(0);
	cells[8][9]->addWall(3);
	cells[8][9]->addWall(2);

	cells[9][0]->addWall(2);
	cells[9][0]->addWall(3);
	cells[9][0]->addWall(1);
	cells[9][1]->addWall(2);
	cells[9][1]->addWall(1);
	cells[9][2]->addWall(0);
	cells[9][2]->addWall(1);
	cells[9][3]->addWall(0);
	cells[9][3]->addWall(1);
	cells[9][4]->addWall(1);
	cells[9][4]->addWall(3);
	cells[9][5]->addWall(1);
	cells[9][5]->addWall(0);
	cells[9][5]->addWall(2);
	cells[9][6]->addWall(1);
	cells[9][6]->addWall(0);
	cells[9][7]->addWall(1);
	cells[9][7]->addWall(0);
	cells[9][8]->addWall(1);
	cells[9][9]->addWall(1);
	cells[9][9]->addWall(3);
}