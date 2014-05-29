#pragma once
#include "ParticleContact.h"

class ParticleContactGenerator
{
public:
	virtual unsigned addContact(ParticleContact *contact, unsigned limit) const = 0;
	virtual void setRestitution(float newRestitution) = 0;
};