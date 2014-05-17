#include "Particle.h"

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
