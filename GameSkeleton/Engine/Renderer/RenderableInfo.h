#pragma once
#include "GeometryInfo.h"
#include "ShaderInfo.h"
#include "TextureInfo.h"
#include "ShaderUniformParameter.h"
#include "PriorityLevel.h"
using glm::mat4;

const GLuint MAX_UNIFORM_PARAMETERS = 20;

class RenderableInfo
{
	RenderableInfo()
	{
		numUniformParameters = 0;
	}
	friend class GeneralGLWindow;
	ShaderInfo* howShaders;
	GLuint numUniformParameters;
	ShaderUniformParameter uniformParameters[MAX_UNIFORM_PARAMETERS];
public:
	bool enableDepth;
	mat4 whereMatrix;
	GeometryInfo* whatGeometry;
	TextureInfo* texture;
	bool visible;
	PriorityLevel priority;
};