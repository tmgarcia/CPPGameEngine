#pragma once

#include "AStarData\Path.h"
#include "ObjReader.h"
class Character
{
public:
	GeometryInfo* geometry;
	RenderableInfo* renderable;
	ShaderInfo* shader;
	ObjReader::ShapeData shapeData;
	mat4 modelToWorldTransform;
	mat4 rotation;
	mat4 fullTransform;
	Path path;
	Character()
	{

	}
	~Character();
};

