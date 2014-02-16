#pragma once
#include "GeometryInfo.h"
#include "ShaderInfo.h"
#include "TextureInfo.h"
using glm::mat4;

class RenderableInfo
{
	friend class GeneralGLWindow;
	GeometryInfo* whatGeometry;
	mat4& whereMatrix;
	ShaderInfo* howShaders;
	bool visible;
	TextureInfo* texture;
};