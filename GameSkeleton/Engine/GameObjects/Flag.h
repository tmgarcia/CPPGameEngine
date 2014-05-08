#pragma once

#include "../AStarData/Nodes/DebugNode.h"
#include "../BinReader.h"

class __declspec(dllexport) Flag
{
public:
	void setAtNode(DebugNode* node);
	void setPosition(vec3 p);
	vec3 getPosition();
	DebugNode* getCurrentNode();
	void update(mat4 worldToProjectionMatrix);

	Flag(char* modelFile, DebugNode* startNode, mat4 worldToProjectionMatrix)
	{
		currentNode = startNode;
		position = currentNode->position;
		worldToProjection = worldToProjectionMatrix;
		loadModel(modelFile);
	}
	Flag()
	{
		//currentNode = startNode;
		//position = currentNode->position;
		//worldToProjection = worldToProjectionMatrix;
		//loadModel(modelFile);
	}
	~Flag(){}

private:
	void loadModel(char* modelFile);
	void renderModel();

	vec3 position;
	DebugNode* currentNode;

	mat4 worldToProjection;
	GeometryInfo* geometry;
	RenderableInfo* renderable;
	ShaderInfo* shader;
	BinReader::ShapeData shapeData;
	mat4 modelToWorldTransform;
	mat4 rotation;
	mat4 fullTransform;
};

