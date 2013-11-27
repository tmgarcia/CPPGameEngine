#include "BinaryWaveEffect.h"


void BinaryWaveEffect::buildParticles()
{
	particles = new Particle[numParticles];
	for(int i = 0; i < numParticles; i++)
	{
		if(origin.x==0)
		{
			if(origin.y==0)
			{
				particles[i].position = origin;
				particles[i].velocity =generator.randomUnitVectorRange(0, 45)*generator.randomFloat();
			}
			else
			{
				particles[i].position = Vector3D(0.0f, generator.randomIntRange(0,900));
				particles[i].velocity =generator.randomIntRange(5,5.00001f);
			}
		}
		int tem = (int)generator.randomIntRange(1,10);
		if(tem % 2 ==0)
			particles[i].size = 0;
		else
			particles[i].size = 1;
		particles[i].color = color;
		particles[i].lifetime = generator.randomIntRange(1, 3);
	}
}
bool BinaryWaveEffect::update(float dt)
{
	for(int i = 0; i< numParticles; i++)
	{
		particles[i].position = particles[i].position+particles[i].velocity*dt*30;
		particles[i].lifetime = particles[i].lifetime-dt;
	}
	return checkAlive();
}
void BinaryWaveEffect::draw(Core::Graphics& g)
{
	g.SetColor(RGB(100,255,100));
	for(int i = 0; i<numParticles; i++)
	{
		if(particles[i].lifetime>0)
		{
			Vector3D v = particles[i].position;
			if(particles[i].size ==0)
				g.DrawString((int)v.x,(int)v.y,"0");
			else
				g.DrawString((int)v.x,(int)v.y,"1");
		}
	}

}