#include "GridCellContainer.h"
#include "Assets\Presets\Materials\LightingAndTextureMat.h"
#include "Assets\Presets\Materials\PassThroughMat.h"
#include "GameObjects\Entity.h"
#include "GameObjects\Components\RendererComponent.h"
#include "GameObjects\Components\PhysicsComponent.h"
#include "GameObjects\Components\ClickBoxComponent.h"
#include "CellStateComponent.h"
#include "Assets\Geometry.h"
#include "Assets\Material.h"
#include "MathTools\Random.h"

const int gridWidth = 9;
const int gridHeight = 9;
int numMines = 10;
Entity* gridCells [gridWidth][gridHeight];

void GridCellContainer::update()
{
	if(gridInitialized)
	{
		for(int i = 0; i < gridWidth; i++)
		{
			for(int j = 0; j < gridHeight; j++)
			{
				gridCells[i][j]->update();
			}
		}
	}
}

void GridCellContainer::setupGrid()
{
	TextureInfo* clear0 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty0.png");
	TextureInfo* clear1 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty1.png");
	TextureInfo* clear2 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty2.png");
	TextureInfo* clear3 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty3.png");
	TextureInfo* clear4 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty4.png");
	TextureInfo* clear5 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty5.png");
	TextureInfo* clear6 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty6.png");
	TextureInfo* clear7 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty7.png");
	TextureInfo* clear8 = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureEmpty8.png");
	TextureInfo* clearMine = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureMine.png");
	TextureInfo* flagged = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureFlagged.png");
	TextureInfo* covered = GeneralGLWindow::getInstance().addTexture("Assets/Textures/mineTextureCovered.png");

	Geometry* cube = new Geometry("Assets/Models/repeatFaceUnitCube.bin");
	
	float currentX = -(gridWidth/2.0f);
	float currentY = 0.0f;
	float currentZ = -(gridHeight/2.0f);
	for(int i = 0; i < gridWidth; i++)
	{
		currentZ = -(gridHeight/2.0f);
		for(int j = 0; j < gridHeight; j++)
		{
			//LightingAndTextureMat* mat = new LightingAndTextureMat();
			LightingAndTextureMat* mat = new LightingAndTextureMat();
			RendererComponent* rend = new RendererComponent();
			ClickBoxComponent* click = new ClickBoxComponent();
			CellStateComponent* cellComp = new	CellStateComponent();
			cellComp->coveredTexture = covered;
			cellComp->flaggedTexture = flagged;

			QObject::connect(click, SIGNAL(LeftClicked()), cellComp, SLOT(leftClickAction()));
			QObject::connect(click, SIGNAL(RightClicked()), cellComp, SLOT(rightClickAction()));
			QObject::connect(cellComp, SIGNAL(CellCleared(CellStateComponent*)), this, SLOT(cellCleared(CellStateComponent*)));
			mat->diffuseMap = covered;
			mat->usingDiffuseMap = true;
			Entity* cell = new Entity();
			cell->transform.position = vec3(currentX, currentY, currentZ);
			cell->update();
			cell->addComponent(rend);
			cell->addComponent(click);
			cell->addComponent(cellComp);

			click->width = 1;
			click->height = 1;
			click->length = 1;
			click->boxOrigin = cell->transform.position;

			rend->setData(cube, true, true, PRIORITY_1, mat);
			mat->addLightingParameters(rend->renderable);
			gridCells[i][j] = cell;
			cellComp->x = i;
			cellComp->y = j;
			currentZ += 1;
		}
		currentX += 1;
	}
	for(int i = 0; i < numMines; i++)
	{
		int x = (int)Random::getInstance().randomFloatRange(0, gridWidth);
		int z = (int)Random::getInstance().randomFloatRange(0, gridHeight);
		if(!gridCells[x][z]->getComponent<CellStateComponent>()->containsMine)
		{
			gridCells[x][z]->getComponent<CellStateComponent>()->containsMine = true;
			gridCells[x][z]->getComponent<CellStateComponent>()->clearedTexture = clearMine;
		}
		else
		{
			i-=1;
		}
	}
	for(int i = 0; i < gridWidth; i++)
	{
		for(int j = 0; j < gridHeight; j++)
		{
			int minesAdj = getNumMinesAdjacent(gridCells[i][j]);
			CellStateComponent* state = gridCells[i][j]->getComponent<CellStateComponent>();
			state->numAdjacentMines = minesAdj;
			if(!state->containsMine)
			{
				switch(minesAdj)
				{
				case 0:
					state->clearedTexture = clear0;
					break;
				case 1:
					state->clearedTexture = clear1;
					break;
				case 2:
					state->clearedTexture = clear2;
					break;
				case 3:
					state->clearedTexture = clear3;
					break;
				case 4:
					state->clearedTexture = clear4;
					break;
				case 5:
					state->clearedTexture = clear5;
					break;
				case 6:
					state->clearedTexture = clear6;
					break;
				case 7:
					state->clearedTexture = clear7;
					break;
				case 8:
					state->clearedTexture = clear8;
					break;
				}
			}
		}
	}
	gridInitialized = true;
}

int GridCellContainer::getNumMinesAdjacent(Entity* cell)
{
	int numMines = 0;
	CellStateComponent* state = cell->getComponent<CellStateComponent>();

	if(state->y > 0)
	{
		if(gridCells[state->x][state->y-1]->getComponent<CellStateComponent>()->containsMine)
		{
			numMines++;
		}
	}
	if(state->y < gridHeight-1)
	{
		if(gridCells[state->x][state->y+1]->getComponent<CellStateComponent>()->containsMine)
		{
			numMines++;
		}
	}
	if(state->x > 0)
	{
		if(gridCells[state->x-1][state->y]->getComponent<CellStateComponent>()->containsMine)
		{
			numMines++;
		}
		if(state->y > 0)
		{
			if(gridCells[state->x-1][state->y-1]->getComponent<CellStateComponent>()->containsMine)
			{
				numMines++;
			}
		}
		if(state->y < gridHeight-1)
		{
			if(gridCells[state->x-1][state->y+1]->getComponent<CellStateComponent>()->containsMine)
			{
				numMines++;
			}
		}
	}

	if(state->x < gridWidth-1)
	{
		if(gridCells[state->x+1][state->y]->getComponent<CellStateComponent>()->containsMine)
		{
			numMines++;
		}
		if(state->y > 0)
		{
			if(gridCells[state->x+1][state->y-1]->getComponent<CellStateComponent>()->containsMine)
			{
				numMines++;
			}
		}
		if(state->y < gridHeight-1)
		{
			if(gridCells[state->x+1][state->y+1]->getComponent<CellStateComponent>()->containsMine)
			{
				numMines++;
			}
		}
	}
	return numMines;
}

void GridCellContainer::cellCleared(CellStateComponent* c)
{
	if(c->containsMine)
	{
		clearAllCells();
	}
	else if(c->numAdjacentMines == 0)
	{
		clearAllAdjacentEmptyCells(c);
	}
}
void GridCellContainer::clearAllCells()
{
	for(int i = 0; i < gridWidth; i++)
	{
		for(int j = 0; j < gridHeight; j++)
		{
			gridCells[i][j]->getComponent<CellStateComponent>()->clear();
		}
	}
}
void GridCellContainer::clearAllAdjacentEmptyCells(CellStateComponent* c)
{
	if(c->y > 0)
	{
		if(!getCellStateAt(c->x,c->y-1)->containsMine &&  !getCellStateAt(c->x,c->y-1)->cleared)
		{
			getCellStateAt(c->x,c->y-1)->clear();
			if(getCellStateAt(c->x,c->y-1)->numAdjacentMines == 0)
			{
				clearAllAdjacentEmptyCells(getCellStateAt(c->x,c->y-1));
			}
		}
	}
	if(c->y < gridHeight-1)
	{
		if(!getCellStateAt(c->x,c->y+1)->containsMine && !getCellStateAt(c->x,c->y+1)->cleared)
		{
			getCellStateAt(c->x,c->y+1)->clear();
			if(getCellStateAt(c->x,c->y+1)->numAdjacentMines == 0)
			{
				clearAllAdjacentEmptyCells(getCellStateAt(c->x,c->y+1));
			}
		}
	}
	if(c->x > 0)
	{
		if(!getCellStateAt(c->x-1,c->y)->containsMine && !getCellStateAt(c->x-1,c->y)->cleared)
		{
			getCellStateAt(c->x-1,c->y)->clear();
			if(getCellStateAt(c->x-1,c->y)->numAdjacentMines == 0)
			{
				clearAllAdjacentEmptyCells(getCellStateAt(c->x-1,c->y));
			}
		}
		if(c->y > 0)
		{
			if(!getCellStateAt(c->x-1,c->y-1)->containsMine && !getCellStateAt(c->x-1,c->y-1)->cleared)
			{
				getCellStateAt(c->x-1,c->y-1)->clear();
				if(getCellStateAt(c->x-1,c->y-1)->numAdjacentMines == 0)
				{
					clearAllAdjacentEmptyCells(getCellStateAt(c->x-1,c->y-1));
				}
			}
		}
		if(c->y < gridHeight-1)
		{
			if(!getCellStateAt(c->x-1,c->y+1)->containsMine && !getCellStateAt(c->x-1,c->y+1)->cleared)
			{
				getCellStateAt(c->x-1,c->y+1)->clear();
				if(getCellStateAt(c->x-1,c->y+1)->numAdjacentMines == 0)
				{
					clearAllAdjacentEmptyCells(getCellStateAt(c->x-1,c->y+1));
				}
			}
		}
	}

	if(c->x < gridWidth-1)
	{
		if(!getCellStateAt(c->x+1,c->y)->containsMine && !getCellStateAt(c->x+1,c->y)->cleared)
		{
			getCellStateAt(c->x+1,c->y)->clear();
			if(getCellStateAt(c->x+1,c->y)->numAdjacentMines == 0)
			{
				clearAllAdjacentEmptyCells(getCellStateAt(c->x+1,c->y));
			}
		}
		if(c->y > 0)
		{
			if(!getCellStateAt(c->x+1,c->y-1)->containsMine && !getCellStateAt(c->x+1,c->y-1)->cleared)
			{
				getCellStateAt(c->x+1,c->y-1)->clear();
				if(getCellStateAt(c->x+1,c->y-1)->numAdjacentMines == 0 )
				{
					clearAllAdjacentEmptyCells(getCellStateAt(c->x+1,c->y-1));
				}
			}
		}
		if(c->y < gridHeight-1)
		{
			if(!getCellStateAt(c->x+1,c->y+1)->containsMine && !getCellStateAt(c->x+1,c->y+1)->cleared)
			{
				getCellStateAt(c->x+1,c->y+1)->clear();
				if(getCellStateAt(c->x+1,c->y+1)->numAdjacentMines == 0)
				{
					clearAllAdjacentEmptyCells(getCellStateAt(c->x+1,c->y+1));
				}
			}
		}
	}
}

CellStateComponent* GridCellContainer::getCellStateAt(int x, int y)
{
	return gridCells[x][y]->getComponent<CellStateComponent>();
}