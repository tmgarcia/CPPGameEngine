#include "TwoDParticleContactGenerator.h"
#include <iostream>

using std::cout;
using std::endl;
float TwoDParticleContactGenerator::currentSeparation() const
{
	vec3 relativePos = particle[0]->position - particle[1]->position;
	return glm::length(relativePos);
}

unsigned TwoDParticleContactGenerator::addContact(ParticleContact *contact, unsigned limit) const
{
	unsigned result = 0;
	float separation = currentSeparation();
	//cout << "Separation" << separation << endl;
	//cout << "Minimum Separation" << minimumSeparation << endl;
	if(separation <= minimumSeparation)
	{
		cout << "separation " << separation << endl;
		cout << "minimumSeparation " << minimumSeparation << endl;
		contact->particle[0] = particle[0];
		contact->particle[1] = particle[1];

		cout << "particle[0] position " << particle[0]->position.x << ","<< particle[0]->position.y << "," << particle[0]->position.z << endl;
		cout << "particle[1] position " << particle[1]->position.x << ","<< particle[1]->position.y << "," << particle[1]->position.z << endl;


		vec3 normal = particle[0]->position - particle[1]->position;
		cout << "Contact Normal " << normal.x << ","<< normal.y << "," << normal.z << endl;
		normal = glm::normalize(normal);
		cout << "Contact Normal Normalized " << normal.x << ","<< normal.y << "," << normal.z << endl;
		contact->contactNormal = normal;

		cout << "penetration " << minimumSeparation - separation << endl;
		contact->penetration = minimumSeparation - separation;
		cout << "restitution " << restitution << endl;
		contact->restitution = restitution;

		result = 1;
	}
	return result;
}