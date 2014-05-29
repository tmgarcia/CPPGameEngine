#include "ThreeDCube.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include <QtGui\qpushbutton.h>
#include "DebugSlider.h"
#include <iostream>
#include <time.h>


using std::cout;
using std::endl;


void ThreeDCube::initialize()
{
	GuiBase::initialize(true, false);
	srand((unsigned)time(NULL));
	originalRestitution = 1.0f;
	originalSpringConstant = 3;
	originalDamping = 0.2f;
	originalRestLength = 5.0f;

	setupParticles();
	setupParticleGraphics();
	setupMenu();
}
void ThreeDCube::setupMenu()
{
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	QPushButton* resetFallButton = new QPushButton("Reset");
	buttonLayout->addWidget(resetFallButton);

	QVBoxLayout* slidersLayout = new QVBoxLayout();

	QHBoxLayout* restitutionLayout = new QHBoxLayout();
	QLabel* restitutionLabel = new QLabel("Restitution");
	DebugSlider* restitutionSlider = new DebugSlider(0.0f, 1.0f);
	restitutionSlider->setValue(originalRestitution);
	restitutionLayout->addWidget(restitutionLabel);
	restitutionLayout->addWidget(restitutionSlider);

	QHBoxLayout* springConstantLayout = new QHBoxLayout();
	QLabel* springConstantLabel = new QLabel("Spring Contant");
	DebugSlider* springConstantSlider = new DebugSlider(0.0f, 100.0f, false, 100.0f);
	springConstantSlider->setValue(originalSpringConstant);
	springConstantLayout->addWidget(springConstantLabel);
	springConstantLayout->addWidget(springConstantSlider);

	QHBoxLayout* dampingLayout = new QHBoxLayout();
	QLabel* dampingLabel = new QLabel("Damping");
	DebugSlider* dampingSlider = new DebugSlider(0.0f, 1.0f, false, 100.0f);
	dampingSlider->setValue(originalDamping);
	dampingLayout->addWidget(dampingLabel);
	dampingLayout->addWidget(dampingSlider);

	/*QHBoxLayout* restLengthLayout = new QHBoxLayout();
	QLabel* restLengthLabel = new QLabel("Base Rest length");
	DebugSlider* restLengthSlider = new DebugSlider(0.5f, 10.0f, false, 100.0f);
	restLengthSlider->setValue(originalRestLength);
	restLengthLayout->addWidget(restLengthLabel);
	restLengthLayout->addWidget(restLengthSlider);*/

	slidersLayout->addLayout(springConstantLayout);
	//slidersLayout->addLayout(restLengthLayout);
	slidersLayout->addLayout(restitutionLayout);
	slidersLayout->addLayout(dampingLayout);

	debugLayout->addLayout(buttonLayout, 1);
	debugLayout->addLayout(slidersLayout, 1);

	QObject::connect(resetFallButton, SIGNAL(clicked()), this, SLOT(resetToFall()));
	QObject::connect(restitutionSlider, SIGNAL(valueChanged(float)), this, SLOT(restitutionChanged(float)));
	QObject::connect(springConstantSlider, SIGNAL(valueChanged(float)), this, SLOT(springConstantChanged(float)));
	QObject::connect(dampingSlider, SIGNAL(valueChanged(float)), this, SLOT(dampingChanged(float)));
	//QObject::connect(restLengthSlider, SIGNAL(valueChanged(float)), this, SLOT(restLengthChanged(float)));
}
void ThreeDCube::setupParticleGraphics()
{
	cubeParticle1Graphic = addVectorGraphic();
	cubeParticle1Graphic->position = cubeParticle1->position;
	cubeParticle1Graphic->color = randomColor.getRandomColor();
	cubeParticle1Graphic->pointSize = cubeParticle1->mass;

	cubeParticle2Graphic = addVectorGraphic();
	cubeParticle2Graphic->position = cubeParticle2->position;
	cubeParticle2Graphic->color = randomColor.getRandomColor();
	cubeParticle2Graphic->pointSize = cubeParticle2->mass;

	cubeParticle3Graphic = addVectorGraphic();
	cubeParticle3Graphic->position = cubeParticle3->position;
	cubeParticle3Graphic->color = randomColor.getRandomColor();
	cubeParticle3Graphic->pointSize = cubeParticle3->mass;

	cubeParticle4Graphic = addVectorGraphic();
	cubeParticle4Graphic->position = cubeParticle4->position;
	cubeParticle4Graphic->color = randomColor.getRandomColor();
	cubeParticle4Graphic->pointSize = cubeParticle4->mass;

	cubeParticle5Graphic = addVectorGraphic();
	cubeParticle5Graphic->position = cubeParticle5->position;
	cubeParticle5Graphic->color = randomColor.getRandomColor();
	cubeParticle5Graphic->pointSize = cubeParticle5->mass;

	cubeParticle6Graphic = addVectorGraphic();
	cubeParticle6Graphic->position = cubeParticle6->position;
	cubeParticle6Graphic->color = randomColor.getRandomColor();
	cubeParticle6Graphic->pointSize = cubeParticle6->mass;

	cubeParticle7Graphic = addVectorGraphic();
	cubeParticle7Graphic->position = cubeParticle7->position;
	cubeParticle7Graphic->color = randomColor.getRandomColor();
	cubeParticle7Graphic->pointSize = cubeParticle7->mass;

	cubeParticle8Graphic = addVectorGraphic();
	cubeParticle8Graphic->position = cubeParticle8->position;
	cubeParticle8Graphic->color = randomColor.getRandomColor();
	cubeParticle8Graphic->pointSize = cubeParticle8->mass;

	syncAllParticles();
}
void ThreeDCube::setupParticles()
{
	float halfRestLength = (originalRestLength/2);
	float bottomFaceHeight = originalRestLength;
	float topFaceHeight = originalRestLength + bottomFaceHeight;

	cubeParticle1 = new Particle();
	cubeParticle1->position = vec3(-halfRestLength,bottomFaceHeight,-halfRestLength);
	cubeParticle1->velocity = vec3(0,0,0);

	cubeParticle2 = new Particle();
	cubeParticle2->position = vec3(-halfRestLength,bottomFaceHeight,halfRestLength);
	cubeParticle2->velocity = vec3(0,0,0);

	cubeParticle3 = new Particle();
	cubeParticle3->position = vec3(halfRestLength,bottomFaceHeight,-halfRestLength);
	cubeParticle3->velocity = vec3(0,0,0);
	
	cubeParticle4 = new Particle();
	cubeParticle4->position = vec3(halfRestLength,bottomFaceHeight,halfRestLength);
	cubeParticle4->velocity = vec3(0,0,0);

	cubeParticle5 = new Particle();
	cubeParticle5->position = vec3(-halfRestLength,topFaceHeight,-halfRestLength);
	cubeParticle5->velocity = vec3(0,0,0);

	cubeParticle6 = new Particle();
	cubeParticle6->position = vec3(-halfRestLength,topFaceHeight,halfRestLength);
	cubeParticle6->velocity = vec3(0,0,0);

	cubeParticle7 = new Particle();
	cubeParticle7->position = vec3(halfRestLength,topFaceHeight,-halfRestLength);
	cubeParticle7->velocity = vec3(0,0,0);

	cubeParticle8 = new Particle();
	cubeParticle8->position = vec3(halfRestLength,topFaceHeight,halfRestLength);
	cubeParticle8->velocity = vec3(0,0,0);

	particleWorld = ParticleWorld(36, 1);
	ParticleContact contacts[36] = {};
	particleWorld.contacts = contacts;
	particleWorld.particles.push_back(cubeParticle1);
	particleWorld.particles.push_back(cubeParticle2);
	particleWorld.particles.push_back(cubeParticle3);
	particleWorld.particles.push_back(cubeParticle4);
	particleWorld.particles.push_back(cubeParticle5);
	particleWorld.particles.push_back(cubeParticle6);
	particleWorld.particles.push_back(cubeParticle7);
	particleWorld.particles.push_back(cubeParticle8);

	for(int i = 0; i < 7; i++)
	{
		for(int j = i+1; j<8; j++)
		{
			TwoDParticleContactGenerator* gen = new TwoDParticleContactGenerator();
			gen->minimumSeparation = 1;
			gen->restitution = originalRestitution;
			gen->particle[0] = particleWorld.particles[i];
			gen->particle[1] = particleWorld.particles[j];
			particleWorld.contactGenerators.push_back(gen);
		}
	}

	for(int i = 0; i<8; i++)
	{
		FloorContactGenerator* gen = new FloorContactGenerator();
		gen->minimumSeparation = 0.5f;
		gen->restitution = originalRestitution;
		gen->particle = particleWorld.particles[i];
		gen->yPositionOfFloor = 0;
		particleWorld.contactGenerators.push_back(gen);
	}

	gravityGenerator = ParticleGravityGenerator();
	for(int i = 0; i<8; i++)
	{
		forceRegistry.add(particleWorld.particles[i], &gravityGenerator);
	}

	for(int i = 0; i<8; i++)
	{
		Particle* anchor = particleWorld.particles[i];
		for(int j = 0; j<8; j++)
		{
			if(i != j)
			{
				Particle* attached = particleWorld.particles[j];
				float rest = glm::length(anchor->position - attached->position);
				ParticleSpringGenerator* gen = new ParticleSpringGenerator(anchor, originalSpringConstant, rest);	
				forceRegistry.add(attached, gen);
				springs.push_back(gen);
			}
		}
	}

}
void ThreeDCube::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{
	switch (vectorGraphicIndex)
	{
	case 0:
		cubeParticle1->position += dragDelta;
		syncAllParticles();
		break;
	case 1:
		cubeParticle2->position += dragDelta;
		syncAllParticles();
		break;
	case 2:
		cubeParticle3->position += dragDelta;
		syncAllParticles();
		break;
	case 3:
		cubeParticle4->position += dragDelta;
		syncAllParticles();
		break;
	case 4:
		cubeParticle5->position += dragDelta;
		syncAllParticles();
		break;
	case 5:
		cubeParticle6->position += dragDelta;
		syncAllParticles();
		break;
	case 6:
		cubeParticle7->position += dragDelta;
		syncAllParticles();
		break;
	case 7:
		cubeParticle8->position += dragDelta;
		syncAllParticles();
		break;
	}
	syncAllParticles();
}
void ThreeDCube::newFrame()
{
	//cout << dt() << endl;
	//cout << freeParticle->velocity.x << ","<< freeParticle->velocity.y << "," << freeParticle->velocity.z << endl;
	forceRegistry.updateForces(dt());

	particleWorld.runPhysics(dt());

	syncAllParticles();
	syncAllLabels();
}
void ThreeDCube::syncAllLabels()
{
}
void ThreeDCube::syncAllParticles()
{
	sync(cubeParticle1Graphic, cubeParticle1->position);
	sync(cubeParticle2Graphic, cubeParticle2->position);
	sync(cubeParticle3Graphic, cubeParticle3->position);
	sync(cubeParticle4Graphic, cubeParticle4->position);
	sync(cubeParticle5Graphic, cubeParticle5->position);
	sync(cubeParticle6Graphic, cubeParticle6->position);
	sync(cubeParticle7Graphic, cubeParticle7->position);
	sync(cubeParticle8Graphic, cubeParticle8->position);

}
void ThreeDCube::restitutionChanged(float newVal)
{
	for(int i = 0; i< 14; i++)
	{
		particleWorld.contactGenerators[i]->setRestitution(newVal);
	}
}
void ThreeDCube::springConstantChanged(float newVal)
{
	for(int i = 0; i< springs.count(); i++)
	{
		springs[i]->springConstant = newVal;
	}

	syncAllParticles();
}
void ThreeDCube::restLengthChanged(float newVal)
{
	for(int i = 0; i< springs.count(); i++)
	{
		springs[i]->restLength = newVal;
	}

	syncAllParticles();
}
void ThreeDCube::dampingChanged(float newVal)
{
	for(int i = 0; i< 8; i++)
	{
		particleWorld.particles[i]->damping = newVal;
	}

	syncAllParticles();
}
void ThreeDCube::resetToFall()
{
	float halfRestLength = (originalRestLength/2);
	float bottomFaceHeight = originalRestLength;
	float topFaceHeight = originalRestLength + bottomFaceHeight;

	cubeParticle1->position = vec3(-halfRestLength,bottomFaceHeight,-halfRestLength);
	cubeParticle1->velocity = vec3(0,0,0);
	cubeParticle1->acceleration = vec3(0,0,0);

	cubeParticle2->position = vec3(-halfRestLength,bottomFaceHeight,halfRestLength);
	cubeParticle2->velocity = vec3(0,0,0);
	cubeParticle2->acceleration = vec3(0,0,0);

	cubeParticle3->position = vec3(halfRestLength,bottomFaceHeight,-halfRestLength);
	cubeParticle3->velocity = vec3(0,0,0);
	cubeParticle3->acceleration = vec3(0,0,0);
	
	cubeParticle4->position = vec3(halfRestLength,bottomFaceHeight,halfRestLength);
	cubeParticle4->velocity = vec3(0,0,0);
	cubeParticle4->acceleration = vec3(0,0,0);

	cubeParticle5->position = vec3(-halfRestLength,topFaceHeight,-halfRestLength);
	cubeParticle5->velocity = vec3(0,0,0);
	cubeParticle5->acceleration = vec3(0,0,0);

	cubeParticle6->position = vec3(-halfRestLength,topFaceHeight,halfRestLength);
	cubeParticle6->velocity = vec3(0,0,0);
	cubeParticle6->acceleration = vec3(0,0,0);

	cubeParticle7->position = vec3(halfRestLength,topFaceHeight,-halfRestLength);
	cubeParticle7->velocity = vec3(0,0,0);
	cubeParticle7->acceleration = vec3(0,0,0);

	cubeParticle8->position = vec3(halfRestLength,topFaceHeight,halfRestLength);
	cubeParticle8->velocity = vec3(0,0,0);
	cubeParticle8->acceleration = vec3(0,0,0);

	syncAllParticles();
}