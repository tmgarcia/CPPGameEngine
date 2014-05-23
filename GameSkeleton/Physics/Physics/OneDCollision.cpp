#include "OneDCollision.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include <QtGui\qpushbutton.h>
#include "DebugSlider.h"
#include <iostream>

using std::cout;
using std::endl;
vec3 redInitialVelocity = vec3(0.5f,0.5f,0);
vec3 blueInitialVelocity = vec3(-4,-1,0);

float redInitialMass = 3.5f;
float blueInitialMass = 1.3f;

float initialRestitution = 1;

float totalMomentum;
float totalKineticEnergy;

QString redVelocityText = "Red Velocity: ";
QString blueVelocityText = "Blue Velocity: ";
QString totalMomentumText = "Total Momentum: ";
QString totalKineticText = "Total Kinetic Energy: ";

QLabel* redVelocityLabel;
QLabel* blueVelocityLabel;
QLabel* totalMomentumLabel;
QLabel* totalKineticEnergyLabel;
void OneDCollision::setupMenu()
{
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	QPushButton* resetButton = new QPushButton("Reset Particles");
	QPushButton* collideButton = new QPushButton("Collide");
	buttonLayout->addWidget(resetButton);
	buttonLayout->addWidget(collideButton);

	QHBoxLayout* redMassLayout = new QHBoxLayout();
	QLabel* redMassLabel = new QLabel("Red Mass");
	DebugSlider* redMassSlider = new DebugSlider(0.0f, 5.0f);
	redMassSlider->setValue(redInitialMass);
	redMassLayout->addWidget(redMassLabel);
	redMassLayout->addWidget(redMassSlider);


	QHBoxLayout* blueMassLayout = new QHBoxLayout();
	QLabel* blueMassLabel = new QLabel("Blue Mass");
	DebugSlider* blueMassSlider = new DebugSlider(0.0f, 5.0f, false, 50.0f);
	blueMassSlider->setValue(blueInitialMass);
	blueMassLayout->addWidget(blueMassLabel);
	blueMassLayout->addWidget(blueMassSlider);

	QHBoxLayout* restitutionLayout = new QHBoxLayout();
	QLabel* restitutionLabel = new QLabel("Restitution");
	DebugSlider* restitutionSlider = new DebugSlider(0.0f, 1.0f);
	restitutionSlider->setValue(initialRestitution);
	restitutionLayout->addWidget(restitutionLabel);
	restitutionLayout->addWidget(restitutionSlider);

	QHBoxLayout* redInitialVelocityLayout = new QHBoxLayout();
	QLabel* redInitialVelocityLabel = new QLabel("Red Initial Velocity");
	QLabel* redInitialVelocityXLabel = new QLabel("X:");
	DebugSlider* redInitialVelocityXSlider = new DebugSlider(0.0f, 10.0f);
	redInitialVelocityXSlider->setValue(redInitialVelocity.x);
	QLabel* redInitialVelocityYLabel = new QLabel("Y:");
	DebugSlider* redInitialVelocityYSlider = new DebugSlider(0.0f, 10.0f);
	redInitialVelocityYSlider->setValue(redInitialVelocity.y);

	redInitialVelocityLayout->addWidget(redInitialVelocityLabel);
	redInitialVelocityLayout->addWidget(redInitialVelocityXLabel);
	redInitialVelocityLayout->addWidget(redInitialVelocityXSlider);
	redInitialVelocityLayout->addWidget(redInitialVelocityYLabel);
	redInitialVelocityLayout->addWidget(redInitialVelocityYSlider);

	QHBoxLayout* blueInitialVelocityLayout = new QHBoxLayout();
	QLabel* blueInitialVelocityLabel = new QLabel("Blue Initial Velocity");
	QLabel* blueInitialVelocityXLabel = new QLabel("X:");
	DebugSlider* blueInitialVelocityXSlider = new DebugSlider(-10.0f, 0.0f);
	blueInitialVelocityXSlider->setValue(blueInitialVelocity.x);
	QLabel* blueInitialVelocityYLabel = new QLabel("Y:");
	DebugSlider* blueInitialVelocityYSlider = new DebugSlider(-10.0f, 0.0f);
	blueInitialVelocityYSlider->setValue(blueInitialVelocity.y);

	blueInitialVelocityLayout->addWidget(blueInitialVelocityLabel);
	blueInitialVelocityLayout->addWidget(blueInitialVelocityXLabel);
	blueInitialVelocityLayout->addWidget(blueInitialVelocityXSlider);
	blueInitialVelocityLayout->addWidget(blueInitialVelocityYLabel);
	blueInitialVelocityLayout->addWidget(blueInitialVelocityYSlider);
	
	QHBoxLayout* dispalyLayout = new QHBoxLayout();
	redVelocityLabel = new QLabel(redVelocityText + QString::number(redInitialVelocity.x));
	blueVelocityLabel = new QLabel(blueVelocityText + QString::number(blueInitialVelocity.x));
	totalKineticEnergyLabel = new QLabel(totalKineticText + QString::number(totalKineticEnergy));
	dispalyLayout->addWidget(redVelocityLabel);
	dispalyLayout->addWidget(blueVelocityLabel);
	dispalyLayout->addWidget(totalKineticEnergyLabel);


	debugLayout->addLayout(buttonLayout);
	debugLayout->addLayout(redMassLayout);
	debugLayout->addLayout(blueMassLayout);
	debugLayout->addLayout(restitutionLayout);
	debugLayout->addLayout(redInitialVelocityLayout);
	debugLayout->addLayout(blueInitialVelocityLayout);
	debugLayout->addLayout(dispalyLayout);

	debugLayout->setSizeConstraint(QLayout::SetFixedSize);

	QObject::connect(resetButton, SIGNAL(clicked()), this, SLOT(resetParticles()));
	QObject::connect(collideButton, SIGNAL(clicked()), this, SLOT(createCollision()));
	QObject::connect(redMassSlider, SIGNAL(valueChanged(float)), this, SLOT(redMassChanged(float)));
	QObject::connect(blueMassSlider, SIGNAL(valueChanged(float)), this, SLOT(blueMassChanged(float)));
	QObject::connect(restitutionSlider, SIGNAL(valueChanged(float)), this, SLOT(restitutionChanged(float)));
	QObject::connect(redInitialVelocityXSlider, SIGNAL(valueChanged(float)), this, SLOT(redInitVelocityXChanged(float)));
	QObject::connect(redInitialVelocityYSlider, SIGNAL(valueChanged(float)), this, SLOT(redInitVelocityYChanged(float)));
	QObject::connect(blueInitialVelocityXSlider, SIGNAL(valueChanged(float)), this, SLOT(blueInitVelocityXChanged(float)));
	QObject::connect(blueInitialVelocityYSlider, SIGNAL(valueChanged(float)), this, SLOT(blueInitVelocityYChanged(float)));
}
void OneDCollision::setupParticleGraphics()
{
	particleRedGraphic = addVectorGraphic();
	particleRedGraphic->position = particleRed->position;
	particleRedGraphic->color = vec3(1,0,0);
	particleRedGraphic->pointSize = particleRed->mass;
	particleRedMomentumGraphic = addVectorGraphic();
	particleRedMomentumGraphic->position = particleRed->position;
	particleRedMomentumGraphic->displayStyle = DS_ARROW;
	particleRedMomentumGraphic->color = vec3(0.5f, 0, 0);

	particleBlueGraphic = addVectorGraphic();
	particleBlueGraphic->position = particleBlue->position;
	particleBlueGraphic->color = vec3(0,0,1);
	particleBlueGraphic->pointSize = particleBlue->mass;
	particleBlueMomentumGraphic = addVectorGraphic();
	particleBlueMomentumGraphic->position = particleBlue->position;
	particleBlueMomentumGraphic->displayStyle = DS_ARROW;
	particleBlueMomentumGraphic->color = vec3(0, 0, 0.5f);

	particleRedSeparatingMomentumGraphic = addVectorGraphic();
	particleRedSeparatingMomentumGraphic->position = particleRed->position;
	particleRedSeparatingMomentumGraphic->displayStyle = DS_ARROW;
	particleRedSeparatingMomentumGraphic->color = vec3(0, 1, 0);

	particleBlueSeparatingMomentumGraphic = addVectorGraphic();
	particleBlueSeparatingMomentumGraphic->position = particleBlue->position;
	particleBlueSeparatingMomentumGraphic->displayStyle = DS_ARROW;
	particleBlueSeparatingMomentumGraphic->color = vec3(0, 1, 0);

	totalMomentumGraphic = addVectorGraphic();
	totalMomentumGraphic->position = vec3(0,0,0);
	totalMomentumGraphic->color = vec3(0,1,1);
	totalMomentumGraphic->displayStyle = DS_ARROW;

	sync(totalMomentumGraphic, particleRed->momentum + particleBlue->momentum, vec3(0,0,0));
	
	syncAllParticles();
}
void OneDCollision::setupParticles()
{
	particleRed = new Particle();
	particleRed->position = vec3(-3, -2, 0);
	particleRed->velocity = redInitialVelocity;
	particleRed->mass = redInitialMass;
	particleBlue = new Particle();
	particleBlue->position = vec3(7, 1, 0);
	particleBlue->velocity = blueInitialVelocity;
	particleBlue->mass = blueInitialMass;

	contactGenerator.minimumSeparation = (particleRed->mass/2.0f) + (particleBlue->mass/2.0f);
	contactGenerator.restitution = initialRestitution;
	contactGenerator.particle[0] = particleRed;
	contactGenerator.particle[1] = particleBlue;

	particleWorld = ParticleWorld(1, 1);
	ParticleContact contacts[1] = {};
	particleWorld.contacts = contacts;
	particleWorld.particles.push_back(particleRed);
	particleWorld.particles.push_back(particleBlue);
	particleWorld.contactGenerators.push_back(&contactGenerator);
}
void OneDCollision::initialize()
{
	GuiBase::initialize(false, false);
	setupParticles();
	setupParticleGraphics();
	setupMenu();
}
void OneDCollision::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	switch (vectorGraphicIndex)
	{
	case 0:
		particleRed->position += dragDelta;
		syncAllParticles();
		break;
	case 2:
		particleBlue->position += dragDelta;
		syncAllParticles();
		break;
	}
}
void OneDCollision::newFrame()
{
	particleWorld.runPhysics(dt());
	syncAllParticles();
	syncAllLabels();
}
void OneDCollision::syncAllLabels()
{
	totalMomentum = glm::length(particleRed->momentum + particleBlue->momentum);
	totalKineticEnergy = particleRed->getKineticEnergy() + particleBlue->getKineticEnergy();

	redVelocityLabel->setText(redVelocityText + QString::number(particleRed->velocity.x));
	blueVelocityLabel->setText(blueVelocityText + QString::number(particleBlue->velocity.x));
	totalKineticEnergyLabel->setText(totalKineticText + QString::number(totalKineticEnergy));
}
void OneDCollision::syncAllParticles()
{
	sync(particleRedGraphic, particleRed->position);
	sync(particleRedMomentumGraphic, particleRed->momentum, particleRed->position);
	sync(particleBlueGraphic, particleBlue->position);
	sync(particleBlueMomentumGraphic, particleBlue->momentum, particleBlue->position);

	vec3 normal = particleRed->position - particleBlue->position;
	normal = glm::normalize(normal);

	sync(particleRedSeparatingMomentumGraphic, glm::dot(particleRed->momentum,normal)*normal, particleRed->position);
	sync(particleBlueSeparatingMomentumGraphic, glm::dot(particleBlue->momentum,normal)*normal, particleBlue->position);

	sync(totalMomentumGraphic, particleRed->momentum + particleBlue->momentum, vec3(0,0,0));
}
void OneDCollision::redMassChanged(float newVal)
{
	particleRed->mass = newVal;
	particleRedGraphic->pointSize = newVal;
	contactGenerator.minimumSeparation = (particleRed->mass/2) + (particleBlue->mass/2);
}
void OneDCollision::blueMassChanged(float newVal)
{
	particleBlue->mass = newVal;
	particleBlueGraphic->pointSize = newVal;
	contactGenerator.minimumSeparation = (particleRed->mass/2) + (particleBlue->mass/2);
}
void OneDCollision::restitutionChanged(float newVal)
{
	contactGenerator.restitution = newVal;
}
void OneDCollision::redInitVelocityXChanged(float newVal)
{
	redInitialVelocity.x = newVal;
}
void OneDCollision::redInitVelocityYChanged(float newVal)
{
	redInitialVelocity.y = newVal;
}
void OneDCollision::blueInitVelocityXChanged(float newVal)
{
	blueInitialVelocity.x = newVal;
}
void OneDCollision::blueInitVelocityYChanged(float newVal)
{
	blueInitialVelocity.y = newVal;
}
void OneDCollision::resetParticles()
{
	particleRed->position = vec3(-3, 0, 0);
	particleRed->velocity = redInitialVelocity;
	particleRed->acceleration = vec3(0,0,0);

	particleBlue->position = vec3(3, 0, 0);
	particleBlue->velocity = blueInitialVelocity;
	particleBlue->acceleration = vec3(0,0,0);

	syncAllParticles();
}
void OneDCollision::createCollision()
{
	ParticleContact contact = ParticleContact();
	contact.particle[0] = particleRed;
	contact.particle[1] = particleBlue;
	vec3 normal = particleRed->position - particleBlue->position;
	normal = glm::normalize(normal);
	contact.contactNormal = normal;
	contact.penetration = 0;
	contact.restitution = contactGenerator.restitution;
	contact.resolve(dt());
}