#pragma once
#include "GeometryInfo.h"
#include "ShaderInfo.h"
#include "DiffuseMapInfo.h"
#include "AlphaMapInfo.h"
#include "AmbientOcclusionMapInfo.h"
#include "NormalMapInfo.h"
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
	bool usingAlphaMap;
	bool usingDiffuseMap;
	bool usingNormalMap;
	bool usingAmbientOcclusionMap;
	mat4 whereMatrix;
	GeometryInfo* whatGeometry;
	DiffuseMapInfo* diffuseMap;
	AlphaMapInfo* alphaMap;
	NormalMapInfo* normalMap;
	AmbientOcclusionMapInfo* ambientOcclusionMap;
	bool visible;
	PriorityLevel priority;
};