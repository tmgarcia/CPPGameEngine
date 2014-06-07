#pragma once

#include "Particle.h"
#include <QtGui\qlabel.h>
#include "PhysicsGui\GuiBase.h"
#include "RandomColorGenerator.h"
#include <Qt\qlist.h>

class Torque : public GuiBase
{
	Q_OBJECT

private:
	int numOfParticles;

	QLabel* angularVelocityLabel;
	QLabel* totalInertiaLabel;
	QLabel* torqueMagnitudeLabel;

	vec3 bodyForceHandle;
	vec3 force;
	vec3 forceHandlePerpProjection;

	vec3 bodyOrigin;
	float bodyTorque;
	float totalInertia;
	float angularAcceleration;
	float torqueMagnitude;
	VectorGraphic* bodyHandleGraphic;
	VectorGraphic* forceGraphic;
	VectorGraphic* forceHandlePerpProjectionGraphic;

	float radius;
	float angularVelocity;

	struct BodyParticle
	{
		float originalRadiusFromOrigin;
		Particle* particle;
		vec3 instantLinearVelocity;
		float inertia;
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

	void mouseClicks();

	float angleIncrement;
	float lengthIncrement;
	float angle;
	float length;

public:
	void vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta);
	void initialize();
	void newFrame();
	Torque(int numParticles = 10)
	{
		numOfParticles = numParticles;
	}

	
private slots:
	void resetParticle();
	void sameRadiusChanged(int);
	void radiusChanged(float);
};

