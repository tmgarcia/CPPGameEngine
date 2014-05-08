#pragma once

#include "Nodes\DebugNode.h"
using glm::mat4;
class __declspec(dllexport)Path
{
public:
	vec3 getNextPathPosition();
	void highlightPathNodes(vec3 color);
	void highlightPathConnections(vec3 color);
	void hidePathNodes();
	void hidePathConnections();
	float speed;//What percent per update ex: 10 = 10% progress between nodes each update 100% is immediately at next node
	int totalNodes;
	bool isValidPath;
	bool reachedEndNode;
	vec3 pathingObjectDefaultViewDirection;//The object being pathed's normalized view direction by default (ex 0,0,-1 facing straight in negative z direction)
	mat4 currentRotation;
	bool pathConnectionsHighlighted;
	vec3 pathConnectionHighlightColor;
	vec3 pathHighlightColor;
	bool pathHighlighted;
	DebugNode* getCurrentNode();
	Path(DebugNode** p=nullptr, int numNodes=0)
	{
		path = p;
		totalNodes = numNodes;
		cout << "numNodes " << totalNodes << endl;
		speed = 0.5;//half a "unit" per stretch
		isValidPath = numNodes>0;
		currentPathIndex = 0;
		currentStretch = 0;
		pathingObjectDefaultViewDirection = vec3(0,0,-1);
		reachedEndNode = false;
		lastPosition= vec3();
		currentRotation = mat4();
		pathHighlighted = false;
		pathConnectionsHighlighted = false;
		pathHighlightColor = vec3();
	}
	~Path(){}
private:
	DebugNode** path;
	int currentPathIndex;
	float currentStretch;
	vec3 lastPosition;
};

