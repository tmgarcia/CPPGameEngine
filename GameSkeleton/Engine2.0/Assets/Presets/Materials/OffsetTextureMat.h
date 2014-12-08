#pragma once
#pragma warning( disable : 4251 )

#include "../../Material.h"

class RenderableInfo;
class ShaderInfo;
#include "ExportHeader.h"
#include "glm\glm.hpp"

class DECL_DLL_EXPORT OffsetTextureMat : public Material
{
public:
	static ShaderInfo* OffsetTextureShader;
	OffsetTextureMat();
	void setDiffuseMap(const char* fileName);
	void setAlphaMap(const char* fileName);
	void sendOffsetParameters(RenderableInfo* renderable);
	glm::vec2 currentOffset;
	bool offsetAlpha;
	bool offsetDiffuse;
	void sendDownShaderParameters();
};

