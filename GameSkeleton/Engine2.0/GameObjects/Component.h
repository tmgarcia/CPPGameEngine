#pragma once
#include "Entity.h"
#include "ExportHeader.h"

class DECL_DLL_EXPORT Component
{
protected:
	friend class Entity;
	Entity* parent;
public:
	virtual void update(){}
	virtual void cleanup(){}
};

