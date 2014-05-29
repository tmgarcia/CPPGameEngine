#pragma once

#include "ParticleContactGenerator.h"

class TwoDParticleContactGenerator : public ParticleContactGenerator
{
public:
	Particle* particle[2];
	float minimumSeparation;
	float restitution;

protected:
	float currentSeparation() const;

public:
	virtual unsigned addContact(ParticleContact *contact, unsigned limit) const;
	virtual void setRestitution(float newRestitution);

};

