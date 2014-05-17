#pragma once	

#include "Qt\qlist.h"
#include "Particle.h"
#include "ParticleForceGenerator.h"

class ParticleForceRegistry
{
protected:
	//keep track of one force generator & particle applied to
	struct ParticleForceRegistration
	{
		Particle *particle;
		ParticleForceGenerator *fg;
		inline bool operator==(const ParticleForceRegistration& rhs)
		{ /* do actual comparison */ 
			return(particle == rhs.particle && fg == rhs.fg);
		}
	};

	//Holds lis tof registrations
	typedef QList<ParticleForceRegistration> Registry;
	Registry registrations;
	
public:
	//Registers given force generator to apply to given particle
	void add(Particle* particle, ParticleForceGenerator *fg);

	//Removes given registered pari from registry
	//if pair not registered, method has no effect
	void remove(Particle* particle, ParticleForceGenerator *fg);

	//Clears all registrations from registry
	//not delete particles / force generators, just connections
	void clear();

	//Calls force generators to update forces of corresponding particles
	void updateForces(float dt);
};

