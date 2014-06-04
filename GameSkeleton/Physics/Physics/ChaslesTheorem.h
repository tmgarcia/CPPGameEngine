#pragma once

#include "Particle.h"
#include "PhysicsGui\GuiBase.h"
#include "RandomColorGenerator.h"
#include <Qt\qlist.h>

class ChaslesTheorem : public GuiBase
{
	Q_OBJECT

private:
	int numOfParticles;

	vec3 bodyOrigin;
	vec3 bodyOriginVelocity;
	VectorGraphic* bodyVelocityGraphic;

	float radius;
	float angularVelocity;
	float throwSpeed;

	struct BodyParticle
	{
		float originalRadiusFromOrigin;
		Particle* particle;
		VectorGraphic* particleGraphic;
		VectorGraphic* particlePositionGraphic;
		VectorGraphic* instantLinearVelocityGraphic;
		VectorGraphic* worldVelocityGraphic;
	};

	QList<BodyParticle*> bodyParticles;

	bool sameRadius;

	void setupMenu();
	void setupParticles();
	void setup();
	void syncAllGraphics();

public:
	void vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta);
	void initialize();
	void newFrame();
	ChaslesTheorem(int numParticles = 10)
	{
		numOfParticles = numParticles;
	}

	
private slots:
	void throwParticle();
	void resetParticle();
	void sameRadiusChanged(int);
	void radiusChanged(float);
	void angularVelocityChanged(float);
	void throwSpeedChanged(float);
};

