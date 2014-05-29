#pragma once

#include "ParticleWorld.h"
#include "TwoDParticleContactGenerator.h"
#include "FloorContactGenerator.h"
#include "PhysicsGui\GuiBase.h"
#include "ParticleGravityGenerator.h"
#include "ParticleSpringGenerator.h"
#include "ParticleForceRegistry.h"
#include "RandomColorGenerator.h"

class ThreeDCube : public GuiBase
{
	Q_OBJECT

private:
	Particle* cubeParticle1;
	Particle* cubeParticle2;
	Particle* cubeParticle3;
	Particle* cubeParticle4;
	Particle* cubeParticle5;
	Particle* cubeParticle6;
	Particle* cubeParticle7;
	Particle* cubeParticle8;

	VectorGraphic* cubeParticle1Graphic;
	VectorGraphic* cubeParticle2Graphic;
	VectorGraphic* cubeParticle3Graphic;
	VectorGraphic* cubeParticle4Graphic;
	VectorGraphic* cubeParticle5Graphic;
	VectorGraphic* cubeParticle6Graphic;
	VectorGraphic* cubeParticle7Graphic;
	VectorGraphic* cubeParticle8Graphic;

	RandomColorGenerator randomColor;

	ParticleWorld particleWorld;

	ParticleGravityGenerator gravityGenerator;
	ParticleForceRegistry forceRegistry;

	QList <ParticleSpringGenerator*> springs;

	float originalRestitution;
	float originalSpringConstant;
	float originalDamping;
	float originalRestLength;

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
	void springConstantChanged(float);
	void dampingChanged(float);
	void restLengthChanged(float);
	void resetToFall();
};

