#include "LerperTrainEffect.h"


void LerperTrainEffect::buildParticles()
{
	particles = new Particle[numParticles];
	for(int i = 0; i < numParticles; i++)
	{
		particles[i].position = origin;
		particles[i].velocity = 0;
		particles[i].color = color;
		particles[i].size = 1;
		particles[i].lifetime = fullLife;
	}
}

bool LerperTrainEffect::update(float dt)
{
	for(int i = 0; i< numParticles; i++)
	{
		particles[i].lifetime = particles[i].lifetime-dt;
		float red = (particles[i].lifetime/fullLife)*255;
		particles[i].color = RGB(red, 200,255);
		particles[i].size = (particles[i].lifetime/fullLife);
	}
	return checkAlive();
}



void LerperTrainEffect::draw(Core::Graphics& g)
{
	Vector3D shapePoints[] = 
	{
		Vector3D(-15, -15),
		Vector3D(15, -15),
		Vector3D(15, 15),
		Vector3D(-15, 15),

	};
	for(int i = 0; i<numParticles; i++)
	{
		Matrix3D trans = translate(particles[i].position.x, particles[i].position.y)*scale(particles[i].size, particles[i].size);
		if(particles[i].lifetime>0)
		{
			g.SetColor(particles[i].color);
			const unsigned int NUM_POINTS = sizeof(shapePoints) / sizeof(*shapePoints);
			for(int j = 0; j<NUM_POINTS; j++)
			{
				Vector3D v1 = trans * shapePoints[j];
				Vector3D v2 = trans * shapePoints[(j+1) % NUM_POINTS];
				g.DrawLine(v1.x, v1.y, v2.x, v2.y);
			}
		}
	}

}