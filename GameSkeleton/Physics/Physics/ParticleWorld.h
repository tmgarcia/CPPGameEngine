#pragma once
#include <vector>
#include "Particle.h"
#include "ParticleContactGenerator.h"
#include "ParticleContactResolver.h"
#include "ParticleContact.h"
#include "ParticleForceRegistry.h"

using std::vector;

class ParticleWorld
{
public:
	vec3 preContactVelocity;
	typedef std::vector<Particle*> Particles;
	Particles particles;

	ParticleWorld(unsigned maxContacts=1, unsigned iterations = -1): maxContacts(maxContacts), resolver(iterations)
	{
		calculateIterations = (iterations==-1);
		resolver = ParticleContactResolver(iterations);
	}

	void startFrame();

	typedef vector<ParticleContactGenerator*> ContactGenerators;
	ParticleForceRegistry registry;

	ParticleContactResolver resolver;

	ContactGenerators contactGenerators;

	ParticleContact *contacts;

	unsigned maxContacts;
	bool calculateIterations;

	unsigned generateContacts();

	void integrate(float dt);

	void runPhysics(float dt);
};

