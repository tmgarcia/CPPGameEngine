#include "MissileAmmo.h"


void MissileAmmo::draw(Core::Graphics& g)
{
	for (unsigned int i=0; i<numActiveMissiles; i++)
	{
		if (missiles[i] != NULL )
			missiles[i]->draw(g);
	}
}
void MissileAmmo::update(float dt)
{
	for (unsigned int i=0; i<numActiveMissiles; i++)
	{
		if (missiles[i] != NULL )
			if(!missiles[i]->update(dt) || grid->wallCollision(missiles[i]->position, 1))
				deleteMissile(i);
	}
}
void MissileAmmo::addMissile(Missile* m)
{
	if(numActiveMissiles<MAX_MISSILES)
	{
		missiles.push_back(m);
		numActiveMissiles++;
	}
}
void MissileAmmo::deleteMissile(int i)
{
	delete missiles[i];
	vector<Missile*>::iterator where = missiles.begin() + i;
	missiles.erase( where );
	numActiveMissiles--;
}

Vector3D MissileAmmo::getMissilePosition(int i)
{
	return missiles[i]->position;
}

void MissileAmmo::clearOut()
{
	for(unsigned int i = 0; i<numActiveMissiles; i++)
	{
		delete missiles[i];
	}
}