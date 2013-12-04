#include "CollideWallEffect.h"

void CollideWallEffect::buildParticles()
{
	particles = new Particle[numParticles];
	for(int i = 0; i < numParticles; i++)
	{
		particles[i].position = origin;
		particles[i].velocity = generator.randomUnitVector()*generator.randomFloat();
		particles[i].color = color;
		particles[i].lifetime = 2;
		int tem = (int)generator.randomIntRange(1,10);
		if(tem % 2 ==0)
			particles[i].size = 0;
		else
			particles[i].size = 1;
	}
}

bool CollideWallEffect::update(float dt)
{
	for(int i = 0; i< numParticles; i++)
	{
		if(particles[i].lifetime>0)
		{
			particles[i].position = particles[i].position+particles[i].velocity*dt*100;
			particles[i].lifetime = particles[i].lifetime-dt;
			float red = (particles[i].lifetime/2)*255;
			particles[i].color = RGB(red, 200,255);
			if(grid->wallCollision(particles[i].position,0))
				particles[i].lifetime=0;
		}
	}
	return checkAlive();
}

void CollideWallEffect::draw(Core::Graphics& g)
{
	for(int i = 0; i<numParticles; i++)
	{
		if(particles[i].lifetime>0)
		{
			g.SetColor(particles[i].color);
			Vector3D v = particles[i].position;
			if(particles[i].size ==0)
				g.DrawString((int)v.x,(int)v.y,"0");
			else
				g.DrawString((int)v.x,(int)v.y,"1");
		}
	}
}