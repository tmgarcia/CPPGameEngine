#pragma once

#include "ParticleWorld.h"
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

	VectorGraphic* bounceParticle1Generator;
	VectorGraphic* bounceParticle2Generator;
	VectorGraphic* bounceParticle3Generator;
	VectorGraphic* bounceParticle4Generator;
	VectorGraphic* freeParticleGenerator;

	ParticleWorld particleWorld;

	ParticleGravityGenerator gravityGenerator;
	ParticleForceRegistry forceRegistry;
	VectorGraphic* bounceParticleGraphic;

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
	void resetToRest();
};

