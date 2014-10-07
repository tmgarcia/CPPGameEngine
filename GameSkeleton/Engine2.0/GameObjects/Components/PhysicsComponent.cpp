#include "PhysicsComponent.h"
#include "../../Time/GameClock.h"

#include "../../DebugTools/ConsolePrinter.h"
void PhysicsComponent::clearForces()
{
	forceAccum = vec3(0,0,0);
}
void PhysicsComponent::addForce(vec3 force)
{
	forceAccum += force;
}

void PhysicsComponent::update()
{
	float dt = GameClock::getInstance().dt();

	parent->transform.position += (velocity * damping);
	float inverseMass = 1/mass;

	acceleration = forceAccum*inverseMass;
	velocity += acceleration;
	//velocity *= glm::pow(damping, dt);

	momentum = mass * velocity;

	clearForces();
}