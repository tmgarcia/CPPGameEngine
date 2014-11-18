#pragma once
#include "../../Material.h"

class RenderableInfo;
class ShaderInfo;
#include "ExportHeader.h"

class DECL_DLL_EXPORT LightingAndTextureMat : public Material
{
public:
	static ShaderInfo* LightTextureShader;
	LightingAndTextureMat();
	/*TextureInfo* diffuseMap;
	TextureInfo* alphaMap;
	TextureInfo* normalMap;
	TextureInfo* ambientOcclusionMap;
	TextureInfo* cubeMap;
	TextureInfo* shadowMap;*/
	void addDiffuseMap(const char* fileName);
	void addAlphaMap(const char* fileName);
	void addNormalMap(const char* fileName);
	void addAmbientOcclusionMap(const char* fileName);
	void addCubeMap(const char* fileName);
	void addShadowMap(const char* fileName);
	void addLightingParameters(RenderableInfo* renderable);
};

