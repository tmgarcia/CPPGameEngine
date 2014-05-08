#pragma once
#include "State.h"
#include "NonPlayerCharacter.h"

class NonPlayerCharacter;

class FetchingFlagState : public State
{
public:
	void update(NonPlayerCharacter* player);

	FetchingFlagState(){}
	~FetchingFlagState(){}
};

