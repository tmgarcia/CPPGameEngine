#pragma once
#include "Entity.h"

class __declspec(dllexport) Component
{
protected:
	friend class Entity;
	Entity* parent;
public:
	virtual void update(){}
};

