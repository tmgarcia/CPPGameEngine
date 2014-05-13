#include "VelocityAcceleration.h"
#include <PhysicsGui\VectorGraphic.h>
#include <Qt\qdebug.h>

VectorGraphic* particleGraphic;
VectorGraphic* velocityGraphic;

glm::vec3 velocity;
glm::vec3 position;

void VelocityAcceleration::initialize()
{
	GuiBase::initialize(false, true);
	position = glm::vec3(0,0,0.5f);
	velocity = glm::vec3(0,0,0);

	particleGraphic = addVectorGraphic();
	particleGraphic->position = position;
	particleGraphic->displayStyle = DS_POINT;

	velocityGraphic = addVectorGraphic();
	velocityGraphic->displayStyle = DS_ARROW;
	velocityGraphic->r = 255;
}

void VelocityAcceleration::newFrame()
{
	float acceleration = 1.00f;
	velocity += acceleration * dt() * getUserDirection();
	position += velocity * dt();
	sync(particleGraphic, position);
	sync(velocityGraphic, velocity, position);
}

void VelocityAcceleration::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	position += dragDelta;
}

glm::vec3 VelocityAcceleration::getUserDirection()
{
	glm::vec3 direction = glm::vec3();
	//initialize then show
	if(isKeyDown("up"))
	{
		direction += glm::vec3(0,1,0);
		glm::normalize(direction);
	}
	if(isKeyDown("down"))
	{
		direction += glm::vec3(0,-1,0);
		glm::normalize(direction);
	}
	if(isKeyDown("left"))
	{
		direction += glm::vec3(-1,0,0);
		glm::normalize(direction);
	}
	if(isKeyDown("right"))
	{
		direction += glm::vec3(1,0,0);
		glm::normalize(direction);
	}

	return direction;
}
