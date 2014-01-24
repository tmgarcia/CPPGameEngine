#include <GL\glew.h>
#include "CoolGLWindow.h"
#include <Qt\qdebug.h>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
#include "Header.h"
#include <time.h>
#include <fstream>
#include "ShapeData.h"
#include "ShapeGenerator.h"
#include "Camera.h"
#include <QtGUI\qmouseevent>
#include <QtGUI\qkeyevent>

#include <iostream>
using std::cout;
using std::endl;

using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;

GLuint programID;

GLuint cubeNumIndices;
GLuint sphereNumIndices;
GLuint planeNumIndices;
GLuint lineNumIndices;

GLuint cubeIndexDataByteOffset;
GLuint sphereIndexDataByteOffset;
GLuint planeIndexDataByteOffset;
GLuint lineIndexDataByteOffset;

GLuint cubeVertexArrayObjectID;
GLuint sphereVertexArrayObjectID;
GLuint planeVertexArrayObjectID;
GLuint lineVertexArrayObjectID;

mat4 cubeTransform;
mat4 sphereTransform;
mat4 planeTransform;
mat4 lineTransform;

mat4 floorTransform;
mat4 wall1Transform;
mat4 wall2Transform;

mat4 column1Transform;
mat4 column2Transform;
mat4 column3Transform;
mat4 column4Transform;
mat4 column5Transform;
mat4 column6Transform;
mat4 column7Transform;
mat4 column8Transform;
mat4 column9Transform;
mat4 column10Transform;
mat4 column11Transform;
mat4 column12Transform;

GLuint theBufferID;
Camera camera;

void CoolGLWindow::initializeGL()
{
	setMouseTracking(true);
	srand((unsigned)time(NULL));
	glewInit();
	glEnable(GL_DEPTH_TEST);
	transformShapes();
	sendDataToHardware();
	compileShaders();
}
void CoolGLWindow::transformColumns()
{
	GLfloat columnHeightScale = 4.0f;
	GLfloat columnX = 5.0f;
	GLfloat columnZGap = 5.0f;
	mat4 columnScale = glm::scale(vec3(0.5f, columnHeightScale, 0.5f));
	mat4 columnRotation = glm::rotate(45.0f, vec3(0, 1, 0));

	column1Transform = glm::translate(mat4(), vec3(-columnX, columnHeightScale, 0.0f));
	column1Transform *= columnScale;
	column1Transform *= columnRotation;

	column2Transform = glm::translate(mat4(), vec3(columnX, columnHeightScale, 0.0f));
	column2Transform *= columnScale;
	column2Transform *= columnRotation;

	column3Transform = glm::translate(mat4(), vec3(-columnX, columnHeightScale, -columnZGap));
	column3Transform *= columnScale;
	column3Transform *= columnRotation;

	column4Transform = glm::translate(mat4(), vec3(columnX, columnHeightScale, -columnZGap));
	column4Transform *= columnScale;
	column4Transform *= columnRotation;

	column5Transform = glm::translate(mat4(), vec3(-columnX, columnHeightScale, -columnZGap*2));
	column5Transform *= columnScale;
	column5Transform *= columnRotation;

	column6Transform = glm::translate(mat4(), vec3(columnX, columnHeightScale, -columnZGap*2));
	column6Transform *= columnScale;
	column6Transform *= columnRotation;

	column7Transform = glm::translate(mat4(), vec3(-columnX, columnHeightScale, -columnZGap*3));
	column7Transform *= columnScale;
	column7Transform *= columnRotation;

	column8Transform = glm::translate(mat4(), vec3(columnX, columnHeightScale, -columnZGap*3));
	column8Transform *= columnScale;
	column8Transform *= columnRotation;

	column9Transform = glm::translate(mat4(), vec3(-columnX, columnHeightScale, -columnZGap*4));
	column9Transform *= columnScale;
	column9Transform *= columnRotation;

	column10Transform = glm::translate(mat4(), vec3(columnX, columnHeightScale, -columnZGap*4));
	column10Transform *= columnScale;
	column10Transform *= columnRotation;

	column11Transform = glm::translate(mat4(), vec3(-columnX, columnHeightScale, -columnZGap*5));
	column11Transform *= columnScale;
	column11Transform *= columnRotation;

	column12Transform = glm::translate(mat4(), vec3(columnX, columnHeightScale, -columnZGap*5));
	column12Transform *= columnScale;
	column12Transform *= columnRotation;
}
void CoolGLWindow::transformShapes()
{
	transformColumns();
	wall1Transform = glm::translate(mat4(), vec3(-10.0f,4.0f,-23.0f));
	wall1Transform *= glm::rotate(90.0f, vec3(0,0,1));
	wall1Transform *= glm::scale(vec3(4.0f, 0.0f, 25.0f));

	wall2Transform = glm::translate(mat4(), vec3(10.0f,4.0f,-23.0f));
	wall2Transform *= glm::rotate(90.0f, vec3(0,0,1));
	wall2Transform *= glm::scale(vec3(4.0f, 0.0f, 25.0f));

	floorTransform = glm::translate(mat4(), vec3(0.0f, 0.0f, -23.0f));
	floorTransform *= glm::scale(vec3(10.0f, 0.0f, 25.0f));
	//Cube, sphere, arrow, teapot, plane, torus, wireframe plane, lines, 
}

void CoolGLWindow::sendDataToHardware()
{
	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	Neumont::ShapeData sphereData = Neumont::ShapeGenerator::makeSphere(12);
	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(3);
	Neumont::ShapeData lineData = Neumont::ShapeGenerator::makeLine();

	glGenBuffers(1, &theBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	glBufferData(GL_ARRAY_BUFFER, 
		cubeData.vertexBufferSize() + cubeData.indexBufferSize()+
		sphereData.vertexBufferSize() + sphereData.indexBufferSize() +
		planeData.vertexBufferSize() + planeData.indexBufferSize() +
		lineData.vertexBufferSize() + lineData.indexBufferSize(), 0, GL_STATIC_DRAW);
	GLsizeiptr currentOffset = 0;
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cubeData.vertexBufferSize(),cubeData.verts);
	currentOffset += cubeData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cubeData.indexBufferSize(), cubeData.indices);
	currentOffset += cubeData.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, sphereData.vertexBufferSize(), sphereData.verts);
	currentOffset += sphereData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, sphereData.indexBufferSize(), sphereData.indices);
	currentOffset += sphereData.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, planeData.vertexBufferSize(), planeData.verts);
	currentOffset += planeData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, planeData.indexBufferSize(), planeData.indices);
	currentOffset += planeData.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, lineData.vertexBufferSize(), lineData.verts);
	currentOffset += lineData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset,lineData.indexBufferSize(), lineData.indices);
	currentOffset += lineData.indexBufferSize();

	cubeNumIndices = cubeData.numIndices;
	sphereNumIndices = sphereData.numIndices;
	planeNumIndices = planeData.numIndices;
	lineNumIndices = lineData.numIndices;

	glGenVertexArrays(1, &cubeVertexArrayObjectID);
	glGenVertexArrays(1, &sphereVertexArrayObjectID);
	glGenVertexArrays(1, &planeVertexArrayObjectID);
	glGenVertexArrays(1, &lineVertexArrayObjectID);

	glBindVertexArray(cubeVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)Neumont::Vertex::POSITION_OFFSET);
	glVertexAttribPointer(1,4,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)Neumont::Vertex::COLOR_OFFSET);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);
	
	glBindVertexArray(sphereVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint sphereByteOffset = cubeData.vertexBufferSize() + cubeData.indexBufferSize();
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(sphereByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1,4,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(sphereByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(planeVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint planeByteOffset = sphereByteOffset + sphereData.vertexBufferSize() + sphereData.indexBufferSize();
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(planeByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1,4,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(planeByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(lineVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint lineByteOffset = planeByteOffset + planeData.vertexBufferSize() + planeData.indexBufferSize();
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(lineByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1,4,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(lineByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	cubeIndexDataByteOffset = cubeData.vertexBufferSize();
	sphereIndexDataByteOffset = sphereByteOffset + sphereData.vertexBufferSize();
	planeIndexDataByteOffset = planeByteOffset + planeData.vertexBufferSize();
	lineIndexDataByteOffset = lineByteOffset + lineData.vertexBufferSize();

	/*cubeData.cleanUp();
	sphereData.cleanUp();*/

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);
}
void CoolGLWindow::myUpdate()
{
	if(GetAsyncKeyState(0x41)<0)//A
	{

	}
	if(GetAsyncKeyState(0x44)<0)//D
	{

	}
	if(GetAsyncKeyState(0x57)<0)//W
	{

	}
	if(GetAsyncKeyState(0x53)<0)//S
	{

	}
	if(GetAsyncKeyState(0x51)<0)//Q
	{

	}
	if(GetAsyncKeyState(0x45)<0)//E
	{

	}
	if(GetAsyncKeyState(0x52)<0)//R
	{

	}
	if(GetAsyncKeyState(0x46)<0)//F
	{

	}
	repaint();
}
void CoolGLWindow::mouseMoveEvent(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	repaint();
}
void CoolGLWindow::keyPressEvent(QKeyEvent* e)
{
	switch(e->key())
	{
	case Qt::Key::Key_W:
		camera.moveForward();
		break;
	case Qt::Key::Key_S:
		camera.moveBackward();
		break;
	case Qt::Key::Key_A:
		camera.strafeLeft();
		break;
	case Qt::Key::Key_D:
		camera.strafeRight();
		break;
	case Qt::Key::Key_R:
		camera.moveUp();
		break;
	case Qt::Key::Key_F:
		camera.moveDown();
		break;
	case Qt::Key::Key_Escape:
		close();
		break;
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

	GLint fullTransformMatrixLocation = glGetUniformLocation(programID, "fullTransformMatrix");
	mat4 fullTransformMatrix;

	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 50.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;
	
	fullTransformMatrix = worldToProjectionMatrix * floorTransform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * wall1Transform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * wall2Transform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

#pragma region Column_Draws
	fullTransformMatrix = worldToProjectionMatrix * column1Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column2Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column3Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column4Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column5Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column6Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column7Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column8Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column9Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column10Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column11Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * column12Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);
#pragma endregion 

	/*fullTransformMatrix = worldToProjectionMatrix * cubeTransform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * sphereTransform;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * planeTransform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * lineTransform;
	glBindVertexArray(lineVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, lineNumIndices, GL_UNSIGNED_SHORT, (void*)lineIndexDataByteOffset);*/
}
