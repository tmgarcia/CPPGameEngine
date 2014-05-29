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
	

	std::cin;
	std::getchar();
}