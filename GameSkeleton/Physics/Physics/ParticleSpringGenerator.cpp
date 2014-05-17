#include "ParticleSpringGenerator.h"

#include <iostream>

using std::cout;
using std::endl;

void ParticleSpringGenerator::updateForce(Particle *particle, float duration)
{
	/*vec3 force;
	force = particle->position;
	force -= other->position;

	cout << "spring Constant " << springConstant << endl;
	cout << "rest length " << restLength << endl;

	float magnitude = glm::length(force);
	cout << "magnitude = glm::length(force) = " << magnitude << endl;
	magnitude = (magnitude - restLength);
	cout << "magnitude = magnitude-restLength = " << magnitude << endl;
	magnitude *= springConstant;
	cout << "magnitude *= springConstant = " << magnitude << endl;

	force = glm::normalize(force);
	force *= -magnitude;*/

	vec3 vectorBetweenParticles = particle->position - other->position;
	float distanceBetweenparticles = glm::length(vectorBetweenParticles);

	float distanceBetweenLengthAndRestLength = distanceBetweenparticles-restLength;

	float k = springConstant;

	float f = -k * distanceBetweenLengthAndRestLength;

	vec3 forceVector = glm::normalize(vectorBetweenParticles) * f;

	particle->addForce(forceVector);
}