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


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	ScratchWindow window;
	window.show();

	/*Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	printFloat("vertexBufferSize(): ", (float)cubeData.vertexBufferSize());
	printFloat("numIndices: ", (float)cubeData.numIndices);
	printFloat("Neumont::Vertex::POSITION_OFFSET: ", (float)Neumont::Vertex::POSITION_OFFSET);
	printFloat("Neumont::Vertex::STRIDE: ", (float)Neumont::Vertex::STRIDE);
	printFloat("Num verts: ", (float)cubeData.numVerts);*/
	//cube = GeneralGLWindow::getInstance().addGeometry(cubeData.verts, cubeData.vertexBufferSize(), cubeData.indices, cubeData.numIndices, GL_TRIANGLES);
	//GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);

	return app.exec();
}
