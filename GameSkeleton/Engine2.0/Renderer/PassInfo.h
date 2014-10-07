#pragma once
#include "TextureInfo.h"
#include "RenderableInfo.h"

const GLuint MAX_RENDERABLES = 600;
const GLuint MAX_OVERRIDE_UNIFORM_PARAMETERS = 20;
class PassInfo
{
	bool storingColorTexture;
	bool storingDepthTexture;
	GLuint frameBufferID;
	int numRenderables;
	GLuint index;
	RenderableInfo* renderables[MAX_RENDERABLES];
	PassInfo()
	{
		numRenderables = 0;
		numOverridingUniformParameters = 0;
		storingColorTexture = false;
		storingDepthTexture = false;
		drawToScreen = true;
		uniformParametersOverrideBufferDraw = false;
		uniformParametersOverrideScreenDraw = false;
	}
	friend class GeneralGLWindow;
public:
	int numOverridingUniformParameters;
	ShaderUniformParameter overridingUniformParameters[MAX_OVERRIDE_UNIFORM_PARAMETERS];
	TextureInfo* colorTexture;
	TextureInfo* depthTexture;
	bool uniformParametersOverrideBufferDraw;
	bool uniformParametersOverrideScreenDraw;
	bool drawToScreen;
};