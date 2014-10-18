#pragma once
#include "DebugNode.h"

class __declspec(dllexport) PathingNode
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