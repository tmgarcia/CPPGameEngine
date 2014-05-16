#include "AccumulatingForces.h"
#include "ParticleGravityGenerator.h"
#include "ParticleKeyboardForceGenerator.h"
#include "ParticleForceRegistry.h"
#include <PhysicsGui\VectorGraphic.h>
#include <Qt\qdebug.h>

VectorGraphic* gravityParticleGraphic;
VectorGraphic* keyboardParticleGraphic;
VectorGraphic* accumulatedParticleGraphic;

ParticleGravityGenerator gravityGenerator;
ParticleKeyboardForceGenerator keyboardGenerator;

ParticleForceRegistry forceRegistry;

void AccumulatingForces::initialize()
{
	GuiBase::initialize(false, true);

	gravityParticle.position = vec3(-2,0,0);
	accumulatedParticle.position = vec3(0,0,0);
	keyboardParticle.position = vec3(2,0,0);

	gravityParticleGraphic = addVectorGraphic();
	gravityParticleGraphic->position = gravityParticle.position;
	gravityParticleGraphic->displayStyle = DS_POINT;
	gravityParticleGraphic->r = 255;
	gravityParticleGraphic->g = 0;
	gravityParticleGraphic->b = 0;

	keyboardParticleGraphic = addVectorGraphic();
	keyboardParticleGraphic->position = keyboardParticle.position;
	keyboardParticleGraphic->displayStyle = DS_POINT;
	keyboardParticleGraphic->r = 0;
	keyboardParticleGraphic->g = 0;
	keyboardParticleGraphic->b = 255;

	accumulatedParticleGraphic = addVectorGraphic();
	accumulatedParticleGraphic->position = accumulatedParticle.position;
	accumulatedParticleGraphic->displayStyle = DS_POINT;
	accumulatedParticleGraphic->r = 200;
	accumulatedParticleGraphic->g = 0;
	accumulatedParticleGraphic->b = 255;

	forceRegistry.add(&gravityParticle, &gravityGenerator);
	forceRegistry.add(&keyboardParticle, &keyboardGenerator);
	forceRegistry.add(&accumulatedParticle, &gravityGenerator);
	forceRegistry.add(&accumulatedParticle, &keyboardGenerator);

}

void AccumulatingForces::newFrame()
{
	forceRegistry.updateForces(1);

	gravityParticle.integrate(dt());
	keyboardParticle.integrate(dt());
	accumulatedParticle.integrate(dt());

	sync(gravityParticleGraphic, gravityParticle.position);
	sync(keyboardParticleGraphic, keyboardParticle.position);
	sync(accumulatedParticleGraphic, accumulatedParticle.position);
}
