#pragma once
#include "GeometryInfo.h"
#include "ShaderInfo.h"
#include "TextureInfo.h"
#include "ShaderUniformParameter.h"
using glm::mat4;

const GLuint MAX_UNIFORM_PARAMETERS = 20;

class RenderableInfo
{
	friend class GeneralGLWindow;
	ShaderInfo* howShaders;
	bool visible;
	TextureInfo* texture;
public:
	mat4& whereMatrix;
	GeometryInfo* whatGeometry;
	GLuint numUniformParameters;
	ShaderUniformParameter uniformParameters[MAX_UNIFORM_PARAMETERS];

};