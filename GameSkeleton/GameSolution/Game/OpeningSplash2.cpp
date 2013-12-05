#include "OpeningSplash2.h"


void OpeningSplash2::buildParticles()
{
	particles = new Particle[numParticles];
	for(int i = 0; i < numParticles; i++)
	{
		particles[i].position = Vector3D(generator.randomIntRange(0,1000), 0.0f);
		particles[i].velocity =Vector3D(0,1)*generator.randomIntRange(4,4.00001f);

		int tem = (int)generator.randomIntRange(1,10);
		if(tem % 2 ==0)
			particles[i].size = 0;
		else
			particles[i].size = 1;
		particles[i].color = color;
		particles[i].lifetime = generator.randomIntRange(0, 3);
	}
}
bool OpeningSplash2::update(float dt)
{

	for(int i = 0; i< numParticles; i++)
	{
		if(particles[i].lifetime<0)
		{
			particles[i].position = Vector3D(generator.randomIntRange(0,1000), 0.0f);
			particles[i].lifetime = generator.randomIntRange(1, 3);
		}
		else
		{
			particles[i].position = particles[i].position+particles[i].velocity*dt*30;
			particles[i].lifetime = particles[i].lifetime-dt;
		}
	}

	return checkAlive();
}
void OpeningSplash2::draw(Core::Graphics& g)
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