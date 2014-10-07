//#pragma once
//
//#include <glm\glm.hpp>
//#include "..\..\DebugTools\DebugShapes.h"
//
//using glm::vec3;
//
//class GameNode
//{
//public:
//	vec3 position;
//	DebugShapes::DebugShapeInfo* nodeInfo;
//	uint numConnections;
//
//	void addConnection(GameNode* n);
//	void removeConnection(GameNode* n);
//	bool isConnectedToNode(GameNode* n);
//
//	void highlightConnections(bool highlightConnectedNode);
//	void hideConnections();
//	void clearAllConnections();
//
//
//	GameNode(vec3 location)
//	{
//		position = location;
//		numConnections = 0;
//	}
//	~GameNode(){}
//
//	struct Connection
//	{
//		float cost;
//		DebugShapes::VectorArrowInfo* arrowInfo;
//		GameNode* target;
//	};
//
//};
//
