#pragma once
#include "DebugNode.h"
#include "ExportHeader.h"

class DECL_DLL_EXPORT PathingNode
{
public:
	float heuristic;
	float costSoFar;
	float totalEstimatedCost;
	bool open;
	DebugNode* node;
	PathingNode* parentNode;
	PathingNode(DebugNode* n, float h)
	{
		node = n;
		heuristic = h;
		parentNode = NULL;
	}
};