#include "ParticleGravityGenerator.h"


void ParticleGravityGenerator::updateForce(Particle *particle, float duration)
{
	//check that particle does not have infinite mass

	particle->addForce(gravity * particle->mass);
}