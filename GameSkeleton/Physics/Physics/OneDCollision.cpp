#include "OneDCollision.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include <QtGui\qpushbutton.h>
#include "DebugSlider.h"
#include <iostream>

using std::cout;
using std::endl;
vec3 redInitialVelocity = vec3(2,0,0);
vec3 blueInitialVelocity = vec3(-3,0,0);

float redInitialMass = 0.5f;
float blueInitialMass = 0.3f;

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
	QPushButton* resetButton = new QPushButton("Reset Particles");

	QHBoxLayout* redMassLayout = new QHBoxLayout();
	QLabel* redMassLabel = new QLabel("Red Mass");
	DebugSlider* redMassSlider = new DebugSlider(0.0f, 5.0f);
	redMassSlider->setValue(redInitialMass);
	redMassLayout->addWidget(redMassLabel);
	redMassLayout->addWidget(redMassSlider);


	QHBoxLayout* blueMassLayout = new QHBoxLayout();
	QLabel* blueMassLabel = new QLabel("Blue Mass");
	DebugSlider* blueMassSlider = new DebugSlider(0.0f, 5.0f);
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
	DebugSlider* redInitialVelocitySlider = new DebugSlider(0.0f, 10.0f);
	redInitialVelocitySlider->setValue(redInitialVelocity.x);
	redInitialVelocityLayout->addWidget(redInitialVelocityLabel);
	redInitialVelocityLayout->addWidget(redInitialVelocitySlider);

	QHBoxLayout* blueInitialVelocityLayout = new QHBoxLayout();
	QLabel* blueInitialVelocityLabel = new QLabel("Blue Initial Velocity");
	DebugSlider* blueInitialVelocitySlider = new DebugSlider(-10.0f, 0.0f);
	blueInitialVelocitySlider->setValue(blueInitialVelocity.x);
	blueInitialVelocityLayout->addWidget(blueInitialVelocityLabel);
	blueInitialVelocityLayout->addWidget(blueInitialVelocitySlider);
	
	QHBoxLayout* dispalyLayout = new QHBoxLayout();
	redVelocityLabel = new QLabel(redVelocityText + QString::number(redInitialVelocity.x));
	blueVelocityLabel = new QLabel(blueVelocityText + QString::number(blueInitialVelocity.x));
	totalMomentumLabel = new QLabel(totalMomentumText + QString::number(totalMomentum));
	totalKineticEnergyLabel = new QLabel(totalKineticText + QString::number(totalKineticEnergy));
	dispalyLayout->addWidget(redVelocityLabel);
	dispalyLayout->addWidget(blueVelocityLabel);
	dispalyLayout->addWidget(totalMomentumLabel);
	dispalyLayout->addWidget(totalKineticEnergyLabel);

	debugLayout->addWidget(resetButton);
	debugLayout->addLayout(redMassLayout);
	debugLayout->addLayout(blueMassLayout);
	debugLayout->addLayout(restitutionLayout);
	debugLayout->addLayout(redInitialVelocityLayout);
	debugLayout->addLayout(blueInitialVelocityLayout);
	debugLayout->addLayout(dispalyLayout);

	debugLayout->setSizeConstraint(QLayout::SetFixedSize);

	QObject::connect(resetButton, SIGNAL(clicked()), this, SLOT(resetParticles()));
	QObject::connect(redMassSlider, SIGNAL(valueChanged(float)), this, SLOT(redMassChanged(float)));
	QObject::connect(blueMassSlider, SIGNAL(valueChanged(float)), this, SLOT(blueMassChanged(float)));
	QObject::connect(restitutionSlider, SIGNAL(valueChanged(float)), this, SLOT(restitutionChanged(float)));
	QObject::connect(redInitialVelocitySlider, SIGNAL(valueChanged(float)), this, SLOT(redInitVelocityChanged(float)));
	QObject::connect(blueInitialVelocitySlider, SIGNAL(valueChanged(float)), this, SLOT(blueInitVelocityChanged(float)));
}
void OneDCollision::setupParticleGraphics()
{
	particleRedGraphic = addVectorGraphic();
	particleRedGraphic->position = particleRed->position;
	particleRedGraphic->color = vec3(1,0,0);
	particleRedMomentumGraphic = addVectorGraphic();
	particleRedMomentumGraphic->position = particleRed->position;
	particleRedMomentumGraphic->displayStyle = DS_ARROW;
	particleRedMomentumGraphic->color = vec3(0.5f, 0, 0);

	particleBlueGraphic = addVectorGraphic();
	particleBlueGraphic->position = particleBlue->position;
	particleBlueGraphic->color = vec3(0,0,1);
	particleBlueMomentumGraphic = addVectorGraphic();
	particleBlueMomentumGraphic->position = particleBlue->position;
	particleBlueMomentumGraphic->displayStyle = DS_ARROW;
	particleBlueMomentumGraphic->color = vec3(0, 0, 0.5f);

	syncAllParticles();
}
void OneDCollision::setupParticles()
{
	particleRed = new Particle();
	particleRed->position = vec3(-3, 0, 0);
	particleRed->velocity = redInitialVelocity;
	particleBlue = new Particle();
	particleBlue->position = vec3(3, 0, 0);
	particleBlue->velocity = blueInitialVelocity;

	contactGenerator.minimumSeparation = (particleRed->mass/2) + (particleBlue->mass/2);
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
	totalMomentumLabel->setText(totalMomentumText + QString::number(totalMomentum));
	totalKineticEnergyLabel->setText(totalKineticText + QString::number(totalKineticEnergy));
}
void OneDCollision::syncAllParticles()
{
	sync(particleRedGraphic, particleRed->position);
	sync(particleRedMomentumGraphic, particleRed->momentum, particleRed->position);
	sync(particleBlueGraphic, particleBlue->position);
	sync(particleBlueMomentumGraphic, particleBlue->momentum, particleBlue->position);
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
void OneDCollision::redInitVelocityChanged(float newVal)
{
	redInitialVelocity = vec3(newVal, 0 , 0);
}
void OneDCollision::blueInitVelocityChanged(float newVal)
{
	blueInitialVelocity = vec3(newVal, 0 , 0);
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