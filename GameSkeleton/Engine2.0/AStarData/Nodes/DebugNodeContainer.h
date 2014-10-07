//#pragma once
//
//#include <Qt\qlist.h>
//#include <glm\glm.hpp>
//
//#include "NodeContainer.h"
//#include "DebugNode.h"
//#include <iostream>
//#include <fstream>
//using std::ofstream;
//using glm::vec3;
//
//class __declspec(dllexport) DebugNodeContainer: public NodeContainer
//{
//
//public:
//	static DebugNodeContainer& getInstance();
//private:
//	static DebugNodeContainer* theInstance;
//	DebugNodeContainer()
//	{
//	}
//	DebugNodeContainer(const DebugNodeContainer&);
//	DebugNodeContainer& operator = (const DebugNodeContainer&);
//
//public:
//	DebugNode* getNode(int index);
//	int numNodes;
//	DebugNode* selectedNode;
//	DebugNode* clickedNode;
//	DebugNode* getRandomNode();
//	void addNode(vec3 position);
//	void removeNode(DebugNode* debugNode);
//	bool nodeRightClicked(vec3 clickDirection, vec3 clickOrigin);
//	void nodeLeftClicked(vec3 clickDirection, vec3 clickOrigin);
//	void deleteSelectedNode();
//	void loadInNodes(uint numNodes, char* nodeData);
//	void clearAllNodes();
//	void resetNodeColors();
//	void highlightAllNodes(vec3 color);
//	void hideAllNodes();
//	ofstream* serializeNodes(ofstream *stream, uint NODE_DATA_BASE);
//
//	~DebugNodeContainer();
//private:
//	QList<DebugNode*> nodes;
//	void addConnection(DebugNode* node);
//	bool nodeHasBeenClicked(vec3 clickDirection, vec3 clickOrigin);
//};
//
