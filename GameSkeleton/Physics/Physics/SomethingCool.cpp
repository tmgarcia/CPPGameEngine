#include "SomethingCool.h"
#include "Qt\qlayout.h"
#include <QtGui\qpushbutton.h>
#include <QtGui\qcheckbox.h>
#include "DebugSlider.h"
#include <time.h>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <Qt\qapplication.h>

#include <random>

void SomethingCool::initialize()
{
	GuiBase::initialize(true, false);
	setup();
}
void SomethingCool::setup()
{
	springConstant = 30;
	restLength = 0;
	damping = 0.3f;
	waveMultiplier = 30.0f;
	initialSplashHeight = 1;
	splashDampen = 0.999f;

	creatingSplash = false;

	setupParticles();
	setupMenu();
}
DebugSlider* springConstantSlider;
DebugSlider* splashDampingSlider;
DebugSlider* dampingSlider;
DebugSlider* waveMultiplierSlider;
void SomethingCool::setupMenu()
{
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	QPushButton* splashButton = new QPushButton("Splash");
	QPushButton* resetButton = new QPushButton("Reset");
	QPushButton* resetSlidersButton = new QPushButton("Reset Sliders");

	buttonLayout->addWidget(splashButton);
	buttonLayout->addWidget(resetButton);
	buttonLayout->addWidget(resetSlidersButton);

	QVBoxLayout* sliderLayout = new QVBoxLayout();

	QHBoxLayout* springConstantLayout = new QHBoxLayout();
	QLabel* springConstantLabel = new QLabel("k");
	springConstantSlider = new DebugSlider(0.1f, 100.0f, false, 99.9f);
	springConstantSlider->setValue(springConstant);
	springConstantLayout->addWidget(springConstantLabel);
	springConstantLayout->addWidget(springConstantSlider);

	QHBoxLayout* splashDampingLayout = new QHBoxLayout();
	QLabel* splashDampingLabel = new QLabel("splash damping");
	splashDampingSlider = new DebugSlider(0.1f, 1.0f, false, 100.0f);
	splashDampingSlider->setValue(splashDampen);
	splashDampingLayout->addWidget(splashDampingLabel);
	splashDampingLayout->addWidget(splashDampingSlider);

	QHBoxLayout* dampingLayout = new QHBoxLayout();
	QLabel* dampingLabel = new QLabel("damping");
	dampingSlider = new DebugSlider(0.1f, 1.0f, false, 100.0f);
	dampingSlider->setValue(damping);
	dampingLayout->addWidget(dampingLabel);
	dampingLayout->addWidget(dampingSlider);

	QHBoxLayout* waveMultiplierLayout = new QHBoxLayout();
	QLabel* waveMultiplierLabel = new QLabel("Wave Multiplier");
	waveMultiplierSlider = new DebugSlider(10.0f, 100.0f, false, 90.0f);
	waveMultiplierSlider->setValue(waveMultiplier);
	waveMultiplierLayout->addWidget(waveMultiplierLabel);
	waveMultiplierLayout->addWidget(waveMultiplierSlider);

	sliderLayout->addLayout(springConstantLayout);
	sliderLayout->addLayout(dampingLayout);
	sliderLayout->addLayout(splashDampingLayout);
	sliderLayout->addLayout(waveMultiplierLayout);

	debugLayout->addLayout(buttonLayout);
	debugLayout->addLayout(sliderLayout);

	QObject::connect(splashButton, SIGNAL(clicked()), this, SLOT(splash()));
	QObject::connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));
	QObject::connect(resetSlidersButton, SIGNAL(clicked()), this, SLOT(resetSliders()));
	QObject::connect(springConstantSlider, SIGNAL(valueChanged(float)), this, SLOT(springConstantChanged(float)));
	QObject::connect(splashDampingSlider, SIGNAL(valueChanged(float)), this, SLOT(splashDampingChanged(float)));
	QObject::connect(dampingSlider, SIGNAL(valueChanged(float)), this, SLOT(dampingChanged(float)));
	QObject::connect(waveMultiplierSlider, SIGNAL(valueChanged(float)), this, SLOT(waveMultiplierChanged(float)));
	
}
void SomethingCool::setupParticles()
{
	float y = 0;

	float x = -25;
	float z = -25;


	for(int i = 0; i< 50; i++)//row
	{
		for(int j = 0; j<50; j++)//column
		{
			bungeeParticles[i][j].active = false;

			vec3 position = vec3(x,y,z);
			bungeeParticles[i][j].particle = new Particle();
			bungeeParticles[i][j].particle->position = position;
			bungeeParticles[i][j].particle->damping = damping;

			bungeeParticles[i][j].bungee = new StickyPointBungeeGenerator(position, springConstant, restLength);
			registry.add(bungeeParticles[i][j].particle, bungeeParticles[i][j].bungee);

			bungeeParticles[i][j].graphic = addVectorGraphic();
			bungeeParticles[i][j].graphic->position = position;

			x+= 1;
		}
		x = -25;
		z+=1;
	}

}
void SomethingCool::newFrame()
{
	registry.updateForces(dt());
	for(int i = 0; i<50; i++)
	{
		for(int j = 0; j<50; j++)
		{
			bungeeParticles[i][j].particle->integrate(dt());
			sync(bungeeParticles[i][j].graphic, bungeeParticles[i][j].particle->position);
		}
	}
	if(creatingSplash)
	{
		makeWave();
	}
}

void SomethingCool::makeWave()
{
	currentWaveRadius++;
	if(waveStage == 0)
	{
		bungeeParticles[randomI][randomJ].particle->velocity = vec3(0,0,0);
		bungeeParticles[randomI][randomJ].particle->position.y = 0;
		splashAcceleration = bungeeParticles[randomI][randomJ].bungee->lastForce;
	}
	splashAcceleration = splashAcceleration * splashDampen;
	int numParticlesMadeActive = 0;
	for(int i = 0; i<50; i++)
	{
		for(int j = 0; j<50; j++)
		{
			if(glm::length(bungeeParticles[i][j].bungee->point-bungeeParticles[randomI][randomJ].bungee->point)<=currentWaveRadius && !bungeeParticles[i][j].active)
			{
				bungeeParticles[i][j].particle->addForce(-splashAcceleration*waveMultiplier);
				bungeeParticles[i][j].active = true;
				numParticlesMadeActive++;
			}
		}
	}
	if(numParticlesMadeActive == 0)
	{
		for(int i = 0; i<50; i++)
		{
			for(int j = 0; j<50; j++)
			{
				bungeeParticles[i][j].active = false;
			}
		}
		creatingSplash = false;
	}
	waveStage ++;
}
void SomethingCool::splash()
{
	if(!creatingSplash)
	{
		std::random_device eng;
		std::uniform_real_distribution<float> randF(0, 1);
		std::uniform_int_distribution<int> rand(0, 49);

		randomI =  rand(eng);
		randomJ =  rand(eng);

		waveStage = 0;
		creatingSplash = true;
		bungeeParticles[randomI][randomJ].particle->position.y = initialSplashHeight;
		currentWaveRadius = 0;
	}
}
void SomethingCool::reset()
{
	creatingSplash = false;
	for(int i = 0; i< 50; i++)//row
	{
		for(int j = 0; j<50; j++)//column
		{
			bungeeParticles[i][j].active = false;

			bungeeParticles[i][j].particle->position.y = 0;
			bungeeParticles[i][j].particle->velocity = vec3(0,0,0);
			bungeeParticles[i][j].particle->acceleration = vec3(0,0,0);
			bungeeParticles[i][j].particle->clearAccumulator();

			bungeeParticles[i][j].graphic->position = bungeeParticles[i][j].particle->position;

		}
	}
}
void SomethingCool::resetSliders()
{
	springConstant = 30;
	damping = 0.3f;
	waveMultiplier = 30.0f;
	splashDampen = 0.999f;

	for(int i = 0; i< 50; i++)//row
	{
		for(int j = 0; j<50; j++)//column
		{
			bungeeParticles[i][j].bungee->springConstant = springConstant;
		}
	}

	springConstantSlider->setValue(springConstant);
	splashDampingSlider->setValue(splashDampen);
	dampingSlider->setValue(damping);
	waveMultiplierSlider->setValue(waveMultiplier);
}
void SomethingCool::dampingChanged(float newVal)
{
	damping = newVal;
}
void SomethingCool::splashDampingChanged(float newVal)
{
	splashDampen = newVal;
}
void SomethingCool::waveMultiplierChanged(float newVal)
{
	waveMultiplier = newVal;
}
void SomethingCool::springConstantChanged(float newVal)
{
	springConstant = newVal;
	for(int i = 0; i< 50; i++)//row
	{
		for(int j = 0; j<50; j++)//column
		{
			bungeeParticles[i][j].bungee->springConstant = springConstant;
		}
	}
}