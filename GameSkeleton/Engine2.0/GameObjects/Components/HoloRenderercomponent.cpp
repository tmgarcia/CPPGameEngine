#include "HoloRenderercomponent.h"
#include "Renderer/GeneralGLWindow.h"
#include "SceneManager.h"

TextureInfo* HoloRenderercomponent::defaultDiffuseMap;
TextureInfo* HoloRenderercomponent::defaultAlphaMap;

HoloRenderercomponent::HoloRenderercomponent()
{
	if(defaultDiffuseMap == 0)
	{
		defaultDiffuseMap = GeneralGLWindow::getInstance().addTexture("Assets/Textures/defaultHoloDiffuseMap.png");
	}
	if(defaultAlphaMap == 0)
	{
		defaultAlphaMap = GeneralGLWindow::getInstance().addTexture("Assets/Textures/defaultHoloAlphaMap.png");
	}

	holoAlpha = true;
	holoDiffuse = true;
	useAlpha = true;
	holoIncrement = 0.01f;
	diffuseMap = defaultDiffuseMap;
	alphaMap = defaultAlphaMap;
}

void HoloRenderercomponent::setData(RenderableInfo* renderable)
{
	this->renderable = renderable;

	GeneralGLWindow::getInstance().addRenderableUniformParameter(this->renderable, "fullTransformMatrix", PT_MAT4, &parent->transform.fullTransformMatrix[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(this->renderable, "worldToProjectionMatrix", PT_MAT4, &SceneManager::getInstance().WORLD_TO_PROJECTION[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(this->renderable, "rotationMatrix", PT_MAT4, &parent->transform.rotationMatrix[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(this->renderable, "modelToWorldMatrix", PT_MAT4, &parent->transform.modelToWorldMatrix[0][0]);
}
void HoloRenderercomponent::setData(Geometry* geometry,bool visible,bool enableDepth,PriorityLevel priority)
{
	offsetTextureMat = new OffsetTextureMat();
	offsetTextureMat->diffuseMap = diffuseMap;
	offsetTextureMat->usingDiffuseMap = true;
	if(useAlpha)
	{
		offsetTextureMat->alphaMap = alphaMap;
		offsetTextureMat->usingAlphaMap= true;
	}
	
	offsetTextureMat->offsetDiffuse = holoDiffuse;
	offsetTextureMat->offsetAlpha = holoAlpha;

	RenderableInfo* r = GeneralGLWindow::getInstance().addRenderable(geometry, parent->transform.modelToWorldMatrix, visible, enableDepth, priority, offsetTextureMat);
	setData(r);
	offsetTextureMat->sendOffsetParameters(this->renderable);
}
void HoloRenderercomponent::update()
{
	offsetTextureMat->currentOffset.y += holoIncrement;
	renderable->whereMatrix = parent->transform.fullTransformMatrix;
}
void HoloRenderercomponent::cleanup()
{
	delete renderable->material;
	delete renderable->whatGeometry;
}