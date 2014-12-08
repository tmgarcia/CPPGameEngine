#pragma once
#include "../Component.h"
#include "../../Renderer/RenderableInfo.h"
#include "../../Renderer/TextureInfo.h"
#include "ExportHeader.h"
#include "Assets\Presets\Materials\OffsetTextureMat.h"

class DECL_DLL_EXPORT HoloRenderercomponent : public Component
{
public:
	RenderableInfo* renderable;
	TextureInfo* diffuseMap;
	TextureInfo* alphaMap;
	bool holoDiffuse;
	bool holoAlpha;
	bool useAlpha;
	HoloRenderercomponent();
	void setData(RenderableInfo* renderable);
	void setData(Geometry* geometry,bool visible,bool enableDepth,PriorityLevel priority);
	void update();
	void cleanup();
	float holoIncrement;
	OffsetTextureMat* offsetTextureMat;
private:
	static TextureInfo* defaultDiffuseMap;
	static TextureInfo* defaultAlphaMap;
};

