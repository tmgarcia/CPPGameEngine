#pragma once

#include <Qt\qlist.h>

#include "EditorNode.h"
#include <iostream>
#include <fstream>
using std::ofstream;

class __declspec(dllexport)EditorNodeContainer
{
public:
	int numNodes;
	EditorNode* selectedNode;
	EditorNode* clickedNode;
	EditorNode* getRandomNode();
	void addNode(vec3 position);
	void removeNode(EditorNode* Editornode);
	bool nodeRightClicked(vec3 clickDirection, vec3 clickOrigin);
	void nodeLeftClicked(vec3 clickDirection, vec3 clickOrigin);
	void deleteSelectedNode();
	void loadInNodes(uint numNodes, char* nodeData);
	void clearAllNodes();
	void resetNodeColors();
	void highlightAllNodes(vec3 color);
	void hideAllNodes();
	ofstream* serializeNodes(ofstream *stream, uint NODE_DATA_BASE);

	EditorNodeContainer();
	~EditorNodeContainer();
private:
	QList<EditorNode*> nodes;
	void addConnection(EditorNode* node);
	bool nodeHasBeenClicked(vec3 clickDirection, vec3 clickOrigin);
};

