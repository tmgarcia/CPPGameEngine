#pragma once

class NonPlayerCharacter;

class __declspec(dllexport) State
{
public:
	virtual void update(NonPlayerCharacter* player) = 0;
	State(){}
	~State(){}
};

