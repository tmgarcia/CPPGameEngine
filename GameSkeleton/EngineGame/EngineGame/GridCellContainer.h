#pragma once
#include <Qt\qobject.h>
class Entity;
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
};

