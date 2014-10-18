#pragma once

#include <list>
#include <glm\glm.hpp>
#include "Node.h"
#include "..\..\DebugTools\DebugShapes.h"

using std::list;
using glm::vec3;

class __declspec(dllexport) DebugNode : public Node
{
public:
	DebugShapes::DebugShapeInfo* nodeInfo;
	void highlight(vec3 color);
	void highlightConnection(DebugNode* n, vec3 color);
	void setVisible(bool isVisible);
	void removeConnection(DebugNode* n);
	void addConnection(DebugNode* n, float cost);
	void highlightAllConnections(vec3 color);
	void hideConnections();
	void clearConnections();
	bool connectedToNode(DebugNode* n);
	DebugNode* getRandomConnection();

	DebugNode(vec3 location) : Node(location)
	{
	}
	~DebugNode();
	struct Connection
	{
		float cost;
		DebugShapes::VectorArrowInfo* arrowInfo;
		DebugNode* node;
	};
	QList<Connection*> connections;
private:
	int findConnection(DebugNode* n);
};

