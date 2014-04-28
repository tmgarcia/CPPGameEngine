#include <glm\glm.hpp>
#include <iostream>

using glm::mat4;
using glm::vec3;
using glm::vec4;

using std::cout;
using std::endl;

void printMatrix(mat4 m)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			cout << i << j << m[i][j]<<endl;
		}
	}
}

int main()
{
	mat4 test1 = mat4();
	printMatrix(test1);
	vec4 v1 = vec4(11.0f, 12.0f, 13.0f, 14.0f);
	vec4 v2 = vec4(21.0f, 22.0f, 23.0f, 24.0f);
	vec4 v3 = vec4(31.0f, 32.0f, 33.0f, 34.0f);
	vec4 v4 = vec4(41.0f, 42.0f, 43.0f, 44.0f);
	mat4 test2 = mat4(v1,v2,v3,v4);
	cout<< "test2" << endl;
	printMatrix(test2);
	std::cin;
}