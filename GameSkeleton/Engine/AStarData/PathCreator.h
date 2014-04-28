#pragma once
#include "PathingNode.h"
#include "Path.h"
#include "EditorNode.h"
class __declspec(dllexport)PathCreator
{
public:
	Path calculatePath(EditorNode* start, EditorNode* end);

	PathCreator()
	{
		
	}
	~PathCreator(){}
private:
	void processNode(EditorNode* node, float costSoFar, PathingNode* parent);
	QList<PathingNode*> processedNodes;
	bool endNodeHasLowestTEC();
	bool openNodesRemaining();
	PathingNode* getOpenNodeWithLowestTEC();
	EditorNode* startNode;
	EditorNode* endNode;
	int nodePreviouslyProcessed(EditorNode* node);
};

