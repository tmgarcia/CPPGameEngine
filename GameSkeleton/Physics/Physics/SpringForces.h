#pragma once

#include "PhysicsGui\GuiBase.h"
#include "Particle.h"

class SpringForces : public GuiBase
{
	Q_OBJECT

	Particle springParticle;
	Particle anchorParticle;

public:
	void vectorGraphicMouseDrag(uint vectorGraphicINdex, const glm::vec3& dragDelta);
	void initialize();
	void newFrame();

private slots:
	void restLengthChanged(float);
	void springConstantChanged(float);
};

