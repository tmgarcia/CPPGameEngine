#pragma once
#include "glm\glm.hpp"

using glm::vec3;

class Particle
{
public:
	vec3 color;
	vec3 position;
	vec3 velocity;
	float size;
	float lifetime;
	float orientation;
};