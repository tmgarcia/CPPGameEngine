#pragma once
#include "../Component.h"
#include "../../Renderer/RenderableInfo.h"

class __declspec(dllexport) RendererComponent : public Component
{
	RenderableInfo* renderable;
public:
	void setData(RenderableInfo* renderable);
	void setData(Geometry* geometry,bool visible,bool enableDepth,PriorityLevel priority,Material* material);
	void update();
};

