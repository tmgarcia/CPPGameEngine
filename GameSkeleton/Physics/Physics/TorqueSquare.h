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

class TorqueSquare : public GuiBase
{
	Q_OBJECT

private:
	QLabel* angularAccelerationLabel;

	QString angularAcclerationLabelText;

	float springConstant;
	float angularAcceleration;
	float damping;
	float angularVelocity;
	float radius;
	float springLength;
	float cornerInertia;
	float rotation;

	vec3 initialSpringAnchorPosition;
	//vec3 particleRotation;
	vec3 handle;
	vec3 forceProjection;
	vec3 torqueVector;

	Particle* springAnchor;
	Particle* bodyCornerPoint;
	Particle* bodyParticle;

	VectorGraphic* torqueVectorGraphic;
	VectorGraphic* springVectorGraphic;
	VectorGraphic* forceProjectionGraphic;
	VectorGraphic* bodyParticleGraphic;

	ParticleSpringGenerator spring;
	ParticleGravityGenerator gravity;

	ParticleForceRegistry registry;

	void setupMenu();
	void setupParticles();
	void setup();
	void syncAllGraphics();

	void mouseClicks();

public:
	void initialize();
	void newFrame();
//
private slots:
	void springConstantChanged(float);
	void dampingChanged(float);
	void reset();
};

