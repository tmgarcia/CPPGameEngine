#include "ParticleDragGenerator.h"

void ParticleDragGenerator::updateForce(Particle *particle, float duration)
{
	vec3 force = particle->velocity;

	float dragCoeff = glm::length(force);
	dragCoeff = (lowSpeed * dragCoeff) + (highSpeed * (dragCoeff * dragCoeff));

	force = glm::normalize(force);
	force *= -dragCoeff;
	particle->addForce(force);
}
