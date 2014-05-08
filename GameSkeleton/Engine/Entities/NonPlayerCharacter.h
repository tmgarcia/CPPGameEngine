#pragma once
#include "..\AStarData\Path.h"
#include "..\BinReader.h"
#include "..\AStarData\Nodes\DebugNode.h"
#include "State.h"

class __declspec(dllexport) NonPlayerCharacter
{
public:
	
	void updatePathPosition();
	void updateFullTransform(mat4 worldToProjectionMatrix);

	vec3 getPosition();
	mat4 getRotation();
	State* getState();
	DebugNode* getBaseNode();
	DebugNode* getCurrentNode();

	void setSpeed(float s);
	void setVisible(bool visible);
	void setState(State* s);
	void startPathing(DebugNode* endNode);
	void stopPathing();
	void setNewPathGoal(DebugNode* endNode);

	bool reachedCurrentGoalNode();
	bool isCurrentlyPathing();

	void highlightPathNodes(vec3 color);
	void hidePathNodes();
	void highlightPathConnections(vec3 color);
	void hidePathConnections();

	bool hasFlag;

	NonPlayerCharacter(){}
	NonPlayerCharacter(QString modelFile, DebugNode* base, mat4 worldToProjectionMatrix);
	~NonPlayerCharacter(){}

private:
	void loadModel(QString filename);
	void renderModel();
	void setupPath();

	float speed;
	Path path;
	vec3 position;
	bool isPathing;
	DebugNode* baseNode;
	DebugNode* currentNode;
	DebugNode* currentGoalNode;
	State* state;

	GeometryInfo* geometry;
	RenderableInfo* renderable;
	ShaderInfo* shader;
	BinReader::ShapeData shapeData;
	mat4 modelToWorldTransform;
	mat4 rotation;
	mat4 fullTransform;
	mat4 worldToProjection;
};

