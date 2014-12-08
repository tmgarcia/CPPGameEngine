#include "CellStateComponent.h"
#include "Components\RendererComponent.h"
#include "Components\HoloRenderercomponent.h"
#include "GameObjects\Entity.h"
#include "ConsolePrinter.h"
void CellStateComponent::update()
{
	if(!cleared)
	{
		this->coveredEntity->update();
	}
	else
	{
		this->clearedEntity->update();
	}
	if(flagged)
	{
		this->flaggedEntity->update();
	}
	//this->clearedEntity->update();
	if((!containsMine && numAdjacentMines > 0) || containsMine)
	{
		this->clearedEntity->update();
	}
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
			this->flaggedEntity->getComponent<HoloRenderercomponent>()->renderable->visible = false;
			//this->Component::parent->getComponent<RendererComponent>()->renderable->material->diffuseMap = coveredTexture;
		}
		else
		{
			flagged = true;
			this->flaggedEntity->getComponent<HoloRenderercomponent>()->renderable->visible = true;
			//this->Component::parent->getComponent<RendererComponent>()->renderable->material->diffuseMap = flaggedTexture;
		}
	}
}
void CellStateComponent::clear()
{
	if(!flagged && !cleared)
	{
		cleared = true;
		this->coveredEntity->getComponent<HoloRenderercomponent>()->renderable->visible = false;
		//this->clearedEntity->getComponent<HoloRenderercomponent>()->renderable->visible = true;
		if((!containsMine && numAdjacentMines > 0) || containsMine)
		{
			this->clearedEntity->getComponent<HoloRenderercomponent>()->renderable->visible = true;
		}
		this->Component::parent->getComponent<RendererComponent>()->renderable->visible = true;
		emit CellCleared(this);
	}
}