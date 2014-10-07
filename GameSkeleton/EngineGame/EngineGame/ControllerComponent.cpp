#include "ControllerComponent.h"
#include "GameObjects\Entity.h"
#include "Input\KeyInput.h"
#include "InputActions.h"
#include "GameObjects\Components\PhysicsComponent.h"

void ControllerComponent::update()
{
	if(KeyInput::getInstance().actionsActive(INPUT_ACT_ACCELERATE_X))
	{
		parent->getComponent<PhysicsComponent>()->addForce(vec3(speed,0,0));
	}
	if(KeyInput::getInstance().actionsActive(INPUT_ACT_REVERSE_X))
	{
		parent->getComponent<PhysicsComponent>()->addForce(vec3(-speed,0,0));
	}
	if(KeyInput::getInstance().actionsActive(INPUT_ACT_ACCELERATE_Y))
	{
		parent->getComponent<PhysicsComponent>()->addForce(vec3(0,speed,0));
	}
	if(KeyInput::getInstance().actionsActive(INPUT_ACT_REVERSE_Y))
	{
		parent->getComponent<PhysicsComponent>()->addForce(vec3(0,-speed,0));
	}
	if(KeyInput::getInstance().actionsActive(INPUT_ACT_ACCELERATE_Z))
	{
		parent->getComponent<PhysicsComponent>()->addForce(vec3(0,0,speed));
	}
	if(KeyInput::getInstance().actionsActive(INPUT_ACT_REVERSE_Z))
	{
		parent->getComponent<PhysicsComponent>()->addForce(vec3(0,0,-speed));
	}
}