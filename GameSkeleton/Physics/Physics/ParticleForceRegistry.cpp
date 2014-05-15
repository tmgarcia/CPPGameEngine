#include "ParticleForceRegistry.h"


void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator *fg)
{
	ParticleForceRegistration reg;
	reg.fg = fg;
	reg.particle = particle;
	registrations.append(reg);
}

	//Removes given registered pari from registry
	//if pair not registered, method has no effect
void ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator *fg)
{
	ParticleForceRegistration reg;
	reg.fg = fg;
	reg.particle = particle;
	if(registrations.contains(reg))
	{
		registrations.removeAll(reg);
	}
}

	//Clears all registrations from registry
	//not delete particles / force generators, just connections
void ParticleForceRegistry::clear()
{
	registrations.clear();
}

	//Calls force generators to update forces of corresponding particles
void ParticleForceRegistry::updateForces(float duration)
{
	Registry::iterator i = registrations.begin();
	for(; i != registrations.end(); i++)
	{
		i->fg->updateForce(i->particle, duration);
	}
}