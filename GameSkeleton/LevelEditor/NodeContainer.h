#pragma once

#include <Qt\qlist.h>

#include "Node.h"

class NodeContainer
{
public:
	int numNodes;
	void addNode(vec3 position);
	void removeNode(Node* node);
	void drawNodes();

	NodeContainer();
	~NodeContainer();
private:
	QList<Node*> nodes;
	void drawNode(Node* node);
};

