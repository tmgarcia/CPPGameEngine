#pragma once
#include "ShaderUniformParameter.h"
#include "PriorityLevel.h"
#include "../Assets/Material.h"
#include "../Assets/Geometry.h"
using glm::mat4;

const GLuint MAX_UNIFORM_PARAMETERS = 20;

class RenderableInfo
{
	RenderableInfo()
	{
		numUniformParameters = 0;
	}
	friend class GeneralGLWindow;
	GLuint numUniformParameters;
	ShaderUniformParameter uniformParameters[MAX_UNIFORM_PARAMETERS];
public:
	void sendRenderableParameters();
	Material* material;
	mat4 whereMatrix;
	Geometry* whatGeometry;
	bool visible;
	bool enableDepth;
	PriorityLevel priority;
};