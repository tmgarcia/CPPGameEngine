#include "Particle.h"

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
