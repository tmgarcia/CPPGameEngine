#pragma once

#include "AStarData\Path.h"
#include "BinReader.h"
#include "AStarData\Nodes\DebugNode.h"
class MapLerper
{
public:
public:
	
	void updatePathPosition();
	void updateFullTransform(mat4 worldToProjectionMatrix);

	vec3 getPosition();
	mat4 getRotation();
	DebugNode* getBaseNode();
	DebugNode* getCurrentNode();

	void setSpeed(float s);
	void setVisible(bool visible);
	void startPathing();
	void stopPathing();

	bool reachedCurrentGoalNode();
	bool isCurrentlyPathing();

	void highlightPathNodes(vec3 color);
	void hidePathNodes();
	void highlightPathConnections(vec3 color);
	void hidePathConnections();

	MapLerper(){}
	MapLerper(QString modelFile, DebugNode* base, mat4 worldToProjectionMatrix);
	~MapLerper(){}

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

	GeometryInfo* geometry;
	RenderableInfo* renderable;
	ShaderInfo* shader;
	BinReader::ShapeData shapeData;
	mat4 modelToWorldTransform;
	mat4 rotation;
	mat4 fullTransform;
	mat4 worldToProjection;
};
