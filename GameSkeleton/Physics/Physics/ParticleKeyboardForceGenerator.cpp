#include "ParticleKeyboardForceGenerator.h"
#include <Windows.h>


void ParticleKeyboardForceGenerator::updateForce(Particle *particle, float duration)
{
	//check that particle does not have infinite mass

	particle->addForce(keyboardAccelerationMultiplier * getUserDirection() * particle->mass);
}

glm::vec3 ParticleKeyboardForceGenerator::getUserDirection()
{
	glm::vec3 direction = glm::vec3();
	//initialize then show
	if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		direction += glm::vec3(0,1,0);
		glm::normalize(direction);
	}
	if(GetAsyncKeyState(VK_DOWN)|| GetAsyncKeyState('S'))
	{
		direction += glm::vec3(0,-1,0);
		glm::normalize(direction);
	}
	if(GetAsyncKeyState(VK_LEFT)|| GetAsyncKeyState('A'))
	{
		direction += glm::vec3(-1,0,0);
		glm::normalize(direction);
	}
	if(GetAsyncKeyState(VK_RIGHT)|| GetAsyncKeyState('D'))
	{
		direction += glm::vec3(1,0,0);
		glm::normalize(direction);
	}

	return direction;
}