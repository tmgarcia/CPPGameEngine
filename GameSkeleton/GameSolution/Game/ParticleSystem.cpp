#include "ParticleSystem.h"


void ParticleSystem::draw(Core::Graphics& g)
{
	for (unsigned int i=0; i<numActiveEffects; i++)
	{
		if (effectList[i] != NULL )
			effectList[i]->draw(g);

	}
}
void ParticleSystem::update(float dt)
{
	for (unsigned int i=0; i<numActiveEffects; i++)
	{
		if (effectList[i] != NULL )
			if(!effectList[i]->update(dt))
				deleteEffect(i);
	}
}
void ParticleSystem::addNewEffect(ParticleEffect* pe)
{
	if(numActiveEffects<MAX_EFFECTS)
	{
		effectList.push_back(pe);
		numActiveEffects++;
	}
}
void ParticleSystem::deleteEffect(int i)
{
	delete effectList[i];
	vector<ParticleEffect*>::iterator where = effectList.begin() + i;
	effectList.erase( where );
	numActiveEffects--;
}