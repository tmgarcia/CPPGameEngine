#include "Random.h"
#include <time.h>

Random* Random::theInstance;

Random& Random::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new Random();
		srand((unsigned)time(NULL));
	}
	return *theInstance;
}

float Random::randomFloat()
{
	return (float)rand()/RAND_MAX;
}

float Random::randomFloatRange(float min, float max)
{
	if(min == 0)
	{
		return randomFloat() * (max*(min+1))+min;
	}
	else
	{
		return randomFloat() * (max*(min))+min;
	}		
}