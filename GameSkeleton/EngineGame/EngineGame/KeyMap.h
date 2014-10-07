#pragma once
#include "Input\IKeyMapper.h"

class KeyMap : public IKeyMapper
{
public:
	int getKeyFor(int action) const;
	
};

