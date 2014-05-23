#include "ParticleContactResolver.h"
#include <iostream>

using std::cout;
using std::endl;

void ParticleContactResolver::resolveContacts(ParticleContact *contactArray, unsigned numContacts, float dt)
{
	unsigned i;

	iterationsUsed = 0;

	while(iterationsUsed < iterations)
	{
		float max = FLT_MAX;
		unsigned maxIndex = numContacts;
		
		for(i = 0; i < numContacts; i++)
		{
			float sepVel = contactArray[i].calculateSeparatingVelocity();
			if(sepVel < max && (sepVel < 0 || contactArray[i].penetration > 0))
			{
				max = sepVel;
				maxIndex = i;
			}
		}

		if(maxIndex == numContacts)
		break;

		contactArray[maxIndex].resolve(dt);
		iterationsUsed++;
	}

}

void ParticleContactResolver::setIterations(unsigned iterations)
{
	ParticleContactResolver::iterations = iterations;
}