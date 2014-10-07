#pragma once
#include "../../Material.h"

class __declspec(dllexport) LightingAndTextureMat : Material
{
public:
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
};

