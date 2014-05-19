#include "MultipleSprings.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include "DebugSlider.h"
#include "ParticleSpringGenerator.h"
#include "PhysicsGui\VectorGraphic.h"
#include <iostream>

using std::cout;
using std::endl;

float initialRestLength = 1.0f;
float initialSpringConstant = 1.0f;
float initialDamping = 0.9f;
float initialGravity = 0.0f;

void MultipleSprings::initialize()
{
	GuiBase::initialize(false, true);

	setupMenu();

	setupParticles();

	setupParticleGraphics();

	anchorAnd1SpringGenerator = ParticleSpringGenerator(&anchorParticle, initialSpringConstant, initialRestLength);
	particleForceRegistry.add(&springParticle1, &anchorAnd1SpringGenerator);

	particle1And2SpringGenerator = ParticleSpringGenerator(&springParticle1, initialSpringConstant, initialRestLength);
	particleForceRegistry.add(&springParticle2, &particle1And2SpringGenerator);

	particle2And3SpringGenerator = ParticleSpringGenerator(&springParticle2, initialSpringConstant, initialRestLength);
	particleForceRegistry.add(&springParticle3, &particle2And3SpringGenerator);

	particle3And4SpringGenerator = ParticleSpringGenerator(&springParticle3, initialSpringConstant, initialRestLength);
	particleForceRegistry.add(&springParticle4, &particle3And4SpringGenerator);

	particle4And5SpringGenerator = ParticleSpringGenerator(&springParticle4, initialSpringConstant, initialRestLength);
	particleForceRegistry.add(&springParticle5, &particle4And5SpringGenerator);

	gravityGenerator = ParticleGravityGenerator(vec3(0, initialGravity,0));
	particleForceRegistry.add(&springParticle1, &gravityGenerator);
	particleForceRegistry.add(&springParticle2, &gravityGenerator);
	particleForceRegistry.add(&springParticle3, &gravityGenerator);
	particleForceRegistry.add(&springParticle4, &gravityGenerator);
	particleForceRegistry.add(&springParticle5, &gravityGenerator);
}

void MultipleSprings::setupMenu()
{
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

	QHBoxLayout *dampingControl = new QHBoxLayout();
	QLabel *dampingLabel = new QLabel("Damping:");
	DebugSlider* dampingSlider = new DebugSlider(0.9f, 1.0f, false);
	dampingSlider->setValue(initialDamping);
	dampingControl->addWidget(dampingLabel);
	dampingControl->addWidget(dampingSlider);

	QHBoxLayout *gravityControl = new QHBoxLayout();
	QLabel *gravityLabel = new QLabel("Gravity:");
	DebugSlider* gravitySlider = new DebugSlider(-2.0f, 0.0f, false);
	gravitySlider->setValue(initialSpringConstant);
	gravityControl->addWidget(gravityLabel);
	gravityControl->addWidget(gravitySlider);

	debugLayout->addLayout(restingLengthControl);
	debugLayout->addLayout(springConstantControl);
	debugLayout->addLayout(dampingControl);
	debugLayout->addLayout(gravityControl);

	QObject::connect(restingLengthSlider, SIGNAL(valueChanged(float)), this, SLOT(restLengthChanged(float)));
	QObject::connect(springConstantSlider, SIGNAL(valueChanged(float)), this, SLOT(springConstantChanged(float)));
	QObject::connect(dampingSlider, SIGNAL(valueChanged(float)), this, SLOT(dampingChanged(float)));
	QObject::connect(gravitySlider, SIGNAL(valueChanged(float)), this, SLOT(gravityChanged(float)));
	
}
void MultipleSprings::setupParticleGraphics()
{
	anchorParticleGraphic = addVectorGraphic();
	anchorParticleGraphic->position = anchorParticle.position;
	anchorParticleGraphic->color = vec3(1,0,0);

	springParticle1Graphic = addVectorGraphic();
	springParticle1Graphic->position = springParticle1.position;
	springParticle1Graphic->color = vec3(1,0.7f,0);

	springParticle2Graphic = addVectorGraphic();
	springParticle2Graphic->position = springParticle2.position;
	springParticle2Graphic->color = vec3(1,1,0);

	springParticle3Graphic = addVectorGraphic();
	springParticle3Graphic->position = springParticle3.position;
	springParticle3Graphic->color = vec3(0,1,0);

	springParticle4Graphic = addVectorGraphic();
	springParticle4Graphic->position = springParticle4.position;
	springParticle4Graphic->color = vec3(0,0,1);

	springParticle5Graphic = addVectorGraphic();
	springParticle5Graphic->position = springParticle5.position;
	springParticle5Graphic->color = vec3(0.8f,0,1);
}
void MultipleSprings::setupParticles()
{
	anchorParticle.position = vec3(0,0,0);
	springParticle1.position = vec3(0,-initialRestLength,0);
	springParticle2.position = vec3(0,2*-initialRestLength,0);
	springParticle3.position = vec3(0,3*-initialRestLength,0);
	springParticle4.position = vec3(0,4*-initialRestLength,0);
	springParticle5.position = vec3(0,5*-initialRestLength,0);
}

void MultipleSprings::newFrame()
{
	particleForceRegistry.updateForces(dt());

	anchorParticle.integrate(dt());
	springParticle1.integrate(dt());
	springParticle2.integrate(dt());
	springParticle3.integrate(dt());
	springParticle4.integrate(dt());
	springParticle5.integrate(dt());

	sync(anchorParticleGraphic, anchorParticle.position);
	sync(springParticle1Graphic, springParticle1.position);
	sync(springParticle2Graphic, springParticle2.position);
	sync(springParticle3Graphic, springParticle3.position);
	sync(springParticle4Graphic, springParticle4.position);
	sync(springParticle5Graphic, springParticle5.position);
	//sync(springRestGraphic, anchorParticle.position);
}

void MultipleSprings::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	switch (vectorGraphicIndex)
	{
	case 0:
		anchorParticle.position += dragDelta;
		syncAllParticles();
		break;
	case 1:
		springParticle1.position += dragDelta;
		syncAllParticles();
		break;
	case 2:
		springParticle2.position += dragDelta;
		syncAllParticles();
		break;
	case 3:
		springParticle3.position += dragDelta;
		syncAllParticles();
		break;
	case 4:
		springParticle4.position += dragDelta;
		syncAllParticles();
		break;
	case 5:
		springParticle5.position += dragDelta;
		syncAllParticles();
		break;
	}
}

void MultipleSprings::syncAllParticles()
{
	sync(anchorParticleGraphic, anchorParticle.position);
	sync(springParticle1Graphic, springParticle1.position);
	sync(springParticle2Graphic, springParticle2.position);
	sync(springParticle3Graphic, springParticle3.position);
	sync(springParticle5Graphic, springParticle5.position);
	sync(springParticle4Graphic, springParticle4.position);
}

void MultipleSprings::restLengthChanged(float newVal)
{
	anchorAnd1SpringGenerator.restLength = newVal;
	particle1And2SpringGenerator.restLength = newVal;
	particle2And3SpringGenerator.restLength = newVal;
	particle3And4SpringGenerator.restLength = newVal;
	particle4And5SpringGenerator.restLength = newVal;
	//springRestGraphic->pointSize = newVal*2;
}

void MultipleSprings::springConstantChanged(float newVal)
{
	anchorAnd1SpringGenerator.springConstant = newVal;
	particle1And2SpringGenerator.springConstant = newVal;
	particle2And3SpringGenerator.springConstant = newVal;
	particle3And4SpringGenerator.springConstant = newVal;
	particle4And5SpringGenerator.springConstant = newVal;
}

void MultipleSprings::gravityChanged(float newVal)
{
	gravityGenerator.gravity = vec3(0,newVal,0);
}

void MultipleSprings::dampingChanged(float newVal)
{
	springParticle1.damping = newVal;
	springParticle2.damping = newVal;
	springParticle3.damping = newVal;
	springParticle4.damping = newVal;
	springParticle5.damping = newVal;
}