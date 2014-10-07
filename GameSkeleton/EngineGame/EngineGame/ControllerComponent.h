#pragma once
#include "GameObjects\Component.h"

class ControllerComponent : public Component
{
public:
	float speed;
	ControllerComponent()
	{
		speed = 1;
	}
	void update();
};

