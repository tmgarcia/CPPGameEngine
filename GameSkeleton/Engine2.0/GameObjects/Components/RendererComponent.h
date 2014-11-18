#pragma once
#include "../Component.h"
#include "../../Renderer/RenderableInfo.h"
#include "ExportHeader.h"

class DECL_DLL_EXPORT RendererComponent : public Component
{
public:
	RenderableInfo* renderable;
	void setData(RenderableInfo* renderable);
	void setData(Geometry* geometry,bool visible,bool enableDepth,PriorityLevel priority,Material* material);
	void update();
	void cleanup();
};

