#include "MultipleContacts.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include <QtGui\qpushbutton.h>
#include "DebugSlider.h"
#include <iostream>
#include <time.h>

#include "RandomColorGenerator.h"

using std::cout;
using std::endl;

RandomColorGenerator randomColor;

void MultipleContacts::initialize()
{
	GuiBase::initialize(false, false);
	srand((unsigned)time(NULL));
	originalRestitution = 0.9f;

	setupParticles();
	setupParticleGraphics();
	setupMenu();
}
void MultipleContacts::setupMenu()
{
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	QPushButton* resetFallButton = new QPushButton("Reset To Fall");
	buttonLayout->addWidget(resetFallButton);

	QHBoxLayout* restitutionLayout = new QHBoxLayout();
	QLabel* restitutionLabel = new QLabel("Restitution");
	DebugSlider* restitutionSlider = new DebugSlider(0.0f, 1.0f);
	restitutionSlider->setValue(originalRestitution);
	restitutionLayout->addWidget(restitutionLabel);
	restitutionLayout->addWidget(restitutionSlider);

	debugLayout->addLayout(restitutionLayout);
	debugLayout->addLayout(buttonLayout);

	debugLayout->setSizeConstraint(QLayout::SetFixedSize);

	QObject::connect(resetFallButton, SIGNAL(clicked()), this, SLOT(resetToFall()));
	QObject::connect(restitutionSlider, SIGNAL(valueChanged(float)), this, SLOT(restitutionChanged(float)));
}
void MultipleContacts::setupParticleGraphics()
{
	bounceParticle1Graphic = addVectorGraphic();
	bounceParticle1Graphic->position = bounceParticle1->position;
	bounceParticle1Graphic->color = randomColor.getRandomColor();
	bounceParticle1Graphic->pointSize = bounceParticle1->mass;

	bounceParticle2Graphic = addVectorGraphic();
	bounceParticle2Graphic->position = bounceParticle2->position;
	bounceParticle2Graphic->color = randomColor.getRandomColor();
	bounceParticle2Graphic->pointSize = bounceParticle2->mass;

	bounceParticle3Graphic = addVectorGraphic();
	bounceParticle3Graphic->position = bounceParticle3->position;
	bounceParticle3Graphic->color = randomColor.getRandomColor();
	bounceParticle3Graphic->pointSize = bounceParticle3->mass;

	bounceParticle4Graphic = addVectorGraphic();
	bounceParticle4Graphic->position = bounceParticle4->position;
	bounceParticle4Graphic->color = randomColor.getRandomColor();
	bounceParticle4Graphic->pointSize = bounceParticle4->mass;

	freeParticleGraphic = addVectorGraphic();
	freeParticleGraphic->position = freeParticle->position;
	freeParticleGraphic->color = randomColor.getRandomColor();
	freeParticleGraphic->pointSize = freeParticle->mass;

	syncAllParticles();
}
void MultipleContacts::setupParticles()
{
	bounceParticle1 = new Particle();
	bounceParticle1->position = vec3(0,1,0);
	bounceParticle1->velocity = vec3(0,0,0);

	bounceParticle2 = new Particle();
	bounceParticle2->position = vec3(0,3,0);
	bounceParticle2->velocity = vec3(0,0,0);

	bounceParticle3 = new Particle();
	bounceParticle3->position = vec3(0,5,0);
	bounceParticle3->velocity = vec3(0,0,0);

	bounceParticle4 = new Particle();
	bounceParticle4->position = vec3(0,7,0);
	bounceParticle4->velocity = vec3(0,0,0);

	freeParticle = new Particle();
	freeParticle->position = vec3(-8.0f,3.5f,0);
	freeParticle->velocity = vec3(2,-0.5f,0);

	particleWorld = ParticleWorld(14, 1);
	ParticleContact contacts[14] = {};
	particleWorld.contacts = contacts;
	particleWorld.particles.push_back(bounceParticle1);
	particleWorld.particles.push_back(bounceParticle2);
	particleWorld.particles.push_back(bounceParticle3);
	particleWorld.particles.push_back(bounceParticle4);
	particleWorld.particles.push_back(freeParticle);

	for(int i = 0; i < 4; i++)
	{
		for(int j = i+1; j<5; j++)
		{
			TwoDParticleContactGenerator* gen = new TwoDParticleContactGenerator();
			gen->minimumSeparation = 1;
			gen->restitution = originalRestitution;
			gen->particle[0] = particleWorld.particles[i];
			gen->particle[1] = particleWorld.particles[j];
			particleWorld.contactGenerators.push_back(gen);
		}
	}

	for(int i = 0; i<4; i++)
	{
		FloorContactGenerator* gen = new FloorContactGenerator();
		gen->minimumSeparation = 0.5f;
		gen->restitution = originalRestitution;
		gen->particle = particleWorld.particles[i];
		gen->yPositionOfFloor = 0;
		particleWorld.contactGenerators.push_back(gen);
	}

	gravityGenerator = ParticleGravityGenerator();
	forceRegistry.add(bounceParticle1, &gravityGenerator);
	forceRegistry.add(bounceParticle2, &gravityGenerator);
	forceRegistry.add(bounceParticle3, &gravityGenerator);
	forceRegistry.add(bounceParticle4, &gravityGenerator);
}
void MultipleContacts::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	switch (vectorGraphicIndex)
	{
	case 0:
		bounceParticle1->position += dragDelta;
		syncAllParticles();
		break;
	case 1:
		bounceParticle2->position += dragDelta;
		syncAllParticles();
		break;
	case 2:
		bounceParticle3->position += dragDelta;
		syncAllParticles();
		break;
	case 3:
		bounceParticle4->position += dragDelta;
		syncAllParticles();
		break;
	case 4:
		freeParticle->position += dragDelta;
		syncAllParticles();
		break;
	}
	syncAllParticles();
}
void MultipleContacts::newFrame()
{
	//cout << dt() << endl;
	//cout << freeParticle->velocity.x << ","<< freeParticle->velocity.y << "," << freeParticle->velocity.z << endl;
	forceRegistry.updateForces(dt());

	particleWorld.runPhysics(dt());

	syncAllParticles();
	syncAllLabels();
}
void MultipleContacts::syncAllLabels()
{
}
void MultipleContacts::syncAllParticles()
{
	sync(bounceParticle1Graphic, bounceParticle1->position);
	sync(bounceParticle2Graphic, bounceParticle2->position);
	sync(bounceParticle3Graphic, bounceParticle3->position);
	sync(bounceParticle4Graphic, bounceParticle4->position);
	sync(freeParticleGraphic, freeParticle->position);

}
void MultipleContacts::restitutionChanged(float newVal)
{
	for(int i = 0; i< 14; i++)
	{
		particleWorld.contactGenerators[i]->setRestitution(newVal);
	}
}
void MultipleContacts::resetToFall()
{
	bounceParticle1->position = vec3(0,1,0);
	bounceParticle1->velocity = vec3(0,0,0);
	bounceParticle1->acceleration = vec3(0,0,0);

	bounceParticle2->position = vec3(0,3,0);
	bounceParticle2->velocity = vec3(0,0,0);
	bounceParticle2->acceleration = vec3(0,0,0);

	bounceParticle3->position = vec3(0,5,0);
	bounceParticle3->velocity = vec3(0,0,0);
	bounceParticle3->acceleration = vec3(0,0,0);

	bounceParticle4->position = vec3(0,7,0);
	bounceParticle4->velocity = vec3(0,0,0);
	bounceParticle4->acceleration = vec3(0,0,0);

	freeParticle->position = vec3(-8.0f,3.5f,0);
	freeParticle->velocity = vec3(2,-0.5f,0);
	freeParticle->acceleration = vec3(0,0,0);

	syncAllParticles();
}