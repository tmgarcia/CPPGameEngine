#pragma once
class TextureInfo;
class ShaderInfo;
#include "ExportHeader.h"

class DECL_DLL_EXPORT Material
{
public:
	bool usingAlphaMap;
	bool usingDiffuseMap;
	bool usingNormalMap;
	bool usingAmbientOcclusionMap;
	bool usingCubeMap;
	bool usingShadowMap;
	TextureInfo* diffuseMap;
	TextureInfo* alphaMap;
	TextureInfo* normalMap;
	TextureInfo* ambientOcclusionMap;
	TextureInfo* cubeMap;
	TextureInfo* shadowMap;

	ShaderInfo* shader;

	Material()
	{
		usingAlphaMap = false;
		usingDiffuseMap = false;
		usingNormalMap = false;
		usingAmbientOcclusionMap = false;
		usingCubeMap = false;
		usingShadowMap = false;
	}

	void bindAllTextures();
	void sendDownShaderParameters();
};

