#pragma once

#include "ParticleWorld.h"
#include "TwoDParticleContactGenerator.h"
#include "FloorContactGenerator.h"
#include "PhysicsGui\GuiBase.h"
#include "ParticleGravityGenerator.h"
#include "ParticleForceRegistry.h"

class MultipleContacts : public GuiBase
{
	Q_OBJECT

private:
	Particle* bounceParticle1;
	Particle* bounceParticle2;
	Particle* bounceParticle3;
	Particle* bounceParticle4;
	Particle* freeParticle;

	VectorGraphic* bounceParticle1Graphic;
	VectorGraphic* bounceParticle2Graphic;
	VectorGraphic* bounceParticle3Graphic;
	VectorGraphic* bounceParticle4Graphic;
	VectorGraphic* freeParticleGraphic;

	ParticleWorld particleWorld;

	ParticleGravityGenerator gravityGenerator;
	ParticleForceRegistry forceRegistry;

	float originalRestitution;


	void setupMenu();
	void setupParticleGraphics();
	void setupParticles();
	void syncAllParticles();
	void syncAllLabels();

public:
	void vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta);
	void initialize();
	void newFrame();

private slots:
	void restitutionChanged(float);
	void resetToFall();
};

