#include "SpringForces.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include "DebugSlider.h"
#include "ParticleForceRegistry.h"
#include "ParticleSpringGenerator.h"
#include "PhysicsGui\VectorGraphic.h"
#include <iostream>

using std::cout;
using std::endl;

ParticleSpringGenerator springGenerator;
VectorGraphic* springParticleGraphic;
VectorGraphic* anchorParticleGraphic;

VectorGraphic* springRestGraphic;

ParticleForceRegistry particleForceRegistry;



void SpringForces::initialize()
{
	float initialRestLength = 4.0f;
	float initialSpringConstant = 0.0f;

	GuiBase::initialize(false, true);

	QHBoxLayout *restingLengthControl = new QHBoxLayout();
	QLabel *restingLengthLabel = new QLabel("RestingLength:");
	DebugSlider* restingLengthSlider = new DebugSlider(0.0f, 10.0f, false);
	restingLengthSlider->setValue(initialRestLength);
	restingLengthControl->addWidget(restingLengthLabel);
	restingLengthControl->addWidget(restingLengthSlider);

	QHBoxLayout *springConstantControl = new QHBoxLayout();
	QLabel *springConstantLabel = new QLabel("Spring Constant:");
	DebugSlider* springConstantSlider = new DebugSlider(0.0f, 100.0f, false);
	springConstantSlider->setValue(initialSpringConstant);
	springConstantControl->addWidget(springConstantLabel);
	springConstantControl->addWidget(springConstantSlider);

	debugLayout->addLayout(restingLengthControl);
	debugLayout->addLayout(springConstantControl);
	QObject::connect(restingLengthSlider, SIGNAL(valueChanged(float)), this, SLOT(restLengthChanged(float)));
	QObject::connect(springConstantSlider, SIGNAL(valueChanged(float)), this, SLOT(springConstantChanged(float)));

	springParticle.position = vec3(-(initialRestLength/2),0,0);
	springParticle.damping = 0.5f;
	anchorParticle.position = vec3((initialRestLength/2),0,0);

	springRestGraphic = addVectorGraphic();
	springRestGraphic->position = anchorParticle.position;
	springRestGraphic->displayStyle = DS_POINT;
	springRestGraphic->color = vec3(0.5f,0.5f,0.5f);
	springRestGraphic->pointSize = initialRestLength*2;


	anchorParticleGraphic = addVectorGraphic();
	anchorParticleGraphic->position = anchorParticle.position;
	anchorParticleGraphic->displayStyle = DS_POINT;
	anchorParticleGraphic->color = vec3(0,0.8f,0);

	springParticleGraphic = addVectorGraphic();
	springParticleGraphic->position = springParticle.position;
	springParticleGraphic->displayStyle = DS_POINT;
	springParticleGraphic->color = vec3(0.5f,0,1);


	springGenerator = ParticleSpringGenerator(&anchorParticle, initialSpringConstant, initialRestLength);
	particleForceRegistry.add(&springParticle, &springGenerator);
}

void SpringForces::newFrame()
{
	cout << dt() << endl;

	particleForceRegistry.updateForces(dt());

	springParticle.integrate(dt());
	anchorParticle.integrate(dt());

	sync(anchorParticleGraphic, anchorParticle.position);
	sync(springRestGraphic, anchorParticle.position);
	sync(springParticleGraphic, springParticle.position);
}

void SpringForces::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	if(vectorGraphicIndex ==2)
	{
		springParticle.position += dragDelta;
		sync(springParticleGraphic, springParticle.position);
	}
	else if(vectorGraphicIndex == 1)
	{
		anchorParticle.position += dragDelta;
		sync(anchorParticleGraphic, anchorParticle.position);
		sync(springRestGraphic, anchorParticle.position);
	}
}

void SpringForces::restLengthChanged(float newVal)
{
	springGenerator.restLength = newVal;
	springRestGraphic->pointSize = newVal*2;
}

void SpringForces::springConstantChanged(float newVal)
{
	springGenerator.springConstant = newVal;
}