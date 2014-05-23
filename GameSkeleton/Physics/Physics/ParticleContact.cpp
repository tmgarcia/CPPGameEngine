#include "ParticleContact.h"
#include <iostream>

using std::cout;
using std::endl;
void ParticleContact::resolve(float dt)
{
	cout << "Resolving Contact" << endl;
	resolveVelocity(dt);
	resolveInterpenetration(dt);
}

float ParticleContact::calculateSeparatingVelocity() const
{
	vec3 relativeVelocity = particle[0]->velocity;
	cout << "Relative velocity " << relativeVelocity.x << ","<< relativeVelocity.y << "," << relativeVelocity.z << endl;
	if(particle[1])
	{
		relativeVelocity -= particle[1]->velocity;
		cout << "Relative velocity " << relativeVelocity.x << ","<< relativeVelocity.y << "," << relativeVelocity.z << endl;
	}
	return glm::dot(relativeVelocity, contactNormal);
}

void ParticleContact::resolveVelocity(float dt)
{
	cout << "\nResolving Velocity" << endl;
	float separatingVelocity = calculateSeparatingVelocity();

	cout << "Separating Velocity: " << separatingVelocity << endl;

	/*if(separatingVelocity > 0)
	{
		return;
	}*/

	float newSepVelocity = -separatingVelocity * restitution;
	cout << "New Separating Velocity: " << newSepVelocity << endl;

	vec3 accCausedVelocity = particle[0]->acceleration;
	if(particle[1])
	{
		accCausedVelocity -= particle[1]->acceleration;
	}

	float accCausedSepVelocity = glm::dot(accCausedVelocity, contactNormal) * dt;
	cout << "Acceleration Caused Velocity: " << accCausedSepVelocity << endl;


	if(accCausedSepVelocity <0)
	{
		newSepVelocity += restitution * accCausedSepVelocity;
		if(newSepVelocity < 0)
		{
			newSepVelocity = 0;
		}
	}

	float deltaVelocity = newSepVelocity - separatingVelocity;
	cout << "Delta Velocity: " << deltaVelocity << endl;
	float totalInverseMass = particle[0]->getInverseMass();

	if(particle[1])
	{
		totalInverseMass += particle[1]->getInverseMass();
	}
	cout << "p0 Mass: " << particle[0]->mass << endl;
	cout << "p1 Mass: " << particle[1]->mass << endl;
	cout << "p0 Inverse Mass: " << particle[0]->getInverseMass() << endl;
	cout << "p1 Inverse Mass: " << particle[1]->getInverseMass() << endl;
	cout << "Total Inverse Mass: " << totalInverseMass << endl;

	if(totalInverseMass <=0)
	{
		return;
	}

	float impulse = deltaVelocity / totalInverseMass;
	cout << "Impulse: " << impulse << endl;

	vec3 impulsePerIMass = contactNormal * impulse;
	cout << "Impulse per mass: " << impulsePerIMass.x << ","<< impulsePerIMass.y << "," << impulsePerIMass.z << endl;

	vec3 p0newVel = (particle[0]->velocity + impulsePerIMass * particle[0]->getInverseMass());
	cout << "New p0 velocity: " << p0newVel.x << ","<< p0newVel.y << "," << p0newVel.z << endl;
	particle[0]->velocity = p0newVel;

	if(particle[1])
	{
		vec3 p1newVel = particle[1]->velocity + impulsePerIMass * -particle[1]->getInverseMass();
		cout << "New p1 velocity: " << p1newVel.x << ","<< p1newVel.y << "," << p1newVel.z << endl;
		particle[1]->velocity = p1newVel;
	}
}

void ParticleContact::resolveInterpenetration(float dt)
{
	cout << "\nResolving Interpenetration" << endl;
	cout << "Penetration: " << penetration <<endl;
	if(penetration<=0)
	{
		return;
	}

	float totalInverseMass = particle[0]->getInverseMass();
	if(particle[1])
	{
		totalInverseMass += particle[1]->getInverseMass();
	}
	cout << "totalInverseMass" << totalInverseMass << endl;
	if(totalInverseMass <= 0)
	{
		return;
	}

	vec3 movePerIMass = contactNormal * (penetration / totalInverseMass);
	cout << "movePerIMass: " << movePerIMass.x << ","<< movePerIMass.y << "," << movePerIMass.z << endl;

	particleMovement[0] = movePerIMass * -particle[0]->getInverseMass();
	if(particle[1])
	{
		particleMovement[1] = movePerIMass * particle[1]->getInverseMass();
	}
	else
	{
		particleMovement[1] = vec3(0,0,0);
	}
	cout << "current particle position [0]: " << particle[0]->position.x << ","<< particle[0]->position.y << "," << particle[0]->position.z << endl;
	cout << "current particle position [1]: " << particle[1]->position.x << ","<< particle[1]->position.y << "," << particle[1]->position.z << endl;

	cout << "particle movement [0]: " << particleMovement[0].x << ","<< particleMovement[0].y << "," << particleMovement[0].z << endl;
	cout << "particle movement [1]: " << particleMovement[1].x << ","<< particleMovement[1].y << "," << particleMovement[1].z << endl;

	particle[0]->position = particle[0]->position + particleMovement[0];
	cout << "new particle position [0]: " << particle[0]->position.x << ","<< particle[0]->position.y << "," << particle[0]->position.z << endl;

	if(particle[1])
	{
		particle[1]->position = particle[1]->position + particleMovement[1];
		cout << "new particle position [1]: " << particle[1]->position.x << ","<< particle[1]->position.y << "," << particle[1]->position.z << endl;
	}

	vec3 relativePos = particle[0]->position - particle[1]->position;
	float newSeparation =  glm::length(relativePos);

	cout << "new separation: " << newSeparation << endl;


	cout << endl;
}