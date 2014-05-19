#pragma once

#include "PhysicsGui\GuiBase.h"
#include "Particle.h"
#include "ParticleForceRegistry.h"
#include "ParticleGravityGenerator.h"
#include "ParticleSpringGenerator.h"

class MultipleSprings : public GuiBase
{
	Q_OBJECT

private:

	ParticleForceRegistry particleForceRegistry;

	Particle springParticle1;
	Particle springParticle2;
	Particle springParticle3;
	Particle springParticle4;
	Particle springParticle5;
	Particle anchorParticle;

	VectorGraphic* springParticle1Graphic;
	VectorGraphic* springParticle2Graphic;
	VectorGraphic* springParticle3Graphic;
	VectorGraphic* springParticle4Graphic;
	VectorGraphic* springParticle5Graphic;
	VectorGraphic* anchorParticleGraphic;

	ParticleGravityGenerator gravityGenerator;

	ParticleSpringGenerator anchorAnd1SpringGenerator;
	ParticleSpringGenerator particle1And2SpringGenerator;
	ParticleSpringGenerator particle2And3SpringGenerator;
	ParticleSpringGenerator particle3And4SpringGenerator;
	ParticleSpringGenerator particle4And5SpringGenerator;

	void setupMenu();
	void setupParticleGraphics();
	void setupParticles();
	void syncAllParticles();

public:
	void vectorGraphicMouseDrag(uint vectorGraphicINdex, const glm::vec3& dragDelta);
	void initialize();
	void newFrame();

private slots:
	void restLengthChanged(float);
	void springConstantChanged(float);
	void gravityChanged(float);
	void dampingChanged(float);
};

