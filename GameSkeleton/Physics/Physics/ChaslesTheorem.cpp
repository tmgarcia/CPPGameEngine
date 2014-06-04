#include "ChaslesTheorem.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include <QtGui\qpushbutton.h>
#include <QtGui\qcheckbox.h>
#include "DebugSlider.h"
#include <time.h>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
using std::cout;
using std::endl;

using glm::vec4;

void ChaslesTheorem::initialize()
{
	GuiBase::initialize(false, false);
	srand((unsigned)time(NULL));
	radius = 1.0f;
	angularVelocity = 1.5f;
	throwSpeed = 3.0f;
	bodyOriginVelocity = vec3(0,0,0);
	bodyOrigin = vec3(0,0,0);

	setup();

	sameRadius = false;
}

void ChaslesTheorem::setup()
{
	setupParticles();
	setupMenu();
}
void ChaslesTheorem::setupMenu()
{
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	QPushButton* throwButton = new QPushButton("Throw");
	QPushButton* retrieveButton = new QPushButton("Reset");

	QLabel* sameRadiusLabel = new QLabel("All Particles Same Radius");
	QCheckBox* sameRadiusCheckbox = new QCheckBox();

	buttonLayout->addWidget(sameRadiusLabel);
	buttonLayout->addWidget(sameRadiusCheckbox);
	buttonLayout->addWidget(throwButton);
	buttonLayout->addWidget(retrieveButton);

	QVBoxLayout* slidersLayout = new QVBoxLayout();

	QHBoxLayout* radiusLayout = new QHBoxLayout();
	QLabel* radiusLabel = new QLabel("Radius");
	DebugSlider* radiusSlider = new DebugSlider(0.1f, 5.0f, false, 500.0f);
	radiusSlider->setValue(radius);
	radiusLayout->addWidget(radiusLabel);
	radiusLayout->addWidget(radiusSlider);

	QHBoxLayout* angularVelocityLayout = new QHBoxLayout();
	QLabel* angularVelocityLabel = new QLabel("Angular Velocity");
	DebugSlider* angularVelocitySlider = new DebugSlider(1.0f, 10.0f, false, 1000.0f);
	angularVelocitySlider->setValue(angularVelocity);
	angularVelocityLayout->addWidget(angularVelocityLabel);
	angularVelocityLayout->addWidget(angularVelocitySlider);

	QHBoxLayout* throwSpeedLayout = new QHBoxLayout();
	QLabel* throwSpeedLabel = new QLabel("Throw Speed");
	DebugSlider* throwSpeedSlider = new DebugSlider(0.1f, 5.0f, false, 500.0f);
	throwSpeedSlider->setValue(throwSpeed);
	throwSpeedLayout->addWidget(throwSpeedLabel);
	throwSpeedLayout->addWidget(throwSpeedSlider);

	slidersLayout->addLayout(radiusLayout);
	slidersLayout->addLayout(angularVelocityLayout);
	slidersLayout->addLayout(throwSpeedLayout);

	debugLayout->addLayout(slidersLayout);
	debugLayout->addLayout(buttonLayout);

	QObject::connect(throwButton, SIGNAL(clicked()), this, SLOT(throwParticle()));
	QObject::connect(retrieveButton, SIGNAL(clicked()), this, SLOT(resetParticle()));
	QObject::connect(sameRadiusCheckbox, SIGNAL(stateChanged(int)), this, SLOT(sameRadiusChanged(int)));
	QObject::connect(radiusSlider, SIGNAL(valueChanged(float)), this, SLOT(radiusChanged(float)));
	QObject::connect(angularVelocitySlider, SIGNAL(valueChanged(float)), this, SLOT(angularVelocityChanged(float)));
	QObject::connect(throwSpeedSlider, SIGNAL(valueChanged(float)), this, SLOT(throwSpeedChanged(float)));
}
VectorGraphic* bodyOriginGraphic;


float angleIncrement = 20.0f;
float lengthIncrement = 0.7f;
float angle;
float length;

void ChaslesTheorem::setupParticles()
{
	bodyVelocityGraphic = addVectorGraphic();
	bodyVelocityGraphic->color = vec3(0,0,0);
	bodyVelocityGraphic->displayStyle = DS_ARROW;
	bodyVelocityGraphic->position = bodyOriginVelocity;
	bodyVelocityGraphic->base = bodyOrigin;
	sync(bodyVelocityGraphic, bodyOriginVelocity, bodyOrigin);


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
		worldVelocityGraphic->color = vec3(0,1,0);
		worldVelocityGraphic->displayStyle = DS_ARROW;
		sync(worldVelocityGraphic, p->velocity, p->position);

		VectorGraphic* instantLinearVelocityGraphic = addVectorGraphic();
		instantLinearVelocityGraphic->position = p->position;
		instantLinearVelocityGraphic->color = vec3(1,0,0);
		instantLinearVelocityGraphic->displayStyle = DS_ARROW;
		sync(instantLinearVelocityGraphic, p->velocity, p->position);

		BodyParticle* bp = new BodyParticle();
		bp->particle = p;
		bp->particleGraphic = particleGraphic;
		bp->particlePositionGraphic = particlePositionGraphic;
		bp->instantLinearVelocityGraphic = instantLinearVelocityGraphic;
		bp->worldVelocityGraphic = worldVelocityGraphic;
		bp->originalRadiusFromOrigin = originalRadiusFromOrigin;

		bodyParticles.push_back(bp);
	}

	bodyOriginGraphic = addVectorGraphic();
	bodyOriginGraphic->color = vec3(1,0,1);
	bodyOriginGraphic->pointSize = 0.5f;
	sync(bodyOriginGraphic, bodyOrigin);
}


void ChaslesTheorem::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{

}
void ChaslesTheorem::newFrame()
{
	for(int i = 0; i< bodyParticles.count(); i++)
	{
		bodyParticles[i]->particle->integrate(dt());

		float realRadius = (sameRadius)? radius : bodyParticles[i]->originalRadiusFromOrigin*radius;
		bodyParticles[i]->particle->position = glm::normalize(bodyParticles[i]->particle->position-bodyOrigin)*realRadius + bodyOrigin;

		vec3 radiusVec = bodyParticles[i]->particle->position - bodyOrigin;
		vec3 perpRadius = vec3(-radiusVec.y, radiusVec.x, radiusVec.z);

		bodyParticles[i]->particle->velocity = (angularVelocity*perpRadius) + bodyOriginVelocity;
	}

	bodyOrigin += bodyOriginVelocity * dt();

	syncAllGraphics();
}

void ChaslesTheorem::syncAllGraphics()
{
	sync(bodyVelocityGraphic, bodyOriginVelocity, bodyOrigin);
	for(int i = 0; i< bodyParticles.count(); i++)
	{
		sync(bodyParticles[i]->particleGraphic, bodyParticles[i]->particle->position);

		sync(bodyParticles[i]->particlePositionGraphic, bodyParticles[i]->particle->position-bodyOrigin, bodyOrigin);
		
		sync(bodyParticles[i]->instantLinearVelocityGraphic, bodyParticles[i]->particle->velocity-bodyOriginVelocity, bodyParticles[i]->particle->position);

		sync(bodyParticles[i]->worldVelocityGraphic, bodyParticles[i]->particle->velocity, bodyParticles[i]->particle->position);

		sync(bodyOriginGraphic, bodyOrigin);

	}

}

void ChaslesTheorem::throwParticle()
{
	float x = ((((float)rand()/RAND_MAX)*2.0f)-1);
	float y = ((((float)rand()/RAND_MAX)*2.0f)-1);
	//float z = ((((float)rand()/RAND_MAX)*2.0f)-1);
	bodyOrigin = vec3(0,0,0);
	bodyOriginVelocity = vec3(x, y, 0) * throwSpeed;
	syncAllGraphics();
}
void ChaslesTheorem::resetParticle()
{
	bodyOrigin = vec3(0,0,0);
	bodyOriginVelocity = vec3(0,0,0);

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
void ChaslesTheorem::sameRadiusChanged(int newVal)
{
	sameRadius = newVal;
}
void ChaslesTheorem::radiusChanged(float newVal)
{
	radius = newVal;
}
void ChaslesTheorem::angularVelocityChanged(float newVal)
{
	angularVelocity = newVal;
}
void ChaslesTheorem::throwSpeedChanged(float newVal)
{
	throwSpeed = newVal;
}