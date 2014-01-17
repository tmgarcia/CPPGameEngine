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
mat3 p1Transform;
mat3 p2Transform;
GLfloat p1Angle = 0;
GLfloat p2Angle = 0;
vec3 p1Position(-0.5f,0,1);
vec3 p2Position(0.5f,0,1);
vec3 p1Color(0.5f,0.0f,0.8f);
vec3 p2Color(0.0f,0.5f,0.5f);

//mat4 a = mat4(currentTransform);
char* vertexShaderCode = 
	"#version 400\r\n"
	""
	"in layout(location=0) vec2 position;"
	"in layout(location=1) vec3 color;"
	""
	"uniform mat3 currentTransform;"
	"uniform vec3 dominatingColor;"
	""
	"out vec3 deColor;"
	""
	"void main()"
	"{"
	"	gl_Position = vec4(position, 1, 1);"
	"	gl_Position = gl_Position*mat4(currentTransform);"
	"	deColor = dominatingColor;"
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
		+0.0f, +0.6f, //0

		+0.3f, +0.3f, //1
		-0.3f, +0.3f, //2

		+0.0f, +0.1f, //3


		-0.4f, +0.1f, //4
		+0.2f, +0.1f,//5
		-0.4f, -0.1f,//6

		+0.4f, -0.1f,//7
		+0.4f, +0.1f,//8
		+0.2f, +0.1f,//9
		

		-0.3f, -0.3f,//10
		-0.1f, -0.5f,//11
		-0.3f, -0.5f,//12

		+0.3f, -0.3f,//13
		+0.3f, -0.5f,//14
		+0.1f, -0.5f,//15

		//

		+0.0f, +0.3f,//16

		+0.5f, -0.1f,//17
		-0.5f, -0.1f,//18

		+0.0f, -0.6f,//19
	};

	GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, 0, 0);
	//glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

	//glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);


	GLushort indices[] = {0,1,2,  1,2,3,  4,5,6, 7,8,9, 10,11,12, 13,14,15, 16,17,18, 17,18,19};
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

void CoolGLWindow::myUpdate()
{
	float velocityScale = 0.05f;
	vec3 acc = vec3(0, velocityScale, 0);
	vec3 direction = mat3(glm::rotate(glm::degrees(-p1Angle),vec3(0,0,1)))*acc;
	//Player 1 Controls
	if(GetAsyncKeyState(0x41)<0)//A
	{
		p1Angle -= 0.09f;
	}
	if(GetAsyncKeyState(0x44)<0)//D
	{
		p1Angle += 0.09f;
	}
	if(GetAsyncKeyState(0x57)<0)//W
	{
		p1Position = p1Position + direction;
	}
	if(GetAsyncKeyState(0x53)<0)//S
	{
		p1Position = p1Position - direction;
	}

	//Player 2 Controls
	direction = mat3(glm::rotate(glm::degrees(-p2Angle),vec3(0,0,1)))*acc;
	if(GetAsyncKeyState(VK_LEFT)<0)
	{
		p2Angle -= 0.09f;
	}
	if(GetAsyncKeyState(VK_RIGHT)<0)
	{
		p2Angle += 0.09f;
	}
	if(GetAsyncKeyState(VK_UP)<0)
	{
		p2Position = p2Position + direction;
	}
	if(GetAsyncKeyState(VK_DOWN)<0)
	{
		p2Position = p2Position - direction;
	}
	
	updatePlayer(p1Position, p1Angle, true);
	updatePlayer(p2Position, p2Angle, false);

	repaint();
}

void CoolGLWindow::updatePlayer(vec3 position, GLfloat angle, bool isP1)
{
	mat3 temp;
	mat3 scalar = mat3(glm::scale(glm::mat4(), vec3(0.3f,0.3f,0)));
	mat3 rotator = mat3(glm::rotate(glm::degrees(angle),vec3(0,0,1)));
	temp = scalar * rotator;
	temp[0].z = position.x;
	temp[1].z = position.y;
	temp[2].z = 1.0f;
	if(isP1)
	{
		p1Transform = mat3();
		p1Transform = p1Transform * temp;
	}
	else
	{
		p2Transform = mat3();
		p2Transform = p2Transform * temp;
	}
	
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
	glViewport(0,0,width(), height());

	vec3 dominatingColor;
	GLint dominatingColorLocation = glGetUniformLocation(programID, "dominatingColor");

	GLint currentTransformLocation = glGetUniformLocation(programID, "currentTransform");

	dominatingColor = p1Color;
	glUniform3fv(dominatingColorLocation, 1, &(dominatingColor[0]));
	currentTransform = p1Transform;
	glUniformMatrix3fv(currentTransformLocation, 1, false, &(currentTransform[0][0]));
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_SHORT, 0);

	dominatingColor = p2Color;
	glUniform3fv(dominatingColorLocation, 1, &(dominatingColor[0]));
	currentTransform = p2Transform;
	glUniformMatrix3fv(currentTransformLocation, 1, false, &(currentTransform[0][0]));
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_SHORT, 0);
}
