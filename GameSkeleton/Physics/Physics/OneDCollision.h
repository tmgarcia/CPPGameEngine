#pragma once

#include "ParticleWorld.h"
#include "TwoDParticleContactGenerator.h"
#include "PhysicsGui\GuiBase.h"

class OneDCollision : public GuiBase
{
	Q_OBJECT

private:
	Particle* particleRed;
	Particle* particleBlue;

	ParticleWorld particleWorld;
	TwoDParticleContactGenerator contactGenerator;

	VectorGraphic* particleRedGraphic;
	VectorGraphic* particleRedMomentumGraphic;
	VectorGraphic* particleRedSeparatingMomentumGraphic;
	VectorGraphic* particleBlueGraphic;
	VectorGraphic* particleBlueMomentumGraphic;
	VectorGraphic* particleBlueSeparatingMomentumGraphic;

	VectorGraphic* totalMomentumGraphic;

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
	void redMassChanged(float);
	void blueMassChanged(float);
	void restitutionChanged(float);
	void redInitVelocityXChanged(float);
	void redInitVelocityYChanged(float);
	void blueInitVelocityXChanged(float);
	void blueInitVelocityYChanged(float);
	void resetParticles();
	void createCollision();
};

