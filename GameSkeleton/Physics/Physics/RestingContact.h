#pragma once

#include "ParticleWorld.h"
#include "FloorContactGenerator.h"
#include "PhysicsGui\GuiBase.h"
#include "ParticleGravityGenerator.h"
#include "ParticleForceRegistry.h"

class RestingContact : public GuiBase
{
	Q_OBJECT

private:
	Particle* bounceParticle;

	ParticleWorld particleWorld;
	FloorContactGenerator contactGenerator;
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

