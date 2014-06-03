#pragma once

#include "Particle.h"
#include "PhysicsGui\GuiBase.h"
#include "RandomColorGenerator.h"

class ChaslesTheorem : public GuiBase
{
	Q_OBJECT

private:
	
	vec3 bodyOrigin;
	VectorGraphic* bodyVelocityGraphic;

	float radius;
	float angularVelocity;
	float throwSpeed;

	struct BodyParticle
	{
		Particle* particle;
		VectorGraphic* particleGraphic;
		VectorGraphic* particlePositionGraphic;
		VectorGraphic* instantLinearVelocityGraphic;
		VectorGraphic* worldVelocityGraphic;
	};

	BodyParticle** bodyParticles;

	bool isThrown;

	void setupMenu();
	void setupParticles();
	void setup();

public:
	void vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta);
	void initialize();
	void newFrame();
	
private slots:
	void throwParticle();
	void resetParticle();
	void sameRadiusChanged(int);
	void radiusChanged(float);
	void angularVelocityChanged(float);
	void throwSpeedChanged(float);
};

