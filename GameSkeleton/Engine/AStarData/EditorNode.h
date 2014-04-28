#pragma once

#include <list>
#include <glm\glm.hpp>
#include "..\DebugTools\DebugShapes.h"

using std::list;
using glm::vec3;

class __declspec(dllexport) EditorNode
{
public:
	vec3 position;
	DebugShapes::DebugShapeInfo* nodeInfo;
	int numAttachedNodes;

	void toggleAttachedNode(EditorNode* n);
	void addAttachedNode(EditorNode* n, float cost);
	void highlightAttachedNodes(vec3 color);
	void hideAttachedNodes();
	void clearAttachedNodes();
	bool connectedToNode(EditorNode* n);
	EditorNode* getRandomAttachedNode();

	EditorNode(vec3 location)
	{
		position = location;
		numAttachedNodes = 0;
	}
	~EditorNode();
	struct ConnectingNode
	{
		float cost;
		DebugShapes::VectorArrowInfo* arrowInfo;
		EditorNode* node;
	};
	QList<ConnectingNode*> attachedNodes;
private:
	void removeAttachedNode(EditorNode* n);
	int findConnection(EditorNode* n);
};

