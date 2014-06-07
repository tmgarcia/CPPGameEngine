#include "Torque.h"
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

void Torque::initialize()
{
	GuiBase::initialize(false, false);
	srand((unsigned)time(NULL));
	radius = 0.6f;
	angularVelocity = 1.5f;
	bodyOrigin = vec3(0,0,0);

	bodyForceHandle = vec3(4,4,0);
	force = vec3(-3.0f, -1.0f, 0);

	angleIncrement = 20.0f;
	lengthIncrement = 0.7f;

	setup();

	sameRadius = false;
}

void Torque::setup()
{
	setupParticles();
	setupMenu();
}
void Torque::setupMenu()
{
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	QPushButton* retrieveButton = new QPushButton("Reset");

	QLabel* sameRadiusLabel = new QLabel("All Particles Same Radius");
	QCheckBox* sameRadiusCheckbox = new QCheckBox();

	buttonLayout->addWidget(sameRadiusLabel);
	buttonLayout->addWidget(sameRadiusCheckbox);
	buttonLayout->addWidget(retrieveButton);

	QVBoxLayout* slidersLayout = new QVBoxLayout();

	QHBoxLayout* radiusLayout = new QHBoxLayout();
	QLabel* radiusLabel = new QLabel("Radius");
	DebugSlider* radiusSlider = new DebugSlider(0.1f, 5.0f, false, 500.0f);
	radiusSlider->setValue(radius);
	radiusLayout->addWidget(radiusLabel);
	radiusLayout->addWidget(radiusSlider);

	slidersLayout->addLayout(radiusLayout);

	debugLayout->addLayout(slidersLayout);
	debugLayout->addLayout(buttonLayout);

	angularVelocityLabel = new QLabel("Angular Velocity: "+QString(QString::number(angularVelocity)));
	totalInertiaLabel = new QLabel("Total Inertia: "+QString(QString::number(totalInertia)));
	torqueMagnitudeLabel = new QLabel("Torque Magnitude: "+QString(QString::number(torqueMagnitude)));

	debugLayout->addWidget(angularVelocityLabel);
	debugLayout->addWidget(totalInertiaLabel);
	debugLayout->addWidget(torqueMagnitudeLabel);

	QObject::connect(retrieveButton, SIGNAL(clicked()), this, SLOT(resetParticle()));
	QObject::connect(sameRadiusCheckbox, SIGNAL(stateChanged(int)), this, SLOT(sameRadiusChanged(int)));
	QObject::connect(radiusSlider, SIGNAL(valueChanged(float)), this, SLOT(radiusChanged(float)));
}

void Torque::setupParticles()
{
	bodyHandleGraphic = addVectorGraphic();
	bodyHandleGraphic->position = bodyForceHandle;
	bodyHandleGraphic->base = bodyOrigin;
	bodyHandleGraphic->color = vec3(0,0,0);
	bodyHandleGraphic->displayStyle = DS_ARROW;

	forceGraphic = addVectorGraphic();
	forceGraphic->position = force;
	forceGraphic->base = bodyForceHandle;
	forceGraphic->color = vec3(0,1,1);
	forceGraphic->displayStyle = DS_ARROW;

	forceHandlePerpProjectionGraphic = addVectorGraphic();
	forceHandlePerpProjectionGraphic->position = forceHandlePerpProjection;
	forceHandlePerpProjectionGraphic->base = bodyForceHandle;
	forceHandlePerpProjectionGraphic->color = vec3(0,1,0);
	forceHandlePerpProjectionGraphic->displayStyle = DS_ARROW;

	angle = 0.0f;
	length = 0.3f;
	for(int i = 0; i<numOfParticles; i++)
	{
		Particle* p = new Particle();
		vec4 pos = vec4(length, 0, 0, 0);
		p->position = vec3(pos * glm::rotate(angle, vec3(0,0,1)));
		p->velocity = vec3(0,0,0);
		length += lengthIncrement;
		angle += angleIncrement;

		float originalRadiusFromOrigin = glm::length(p->position - bodyOrigin);
		p->position = glm::normalize(p->position-bodyOrigin)*(originalRadiusFromOrigin*radius) + bodyOrigin;


		VectorGraphic* particleGraphic = addVectorGraphic();
		particleGraphic->position = p->position;
		particleGraphic->color = vec3(0,0,1);
		particleGraphic->pointSize = p->mass;
		sync(particleGraphic, p->position);

		VectorGraphic* particlePositionGraphic = addVectorGraphic();
		particlePositionGraphic->position = bodyOrigin;
		particlePositionGraphic->color = vec3(0,0,1);
		particlePositionGraphic->displayStyle = DS_ARROW;
		sync(particlePositionGraphic, p->position, bodyOrigin);

		VectorGraphic* worldVelocityGraphic = addVectorGraphic();
		worldVelocityGraphic->position = p->position;
		worldVelocityGraphic->color = vec3(1,0,0);
		worldVelocityGraphic->displayStyle = DS_ARROW;
		sync(worldVelocityGraphic, p->velocity, p->position);

		BodyParticle* bp = new BodyParticle();
		bp->particle = p;
		bp->particleGraphic = particleGraphic;
		bp->particlePositionGraphic = particlePositionGraphic;
		bp->worldVelocityGraphic = worldVelocityGraphic;
		bp->originalRadiusFromOrigin = originalRadiusFromOrigin;
		bp->inertia = glm::dot(originalRadiusFromOrigin*radius, originalRadiusFromOrigin*radius);

		bodyParticles.push_back(bp);
	}

}

void Torque::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{

}
void Torque::newFrame()
{
	totalInertia = 0;
	for(int i = 0; i< bodyParticles.count(); i++)
	{
		bodyParticles[i]->particle->integrate(dt());

		float realRadius = (sameRadius)? radius : bodyParticles[i]->originalRadiusFromOrigin*radius;
		bodyParticles[i]->particle->position = glm::normalize(bodyParticles[i]->particle->position-bodyOrigin)*realRadius + bodyOrigin;
		bodyParticles[i]->inertia = glm::dot(realRadius, realRadius);

		vec3 radiusVec = bodyParticles[i]->particle->position - bodyOrigin;
		vec3 perpRadius = vec3(-radiusVec.y, radiusVec.x, radiusVec.z);
		bodyParticles[i]->instantLinearVelocity = (angularVelocity*perpRadius);
		bodyParticles[i]->particle->velocity = bodyParticles[i]->instantLinearVelocity;

		totalInertia += bodyParticles[i]->inertia;
	}

	vec3 perpedR = vec3(-bodyForceHandle.y, bodyForceHandle.x, 0);
	torqueMagnitude = glm::dot(perpedR, force);
	forceHandlePerpProjection = glm::normalize(perpedR)*torqueMagnitude;
	angularAcceleration = torqueMagnitude/totalInertia;

	angularVelocity += angularAcceleration * dt();

	syncAllGraphics();
	mouseClicks();
}

void Torque::syncAllGraphics()
{
	sync(bodyHandleGraphic, bodyForceHandle, bodyOrigin);
	sync(forceGraphic, force, bodyForceHandle);
	sync(forceHandlePerpProjectionGraphic, forceHandlePerpProjection, bodyForceHandle);
	for(int i = 0; i< bodyParticles.count(); i++)
	{
		sync(bodyParticles[i]->particleGraphic, bodyParticles[i]->particle->position);
		sync(bodyParticles[i]->particlePositionGraphic, bodyParticles[i]->particle->position-bodyOrigin, bodyOrigin);
		sync(bodyParticles[i]->worldVelocityGraphic, bodyParticles[i]->particle->velocity, bodyParticles[i]->particle->position);
	}
	angularVelocityLabel->setText("Angular Velocity: "+QString(QString::number(angularVelocity)));
	totalInertiaLabel->setText("Total Inertia: "+QString(QString::number(totalInertia)));
	torqueMagnitudeLabel->setText("Torque Magnitude: "+QString(QString::number(torqueMagnitude)));
}

void Torque::resetParticle()
{
	bodyOrigin = vec3(0,0,0);
	angularVelocity = 1.5f;
	bodyOrigin = vec3(0,0,0);

	angle = 0.0f;
	length = 0.3f;

	for(int i = 0; i<bodyParticles.count(); i++)
	{
		vec4 pos = vec4(length, 0, 0, 0);
		bodyParticles[i]->particle->position = vec3(pos * glm::rotate(angle, vec3(0,0,1)));
		bodyParticles[i]->particle->velocity = vec3(0,0,0);
		length += lengthIncrement;
		angle += angleIncrement;
	}

	syncAllGraphics();
}
void Torque::sameRadiusChanged(int newVal)
{
	sameRadius = newVal;
}
void Torque::radiusChanged(float newVal)
{
	radius = newVal;
}

void Torque::mouseClicks()
{
	if(QApplication::mouseButtons() &Qt::MouseButton::RightButton)//force base
	{
		bodyForceHandle = getMousePosition();
		syncAllGraphics();
	}
	if(QApplication::mouseButtons() &Qt::MouseButton::LeftButton)//force base
	{
		vec3 temp = getMousePosition();
		force = temp - bodyForceHandle;
		syncAllGraphics();
	}
}