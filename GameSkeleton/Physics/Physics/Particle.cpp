#include "Particle.h"

#include <iostream>

using std::cout;
using std::endl;

void Particle::integrate(float dt)
{
	position += velocity * dt;

	float inverseMass = 1/mass;

	acceleration = forceAccum*inverseMass;
	velocity += acceleration *dt;
	velocity *= glm::pow(damping,dt);

	momentum = mass * velocity;

	clearAccumulator();
}
void Particle::clearAccumulator()
{
	forceAccum = vec3(0,0,0);
}
void Particle::addForce(const vec3 &force)
{
	forceAccum += force;
}
float Particle::getMomentumLength()
{
	return glm::length(momentum);
}
void Particle::newFrame(float dt, vec3 direction)
{
	velocity += acceleration * dt * damping* direction;
	position += velocity * dt;
	momentum = mass * velocity;
}
float Particle::getInverseMass()
{
	return 1/mass;
}
float Particle::getKineticEnergy()
{
	return (0.5) * mass * glm::pow(glm::length(velocity),2.0f);
}