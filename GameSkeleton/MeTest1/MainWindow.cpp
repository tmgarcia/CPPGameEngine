#include "MainWindow.h"
#include <glm\gtx\transform.hpp>
#include <GL\glew.h>
#include <GL\GL.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <glm\gtx\transform.hpp>
#include <GL\GLU.h>
#include <QtOpenGL\qglbuffer.h>
#include <QtOpenGL\qgl.h>
#include "ShapeData.h"
#include "ShapeGenerator.h"

using glm::vec4;
using glm::vec3;
using glm::mat4;

GLuint theBufferID;
GLuint programID;

GLuint cubeNumIndices;
GLuint torusNumIndices;
GLuint planeNumIndices;

GLuint cubeVertexArrayObjectID;
GLuint torusVertexArrayObjectID;
GLuint planeVertexArrayObjectID;

GLuint cubeVertexArrayIndex;
GLuint torusVertexArrayIndex;
GLuint planeVertexArrayIndex;


char* VectorShaderCode = 
{
	"#version 400"
	""
	"in layout(location=0) vec4 position;"
	"in layout(location=1) vec4 color;"
	""
	"out vec4 deColor;"
	""
	"void main()"
	"{"
	"	gl_position = position;"
	"	deColor = position;"
	"}"
	""
	""
	""
};

char* FragmentShaderCode = 
{
	"#version 400"
	""
	"in vec4 deColor;"
	""
	"out vec4 finalColor;"
	""
	"void main()"
	"{"
	"	finalColor = deColor;"
	"}"
	""
	""
	""
};

void MainWindow::initializeGL()
{
	
}

void MainWindow::sendDataToHardware()
{
	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	Neumont::ShapeData torusData = Neumont::ShapeGenerator::makeTorus(12);
	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(3);

	glGenBuffers(1, &theBufferID);
	glBufferData(GL_ARRAY_BUFFER, 
		cubeData.vertexBufferSize() + cubeData.indexBufferSize() +
		torusData.vertexBufferSize() + torusData.indexBufferSize() +
		planeData.vertexBufferSize() + planeData.indexBufferSize(), 0, GL_FALSE);
	
	GLintptr currentOffset = 0;
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cubeData.vertexBufferSize(), cubeData.verts);
	currentOffset += cubeData.vertexBufferSize();
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, currentOffset, cubeData.indexBufferSize(), cubeData.verts);
	currentOffset += cubeData.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, torusData.vertexBufferSize(), torusData.verts);
	currentOffset += torusData.vertexBufferSize();
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, currentOffset, torusData.indexBufferSize(), torusData.verts);
	currentOffset += torusData.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, planeData.vertexBufferSize(), planeData.verts);
	currentOffset += planeData.vertexBufferSize();
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, currentOffset, planeData.indexBufferSize(), planeData.verts);
	currentOffset += planeData.indexBufferSize();

	cubeNumIndices = cubeData.numIndices;
	torusNumIndices = torusData.numIndices;
	planeNumIndices = planeData.numIndices;

	glBindAttribLocation(programID, cubeVertexArrayIndex, &cubeVertexArrayIndex);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

void MainWindow::paintGL()
{

}
