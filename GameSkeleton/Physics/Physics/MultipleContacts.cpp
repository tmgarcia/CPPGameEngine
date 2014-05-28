#include "MultipleContacts.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include <QtGui\qpushbutton.h>
#include "DebugSlider.h"
#include <iostream>

using std::cout;
using std::endl;

//float startRestitution = 0.9f;

void MultipleContacts::setupMenu()
{
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	QPushButton* resetFallButton = new QPushButton("Reset To Fall");
	QPushButton* resetRestButton = new QPushButton("Reset To Rest");
	buttonLayout->addWidget(resetFallButton);
	buttonLayout->addWidget(resetRestButton);

	QHBoxLayout* restitutionLayout = new QHBoxLayout();
	QLabel* restitutionLabel = new QLabel("Restitution");
	DebugSlider* restitutionSlider = new DebugSlider(0.0f, 1.0f);
	//restitutionSlider->setValue(startRestitution);
	restitutionLayout->addWidget(restitutionLabel);
	restitutionLayout->addWidget(restitutionSlider);
	
	QHBoxLayout* dispalyLayout = new QHBoxLayout();
	//incomingBounceLabel = new QLabel(incomingBounceText + QString::number(0));
	//outgoingBounceLabel = new QLabel(outgoingBounceText + QString::number(0));
	//dispalyLayout->addWidget(incomingBounceLabel);
	//dispalyLayout->addWidget(outgoingBounceLabel);

	debugLayout->addLayout(dispalyLayout);
	debugLayout->addLayout(restitutionLayout);
	debugLayout->addLayout(buttonLayout);

	debugLayout->setSizeConstraint(QLayout::SetFixedSize);

	QObject::connect(resetFallButton, SIGNAL(clicked()), this, SLOT(resetToFall()));
	QObject::connect(resetRestButton, SIGNAL(clicked()), this, SLOT(resetToRest()));
	QObject::connect(restitutionSlider, SIGNAL(valueChanged(float)), this, SLOT(restitutionChanged(float)));
}
void MultipleContacts::setupParticleGraphics()
{
	/*bounceParticleGraphic = addVectorGraphic();
	bounceParticleGraphic->position = bounceParticle->position;
	bounceParticleGraphic->color = vec3(1,0,0);
	bounceParticleGraphic->pointSize = bounceParticle->mass;
*/
	syncAllParticles();
}
void MultipleContacts::setupParticles()
{
	bounceParticle1 = new Particle();
	bounceParticle1->position = vec3(0, 3, 0);
	bounceParticle1->velocity = vec3(0,0,0);

	bounceParticle2 = new Particle();
	bounceParticle2->position = vec3(0, 3, 0);
	bounceParticle2->velocity = vec3(0,0,0);

	bounceParticle3 = new Particle();
	bounceParticle3->position = vec3(0, 3, 0);
	bounceParticle3->velocity = vec3(0,0,0);

	bounceParticle4 = new Particle();
	bounceParticle4->position = vec3(0, 3, 0);
	bounceParticle4->velocity = vec3(0,0,0);

	freeParticle = new Particle();
	freeParticle->position = vec3(0, 3, 0);
	freeParticle->velocity = vec3(0,0,0);

	particleWorld = ParticleWorld(14, 1);
	ParticleContact contacts[14] = {};
	particleWorld.contacts = contacts;
	particleWorld.particles.push_back(bounceParticle1);
	particleWorld.particles.push_back(bounceParticle2);
	particleWorld.particles.push_back(bounceParticle3);
	particleWorld.particles.push_back(bounceParticle4);
	particleWorld.particles.push_back(freeParticle);

	//for(int i = 0; i < 3

	//bounceParticle = new Particle();
	//bounceParticle->position = vec3(0, 3, 0);
	//bounceParticle->velocity = vec3(1,0,0);
	////bounceParticle->damping = 0.9f;

	//contactGenerator.minimumSeparation = (bounceParticle->mass/2.0f);
	//contactGenerator.restitution = startRestitution;
	//contactGenerator.particle = bounceParticle;
	//contactGenerator.yPositionOfFloor = 0;

	//gravityGenerator = ParticleGravityGenerator();
	//forceRegistry.add(bounceParticle, &gravityGenerator);
	//
	//particleWorld = ParticleWorld(1, 1);
	//ParticleContact contacts[1] = {};
	//particleWorld.contacts = contacts;
	//particleWorld.particles.push_back(bounceParticle);
	//particleWorld.contactGenerators.push_back(&contactGenerator);
}
void MultipleContacts::initialize()
{
	GuiBase::initialize(false, false);
	setupParticles();
	setupParticleGraphics();
	setupMenu();
}
void MultipleContacts::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	//bounceParticle->position += dragDelta;
	syncAllParticles();
}
void MultipleContacts::newFrame()
{
	forceRegistry.updateForces(dt());

	particleWorld.runPhysics(dt());
	//incomingBounce = glm::length(particleWorld.preContactVelocity);
	//incomingBounceLabel->setText(incomingBounceText + QString::number(incomingBounce));

	//outgoingBounce = glm::length(bounceParticle->velocity);
	//outgoingBounceLabel->setText(outgoingBounceText + QString::number(outgoingBounce));
	syncAllParticles();
	syncAllLabels();
}
void MultipleContacts::syncAllLabels()
{
}
void MultipleContacts::syncAllParticles()
{
	//sync(bounceParticleGraphic, bounceParticle->position);

}
void MultipleContacts::restitutionChanged(float newVal)
{
	//contactGenerator.restitution = newVal;
}
void MultipleContacts::resetToFall()
{
	//bounceParticle->position = vec3(0, 3, 0);
	//bounceParticle->acceleration = vec3(0,0,0);
	//bounceParticle->velocity = vec3(1,0,0);

	syncAllParticles();
}
void MultipleContacts::resetToRest()
{
	//bounceParticle->position = vec3(0, 0.5f, 0);
	//bounceParticle->velocity = vec3(0,0,0);
	//bounceParticle->acceleration = vec3(0,0,0);

}