#pragma once
#include <Qt\qobject.h>
#include <glm\glm.hpp>
#pragma warning( disable : 4251 )

class Entity;
class TextureInfo;
class Geometry;
class CellStateComponent;
class GridCellContainer : QObject
{
	Q_OBJECT
public:
	GridCellContainer()
	{
		gridInitialized = false;
	}
	void setupGrid();
	bool gridInitialized;
	void update();

public slots:
	void cellCleared(CellStateComponent*);

private:
	int getNumMinesAdjacent(Entity* cell);
	void clearAllCells();
	void clearAllAdjacentEmptyCells(CellStateComponent*);
	CellStateComponent* getCellStateAt(int x, int y);
	Entity* createCoveringEntity(glm::vec3 position, TextureInfo* diffuse, TextureInfo* alpha, Geometry* geo);
	Entity* createFlaggedEntity(glm::vec3 position, TextureInfo* diffuse, Geometry* geo);
};
