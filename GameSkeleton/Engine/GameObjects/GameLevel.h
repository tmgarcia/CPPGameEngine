#pragma once
#include "..\BinReader.h"
#include "..\Renderer\GeneralGLWindow.h"
#include "..\AStarData\Nodes\DebugNodeContainer.h"
#include "..\AStarData\Nodes\DebugNode.h"

class __declspec(dllexport) GameLevel
{
public:
	static GameLevel& getInstance();
private:
	static GameLevel* theInstance;
	GameLevel()
	{
		lightPosition = vec3(0.0f, 5.0f, 0.0f);
		diffusionIntensity = 1;
		specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
		specularExponent = 100;
		eyePosition;
		overridingObjectColor = vec3(0.5,0.5,0.5);
		ambientLight = vec3(0.4f, 0.4f, 0.4f);

		modelToWorldTransform = mat4();
		rotation = mat4();
		fullTransform = mat4();
	}
	GameLevel(const GameLevel&);
	GameLevel& operator = (const GameLevel&);


public:
	void loadLevel(QString fileName);
	void update(vec3 eye, mat4 worldToProjection);
	void setLightPosition(vec3 p);
	void setEyePosition(vec3 p);
	void setVisible(bool visible);

	DebugNode* baseNode;
	vec3 lightPosition;
	float diffusionIntensity;
	vec4 specularColor;
	float specularExponent;
	vec3 eyePosition;
	vec3 overridingObjectColor;
	vec3 ambientLight;
	~GameLevel(){}
private:
	void setupLevelGeometry();

	GeometryInfo* geometry;
	RenderableInfo* renderable;
	ShaderInfo* shader;
	DiffuseMapInfo* texture;
	BinReader::ShapeData shapeData;

	mat4 modelToWorldTransform;
	mat4 rotation;
	mat4 fullTransform;

};

