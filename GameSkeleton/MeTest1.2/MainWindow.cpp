#include "MainWindow.h"
#include <GL\GL.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <ShapeData.h>
#include <ShapeGenerator.h>
#include "Camera.h"
#include <iostream>

using std::cout;
using std::endl;
using glm::vec4;
using glm::vec3;
using glm::mat4;

Camera camera;

GLuint theBufferID;
GLuint programID;

GLuint cubeNumIndices;
GLuint torusNumIndices;
GLuint planeNumIndices;

GLuint cubeVertexArrayID;
GLuint torusVertexArrayID;
GLuint planeVertexArrayID;

GLuint cubeIndexDataByteOffset;
GLuint torusIndexDataByteOffset;
GLuint planeIndexDataByteOffset;

const char* vertexShaderCode=
	"#version 430\r\n"
	""
	"in layout(location=0) vec3 position;"
	"in layout(location=1) vec4 color;"
	""
	"uniform mat4 fullTransform;"
	""
	"out vec4 deColor;"
	""
	"void main()"
	"{"
	"	vec4 v = vec4(position, 1.0f);"
	"	vec4 transformed = fullTransform * v;"
	"	gl_Position = transformed;"
	"	deColor = color;"
	"}";

const char* fragmentShaderCode=
	"#version 430\r\n"
	""
	"in vec4 deColor;"
	""
	"out vec4 finalColor;"
	""
	"void main()"
	"{"
	"	finalColor = deColor;"
	"}";

mat4 cube1Transform;
mat4 torus1Transform;
mat4 plane1Transform;

void MainWindow::transformModels()
{
	cube1Transform = glm::translate(mat4(), vec3(-10.0f, 0.0f, -10.0f));
	torus1Transform = glm::translate(mat4(), vec3(0.0f, 0.0f, -10.0f));
	plane1Transform = glm::translate(mat4(), vec3(10.0f, 0.0f, -10.0f));
	plane1Transform *= glm::rotate(90.0f, vec3(1,0,0));

}

void MainWindow::initializeGL()
{
	glewInit();
	glEnable(GL_DEPTH_BUFFER);
	transformModels();
	sendDataToHardware();
	compileShaders();
}

void MainWindow::sendDataToHardware()
{
	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	Neumont::ShapeData torusData = Neumont::ShapeGenerator::makeTorus(12);
	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(3);

	glGenBuffers(1, &theBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	glBufferData(GL_ARRAY_BUFFER, cubeData.vertexBufferSize()+cubeData.indexBufferSize() +
		torusData.vertexBufferSize()+torusData.indexBufferSize()+
		planeData.vertexBufferSize()+planeData.indexBufferSize(), 0, GL_STATIC_DRAW);
	
	GLsizeiptr currentOffset = 0;
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cubeData.vertexBufferSize(), cubeData.verts);
	currentOffset += cubeData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cubeData.indexBufferSize(), cubeData.indices);
	currentOffset += cubeData.indexBufferSize();

	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, torusData.vertexBufferSize(), torusData.verts);
	currentOffset += torusData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, torusData.indexBufferSize(), torusData.indices);
	currentOffset += torusData.indexBufferSize();

	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, planeData.vertexBufferSize(), planeData.verts);
	currentOffset += planeData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, planeData.indexBufferSize(), planeData.indices);
	currentOffset += planeData.indexBufferSize();

	glGenVertexArrays(1, &cubeVertexArrayID);
	glGenVertexArrays(1, &torusVertexArrayID);
	glGenVertexArrays(1, &planeVertexArrayID);

	glBindVertexArray(cubeVertexArrayID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	glVertexAttribPointer(0, 3,GL_FLOAT,GL_FALSE,Neumont::Vertex::STRIDE,(void*)Neumont::Vertex::POSITION_OFFSET);
	glVertexAttribPointer(1, 4,GL_FLOAT,GL_FALSE,Neumont::Vertex::STRIDE,(void*)Neumont::Vertex::COLOR_OFFSET);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(torusVertexArrayID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint torusByteOffset = cubeData.vertexBufferSize() + cubeData.indexBufferSize();
	glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE,Neumont::Vertex::STRIDE,(void*)(torusByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1, 4, GL_FLOAT,GL_FALSE,Neumont::Vertex::STRIDE,(void*)(torusByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);


	glBindVertexArray(planeVertexArrayID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint planeByteOffset = torusByteOffset + torusData.vertexBufferSize() + torusData.indexBufferSize();
	glVertexAttribPointer(0, 3,GL_FLOAT,GL_FALSE,Neumont::Vertex::STRIDE,(void*)(planeByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1, 4,GL_FLOAT,GL_FALSE,Neumont::Vertex::STRIDE,(void*)(planeByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	cubeIndexDataByteOffset = cubeData.vertexBufferSize();
	torusIndexDataByteOffset = torusByteOffset + torusData.vertexBufferSize();
	planeIndexDataByteOffset = planeByteOffset + planeData.vertexBufferSize();

	cubeNumIndices = cubeData.numIndices;
	torusNumIndices = torusData.numIndices;
	planeNumIndices = planeData.numIndices;
}
void MainWindow::compileShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	adapter[0] = vertexShaderCode;
	glShaderSource(vertexShaderID, 1, adapter, 0);
	adapter[0] = fragmentShaderCode;
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	GLint compileStatus;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compileStatus);
	if(compileStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];
		GLsizei bufferSize;
		glGetShaderInfoLog(vertexShaderID, infoLogLength, &bufferSize, buffer);
		cout << buffer << endl;
		delete [] buffer;
	}

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);

	glLinkProgram(programID);
	glUseProgram(programID);
}
void MainWindow::paintGL()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, (float)width()/height(), 0.1f,50.0f);
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	mat4 fullTransform;
	GLuint fullTransformLocation = glGetUniformLocation(programID, "fullTransform");

	fullTransform = worldToProjectionMatrix * cube1Transform;
	glBindVertexArray(cubeVertexArrayID);
	glUniformMatrix4fv(fullTransformLocation, 1, GL_FALSE, (float*)&fullTransform);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransform = worldToProjectionMatrix * torus1Transform;
	glBindVertexArray(torusVertexArrayID);
	glUniformMatrix4fv(fullTransformLocation, 1, false, (float*)&fullTransform);
	glDrawElements(GL_TRIANGLES, torusNumIndices, GL_UNSIGNED_SHORT, (void*)torusIndexDataByteOffset);

	fullTransform = worldToProjectionMatrix * plane1Transform;
	glBindVertexArray(planeVertexArrayID);
	glUniformMatrix4fv(fullTransformLocation, 1, false, (float*)&fullTransform);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);
}