#include "ParticleEffect.h"


ParticleEffect::~ParticleEffect()
{
	delete [] particles;
}

void ParticleEffect::buildParticles()
{
	
}

bool ParticleEffect::update(float dt)
{
	for(int i = 0; i< numParticles; i++)
	{
		particles[i].position = particles[i].position+particles[i].velocity*dt*100;
		particles[i].lifetime = particles[i].lifetime-dt;
	}
	return checkAlive();
}

void ParticleEffect::draw(Core::Graphics& g)
{
	for(int i = 0; i<numParticles; i++)
	{
		Vector3D v1 = particles[i].position;
		Vector3D v2 = particles[i].position+Vector3D(1,0);
		g.DrawLine(v1.x, v1.y, v2.x, v2.y);
	}
}

bool ParticleEffect::checkAlive()
{
	bool alive = false;
	for(int i = 0; i< numParticles; i++)
	{
		if(particles[i].lifetime>0)
			alive = true;
	}
	return alive;
}