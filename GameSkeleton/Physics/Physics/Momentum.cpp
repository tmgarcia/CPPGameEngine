#include "Momentum.h"
#include <Qt\qdebug.h>
#include "Particle.h"
#include "Qt\qlayout.h"
#include <QtGui\qcheckbox.h>
#include <QtGui\qlabel.h>
#include <QtGui\qslider>
#include "DebugSlider.h"
#include <Windows.h>


Particle particle;

QLabel* momentumDisplay;

void Momentum::initialize()
{
	momentumConserved = false;
	GuiBase::initialize(false, true);
	//label slider checkbox
	QHBoxLayout *momentumControl = new QHBoxLayout();
	QLabel *momentumLabel = new QLabel("Momentum:");
	momentumDisplay = new QLabel(QString::number(particle.getMomentumLength()));
	QLabel* conserveLabel = new QLabel("Conserve Momentum:");
	QCheckBox* conserveBox = new QCheckBox();
	DebugSlider* massSlider = new DebugSlider(0.10f, 10.0f, false);
	massSlider->setValue(1.0f);
	momentumControl->addWidget(momentumLabel);
	momentumControl->addWidget(momentumDisplay);
	momentumControl->addWidget(conserveLabel);
	momentumControl->addWidget(conserveBox);
	momentumControl->addWidget(massSlider);
	debugLayout->addLayout(momentumControl);

	QObject::connect(massSlider, SIGNAL(valueChanged(float)), this, SLOT(particleMassChanged(float)));
	QObject::connect(conserveBox, SIGNAL(stateChanged(int)), this, SLOT(toggleMomentumConservation(int)));
	
	particleGraphic = addVectorGraphic();
	particleGraphic->position = particle.position;
	particleGraphic->displayStyle = DS_POINT;
	particleGraphic->color = vec3(0.5f,0,0.5f);

	velocityGraphic = addVectorGraphic();
	velocityGraphic->displayStyle = DS_ARROW;
	velocityGraphic->color = vec3(1,0,0);

	momentumGraphic = addVectorGraphic();
	momentumGraphic->displayStyle = DS_ARROW;
	momentumGraphic->color = vec3(1,0,0);
}

void Momentum::newFrame()
{
	float acceleration = 1.00f;
	particle.newFrame(dt(), getUserDirection());
	momentumDisplay->setText(QString::number(particle.getMomentumLength()));
	sync(particleGraphic, particle.position);
	sync(velocityGraphic, particle.velocity, particle.position);
	sync(momentumGraphic, particle.momentum, particle.position);
}

void Momentum::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	particle.position += dragDelta;
}

glm::vec3 Momentum::getUserDirection()
{
	glm::vec3 direction = glm::vec3();
	//initialize then show
	if(isKeyDown("up") || GetAsyncKeyState('W'))
	{
		direction += glm::vec3(0,1,0);
		glm::normalize(direction);
	}
	if(isKeyDown("down")|| GetAsyncKeyState('S'))
	{
		direction += glm::vec3(0,-1,0);
		glm::normalize(direction);
	}
	if(isKeyDown("left")|| GetAsyncKeyState('A'))
	{
		direction += glm::vec3(-1,0,0);
		glm::normalize(direction);
	}
	if(isKeyDown("right")|| GetAsyncKeyState('D'))
	{
		direction += glm::vec3(1,0,0);
		glm::normalize(direction);
	}

	return direction;
}

void Momentum::particleMassChanged(float m)
{
	if(momentumConserved)
	{
		particle.velocity = particle.momentum/m;
	}
	particle.mass = m;
	particleGraphic->pointSize = m;
}
void Momentum::toggleMomentumConservation(int newVal)
{
	momentumConserved = newVal;
}