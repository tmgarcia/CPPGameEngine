#include "Particle.h"

void Particle::integrate(float dt)
{
	acceleration = forceAccum/mass;
	velocity += acceleration * dt * damping;
	position += velocity * dt;
	momentum = mass * velocity;
	clearAccumulator();
}
void Particle::clearAccumulator()
{
	forceAccum = vec3();
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
