#include "OpeningSplash.h"


void OpeningSplash::buildParticles()
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
bool OpeningSplash::update(float dt)
{

	if( Core::Input::IsPressed( Core::Input::BUTTON_ENTER ) )
	{
		splashing = false;
	}

	for(int i = 0; i< numParticles; i++)
	{
		if(splashing && particles[i].lifetime<0)
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
void OpeningSplash::draw(Core::Graphics& g)
{
	for(int i = 0; i<numParticles; i++)
	{
		if(particles[i].lifetime>0)
		{
			assignColor(i, g);
			Vector3D v = particles[i].position;
			if(particles[i].size ==0)
				g.DrawString((int)v.x,(int)v.y,"0");
			else
				g.DrawString((int)v.x,(int)v.y,"1");
		}
	}

}

void OpeningSplash::assignColor(int i, Core::Graphics& g)
{
	if(splashing&&
/*H*/((particles[i].position.x>112 && particles[i].position.x<139) && (particles[i].position.y>208 && particles[i].position.y<411)
/*H*/|| (particles[i].position.x>139 && particles[i].position.x<236) && (particles[i].position.y>294 && particles[i].position.y<317)
/*H */|| (particles[i].position.x>236 && particles[i].position.x<263) && (particles[i].position.y>208 && particles[i].position.y<411)
/*E*/|| (particles[i].position.x>308 && particles[i].position.x<335) && (particles[i].position.y>208 && particles[i].position.y<411)
/*E*/|| (particles[i].position.x>335 && particles[i].position.x<418) && (particles[i].position.y>208 && particles[i].position.y<231)
/*E*/|| (particles[i].position.x>335 && particles[i].position.x<413) && (particles[i].position.y>294 && particles[i].position.y<317)
/*E*/|| (particles[i].position.x>335 && particles[i].position.x<418) && (particles[i].position.y>388 && particles[i].position.y<411)
/*L1*/|| (particles[i].position.x>455 && particles[i].position.x<482) && (particles[i].position.y>208 && particles[i].position.y<411)
/*L1*/|| (particles[i].position.x>482 && particles[i].position.x<568) && (particles[i].position.y>388 && particles[i].position.y<411)
/*L2*/|| (particles[i].position.x>596 && particles[i].position.x<623) && (particles[i].position.y>208 && particles[i].position.y<411)
/*L2*/|| (particles[i].position.x>623 && particles[i].position.x<709) && (particles[i].position.y>388 && particles[i].position.y<411)
/*O*/|| (particles[i].position.x>735 && particles[i].position.x<762) && (particles[i].position.y>208 && particles[i].position.y<411)
/*O*/|| (particles[i].position.x>762 && particles[i].position.x<857) && (particles[i].position.y>208 && particles[i].position.y<231)
/*O*/|| (particles[i].position.x>762 && particles[i].position.x<857) && (particles[i].position.y>388 && particles[i].position.y<411)
/*O*/|| (particles[i].position.x>857 && particles[i].position.x<884) && (particles[i].position.y>208 && particles[i].position.y<411)))
	{
		g.SetColor(RGB(255,255,255));

	}
	else
		g.SetColor(particles[i].color);
}