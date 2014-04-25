#pragma once

#include <Qt\qlist.h>

#include "Node.h"
#include <iostream>
#include <fstream>
using std::ofstream;

class NodeContainer
{
public:
	int numNodes;
	Node* selectedNode;
	Node* clickedNode;
	void addNode(vec3 position);
	void removeNode(Node* node);
	bool nodeRightClicked(vec3 clickDirection, vec3 clickOrigin);
	void nodeLeftClicked(vec3 clickDirection, vec3 clickOrigin);
	void deleteSelectedNode();
	void loadInNodes(uint numNodes, char* nodeData);
	void clearAllNodes();

	ofstream* serializeNodes(ofstream *stream, uint NODE_DATA_BASE);

	NodeContainer();
	~NodeContainer();
private:
	QList<Node*> nodes;
	void resetNodeColors();
	void addConnection(Node* node);
	bool nodeHasBeenClicked(vec3 clickDirection, vec3 clickOrigin);
};

