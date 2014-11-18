#include "CellStateComponent.h"
#include "Components\RendererComponent.h"
#include "ConsolePrinter.h"
void CellStateComponent::update()
{

}
void CellStateComponent::cleanup()
{

}

void CellStateComponent::leftClickAction()
{
	clear();
}
void CellStateComponent::rightClickAction()
{
	toggleFlag();
}

void CellStateComponent::toggleFlag()
{
	if(!cleared)
	{
		if(flagged)
		{
			flagged = false;
			this->Component::parent->getComponent<RendererComponent>()->renderable->material->diffuseMap = coveredTexture;
		}
		else
		{
			flagged = true;
			this->Component::parent->getComponent<RendererComponent>()->renderable->material->diffuseMap = flaggedTexture;
		}
	}
}
void CellStateComponent::clear()
{
	if(!flagged && !cleared)
	{
		cleared = true;
		this->Component::parent->getComponent<RendererComponent>()->renderable->material->diffuseMap = clearedTexture;
		emit CellCleared(this);
	}
}