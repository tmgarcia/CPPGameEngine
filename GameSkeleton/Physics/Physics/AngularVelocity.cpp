#include "AngularVelocity.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include <QtGui\qpushbutton.h>
#include "DebugSlider.h"
#include <time.h>


float radius;
float angularVelocity;
vec3 origin = vec3(0,0,0);
void AngularVelocity::initialize()
{
	GuiBase::initialize(false, false);
	srand((unsigned)time(NULL));
	radius = 3.0f;
	angularVelocity = 0.5f;

	setupParticles();
	setupMenu();

	isSpinning = true;
}
void AngularVelocity::setup()
{

}
void AngularVelocity::setupMenu()
{
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	QPushButton* throwButton = new QPushButton("Throw");
	QPushButton* retrieveButton = new QPushButton("Retrieve");
	buttonLayout->addWidget(throwButton);
	buttonLayout->addWidget(retrieveButton);

	QVBoxLayout* slidersLayout = new QVBoxLayout();

	QHBoxLayout* radiusLayout = new QHBoxLayout();
	QLabel* radiusLabel = new QLabel("Radius");
	DebugSlider* radiusSlider = new DebugSlider(0.1f, 5.0f);
	radiusSlider->setValue(radius);
	radiusLayout->addWidget(radiusLabel);
	radiusLayout->addWidget(radiusSlider);

	QHBoxLayout* angularVelocityLayout = new QHBoxLayout();
	QLabel* angularVelocityLabel = new QLabel("Angular Velocity");
	DebugSlider* angularVelocitySlider = new DebugSlider(0.0f, 10.0f);
	angularVelocitySlider->setValue(angularVelocity);
	angularVelocityLayout->addWidget(angularVelocityLabel);
	angularVelocityLayout->addWidget(angularVelocitySlider);

	slidersLayout->addLayout(radiusLayout);
	slidersLayout->addLayout(angularVelocityLayout);

	debugLayout->addLayout(slidersLayout, 1);
	debugLayout->addLayout(buttonLayout, 1);

	QObject::connect(throwButton, SIGNAL(clicked()), this, SLOT(throwParticle()));
	QObject::connect(retrieveButton, SIGNAL(clicked()), this, SLOT(retrieveParticle()));
	QObject::connect(radiusSlider, SIGNAL(valueChanged(float)), this, SLOT(radiusChanged(float)));
	QObject::connect(angularVelocitySlider, SIGNAL(valueChanged(float)), this, SLOT(angularVelocityChanged(float)));

}
void AngularVelocity::setupParticles()
{
	particle = new Particle();
	particle->position = vec3(3, 0, 0);
	particle->velocity = vec3(0,0,0);//position vector, normalize, * by radius

	particleGraphic = addVectorGraphic();
	particleGraphic->position = particle->position;
	particleGraphic->color = vec3(0,0,1);
	particleGraphic->pointSize = particle->mass;

	linearVelocityGraphic = addVectorGraphic();
	linearVelocityGraphic->position = particle->position;
	linearVelocityGraphic->color = vec3(1,0,1);
	linearVelocityGraphic->displayStyle = DS_ARROW;
	sync(linearVelocityGraphic, particle->velocity, particle->position);
}

void AngularVelocity::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	particle->position += dragDelta;
	sync(particleGraphic, particle->position);
	sync(linearVelocityGraphic, particle->velocity, particle->position);
}
void AngularVelocity::newFrame()
{
	particle->integrate(dt());
	if(isSpinning)
	{
		particle->position = glm::normalize(particle->position - origin)*radius;
		vec3 radiusVec = glm::normalize(particle->position - origin)*radius;
		vec3 perpRadius = vec3(-radiusVec.y, radiusVec.x, radiusVec.z);
		particle->velocity = angularVelocity*perpRadius;
	}

	sync(particleGraphic, particle->position);
	sync(linearVelocityGraphic, particle->velocity, particle->position);
}

void AngularVelocity::throwParticle()
{
	isSpinning = false;

}
void AngularVelocity::retrieveParticle()
{
	particle->position = vec3(3, 0, 0);
	isSpinning = true;
}
void AngularVelocity::radiusChanged(float newVal)
{
	radius = newVal;
}
void AngularVelocity::angularVelocityChanged(float newVal)
{
	angularVelocity = newVal;

}