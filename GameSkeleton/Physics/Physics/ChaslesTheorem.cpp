#include "ChaslesTheorem.h"
#include "Qt\qlayout.h"
#include <QtGui\qlabel.h>
#include <QtGui\qpushbutton.h>
#include "DebugSlider.h"
#include <time.h>

void ChaslesTheorem::initialize()
{
	GuiBase::initialize(false, false);
	srand((unsigned)time(NULL));
	radius = 2.0f;
	angularVelocity = 1.5f;
	throwSpeed = 2.8f;

	setup();

	isThrown = true;
}

void ChaslesTheorem::setup()
{
	setupParticles();
	setupMenu();
}
void ChaslesTheorem::setupMenu()
{

}
void ChaslesTheorem::setupParticles()
{
	bodyOrigin = vec3(0,0,0);
	vec3 lastPos = bodyOrigin;
	float spiralWidth = 0;
	float spiralIncrement= 0.5f;
	bool negate = true;

	for(int i = 0; i<10; i++)
	{
		spiralWidth = (i%2==0)? spiralWidth+spiralIncrement: spiralWidth;
		float multiplier = (negate)? -1:1;
		Particle* p = new Particle();
		p->position = (i%2 == 0)? vec3((lastPos.x+spiralWidth)*multiplier, lastPos.y, lastPos.x): vec3(lastPos.x, (lastPos.y+spiralWidth)*multiplier, lastPos.x);
		negate = (i%2 ==0);
		p->velocity = vec3(0,0,0);

		VectorGraphic* particleGraphic = addVectorGraphic();
		particleGraphic->position = p->position;
		particleGraphic->color = vec3(0,0,1);
		particleGraphic->pointSize = p->mass;

		VectorGraphic* particlePositionGraphic = addVectorGraphic();
		particlePositionGraphic->position = p->position;
		particlePositionGraphic->color = vec3(0,0,1);
		particlePositionGraphic->pointSize = p->mass;
		particlePositionGraphic->displayStyle = DS_ARROW;
		sync(particlePositionGraphic, p->position, bodyOrigin);


		BodyParticle* bp = new BodyParticle();
		bp->particle = p;

	}
}


void ChaslesTheorem::vectorGraphicMouseDrag(uint vectorGraphicIndex, const glm::vec3& dragDelta)
{

}
void ChaslesTheorem::newFrame()
{

}

void ChaslesTheorem::throwParticle()
{

}
void ChaslesTheorem::resetParticle()
{

}
void ChaslesTheorem::sameRadiusChanged(int)
{

}
void ChaslesTheorem::radiusChanged(float)
{

}
void ChaslesTheorem::angularVelocityChanged(float)
{

}
void ChaslesTheorem::throwSpeedChanged(float)
{

}