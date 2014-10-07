#include "Entity.h"
#include "Component.h"

Entity::Entity()
{
	numComponents = 0;
}

void Entity::addComponent(Component* c)
{
	//check that num components < max num components
	components[numComponents] = c;
	numComponents++;
	c->parent = this;
}

void Entity::update(mat4 worldToProjectionMatrix)
{
	transform.update(worldToProjectionMatrix);
	for(int i = 0; i < numComponents; i++)
	{
		components[i]->update();
	}
}