#include "GridCellContainer.h"
#include "Assets\Presets\Materials\LightingAndTextureMat.h"
#include "Assets\Presets\Materials\PassThroughMat.h"
#include "GameObjects\Entity.h"
#include "GameObjects\Components\RendererComponent.h"
#include "GameObjects\Components\PhysicsComponent.h"
#include "GameObjects\Components\ClickBoxComponent.h"
#include "GameObjects\Components\HoloRenderercomponent.h"
#include "CellStateComponent.h"
#include "Assets\Geometry.h"
#include "Assets\Material.h"
#include "MathTools\Random.h"

const int gridWidth = 9;
const int gridHeight = 9;
int numMines = 10;
int holoSpeed = 0.001f;
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
Entity* GridCellContainer::createCoveringEntity(vec3 position, TextureInfo* diffuse, TextureInfo* alpha, Geometry* geo)
{
	HoloRenderercomponent* holoRenderer = new HoloRenderercomponent();
	Entity* coveredEntity = new Entity();
	coveredEntity->transform.position = position;
	//coveredEntity->transform.position.y += 0.5f;
	coveredEntity->update();
	coveredEntity->addComponent(holoRenderer);
	holoRenderer->useAlpha = false;
	//holoRenderer->holoDiffuse = false;
	holoRenderer->holoIncrement = 0.001f;
	holoRenderer->diffuseMap = diffuse;
	//holoRenderer->alphaMap = alpha;
	holoRenderer->setData(geo, true, true, PRIORITY_1);

	return coveredEntity;
}
Entity* GridCellContainer::createFlaggedEntity(vec3 position, TextureInfo* diffuse, Geometry* geo)
{
	HoloRenderercomponent* holoRenderer = new HoloRenderercomponent();
	Entity* flaggedEntity = new Entity();
	flaggedEntity->transform.position = position;
	//flaggedEntity->transform.position.y += 0.5f;
	flaggedEntity->update();
	flaggedEntity->addComponent(holoRenderer);
	holoRenderer->holoDiffuse = false;
	holoRenderer->holoIncrement = 0.001f;
	holoRenderer->diffuseMap = diffuse;
	holoRenderer->setData(geo, false, true, PRIORITY_1);

	return flaggedEntity;
}
void GridCellContainer::setupGrid()
{
	TextureInfo* cellText = GeneralGLWindow::getInstance().addTexture("Assets/Textures/cellInnerDiffuse.png");
	TextureInfo* coveringDiffuse = GeneralGLWindow::getInstance().addTexture("Assets/Textures/darkHoloDiffuse.png");
	TextureInfo* coveringAlpha = GeneralGLWindow::getInstance().addTexture("Assets/Textures/scrollingCodeAlpha.png");
	TextureInfo* breakpointDiffuse = GeneralGLWindow::getInstance().addTexture("Assets/Textures/breakpointTexture.png");
	TextureInfo* bugDiffuse = GeneralGLWindow::getInstance().addTexture("Assets/Textures/bugTexture.png");

	Geometry* number1 = new Geometry("Assets/Models/number1.bin");
	Geometry* number2 = new Geometry("Assets/Models/number2.bin");
	Geometry* number3 = new Geometry("Assets/Models/number3.bin");
	Geometry* number4 = new Geometry("Assets/Models/number4.bin");
	Geometry* number5 = new Geometry("Assets/Models/number5.bin");
	Geometry* number6 = new Geometry("Assets/Models/number6.bin");
	Geometry* number7 = new Geometry("Assets/Models/number7.bin");
	Geometry* number8 = new Geometry("Assets/Models/number8.bin");
	Geometry* breakpoint = new Geometry("Assets/Models/BreakPoint.bin");
	Geometry* bug = new Geometry("Assets/Models/Bug.bin");
	Geometry* coveringCube = new Geometry("Assets/Models/CellCover.bin");
	Geometry* cellInner = new Geometry("Assets/Models/CellInner.bin");
	Geometry* cube = new Geometry("Assets/Models/repeatFaceUnitCube.bin");

	float currentX = -(gridWidth/2.0f);
	float currentY = 0.0f;
	float currentZ = -(gridHeight/2.0f);
	for(int i = 0; i < gridWidth; i++)
	{
		currentZ = -(gridHeight/2.0f);
		for(int j = 0; j < gridHeight; j++)
		{
			LightingAndTextureMat* mat = new LightingAndTextureMat();
			//HoloRenderercomponent* holoRenderer = new HoloRenderercomponent();

			RendererComponent* rend = new RendererComponent();
			ClickBoxComponent* click = new ClickBoxComponent();
			CellStateComponent* cellComp = new	CellStateComponent();

			QObject::connect(click, SIGNAL(LeftClicked()), cellComp, SLOT(leftClickAction()));
			QObject::connect(click, SIGNAL(RightClicked()), cellComp, SLOT(rightClickAction()));
			QObject::connect(cellComp, SIGNAL(CellCleared(CellStateComponent*)), this, SLOT(cellCleared(CellStateComponent*)));
			mat->diffuseMap = cellText;
			mat->usingDiffuseMap = true;
			Entity* cell = new Entity();
			cell->transform.position = vec3(currentX, currentY, currentZ);
			cell->update();
			cell->addComponent(rend);
			cell->addComponent(click);
			cell->addComponent(cellComp);

			click->width = 1;
			click->height = 0.09f;
			click->length = 1;
			click->boxOrigin = cell->transform.position;

			rend->setData(cellInner, true, true, PRIORITY_1, mat);
			mat->addLightingParameters(rend->renderable);

			Entity* coveredEntity = createCoveringEntity(vec3(currentX, currentY, currentZ),coveringDiffuse, coveringAlpha, coveringCube);
			Entity* flaggedEntity = createFlaggedEntity(vec3(currentX, currentY, currentZ),breakpointDiffuse, breakpoint);

			cellComp->coveredEntity = coveredEntity;
			cellComp->flaggedEntity = flaggedEntity;

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

			HoloRenderercomponent* holoRenderer = new HoloRenderercomponent();
			Entity* mineEntity = new Entity();
			mineEntity->transform.position = gridCells[x][z]->transform.position;
			//mineEntity->transform.position.y += 0.5f;
			mineEntity->update();
			mineEntity->addComponent(holoRenderer);
			holoRenderer->holoDiffuse = false;
			holoRenderer->holoIncrement = 0.001f;
			holoRenderer->diffuseMap = bugDiffuse;
			holoRenderer->setData(bug, false, true, PRIORITY_1);

			gridCells[x][z]->getComponent<CellStateComponent>()->clearedEntity = mineEntity;
			//gridCells[x][z]->getComponent<CellStateComponent>()->clearedTexture = clearMine;
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
			Geometry* numberGeo = cube;
			if(!state->containsMine)
			{
				switch(minesAdj)
				{
				case 0:
					numberGeo = coveringCube;
					break;
				case 1:
					//state->clearedTexture = clear1;
					numberGeo = number1;
					break;
				case 2:
					//state->clearedTexture = clear2;
					numberGeo = number2;
					break;
				case 3:
					numberGeo = number3;
					//state->clearedTexture = clear3;
					break;
				case 4:
					numberGeo = number4;
					//state->clearedTexture = clear4;
					break;
				case 5:
					numberGeo = number5;
					//state->clearedTexture = clear5;
					break;
				case 6:
					numberGeo = number6;
					//state->clearedTexture = clear6;
					break;
				case 7:
					numberGeo = number7;
					//state->clearedTexture = clear7;
					break;
				case 8:
					numberGeo = number8;
					//state->clearedTexture = clear8;
					break;
				}
				HoloRenderercomponent* holoRenderer = new HoloRenderercomponent();
				Entity* numberEntity = new Entity();
				numberEntity->transform.position = gridCells[i][j]->transform.position;
				numberEntity->transform.position.y += 0.2f;
				numberEntity->update();
				numberEntity->addComponent(holoRenderer);
				//holoRenderer->holoDiffuse = false;
				holoRenderer->holoIncrement = 0.001f;
				//holoRenderer->diffuseMap = bugDiffuse;
				holoRenderer->setData(numberGeo, false, true, PRIORITY_1);
				state->clearedEntity = numberEntity;
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