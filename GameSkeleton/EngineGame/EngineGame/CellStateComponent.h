#pragma once
#include "Component.h"
#include "Assets\Material.h"
#include "GeneralGLWindow.h"
#include <Qt\qobject.h>

class Entity;
class CellStateComponent : public QObject, public Component
{
	Q_OBJECT

public:
	int x;
	int y;
	int numAdjacentMines;
	bool containsMine;
	bool cleared;
	bool flagged;

	TextureInfo* coveredTexture;
	TextureInfo* clearedTexture;
	TextureInfo* flaggedTexture;
	Entity* flaggedEntity;
	Entity* coveredEntity;
	Entity* clearedEntity;

	CellStateComponent()
	{
		x = 0;
		y = 0;
		numAdjacentMines = 0;
		containsMine = false;
		cleared = false;
		flagged = false;
		
	}
	void toggleFlag();
	void clear();
	void update();
	void cleanup();

public slots:
	void leftClickAction();
	void rightClickAction();

signals:
	void CellCleared(CellStateComponent*);

private: 

};

