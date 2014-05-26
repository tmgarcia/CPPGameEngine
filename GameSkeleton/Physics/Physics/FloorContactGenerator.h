#pragma once
#include "ParticleContactGenerator.h"

class FloorContactGenerator : public ParticleContactGenerator
{
public:
	Particle* particle;
	float yPositionOfFloor;
	float restitution;
	float minimumSeparation;

protected:
	float currentSeparation() const;

public:
	virtual unsigned addContact(ParticleContact *contact, unsigned limit) const;
};

