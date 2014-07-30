#pragma once
#include "TextureInfo.h"
#include "RenderableInfo.h"

const GLuint MAX_RENDERABLES = 600;

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
		storingColorTexture = false;
		storingDepthTexture = false;
	}
	friend class GeneralGLWindow;
public:
	TextureInfo* colorTexture;
	TextureInfo* depthTexture;
};