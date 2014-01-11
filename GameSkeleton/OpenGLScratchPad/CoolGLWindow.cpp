#include <GL\glew.h>
#include "CoolGLWindow.h"
#include <Qt\qdebug.h>

char* vertexShaderCode = 
	"#version 400\r\n"
	""
	"in layout(location=0) vec2 position;"
	"in layout(location=1) vec3 color;"
	""
	"out vec3 deColor;"
	""
	"void main()"
	"{"
	"	gl_Position = vec4(position, 1, 1);"
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
		-0.3f, -0.1f,
		+1.0f, +1.0f, +1.0f,
		-0.1f, -0.6f,
		+1.0f, +1.0f, +1.0f,
		+0.1f, -0.1f,
		+1.0f, +1.0f, +1.0f,

		-0.3f, -0.1f,
		+1.0f, +1.0f, +1.0f,
		-0.1f, -0.6f,
		+1.0f, +1.0f, +1.0f,
		-0.3f, -0.5f,
		+1.0f, +1.0f, +1.0f,

		+0.1f, -0.1f,
		+1.0f, +1.0f, +1.0f,
		-0.1f, -0.6f,
		+1.0f, +1.0f, +1.0f,
		+0.1f, -0.5f,
		+1.0f, +1.0f, +1.0f,

		-0.4f, +0.1f,
		+1.0f, +1.0f, +1.0f,
		-0.2f, +0.0f,
		+1.0f, +1.0f, +1.0f,
		-0.35f, -0.35f,
		+0.8f, +0.8f, +0.8f,

		+0.2f, +0.1f,
		+1.0f, +1.0f, +1.0f,
		+0.0f, +0.0f,
		+1.0f, +1.0f, +1.0f,
		+0.15f, -0.35f,
		+0.8f, +0.8f, +0.8f,

		-0.2f, +0.0f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.1f, -0.2f,
		+0.5255f, +0.3412f, +0.1294f,
		+0.0f, +0.0f,
		+0.5255f, +0.3412f, +0.1294f,

		+0.0f, +0.0f,
		+0.5255f, +0.3412f, +0.1294f,
		+0.1f, -0.24f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.05f, -0.1f,
		+0.5255f, +0.3412f, +0.1294f,

		-0.15f, -0.1f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.2f, -0.0f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.3f, -0.24f,
		+0.5255f, +0.3412f, +0.1294f,

		-0.15f, -0.1f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.3f, -0.5f,
		+0.3255f, +0.1412f, +0.0094f,
		-0.15f, -0.25f,
		+0.5255f, +0.3412f, +0.1294f,

		-0.05f, -0.1f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.05f, -0.25f,
		+0.5255f, +0.3412f, +0.1294f,
		+0.1f, -0.5f,
		+0.3255f, +0.1412f, +0.0094f,

		-0.1f, -0.2f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.15f, -0.25f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.05f, -0.25f,
		+0.5255f, +0.3412f, +0.1294f,

		-0.3f, -0.24f,
		+0.5255f, +0.3412f, +0.1294f,
		-0.35f, -0.35f,
		+0.3255f, +0.1412f, +0.0094f,
		-0.3f, -0.5f,
		+0.3255f, +0.1412f, +0.0094f,

		+0.1f, -0.24f,
		+0.5255f, +0.3412f, +0.1294f,
		+0.15f, -0.35f,
		+0.3255f, +0.1412f, +0.0094f,
		+0.1f, -0.5f,
		+0.3255f, +0.1412f, +0.0094f,

		-0.3f, -0.5f,
		+0.1608f, +0.0902f, +0.0f,
		-0.1f, -0.6f,
		+0.1608f, +0.0902f, +0.0f,
		-0.3f, -1.0f,
		+0.0608f, +0.0092f, +0.0f,

		+0.1f, -1.0f,
		+0.0608f, +0.0092f, +0.0f,
		-0.1f, -0.6f,
		+0.1608f, +0.0902f, +0.0f,
		-0.3f, -1.0f,
		+0.0608f, +0.0092f, +0.0f,

		-0.1f, -0.6f,
		+0.1608f, +0.0902f, +0.0f,
		+0.1f, -0.5f,
		+0.1608f, +0.0902f, +0.0f,
		+0.1f, -1.0f,
		+0.0608f, +0.0092f, +0.0f,

		-0.15f, -0.4f,
		+0.0f, +0.0f, +0.0f,
		-0.1f, -0.5f,
		+0.0f, +0.0f, +0.0f,
		-0.05f, -0.4f,
		+0.0f, +0.0f, +0.0f,
		//------------------------------
		-0.9f, +1.0f,
		+0.2451f, +0.2882f, +0.0176f,
		-0.7f, +1.0f,
		+0.3451f, +0.5882f, +0.1176f,
		-0.6f, +0.3f,
		+0.3451f, +0.5882f, +0.1176f,

		-0.9f, +0.9f,
		+0.2451f, +0.2882f, +0.0176f,
		-0.8f, +0.1f,
		+0.2451f, +0.2882f, +0.0176f,
		-0.6f, +0.2f,
		+0.3451f, +0.5882f, +0.1176f,

		-0.8f, +0.0f,
		+0.2451f, +0.2882f, +0.0176f,
		-0.6f, +0.1f,
		+0.3451f, +0.5882f, +0.1176f,
		-0.5f, -0.9f,
		+0.3451f, +0.5882f, +0.1176f,

		-0.8f, -0.1f,
		+0.2451f, +0.2882f, +0.0176f,
		-0.7f, -1.0f,
		+0.2451f, +0.2882f, +0.0176f,
		-0.5f, -1.0f,
		+0.3451f, +0.5882f, +0.1176f,

		+0.6f, +1.0f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.5f, +1.0f,
		+0.3451f, +0.5882f, +0.1176f,
		+0.6f, +0.1f,
		+0.2451f, +0.2882f, +0.0176f,

		+0.5f, +0.8f,
		+0.3451f, +0.5882f, +0.1176f,
		+0.6f, +0.0f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.5f, -0.9f,
		+0.3451f, +0.5882f, +0.1176f,

		+0.6f, -0.1f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.5f, -1.0f,
		+0.3451f, +0.5882f, +0.1176f,
		+0.6f, -1.0f,
		+0.2451f, +0.2882f, +0.0176f,

		+0.7f, +1.0f,
		+0.3451f, +0.5882f, +0.1176f,
		+0.8f, +1.0f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.6f, +0.5f,
		+0.3451f, +0.5882f, +0.1176f,

		+0.8f, +0.9f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.6f, +0.4f,
		+0.3451f, +0.5882f, +0.1176f,
		+0.6f, +0.2f,
		+0.2451f, +0.2882f, +0.0176f,

		+0.5f, +0.2f,
		+0.3451f, +0.5882f, +0.1176f,
		+0.5f, +0.0f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.2f, -0.9f,
		+0.3451f, +0.5882f, +0.1176f,

		+0.5f, -0.1f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.3f, -1.0f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.2f, -1.0f,
		+0.3451f, +0.5882f, +0.1176f,

		+0.7f, -0.4f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.6f, -0.6f,
		+0.2451f, +0.2882f, +0.0176f,
		+0.6f, -0.7f,
		+0.2451f, +0.2882f, +0.0176f,
		//---------------------------------------------
		-0.8f, -1.0f,
		+0.3451f, +0.3922f, +0.0f,
		-0.9f, -1.0f,
		+0.1451f, +0.1922f, +0.0f,
		-1.0f, -0.5f,
		+0.1451f, +0.1922f, +0.0f,

		-0.8f, -1.0f,
		+0.1451f, +0.1922f, +0.0f,
		-0.7f, -1.0f,
		+0.3451f, +0.3922f, +0.0f,
		-0.9f, -0.2f,
		+0.1451f, +0.1922f, +0.0f,

		-0.5f, +0.4f,
		+0.3451f, +0.3922f, +0.0f,
		-0.6f, +0.3f,
		+0.1451f, +0.1922f, +0.0f,
		-0.6f, +0.1f,
		+0.1451f, +0.1922f, +0.0f,

		-0.6f, +0.2f,
		+0.1451f, +0.1922f, +0.0f,
		-0.6f, +0.1f,
		+0.1451f, +0.1922f, +0.0f,
		-0.3f, +0.1f,
		+0.3451f, +0.3922f, +0.0f,

		-0.6f, +0.1f,
		+0.1451f, +0.1922f, +0.0f,
		-0.5f, +0.0f,
		+0.3451f, +0.3922f, +0.0f,
		-0.4f, -0.3f,
		+0.3451f, +0.3922f, +0.0f,

		+0.1f, -0.3f,
		+0.3451f, +0.3922f, +0.0f,
		+0.3f, -0.5f,
		+0.1451f, +0.1922f, +0.0f,
		+0.3f, -0.6f,
		+0.1451f, +0.1922f, +0.0f,

		+0.2f, -0.2f,
		+0.3451f, +0.3922f, +0.0f,
		+0.3f, -0.5f,
		+0.1451f, +0.1922f, +0.0f,
		+0.3f, -0.6f,
		+0.1451f, +0.1922f, +0.0f,

		+0.6f, -0.1f,
		+0.1451f, +0.1922f, +0.0f,
		+0.7f, -0.3f,
		+0.1451f, +0.1922f, +0.0f,
		+0.7f, -0.4f,
		+0.1451f, +0.1922f, +0.0f,

		+0.7f, -0.3f,
		+0.1451f, +0.1922f, +0.0f,
		+0.7f, -0.4f,
		+0.1451f, +0.1922f, +0.0f,
		+0.8f, +0.0f,
		+0.1451f, +0.1922f, +0.0f,

		+0.7f, -0.4f,
		+0.1451f, +0.1922f, +0.0f,
		+0.8f, -0.4f,
		+0.1451f, +0.1922f, +0.0f,
		+0.9f, -0.2f,
		+0.1451f, +0.1922f, +0.0f,

	};

	GLuint bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

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

	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragShaderID);

	glLinkProgram(programID);

	glUseProgram(programID);
}

void CoolGLWindow::paintGL()
{
	glDrawArrays(GL_TRIANGLES, 0, 117);
}