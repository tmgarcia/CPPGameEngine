#include <glm\glm.hpp>
#include <iostream>
#include <glm\gtx\transform.hpp>
#include "ScratchWindow.h"

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

//int main()
//{
//	ScratchWindow window;
//	window.show();
//}
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	ScratchWindow window;
	window.show();

	return app.exec();
}