#include "ParticleEffect.h"

void ParticleEffect::buildParticles()
{
		particles = new Particle[numParticles];
		if(effectType==1)
		{
			particleType=1;
			for(int i = 0; i < numParticles; i++)
			{
				particles[i].position = origin;
				particles[i].velocity = generator.randomUnitVector()*generator.randomFloat();
				particles[i].color = color;
				particles[i].lifetime = 5;
			}
		}
		else if(effectType==2)
		{
			particleType = 2;
			for(int i = 0; i < numParticles; i++)
			{
				particles[i].position = origin;
				particles[i].velocity = generator.randomUnitVectorRange(orientation-2, orientation+1)*generator.randomFloat();
				particles[i].color = color;
				particles[i].size = generator.randomIntRange(.5, 2);
				particles[i].lifetime = generator.randomIntRange(1, 1.5);
			}
		}
		else if(effectType==3)
		{
			particleType = 3;
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
}

bool ParticleEffect::update(float dt)
{
	if(particleType==1)
			{
				for(int i = 0; i< numParticles; i++)
				{
					particles[i].position = particles[i].position+particles[i].velocity*dt*100;
					particles[i].lifetime = particles[i].lifetime-dt;
				}
			}
	if(particleType==2)
	{
		for(int i = 0; i< numParticles; i++)
		{
			particles[i].position = particles[i].position+particles[i].velocity*dt*100;
			particles[i].lifetime = particles[i].lifetime-dt;			
		}
	}

	if(particleType==3)
	{
		for(int i = 0; i< numParticles; i++)
		{
			particles[i].position = particles[i].position+particles[i].velocity*dt*30;
			particles[i].lifetime = particles[i].lifetime-dt;
		}
	}
	bool alive = false;
	for(int i = 0; i< numParticles; i++)
	{
		if(particles[i].lifetime>0)
			alive = true;
	}
	return alive;
}

void ParticleEffect::draw(Core::Graphics& g)
{
	if(particleType == 1)
	{
		for(int i = 0; i<numParticles; i++)
		{
			Vector3D v1 = particles[i].position;
			Vector3D v2 = particles[i].position+Vector3D(1,0);
			g.DrawLine(v1.x, v1.y, v2.x, v2.y);
		}
	} 
	if(particleType == 2)
	{
		Vector3D* shapePoints[] = 
			{
				new Vector3D(0.0f, -5.0f),
				new Vector3D(3.5f, -3.5f),
				new Vector3D(5.0f, 0.0f),
				new Vector3D(3.5f, 3.5f),
				new Vector3D(0.0f, 5.0f),
				new Vector3D(-3.5f, 3.5f),
				new Vector3D(-5.0f, 0.0f),
				new Vector3D(-3.5f, -3.5f),
			};
			Vector3D* whitePoints[] = 
			{
				new Vector3D(-2.0f, -3.0f),
				new Vector3D(-1.3f, -2.1f),
				new Vector3D(-1.0f, 0.0f),
				new Vector3D(-1.3f, 2.1f),
				new Vector3D(-2.0f, 3.0f),
				new Vector3D(-2.7f, 2.1f),
				new Vector3D(-3.0f, -0.0f),
				new Vector3D(-2.7f, -2.1f),
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
					Vector3D v1 = trans * *shapePoints[j];
					Vector3D v2 = trans * *shapePoints[(j+1) % NUM_POINTS];
					g.DrawLine(v1.x, v1.y, v2.x, v2.y);
				}
				g.SetColor(RGB(155,155,155));
				for(int k = 0; k<NUM_POINTS; k++)
				{
					Vector3D v1 = trans * *whitePoints[k];
					Vector3D v2 = trans * *whitePoints[(k+1) % NUM_POINTS];
					g.DrawLine(v1.x, v1.y, v2.x, v2.y);
				}
			}
			else if(particles[i].lifetime<=0)
			{
				Vector3D a1 = trans * Vector3D(-1,-1);
				Vector3D a2 = trans * Vector3D(1,1);
				Vector3D b1 = trans * Vector3D(1,-1);
				Vector3D b2 = trans * Vector3D(-1,1);
				g.DrawLine(a1.x, a1.y, a2.x, a2.y);
				g.DrawLine(b1.x, b1.y, b2.x, b2.y);
			}
		}
	}
	else if(particleType == 3)
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
}
