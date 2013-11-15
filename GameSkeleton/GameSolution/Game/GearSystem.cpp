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
		offset = 10.0f;
	}
	gears[i] = new Gear(gscale, offset);
	if(i<NUM_GEARS)
	{
		createGear(i+1);
	}
}

void GearSystem::draw(Core::Graphics& g)
{
    g.SetColor(RGB(100,100,100));
    Vector3D nextOrigin = origin;
    for(unsigned int i = 0; i < NUM_GEARS; i++)
    {
        if(i ==0)
            g.SetColor(RGB(255,0,0));
        else
            g.SetColor(RGB(255,255,255));
        nextOrigin = gears[i]->draw(g, nextOrigin);
    }
}

void GearSystem::update(float dt)
{
	for(unsigned int i = 0; i < NUM_GEARS; i++)
	{
		(*gears[i]).update(dt);
	}
}