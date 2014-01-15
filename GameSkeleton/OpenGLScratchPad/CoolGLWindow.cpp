#include <GL\glew.h>
#include "CoolGLWindow.h"
#include <Qt\qdebug.h>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"

#include <iostream>
using std::cout;
using std::endl;

using glm::vec3;
using glm::mat3;
using glm::mat4;

GLuint programID;
mat3 currentTransform;
GLfloat angle = 0;
vec3 position(0,0,1);
//mat4 a = mat4(currentTransform);
char* vertexShaderCode = 
	"#version 400\r\n"
	""
	"in layout(location=0) vec2 position;"
	"in layout(location=1) vec3 color;"
	""
	"uniform mat3 currentTransform;"
	""
	"out vec3 deColor;"
	""
	"void main()"
	"{"
	"	gl_Position = vec4(position, 1, 1);"
	"	gl_Position = gl_Position*mat4(currentTransform);"
	"	deColor = color;"
	"}"
	"";

char* fragmentShaderCode = 
	"#version 400\r\n"
	""
	"in vec3 deColor;"
	"out vec3 theFinalColor;"
	""
	"void main()"
	"{"
	"	theFinalColor = deColor;"
	"}";

void CoolGLWindow::initializeGL()
{
	glewInit();
	sendDataToHardware();
	compileShaders();

}

void CoolGLWindow::sendDataToHardware()
{
	GLfloat vertices[] = 
	{
		-0.2f, -0.2f,
		+1.0f, +0.0f, +0.0f,
		+0.0f, +0.2f,
		+0.0f, +1.0f, +0.0f,
		+0.2f, -0.2f,
		+0.0f, +0.0f, +1.0f,
	};

	GLuint bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);
}

void CoolGLWindow::myUpdate()
{
	float velocityScale = 0.05f;
	vec3 acc = vec3(0, velocityScale, 0);
	vec3 direction = mat3(glm::rotate(glm::degrees(-angle),vec3(0,0,1)))*acc;

	if(GetAsyncKeyState(VK_LEFT)<0)
	{
		angle -= 0.05f;
	}
	if(GetAsyncKeyState(VK_RIGHT)<0)
	{
		angle += 0.05f;
	}
	if(GetAsyncKeyState(VK_UP)<0)
	{
		position = position + direction;
	}
	if(GetAsyncKeyState(VK_DOWN)<0)
	{
		position = position - direction;
	}
	
	repaint();
}

void CoolGLWindow::compileShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	adapter[0] = fragmentShaderCode;
	glShaderSource(fragShaderID, 1, adapter, 0);
	adapter[0] = vertexShaderCode;
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
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	mat3 temp;
	mat3 scalar = mat3(glm::scale(glm::mat4(), vec3(2,1,0)));
	mat3 rotator = mat3(glm::rotate(glm::degrees(angle),vec3(0,0,1)));
	temp = scalar * rotator;
	temp[0].z = position.x;
	temp[1].z = position.y;
	temp[2].z = 1.0f;
	currentTransform = mat3();
	currentTransform = currentTransform * temp;

	GLint currentTransformLocation = glGetUniformLocation(programID, "currentTransform");
	glUniformMatrix3fv(currentTransformLocation, 1, false, &(currentTransform[0][0]));
	glDrawArrays(GL_TRIANGLES, 0, 3);
}