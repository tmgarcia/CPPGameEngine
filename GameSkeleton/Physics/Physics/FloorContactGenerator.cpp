#include "FloorContactGenerator.h"
#include <iostream>

using std::cout;
using std::endl;

float FloorContactGenerator::currentSeparation() const
{
	float separation = particle->position.y - yPositionOfFloor;
	return separation;
}

void FloorContactGenerator::setRestitution(float newRestitution)
{
	restitution = newRestitution;
}

unsigned FloorContactGenerator::addContact(ParticleContact *contact, unsigned limit) const
{
	unsigned result = 0;
	float separation = currentSeparation();

	if(separation < minimumSeparation)
	{
		contact->particle[0] = particle;
		contact->particle[1] = NULL;
		
		vec3 normal = vec3(0,1,0);
		normal = glm::normalize(normal);
		contact->contactNormal = normal;

		float penetration = minimumSeparation - separation;
		contact->penetration = minimumSeparation - separation;
		//cout<< endl;
		//cout<< "min sep " << minimumSeparation << " sep " << separation << " penetration " << penetration << endl;
		contact->restitution = restitution;
		result = 1;
	}

	return result;
}