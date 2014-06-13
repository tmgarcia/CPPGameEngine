#pragma once

#include "Particle.h"
#include <QtGui\qlabel.h>
#include "ParticleGravityGenerator.h"
#include "ParticleSpringGenerator.h"
#include "PhysicsGui\GuiBase.h"
#include "RandomColorGenerator.h"
#include <Qt\qlist.h>
#include "ParticleForceRegistry.h"
#include "Qt\qstring.h"
#include "StickyPointBungeeGenerator.h"

class SomethingCool : public GuiBase
{
	Q_OBJECT

private:
	float springConstant;
	float restLength;
	float damping;
	float initialSplashHeight;
	float splashDampen;

	float waveMultiplier;

	float currentWaveRadius;

	vec3 splashAcceleration;

	int randomI;
	int randomJ;
	int waveStage;
	bool creatingSplash;

	ParticleForceRegistry registry;

	struct BungeeMeshParticle
	{
		Particle* particle;
		VectorGraphic* graphic;
		StickyPointBungeeGenerator* bungee;
		bool active;
	};

	BungeeMeshParticle bungeeParticles[50][50];

	void setupMenu();
	void setupParticles();
	void setup();

	void makeWave();

public:
	void initialize();
	void newFrame();

private slots:
	void splash();
	void reset();
	void resetSliders();
	void dampingChanged(float);
	void splashDampingChanged(float);
	void waveMultiplierChanged(float);
	void springConstantChanged(float);
};

