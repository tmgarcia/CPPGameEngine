#include "Character.h"


Character::~Character(void)
{
}

void Character::updatePosition()
{
	vec3 newPosition = path.getNextPathPosition();
	mat4 nextTranslation = glm::translate(newPosition);
	mat4 nextRotation = path.currentRotation;
	modelToWorldTransform = nextTranslation * nextRotation;
	position = newPosition;
	renderable->whereMatrix = modelToWorldTransform;
	rotation = nextRotation;
}