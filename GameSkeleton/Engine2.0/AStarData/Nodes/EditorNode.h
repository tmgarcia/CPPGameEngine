#pragma once

#include <list>
#include <glm\glm.hpp>
#include "Node.h"
#include "..\..\DebugTools\DebugShapes.h"

using std::list;
using glm::vec3;
#include "ExportHeader.h"

class DECL_DLL_EXPORT EditorNode : public Node
{
public:
	DebugShapes::DebugShapeInfo* nodeInfo;
	void highlight(vec3 color);
	void highlightConnection(EditorNode* n, vec3 color);
	void setVisible(bool isVisible);
	void toggleConnection(EditorNode* n);
	void addConnection(EditorNode* n, float cost);
	void highlightAllConnections(vec3 color);
	void hideConnections();
	void clearConnections();
	bool connectedToNode(EditorNode* n);
	EditorNode* getRandomConnection();

	EditorNode(vec3 location) : Node(location)
	{
	}
	~EditorNode();
	struct ConnectingNode
	{
		float cost;
		DebugShapes::VectorArrowInfo* arrowInfo;
		EditorNode* node;
	};
	QList<ConnectingNode*> connections;
private:
	void removeConnection(EditorNode* n);
	int findConnection(EditorNode* n);
};

