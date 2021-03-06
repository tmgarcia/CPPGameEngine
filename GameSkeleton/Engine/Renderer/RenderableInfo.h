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
		usingShadowMap = false;
	}
	friend class GeneralGLWindow;
	ShaderInfo* howShaders;
	GLuint numUniformParameters;
	ShaderUniformParameter uniformParameters[MAX_UNIFORM_PARAMETERS];
public:
	bool enableDepth;
	bool usingAlphaMap;
	bool usingDiffuseMap;
	bool usingNormalMap;
	bool usingAmbientOcclusionMap;
	bool usingCubeMap;
	bool usingShadowMap;
	mat4 whereMatrix;
	GeometryInfo* whatGeometry;
	TextureInfo* diffuseMap;
	TextureInfo* alphaMap;
	TextureInfo* normalMap;
	TextureInfo* ambientOcclusionMap;
	TextureInfo* cubeMap;
	TextureInfo* shadowMap;
	bool visible;
	PriorityLevel priority;
};