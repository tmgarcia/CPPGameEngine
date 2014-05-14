#pragma once
#include <glm\glm.hpp>
using glm::vec3;

class Particle
{
public:
	vec3 position;
	vec3 velocity;
	vec3 momentum;
	float acceleration;
	float damping;
	float mass;

	float getMomentumLength();
	void newFrame(float dt, vec3 direction);
	Particle(vec3 velocity=vec3(0,0,0), float acceleration=1.0f, float damping=0.95f, float mass=1.0f): velocity(velocity), acceleration(acceleration), damping(damping), mass(mass)
	{

	}
	~Particle(){}
};

