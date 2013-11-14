#include "GearSystem.h"

Gear* gears[3];
const unsigned int NUM_GEARS = sizeof(gears) / sizeof(*gears);
void GearSystem::buildSystem()
{
	unsigned int i = 0;
	createGear(i);
}

void GearSystem::createGear(int i)
{
	float gscale = (float)(NUM_GEARS-i)/NUM_GEARS;
	float offset;
	Vector3D position;
	if(i==0)
	{
		offset = 0;
	}
	else
	{
		//offset = (float)(((NUM_GEARS-(i-1))/NUM_GEARS)*116)+5;
		offset = 10;
	}
	gears[i] = new Gear(gscale, offset);
	if(i<NUM_GEARS)
	{
		createGear(i+1);
	}
}

void GearSystem::draw(Core::Graphics& g)
{
	for(unsigned int i = 0; i < NUM_GEARS; i++)
	{
		if(i==0)
			(*gears[i]).draw(g, origin);
		else
			(*gears[i]).draw(g, (*gears[i-1]).currentPosition);
			//(*gears[i]).draw(g, origin);
	}
}

void GearSystem::update(float dt)
{
	for(unsigned int i = 0; i < NUM_GEARS; i++)
	{
		(*gears[i]).update(dt);
	}
}