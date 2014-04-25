#pragma once

#include <list>
#include <glm\glm.hpp>
#include "DebugShapes.h"

using std::list;
using glm::vec3;

class Node
{
public:
	vec3 position;
	DebugShapes::DebugShapeInfo* nodeInfo;
	int numAttachedNodes;

	void toggleAttachedNode(Node* n);
	void addAttachedNode(Node* n, float cost);
	void highlightAttachedNodes(vec3 color);
	void hideAttachedNodes();
	void clearAttachedNodes();
	bool connectedToNode(Node* n);
	Node* getRandomAttachedNode();

	Node(vec3 location)
	{
		position = location;
		numAttachedNodes = 0;
	}
	~Node();
	struct ConnectingNode
	{
		float cost;
		DebugShapes::VectorArrowInfo* arrowInfo;
		Node* node;
	};
	QList<ConnectingNode*> attachedNodes;
private:
	void removeAttachedNode(Node* n);
	int findConnection(Node* n);
};

