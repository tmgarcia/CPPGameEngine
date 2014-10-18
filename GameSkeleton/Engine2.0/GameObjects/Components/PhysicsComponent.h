#pragma once
#include "../Component.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\transform.hpp>

using glm::vec3;
using glm::mat4;

class __declspec(dllexport) PhysicsComponent : public Component
{
public:
	vec3 velocity;
	vec3 momentum;
	vec3 acceleration;
	vec3 forceAccum;

	PhysicsComponent()
	{
		mass = 1;
		damping = 0.01f;
		acceleration = vec3();
		forceAccum = vec3();
		velocity = vec3();
	}

	float mass;
	float damping;

	void clearForces();
	void addForce(vec3 force);
	void update();
	void cleanup();
};

