#include "TorqueSquare.h"
#include "Qt\qlayout.h"
#include <QtGui\qpushbutton.h>
#include <QtGui\qcheckbox.h>
#include "DebugSlider.h"
#include <time.h>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <Qt\qapplication.h>
using std::cout;
using std::endl;

using glm::vec4;

void TorqueSquare::initialize()
{
	GuiBase::initialize(false, false);
	springConstant = 5;
	damping = 0.9f;
	angularVelocity = 1;
	springLength = 2;
	initialSpringAnchorPosition = vec3(-2.5,3,0);

	angularAcclerationLabelText = "Angular Acceleration ";

	setup();
}
void TorqueSquare::setup()
{
	setupMenu();
	setupParticles();

}
void TorqueSquare::setupMenu()
{
	QVBoxLayout* slidersLayout = new QVBoxLayout();

	QHBoxLayout* springConstantLayout = new QHBoxLayout();
	QLabel* springConstantLabel = new QLabel("K");
	DebugSlider* springConstantSlider = new DebugSlider(0.1f, 8.0f, false, 800.0f);
	springConstantSlider->setValue(springConstant);
	springConstantLayout->addWidget(springConstantLabel);
	springConstantLayout->addWidget(springConstantSlider);

	QHBoxLayout* dampingLayout = new QHBoxLayout();
	QLabel* dampingLabel = new QLabel("Damping");
	DebugSlider* dampingSlider = new DebugSlider(0.1f, 1.0f, false, 90.0f);
	dampingSlider->setValue(damping);
	dampingLayout->addWidget(dampingLabel);
	dampingLayout->addWidget(dampingSlider);

	slidersLayout->addLayout(springConstantLayout);
	slidersLayout->addLayout(dampingLayout);

	QHBoxLayout* buttonLayout = new QHBoxLayout();
	angularAccelerationLabel = new QLabel(angularAcclerationLabelText + QString::number(angularAcceleration));
	QPushButton* resetButton = new QPushButton("Reset");
	buttonLayout->addWidget(angularAccelerationLabel);
	buttonLayout->addWidget(resetButton);

	debugLayout->addLayout(slidersLayout);
	debugLayout->addLayout(buttonLayout);

	QObject::connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));
	QObject::connect(springConstantSlider, SIGNAL(valueChanged(float)), this, SLOT(springConstantChanged(float)));
	QObject::connect(dampingSlider, SIGNAL(valueChanged(float)), this, SLOT(dampingChanged(float)));

}
void TorqueSquare::setupParticles()
{
	bodyParticle = new Particle();
	bodyParticle->position = vec3(0,0,0);
	bodyParticle->acceleration = vec3(0,0,0);
	bodyParticle->damping = damping;
	
	bodyParticleGraphic = addVectorGraphic();
	bodyParticleGraphic->position = bodyParticle->position;
	bodyParticleGraphic->color = vec3(0,0,1);
	bodyParticleGraphic->displayStyle = DS_SQUARE;
	bodyParticleGraphic->rotation = rotation;
		//at tan 2

	bodyCornerPoint = new Particle();
	bodyCornerPoint->position = vec3(-0.5f,0.5f,0);
	bodyCornerPoint->damping = damping;

	springAnchor = new Particle();
	springAnchor->position = initialSpringAnchorPosition;

	handle = bodyCornerPoint->position-bodyParticle->position;
	radius = glm::length(handle);

	torqueVectorGraphic = addVectorGraphic();
	torqueVectorGraphic->position = torqueVector;
	torqueVectorGraphic->base = bodyCornerPoint->position;
	torqueVectorGraphic->color = vec3(0,1,0);
	torqueVectorGraphic->displayStyle = DS_ARROW;

	forceProjectionGraphic = addVectorGraphic();
	forceProjectionGraphic->position = forceProjection;
	forceProjectionGraphic->base = bodyParticle->position;
	forceProjectionGraphic->color = vec3(1,0,0);
	forceProjectionGraphic->displayStyle = DS_ARROW;

	springVectorGraphic = addVectorGraphic();
	springVectorGraphic->position = springAnchor->position;
	springVectorGraphic->base = bodyCornerPoint->position;
	springVectorGraphic->color = vec3(0,0,0);
	springVectorGraphic->displayStyle = DS_LINE;

	spring = ParticleSpringGenerator(springAnchor, springConstant, springLength);
	gravity = ParticleGravityGenerator();

	registry.add(bodyCornerPoint, &spring);
	registry.add(bodyParticle, &gravity);

}
void TorqueSquare::mouseClicks()
{
	if(QApplication::mouseButtons() &Qt::MouseButton::LeftButton)//force base
	{
		vec3 temp = getMousePosition();
		springAnchor->position = temp;
		syncAllGraphics();
	}
}
void TorqueSquare::newFrame()
{
	registry.updateForces(dt());
	bodyCornerPoint->integrate(dt());

	bodyCornerPoint->position = glm::normalize(bodyCornerPoint->position-bodyParticle->position)*radius + bodyParticle->position;
	cornerInertia = glm::dot(radius, radius);

	vec3 radiusVec = bodyCornerPoint->position - bodyParticle->position;
	vec3 perpRadius = vec3(-radiusVec.y, radiusVec.x, radiusVec.z);
	bodyCornerPoint->velocity = (angularVelocity*perpRadius)+bodyParticle->velocity;

	float totalInertia = cornerInertia;

	forceProjection = glm::normalize(springAnchor->position - bodyParticle->position)*glm::length(spring.lastForce);
	float torqueMagnitude = glm::dot(perpRadius, spring.lastForce);
	torqueVector = glm::normalize(perpRadius)*torqueMagnitude;
	angularAcceleration = torqueMagnitude/totalInertia;

	angularVelocity += angularAcceleration * dt();
	angularVelocity *= glm::pow(damping,dt());

	rotation = -((atan2f(radiusVec.y,radiusVec.x)-(2.356194490192345)));
	bodyParticleGraphic->rotation = rotation;

	bodyParticle->velocity += bodyCornerPoint->acceleration*dt();
	bodyParticle->integrate(dt());
	syncAllGraphics();
	mouseClicks();
}
void TorqueSquare::syncAllGraphics()
{
	angularAccelerationLabel->setText(angularAcclerationLabelText+QString::number(angularAcceleration));
	sync(springVectorGraphic, springAnchor->position-bodyCornerPoint->position, bodyCornerPoint->position);
	sync(forceProjectionGraphic, forceProjection, bodyParticle->position);
	sync(torqueVectorGraphic, torqueVector, bodyCornerPoint->position);
	sync(bodyParticleGraphic, bodyParticle->position);
}
void TorqueSquare::reset()
{
	angularVelocity = 1;
	rotation = 0;

	bodyParticle->position = vec3(0,0,0);
	bodyParticle->acceleration = vec3(0,0,0);
	bodyParticle->velocity = vec3(0,0,0);
	bodyParticle->damping = damping;
	
	bodyParticleGraphic->position = bodyParticle->position;
	bodyParticleGraphic->rotation = rotation;

	bodyCornerPoint->position = vec3(-0.5f,0.5f,0);
	bodyCornerPoint->acceleration = vec3(0,0,0);
	bodyCornerPoint->velocity = vec3(0,0,0);
	bodyCornerPoint->damping = damping;

	springAnchor->position = initialSpringAnchorPosition;

	torqueVectorGraphic->position = torqueVector;

	forceProjectionGraphic->position = forceProjection;
	forceProjectionGraphic->base = bodyParticle->position;

	springVectorGraphic->position = springAnchor->position;
	springVectorGraphic->base = bodyCornerPoint->position;
}
void TorqueSquare::springConstantChanged(float newVal)
{
	springConstant = newVal;
	spring.springConstant = newVal;
}
void TorqueSquare::dampingChanged(float newVal)
{
	damping = newVal;
	bodyParticle->damping = newVal;
	bodyCornerPoint->damping = newVal;
}