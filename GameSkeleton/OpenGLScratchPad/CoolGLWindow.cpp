#include <GL\glew.h>
#include "CoolGLWindow.h"
#include <Qt\qdebug.h>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
#include "Header.h"
#include <time.h>
#include <fstream>

#include <iostream>
using std::cout;
using std::endl;

using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;

GLint frameCount = 0;
GLuint programID;
GLfloat xAngle=0.9f;
GLfloat yAngle=0.5f;
GLfloat zAngle=0.0f;

void CoolGLWindow::initializeGL()
{
	srand((unsigned)time(NULL));
	glewInit();
	glEnable(GL_DEPTH_TEST);
	sendDataToHardware();
	compileShaders();
}

void CoolGLWindow::sendDataToHardware()
{
	GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Shape::verts), Shape::verts, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 2 * sizeof(vec3), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 2 * sizeof(vec3), (void*)(1 * sizeof(vec3)));
	
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Shape::indices), Shape::indices, GL_STATIC_DRAW);

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);
}

void CoolGLWindow::myUpdate()
{
	if(GetAsyncKeyState(0x41)<0)//A
	{
		yAngle -= 0.09f;
	}
	if(GetAsyncKeyState(0x44)<0)//D
	{
		yAngle += 0.09f;
	}
	if(GetAsyncKeyState(0x57)<0)//W
	{
		xAngle += 0.09f;
	}
	if(GetAsyncKeyState(0x53)<0)//S
	{
		xAngle -= 0.09f;
	}
	if(GetAsyncKeyState(0x45)<0)//E
	{
		zAngle += 0.09f;
	}
	if(GetAsyncKeyState(0x51)<0)//Q
	{
		zAngle -= 0.09f;
	}

	repaint();
}

std::string CoolGLWindow::readShaderCode(const char *filename)
{
	std::ifstream input(filename);
	if(!input.good())
	{
		cout << "File failed to load: " << filename;
		exit(1);
	}
	return std::string(
		std::istreambuf_iterator<char>(input),
		std::istreambuf_iterator<char>());
}

void CoolGLWindow::compileShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	std::string temp = readShaderCode("FragmentShaderCode.glsl");	
	adapter[0] = temp.c_str();
	glShaderSource(fragShaderID, 1, adapter, 0);
	 temp = readShaderCode("VertexShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);

	glCompileShader(fragShaderID);
	glCompileShader(vertexShaderID);

	GLint compileStatus;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compileStatus);
	if(compileStatus != GL_TRUE)
	{
		GLint logLength;
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &logLength);
		char* buffer = new char[logLength];
		GLsizei bitBucket;
		glGetShaderInfoLog(vertexShaderID, logLength, &bitBucket, buffer);
		qDebug() << buffer;
		delete [] buffer;
	}

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragShaderID);

	glLinkProgram(programID);

	glUseProgram(programID);
}

void CoolGLWindow::paintGL()
{
	//glm::perspective(fieldOfView, apsectRatio, Znear, Zfar);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0,0,width(), height());

	mat4 currentTransform = glm::translate(mat4(), vec3(0.0f, 0.0f, -4.0f));
	currentTransform *= glm::rotate(glm::degrees(xAngle), vec3(1,0,0));
	currentTransform *= glm::rotate(glm::degrees(yAngle), vec3(0,1,0));
	currentTransform *= glm::rotate(glm::degrees(zAngle), vec3(0,0,1));
	GLint currentTransformLocation = glGetUniformLocation(programID, "currentTransform");

	mat4 currentProjection = glm::perspective(60.0f, ((float)width()) / width(), 0.1f, 10.0f);
	GLint currentProjectionLocation = glGetUniformLocation(programID, "currentProjection");

	glUniformMatrix4fv(currentTransformLocation, 1, GL_FALSE, &(currentTransform[0][0]));
	glUniformMatrix4fv(currentProjectionLocation, 1, GL_FALSE, &(currentProjection[0][0]));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
}
