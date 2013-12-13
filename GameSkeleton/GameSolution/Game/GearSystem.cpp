#include "GearSystem.h"

Gear* GearSystem::gears[5];
const unsigned int NUM_GEARS = sizeof(GearSystem::gears) / sizeof(*GearSystem::gears);
void GearSystem::buildSystem()
{
	unsigned int i = 0;
	createGear(i, 0.6f);
}

void GearSystem::clearGears()
{
	GearSystem::gears[0]->clear();
	for(int i=0; i < 5; i++)
	{
		delete GearSystem::gears[i];
	}
}
void GearSystem::createGear(int i, float rotationalSpeed)
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
		offset = (GearSystem::gears[i-1]->gscale*58)+10;
		//offset = 100.0f;
	}
	GearSystem::gears[i] = new Gear(gscale, offset, rotationalSpeed);
	if(i<NUM_GEARS)
	{
		createGear(i+1, rotationalSpeed*1.5f);
	}
}

void GearSystem::draw(Core::Graphics& g)
{
    g.SetColor(RGB(20, 20, 100));
    Vector3D nextOrigin = origin;
    for(unsigned int i = 0; i < NUM_GEARS; i++)
    {
        nextOrigin = GearSystem::gears[i]->draw(g, nextOrigin);
    }
}

void GearSystem::update(float dt)
{
	for(unsigned int i = 0; i < NUM_GEARS; i++)
	{
		(*GearSystem::gears[i]).update(dt);
	}
}

int GearSystem::getNumGears()
{
	return NUM_GEARS;
}

Vector3D GearSystem::getIndexedGearPosition(int i)
{
	return GearSystem::gears[i]->position;
}