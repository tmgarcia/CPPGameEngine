#include "DragForces.h"

#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include "DebugSlider.h"
#include "ParticleForceRegistry.h"
#include "ParticleDragGenerator.h"
#include "PhysicsGui\VectorGraphic.h"

ParticleDragGenerator dragGenerator;
VectorGraphic* particleVGraphic;
ParticleForceRegistry registry;
QLabel *particleSpeedLabel;

void DragForces::initialize()
{
	GuiBase::initialize(false, true);
	QHBoxLayout *dragControl = new QHBoxLayout();

	particleSpeedLabel = new QLabel("Particle Speed:");
	QLabel *lowSpeedLabel = new QLabel("Low Speed:");
	DebugSlider* lowSpeedSlider = new DebugSlider(0.0f, 10.0f, false);
	QLabel* highSpeedLabel = new QLabel("High Speed:");
	DebugSlider* highSpeedSlider = new DebugSlider(0.0f, 10.0f, false);


	lowSpeedSlider->setValue(0.0f);
	highSpeedSlider->setValue(0.0f);
	dragControl->addWidget(particleSpeedLabel);
	dragControl->addWidget(lowSpeedLabel);
	dragControl->addWidget(lowSpeedSlider);
	dragControl->addWidget(highSpeedLabel);
	dragControl->addWidget(highSpeedSlider);
	debugLayout->addLayout(dragControl);
	QObject::connect(lowSpeedSlider, SIGNAL(valueChanged(float)), this, SLOT(lowSpeedChanged(float)));
	QObject::connect(highSpeedSlider, SIGNAL(valueChanged(float)), this, SLOT(highSpeedChanged(float)));

	dragGenerator = ParticleDragGenerator(0, 0);

	particle.position = vec3(-4, 0, 0);
	particle.velocity = vec3(3, 0, 0);

	particleVGraphic = addVectorGraphic();
	particleVGraphic->position = particle.position;
	particleVGraphic->displayStyle = DS_POINT;
	particleVGraphic->color = vec3(0.8f,0,1);

	registry.add(&particle, &dragGenerator);

}
void DragForces::newFrame()
{
	registry.updateForces(1);

	particle.integrate(dt());

	if(particle.position.x >= 4 || glm::length(particle.velocity)<=0.09f)
	{
		particle.position = vec3(-4, 0, 0);
		particle.velocity = vec3(3, 0, 0);
	}
	particleSpeedLabel->setText(QString::number(glm::length(particle.velocity)));
	sync(particleVGraphic, particle.position);
}


void DragForces::highSpeedChanged(float newVal)
{
	dragGenerator.highSpeed = newVal;
}
void DragForces::lowSpeedChanged(float newVal)
{
	dragGenerator.lowSpeed = newVal;

}