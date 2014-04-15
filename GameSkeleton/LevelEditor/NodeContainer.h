#pragma once

#include <Qt\qlist.h>

#include "Node.h"

class NodeContainer
{
public:
	int numNodes;
	Node* selectedNode;
	Node* clickedNode;
	void addNode(vec3 position);
	void removeNode(Node* node);
	void drawNodes();
	bool nodeRightClicked(vec3 clickDirection, vec3 clickOrigin);
	void nodeLeftClicked(vec3 clickDirection, vec3 clickOrigin);
	void deleteSelectedNode();

	NodeContainer();
	~NodeContainer();
private:
	QList<Node*> nodes;
	void drawNode(Node* node);
	void resetNodeColors();
	void addConnection(Node* node);
	bool nodeHasBeenClicked(vec3 clickDirection, vec3 clickOrigin);
};

