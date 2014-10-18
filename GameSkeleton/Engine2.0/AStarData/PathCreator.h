#pragma once
#include "Nodes\PathingNode.h"
#include "Path.h"
#include "Nodes\DebugNode.h"
class __declspec(dllexport)PathCreator
{
public:
	Path calculatePath(DebugNode* start, DebugNode* end);

	PathCreator()
	{
		
	}
	~PathCreator(){}
private:
	void processNode(DebugNode* node, float costSoFar, PathingNode* parent);
	QList<PathingNode*> processedNodes;
	bool endNodeHasLowestTEC();
	bool openNodesRemaining();
	PathingNode* getOpenNodeWithLowestTEC();
	DebugNode* startNode;
	DebugNode* endNode;
	int nodePreviouslyProcessed(DebugNode* node);
};

