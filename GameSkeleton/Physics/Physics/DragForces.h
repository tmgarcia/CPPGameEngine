#pragma once
#include "PhysicsGui\GuiBase.h"
#include "Particle.h"


class DragForces : public GuiBase
{
	Q_OBJECT

	Particle particle;

public:
	void initialize();
	void newFrame();

private slots:
	void highSpeedChanged(float);
	void lowSpeedChanged(float);
};

