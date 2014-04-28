#pragma once
#include "EditorNode.h"

class __declspec(dllexport) PathingNode
{
public:
	float heuristic;
	float costSoFar;
	float totalEstimatedCost;
	bool open;
	EditorNode* node;
	PathingNode* parentNode;
	PathingNode(EditorNode* n, float h)
	{
		node = n;
		heuristic = h;
		parentNode = NULL;
	}
};