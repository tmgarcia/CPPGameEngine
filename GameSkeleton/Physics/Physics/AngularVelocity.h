#pragma once

#include "Particle.h"
#include "PhysicsGui\GuiBase.h"
#include "RandomColorGenerator.h"

class AngularVelocity : public GuiBase
{
	Q_OBJECT
private:
	
	Particle* particle;
	VectorGraphic* particleGraphic;
	VectorGraphic* linearVelocityGraphic;

	bool isSpinning;

	void setupMenu();
	void setupParticles();
	void setup();

public:
	void vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta);
	void initialize();
	void newFrame();
	
private slots:
	void throwParticle();
	void retrieveParticle();
	void radiusChanged(float);
	void angularVelocityChanged(float);
};

