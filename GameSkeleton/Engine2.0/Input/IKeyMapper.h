#pragma once

class IKeyMapper
{
public:
	virtual int getKeyFor(int action) const = 0;
};