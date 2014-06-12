#include <glm\glm.hpp>
#include <iostream>
#include <glm\gtx\transform.hpp>

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

void printRotation(float x, float y)
{
	printFloat("x ", x);
	printFloat("y ", y);
	printFloat("atan2f(y,x) ", atan2f(y,x));
	printFloat("atan2f(y,x)-2.356194490192345 ", atan2f(y,x)-2.356194490192345);
	cout << ""<< endl;
}

int main()
{
	//o/a = x/y
	float x = -1.82427f;
	float y = 3.05675f;
	float rotation =atan2f(y,x);

	printRotation(x, y);

	x = -1.79649f;
	y = 3.16623f;
	printRotation(x, y);

	x=-1.76427f; 
	y=3.26915f;
	printRotation(x, y);

	x=-1.73057f; 
	y=3.36643f;
	printRotation(x, y);

	x=-1.69278f; 
	y=3.4593f;
	printRotation(x, y);

	x=-1.64712f; 
	y=3.55661f;
	printRotation(x, y);

	x=-1.59912f; 
	y=3.64766;
	printRotation(x, y);

	x=-1.54388f; 
	y=3.74149f;
	printRotation(x, y);

	x=-1.48218f; 
	y=3.83258f;
	printRotation(x, y);

	x=-1.41672f; 
	y=3.91744f;
	printRotation(x, y);

	x=-1.34663f; 
	y=3.399652f;
	printRotation(x, y);

	x=-1.27308f; 
	y=4.06909f;
	printRotation(x, y);

	std::cin;
	std::getchar();
}