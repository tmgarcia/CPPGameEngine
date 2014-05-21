#include "ParticleWorld.h"
#include <iostream>

using std::cout;
using std::endl;

unsigned ParticleWorld::generateContacts()
{
	unsigned limit = maxContacts;
	ParticleContact *nextContact = contacts;

	for(ContactGenerators::iterator g = contactGenerators.begin(); g != contactGenerators.end() && limit>0; g++)
	{
		unsigned used = (*g)->addContact(nextContact, limit);
		limit -=used;
		nextContact += used;

		if(limit<=0)
			break;
	}
	return maxContacts - limit;
}

void ParticleWorld::integrate(float dt)
{
	for(Particles::iterator p = particles.begin(); p != particles.end(); p++)
	{
		(*p)->integrate(dt);
	}
}

void ParticleWorld::runPhysics(float dt)
{
	registry.updateForces(dt);
	integrate(dt);
	unsigned usedContacts = generateContacts();
	if(usedContacts)
	{
		cout << "used contacts " << usedContacts << endl;
		if(calculateIterations)
		{
			resolver.setIterations(usedContacts * 2);
			resolver.resolveContacts(contacts, usedContacts, dt);
		}
		else
		{
			resolver.resolveContacts(contacts, usedContacts, dt);
		}
	}
}