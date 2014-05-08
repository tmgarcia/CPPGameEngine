#pragma once
#include "State.h"
#include "NonPlayerCharacter.h"

class NonPlayerCharacter;

class ReturningToBaseState : public State
{
public:
	void update(NonPlayerCharacter* player);

	ReturningToBaseState(){}
	~ReturningToBaseState(){}
};

