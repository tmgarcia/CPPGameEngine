#include <glm\glm.hpp>
#include <iostream>

using glm::mat4;
using glm::vec3;
using glm::vec4;

using std::cout;
using std::endl;

void printMatrix(char* title, mat4 m)
{
	cout << title << endl;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			cout << i << j << "[" << m[i][j] <<"],"<< endl;
		}
	}
}

void printVector(char* title, vec3 v)
{
	cout << title << "("<< v.x << "," << v.y << "," << v.z << ")" << endl;
}

void printFloat(char* title, float f)
{
	cout << title << f << endl;
}

int main()
{
	cout << "---- BUILDING FORCE ----" << endl;
	vec3 p = vec3(0,0,0);
	printVector("particle position: ",p);
	vec3 o = vec3(2,0,0);
	printVector("other position: ",o);
	float restlength = 4;
	printFloat("restLength: ",restlength);
	float springConstant = 100;
	printFloat("springConstant: ",springConstant);

	cout << "--------" << endl;

	vec3 force = p;
	printVector("force = particle->position: ",force);
	force = p-o;
	printVector("force = force-other->position: ",force);
	float mag = glm::length(force);
	printFloat("magnitude = glm::length(force): ",mag);
	mag = (mag - restlength);
	printFloat("magnitude = magnitude - restlength: ",mag);

	/*mag = fabsf(mag);
	printFloat("magnitude = fabsf(magnitude): ",mag);*/

	mag = mag * springConstant;
	printFloat("magnitude = magnitude*springConstant: ",mag);

	force = glm::normalize(force);
	printVector("force = glm::normalize(force): ",force);

	force = force * -mag;
	printVector("force * -magnitude: ",force);

	cout << endl;
	cout << "---- BUILDING PARTICLE VELOCITY ----" << endl;
	
	printVector("particle position: ",p);
	vec3 v = vec3(0,0,0);
	printVector("particle velocity: ",v);
	vec3 a = vec3(0,0,0);
	printVector("particle acceleration: ",a);
	float m = 1.0f;
	printFloat("particle mass: ",m);
	float damp = 0.5f;
	float dt = 0.0065f;
	printFloat("dt(): ",dt);
	cout << "--------" << endl;

	p+= v * dt;
	printVector("position+=velocity*dt: ",p);
	float inverseMass = 1/m;
	printFloat("inverseMass = 1/mass: ",inverseMass);
	a = force * inverseMass;
	printVector("acceleration = accumulatedForce * inverseMass: ",a);
	v+= a * dt;
	printVector("velocity = acceleration * dt: ",v);
	v*= glm::pow(damp, dt);
	printVector("velocity *= glm::pow(damping,dt): ",v);
	p+= v * dt;
	printVector("next postion = position+=velocity*dt: ",p);

	std::cin;
	std::getchar();
}