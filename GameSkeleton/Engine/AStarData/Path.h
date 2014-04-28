#pragma once

#include "EditorNode.h"
using glm::mat4;
class __declspec(dllexport)Path
{
public:
	mat4 getNextPathTransform();
	float speed;//What percent per update ex: 10 = 10% progress between nodes each update 100% is immediately at next node
	int totalNodes;
	bool isValidPath;
	bool reachedEndNode;
	vec3 pathingObjectDefaultViewDirection;//The object being pathed's normalized view direction by default (ex 0,0,-1 facing straight in negative z direction)
	mat4 currentRotation;
	Path(EditorNode** p=nullptr, int numNodes=0)
	{
		path = p;
		totalNodes = numNodes;
		speed = 1;//Default 10% per update, or 0.1
		isValidPath = numNodes>0;
		currentPathIndex = 0;
		currentStretch = 0;
		pathingObjectDefaultViewDirection = vec3(0,0,-1);
		reachedEndNode = false;
		lastTransform = mat4();
		currentRotation = mat4();
	}
	~Path(){}
private:
	EditorNode** path;
	int currentPathIndex;
	float currentStretch;
	mat4 lastTransform;
};

