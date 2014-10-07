#include "RendererComponent.h"
#include "../../Renderer/GeneralGLWindow.h"

void RendererComponent::setData(RenderableInfo* renderable)
{
	this->renderable = renderable;

	GeneralGLWindow::getInstance().addRenderableUniformParameter(this->renderable, "fullTransformMatrix", PT_MAT4, &parent->transform.fullTransformMatrix[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(this->renderable, "worldToProjectionMatrix", PT_MAT4, &parent->transform.worldToProjectionMatrix[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(this->renderable, "rotationMatrix", PT_MAT4, &parent->transform.rotationMatrix[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(this->renderable, "modelToWorldMatrix", PT_MAT4, &parent->transform.modelToWorldMatrix[0][0]);
}
void RendererComponent::setData(Geometry* geometry,bool visible,bool enableDepth,PriorityLevel priority,Material* material)
{
	RenderableInfo* r = GeneralGLWindow::getInstance().addRenderable(geometry, parent->transform.modelToWorldMatrix, visible, enableDepth, priority, material);
	setData(r);
}
void RendererComponent::update()
{
	renderable->whereMatrix = parent->transform.fullTransformMatrix;
}