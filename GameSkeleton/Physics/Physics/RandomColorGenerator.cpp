#include "RandomColorGenerator.h"

vec3 RandomColorGenerator::getRandomColor()
{
	float r =  (float)rand()/RAND_MAX;
	float g =  (float)rand()/RAND_MAX;
	float b =  (float)rand()/RAND_MAX;

	return vec3(r,g,b);
}