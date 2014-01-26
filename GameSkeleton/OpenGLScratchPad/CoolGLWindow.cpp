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
GLuint torusNumIndices;
GLuint wirePlaneNumIndices;
GLuint arrowNumIndices;
GLuint teapotNumIndices;

GLuint cubeIndexDataByteOffset;
GLuint sphereIndexDataByteOffset;
GLuint planeIndexDataByteOffset;
GLuint lineIndexDataByteOffset;
GLuint torusIndexDataByteOffset;
GLuint wirePlaneIndexDataByteOffset;
GLuint arrowIndexDataByteOffset;
GLuint teapotIndexDataByteOffset;

GLuint cubeVertexArrayObjectID;
GLuint sphereVertexArrayObjectID;
GLuint planeVertexArrayObjectID;
GLuint lineVertexArrayObjectID;
GLuint torusVertexArrayObjectID;
GLuint wirePlaneVertexArrayObjectID;
GLuint arrowVertexArrayObjectID;
GLuint teapotVertexArrayObjectID;


mat4 cubeTransform;
mat4 sphereTransform;
mat4 planeTransform;
mat4 lineTransform;

mat4 floorTransform;
mat4 rugTransform;

mat4 wall1Transform;
mat4 wall2Transform;

mat4 wall3Transform;
mat4 wall4Transform;

mat4 window1Transform;
mat4 window2Transform;

mat4 ceilingTransform;

mat4 door1Transform;
mat4 door2Transform;

mat4 pedestal1Transform;
mat4 pedestal2Transform;
mat4 pedestal3Transform;
mat4 pedestal4Transform;
mat4 pedestal5Transform;
mat4 pedestal6Transform;
mat4 pedestal7Transform;
mat4 pedestal8Transform;

mat4 pedestalTopperTorusTransform;
mat4 pedestalTopperSphereTransform;
GLfloat pedestalTopperSphereAngleX=0;
GLfloat pedestalTopperSphereAngleZ=0;

mat4 pedestalTopperWireTransform;
GLfloat pedestalTopperWireAngleX;
GLfloat pedestalTopperWireAngleY;
GLfloat pedestalTopperWireAngleZ;

mat4 pedestalTopperWire2Transform;
GLfloat pedestalTopperWire2AngleX;
GLfloat pedestalTopperWire2AngleY;
GLfloat pedestalTopperWire2AngleZ;

mat4 pedestalTopperLine1Transform;	  
mat4 pedestalTopperLine2Transform;
mat4 pedestalTopperLine3Transform;	  
mat4 pedestalTopperLine4Transform;
mat4 pedestalTopperLine5Transform;	  
mat4 pedestalTopperLine6Transform;
mat4 pedestalTopperLine7Transform;	  
mat4 pedestalTopperLine8Transform;

mat4 pedestalTopperArrowTransform;
GLfloat pedestalTopperArrowAngleY = 0;
GLfloat pedestalTopperArrowPosY = 0;
GLboolean pedestalTopperArrowUp = true;

mat4 pedestalTopperAtomBase;
mat4 pedestalTopperAtomE1;
mat4 pedestalTopperAtomE2;
mat4 pedestalTopperAtomE3;
mat4 pedestalTopperAtomE4;
mat4 pedestalTopperAtomE5;
mat4 pedestalTopperAtomE6;
GLfloat pedestalTopperAtomE1Angle = 0;

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

mat4 smokeTransform;
GLfloat smokeScaleX = 0.125f;
GLfloat smokeScaleY = 0.125f;
GLfloat smokeScaleZ = 0.125f;
GLfloat smokePosY = 0;

mat4 potTransform;

GLuint frameCount=0;
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
	GLfloat columnZGap = 8.0f;
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
void CoolGLWindow::transformWalls()
{
	wall1Transform = glm::translate(mat4(), vec3(-10.0f,4.0f,-23.0f));
	wall1Transform *= glm::rotate(90.0f, vec3(0,0,1));
	wall1Transform *= glm::scale(vec3(4.0f, 1.0f, 25.0f));

	wall2Transform = glm::translate(mat4(), vec3(10.0f,4.0f,-23.0f));
	wall2Transform *= glm::rotate(-90.0f, vec3(0,0,1));
	wall2Transform *= glm::scale(vec3(4.0f, 1.0f, 25.0f));

	wall3Transform = glm::translate(mat4(), vec3(0.0f,4.0f,2.0f));
	wall3Transform *= glm::rotate(-90.0f, vec3(1,0,0));
	wall3Transform *= glm::scale(vec3(10.0f, 1.0f, 4.0f));

	wall4Transform = glm::translate(mat4(), vec3(0.0f,4.0f,-48.0f));
	wall4Transform *= glm::rotate(-90.0f, vec3(1,0,0));
	wall4Transform *= glm::scale(vec3(10.0f, 1.0f, 4.0f));

	window1Transform = glm::translate(mat4(), vec3(-9.99f,4.0f,-4.0f));
	window1Transform *= glm::rotate(-90.0f, vec3(0,0,1));
	window1Transform *= glm::scale(vec3(2, 1, 2));

	window2Transform = glm::translate(mat4(), vec3(9.99f,4.0f,-4.0f));
	window2Transform *= glm::rotate(-90.0f, vec3(0,0,1));
	window2Transform *= glm::scale(vec3(2, 1, 2));

	ceilingTransform = glm::translate(mat4(), vec3(0.0f, 8.0f, -23.0f));
	ceilingTransform *= glm::scale(vec3(10.0f, 0.0f, 25.0f));

	floorTransform = glm::translate(mat4(), vec3(0.0f, 0.0f, -23.0f));
	floorTransform *= glm::scale(vec3(10.0f, 1.0f, 25.0f));
}
void CoolGLWindow::transformShapes()
{
	transformColumns();
	transformWalls();
	continuousTransforms();

	pedestalTopperAtomBase = glm::translate(mat4(), vec3(7.5f,4.0f, -20.0f));
	pedestalTopperAtomBase *= glm::scale(vec3(0.25f, 0.25f, 0.25f));

	potTransform = glm::translate(mat4(), vec3(0, 2, -45));
	potTransform *= glm::rotate(-90.0f, vec3(1,0,0));

	rugTransform = glm::translate(mat4(), vec3(0.0f, 0.01f, -23.0f));
	rugTransform *= glm::scale(vec3(2.5f, 1.0f, 25.0f));

	door1Transform = glm::translate(mat4(), vec3(-1.25f, 2.0f, 2.0f));
	door1Transform *= glm::scale(vec3(1.25f, 2.0f, 0.25f));

	door2Transform = glm::translate(mat4(), vec3(1.25f, 2.0f, 2.0f));
	door2Transform *= glm::scale(vec3(1.25f, 2.0f, 0.25f));

	pedestal1Transform = glm::translate(mat4(), vec3(7.5f, 1.5f, -4.0f));
	pedestal1Transform *= glm::scale(vec3(0.5f, 1.5f, 0.5f));

	pedestal2Transform = glm::translate(mat4(), vec3(-7.5f, 1.5f, -4.0f));
	pedestal2Transform *= glm::scale(vec3(0.5f, 1.5f, 0.5f));

	pedestal3Transform = glm::translate(mat4(), vec3(7.5f, 1.5f, -12.0f));
	pedestal3Transform *= glm::scale(vec3(0.5f, 1.5f, 0.5f));

	pedestal4Transform = glm::translate(mat4(), vec3(-7.5f, 1.5f, -12.0f));
	pedestal4Transform *= glm::scale(vec3(0.5f, 1.5f, 0.5f));

	pedestal5Transform = glm::translate(mat4(), vec3(7.5f, 1.5f, -20.0f));
	pedestal5Transform *= glm::scale(vec3(0.5f, 1.5f, 0.5f));

	pedestal6Transform = glm::translate(mat4(), vec3(-7.5f, 1.5f, -20.0f));
	pedestal6Transform *= glm::scale(vec3(0.5f, 1.5f, 0.5f));

	pedestal7Transform = glm::translate(mat4(), vec3(7.5f, 1.5f, -28.0f));
	pedestal7Transform *= glm::scale(vec3(0.5f, 1.5f, 0.5f));

	pedestal8Transform = glm::translate(mat4(), vec3(-7.5f, 1.5f, -28.0f));
	pedestal8Transform *= glm::scale(vec3(0.5f, 1.5f, 0.5f));

	pedestalTopperTorusTransform = glm::translate(mat4(), vec3(-7.5f, 4.0f, -4.0f));
	pedestalTopperTorusTransform *= glm::rotate(90.0f, vec3(0, 0, 1.0f));
	pedestalTopperTorusTransform *= glm::scale(vec3(0.5f, 0.25f, 0.5f));

	//Cube, sphere, arrow, teapot, plane, torus, wireframe plane, lines, 
}

void CoolGLWindow::continuousTransforms()
{
	pedestalTopperAtomE1 = glm::translate(vec3(7.5f,4.0f, -20.0f));
	pedestalTopperAtomE1 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(1, 0, 0));
	pedestalTopperAtomE1 *= glm::translate(vec3(0,0.5f,0));
	pedestalTopperAtomE1 *= glm::scale(vec3(0.0625f, 0.0625f, 0.0625f));

	pedestalTopperAtomE2 = glm::translate(vec3(7.5f,4.0f, -20.0f));
	pedestalTopperAtomE2 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(0, 1, 0));
	pedestalTopperAtomE2 *= glm::translate(vec3(0,0,0.5f));
	pedestalTopperAtomE2 *= glm::scale(vec3(0.0625f, 0.0625f, 0.0625f));

	pedestalTopperAtomE3 = glm::translate(vec3(7.5f,4.0f, -20.0f));
	pedestalTopperAtomE3 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(0, 0, 1));
	pedestalTopperAtomE3 *= glm::translate(vec3(0.5f,0,0));
	pedestalTopperAtomE3 *= glm::scale(vec3(0.0625f, 0.0625f, 0.0625f));

	pedestalTopperAtomE4 = glm::translate(mat4(), vec3(-7.5f, 4.0f, -4.0f));
	pedestalTopperAtomE4 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(1, 0, 0));
	pedestalTopperAtomE4 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(0, 0, 1));
	pedestalTopperAtomE4 *= glm::translate(vec3(0,1,0));
	pedestalTopperAtomE4 *= glm::scale(vec3(0.0625f, 0.0625f, 0.0625f));

	pedestalTopperAtomE5 = glm::translate(mat4(), vec3(-7.5f, 4.0f, -4.0f));
	pedestalTopperAtomE5 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(0, 1, 0));
	pedestalTopperAtomE5 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(1, 0, 0));
	pedestalTopperAtomE5 *= glm::translate(vec3(0,0,1));
	pedestalTopperAtomE5 *= glm::scale(vec3(0.0625f, 0.0625f, 0.0625f));

	pedestalTopperAtomE6 = glm::translate(mat4(), vec3(-7.5f, 4.0f, -4.0f));
	pedestalTopperAtomE6 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(0, 0, 1));
	pedestalTopperAtomE6 *= glm::rotate(pedestalTopperAtomE1Angle, vec3(0, 1, 0));
	pedestalTopperAtomE6 *= glm::translate(vec3(1,0,0));
	pedestalTopperAtomE6 *= glm::scale(vec3(0.0625f, 0.0625f, 0.0625f));

	smokeTransform = glm::translate(mat4(), vec3(3, 4.48+smokePosY, -45));
	smokeTransform *= glm::scale(vec3(smokeScaleX, smokeScaleY, smokeScaleZ));

	pedestalTopperSphereTransform = glm::translate(mat4(), vec3(-7.5f, 4.0f, -4.0f));
	pedestalTopperSphereTransform *= glm::rotate(pedestalTopperSphereAngleX, vec3(1,0,0));
	pedestalTopperSphereTransform *= glm::rotate(pedestalTopperSphereAngleZ, vec3(0,0,1));
	pedestalTopperSphereTransform *= glm::scale(vec3(0.125f, 0.125f, 0.125f));

	pedestalTopperWireTransform = glm::translate(mat4(), vec3(7.5f, 4.0f, -4.0f));
	pedestalTopperWireTransform *= glm::rotate(pedestalTopperWireAngleX, vec3(1,0,0));
	pedestalTopperWireTransform *= glm::rotate(pedestalTopperWireAngleY, vec3(0,1,0));
	pedestalTopperWireTransform *= glm::rotate(pedestalTopperWireAngleZ, vec3(0,0,1));
	pedestalTopperWireTransform *= glm::scale(vec3(0.5f, 0.5f, 0.5f));

	pedestalTopperWire2Transform = glm::translate(mat4(), vec3(7.5f, 4.0f, -4.0f));
	pedestalTopperWire2Transform *= glm::rotate(pedestalTopperWire2AngleX, vec3(1,0,0));
	pedestalTopperWire2Transform *= glm::rotate(pedestalTopperWire2AngleY, vec3(0,1,0));
	pedestalTopperWire2Transform *= glm::rotate(pedestalTopperWire2AngleZ, vec3(0,0,1));
	pedestalTopperWire2Transform *= glm::scale(vec3(0.5f, 0.5f, 0.5f));

	pedestalTopperLine1Transform = glm::translate(mat4(), vec3(-7.5f, 4.0f, -12.0f));
	pedestalTopperLine1Transform *= glm::rotate(pedestalTopperWireAngleX, vec3(1,0,0));
	pedestalTopperLine1Transform *= glm::rotate(pedestalTopperWireAngleZ, vec3(0,0,1));
	pedestalTopperLine1Transform *= glm::rotate(pedestalTopperWireAngleY, vec3(0,1,0));
				  
	pedestalTopperLine2Transform = glm::translate(mat4(), vec3(-7.5f, 4.0f, -12.0f));
	pedestalTopperLine2Transform *= glm::rotate(pedestalTopperWire2AngleX, vec3(1,0,0));
	pedestalTopperLine2Transform *= glm::rotate(pedestalTopperWire2AngleZ, vec3(0,0,1));
	pedestalTopperLine2Transform *= glm::rotate(pedestalTopperWire2AngleY, vec3(0,1,0));
	
	pedestalTopperLine3Transform = glm::translate(mat4(), vec3(-7.5f, 4.0f, -12.0f));
	pedestalTopperLine3Transform *= glm::rotate(0.5f*pedestalTopperWireAngleX, vec3(1,0,0));
	pedestalTopperLine3Transform *= glm::rotate(pedestalTopperWireAngleZ, vec3(0,0,1));
	pedestalTopperLine3Transform *= glm::rotate(0.5f*pedestalTopperWireAngleY, vec3(0,1,0));
				  
	pedestalTopperLine4Transform = glm::translate(mat4(), vec3(-7.5f, 4.0f, -12.0f));
	pedestalTopperLine4Transform *= glm::rotate(pedestalTopperWire2AngleX, vec3(1,0,0));
	pedestalTopperLine4Transform *= glm::rotate(0.5f*pedestalTopperWire2AngleZ, vec3(0,0,1));
	pedestalTopperLine4Transform *= glm::rotate(pedestalTopperWire2AngleY, vec3(0,1,0));

	pedestalTopperLine5Transform = glm::translate(mat4(), vec3(-7.5f, 4.0f, -12.0f));
	pedestalTopperLine5Transform *= glm::rotate(1.5f*pedestalTopperWireAngleX, vec3(1,0,0));
	pedestalTopperLine5Transform *= glm::rotate(1.5f*pedestalTopperWireAngleZ, vec3(0,0,1));
	pedestalTopperLine5Transform *= glm::rotate(1.5f*pedestalTopperWireAngleY, vec3(0,1,0));
				  
	pedestalTopperLine6Transform = glm::translate(mat4(), vec3(-7.5f, 4.0f, -12.0f));
	pedestalTopperLine6Transform *= glm::rotate(0.5f*pedestalTopperWire2AngleX, vec3(1,0,0));
	pedestalTopperLine6Transform *= glm::rotate(0.5f*pedestalTopperWire2AngleZ, vec3(0,0,1));
	pedestalTopperLine6Transform *= glm::rotate(0.5f*pedestalTopperWire2AngleY, vec3(0,1,0));

	pedestalTopperArrowTransform = glm::translate(mat4(), vec3(7.5f, 4.0f+pedestalTopperArrowPosY, -12.0f));
	pedestalTopperArrowTransform *= glm::rotate(pedestalTopperArrowAngleY, vec3(0,1,0));
	pedestalTopperArrowTransform *= glm::scale(vec3(0.5f, 0.5f, 0.5f));


}

void CoolGLWindow::sendDataToHardware()
{
	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	Neumont::ShapeData sphereData = Neumont::ShapeGenerator::makeSphere(12);
	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(3);
	Neumont::ShapeData lineData = Neumont::ShapeGenerator::makeLine();
	Neumont::ShapeData torusData = Neumont::ShapeGenerator::makeTorus(12);
	Neumont::ShapeData wirePlaneData = Neumont::ShapeGenerator::makeWireframePlane(3);
	Neumont::ShapeData arrowData = Neumont::ShapeGenerator::makeArrow();
	Neumont::ShapeData teapotData = Neumont::ShapeGenerator::makeTeapot(6 , mat4());


	glGenBuffers(1, &theBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	glBufferData(GL_ARRAY_BUFFER, 
		cubeData.vertexBufferSize() + cubeData.indexBufferSize()+
		sphereData.vertexBufferSize() + sphereData.indexBufferSize() +
		planeData.vertexBufferSize() + planeData.indexBufferSize() +
		lineData.vertexBufferSize() + lineData.indexBufferSize() +
		torusData.vertexBufferSize() + torusData.indexBufferSize() +
		wirePlaneData.vertexBufferSize() + wirePlaneData.indexBufferSize() +
		arrowData.vertexBufferSize() + arrowData.indexBufferSize() +
		teapotData.vertexBufferSize() + teapotData.indexBufferSize(), 0, GL_STATIC_DRAW);
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
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, torusData.vertexBufferSize(), torusData.verts);
	currentOffset += torusData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset,torusData.indexBufferSize(), torusData.indices);
	currentOffset += torusData.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, wirePlaneData.vertexBufferSize(), wirePlaneData.verts);
	currentOffset += wirePlaneData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset,wirePlaneData.indexBufferSize(), wirePlaneData.indices);
	currentOffset += wirePlaneData.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, arrowData.vertexBufferSize(), arrowData.verts);
	currentOffset += arrowData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset,arrowData.indexBufferSize(), arrowData.indices);
	currentOffset += arrowData.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, teapotData.vertexBufferSize(), teapotData.verts);
	currentOffset += teapotData.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset,teapotData.indexBufferSize(), teapotData.indices);
	currentOffset += teapotData.indexBufferSize();

	cubeNumIndices = cubeData.numIndices;
	sphereNumIndices = sphereData.numIndices;
	planeNumIndices = planeData.numIndices;
	lineNumIndices = lineData.numIndices;
	torusNumIndices = torusData.numIndices;
	wirePlaneNumIndices = wirePlaneData.numIndices;
	arrowNumIndices = arrowData.numIndices;
	teapotNumIndices = teapotData.numIndices;

	glGenVertexArrays(1, &cubeVertexArrayObjectID);
	glGenVertexArrays(1, &sphereVertexArrayObjectID);
	glGenVertexArrays(1, &planeVertexArrayObjectID);
	glGenVertexArrays(1, &lineVertexArrayObjectID);
	glGenVertexArrays(1, &torusVertexArrayObjectID);
	glGenVertexArrays(1, &wirePlaneVertexArrayObjectID);
	glGenVertexArrays(1, &arrowVertexArrayObjectID);
	glGenVertexArrays(1, &teapotVertexArrayObjectID);

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

	glBindVertexArray(torusVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint torusByteOffset = lineByteOffset + lineData.vertexBufferSize() + lineData.indexBufferSize();
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(torusByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1,4,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(torusByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(wirePlaneVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint wirePlaneByteOffset = torusByteOffset + torusData.vertexBufferSize() + torusData.indexBufferSize();
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(wirePlaneByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1,4,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(wirePlaneByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(arrowVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint arrowByteOffset = wirePlaneByteOffset + wirePlaneData.vertexBufferSize() + wirePlaneData.indexBufferSize();
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(arrowByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1,4,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(arrowByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(teapotVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint teapotByteOffset = arrowByteOffset + arrowData.vertexBufferSize() + arrowData.indexBufferSize();
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(teapotByteOffset + Neumont::Vertex::POSITION_OFFSET));
	glVertexAttribPointer(1,4,GL_FLOAT, GL_FALSE, Neumont::Vertex::STRIDE, (void*)(teapotByteOffset + Neumont::Vertex::COLOR_OFFSET));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	cubeIndexDataByteOffset = cubeData.vertexBufferSize();
	sphereIndexDataByteOffset = sphereByteOffset + sphereData.vertexBufferSize();
	planeIndexDataByteOffset = planeByteOffset + planeData.vertexBufferSize();
	lineIndexDataByteOffset = lineByteOffset + lineData.vertexBufferSize();
	torusIndexDataByteOffset = torusByteOffset + torusData.vertexBufferSize();
	wirePlaneIndexDataByteOffset = wirePlaneByteOffset + wirePlaneData.vertexBufferSize();
	arrowIndexDataByteOffset = arrowByteOffset + arrowData.vertexBufferSize();
	teapotIndexDataByteOffset = teapotByteOffset + teapotData.vertexBufferSize();

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

	pedestalTopperAtomE1Angle += 5.0f;

	pedestalTopperSphereAngleX+=5;
	pedestalTopperSphereAngleZ+=5;

	pedestalTopperWireAngleX+=5;
	pedestalTopperWireAngleZ+=5;
	pedestalTopperWireAngleZ+=5;

	pedestalTopperWire2AngleX-=2;
	pedestalTopperWire2AngleZ-=2;
	pedestalTopperWire2AngleZ-=2;

	pedestalTopperArrowAngleY += 5.0f;
	pedestalTopperArrowPosY += (pedestalTopperArrowUp)? 0.01 : -0.01;
	if(frameCount % 50 ==0)
		pedestalTopperArrowUp = !pedestalTopperArrowUp;

	smokePosY+= 0.04f;
	smokeScaleX +=0.005f;
	smokeScaleY +=0.005f;
	smokeScaleZ +=0.005f;

	if(frameCount % 100 ==0)
	{
		smokeScaleX = 0.125f;
		smokeScaleY = 0.125f;
		smokeScaleZ = 0.125f;
		smokePosY = 0;
	}

	continuousTransforms();
	frameCount++;
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

	vec3 newColor = vec3(0, 0, 0);
	GLint newColorLocation = glGetUniformLocation(programID, "newColor");
	glUniform3fv(newColorLocation, 1, &newColor[0]);

	GLint fullTransformMatrixLocation = glGetUniformLocation(programID, "fullTransformMatrix");
	mat4 fullTransformMatrix;

	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 50.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;
	
	fullTransformMatrix = worldToProjectionMatrix * floorTransform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * rugTransform;
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

	fullTransformMatrix = worldToProjectionMatrix * wall3Transform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * wall4Transform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * ceilingTransform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * door1Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * door2Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestal1Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestal2Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestal3Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestal4Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestal5Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestal6Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestal7Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestal8Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperTorusTransform;
	glBindVertexArray(torusVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, torusNumIndices, GL_UNSIGNED_SHORT, (void*)torusIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperSphereTransform;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperWireTransform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperWire2Transform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperArrowTransform;
	glBindVertexArray(arrowVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, arrowNumIndices, GL_UNSIGNED_SHORT, (void*)arrowIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperLine1Transform;
	glBindVertexArray(lineVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, lineNumIndices, GL_UNSIGNED_SHORT, (void*)lineIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperLine2Transform;
	glBindVertexArray(lineVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, lineNumIndices, GL_UNSIGNED_SHORT, (void*)lineIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperLine3Transform;
	glBindVertexArray(lineVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, lineNumIndices, GL_UNSIGNED_SHORT, (void*)lineIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperLine4Transform;
	glBindVertexArray(lineVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, lineNumIndices, GL_UNSIGNED_SHORT, (void*)lineIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperLine5Transform;
	glBindVertexArray(lineVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, lineNumIndices, GL_UNSIGNED_SHORT, (void*)lineIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperLine6Transform;
	glBindVertexArray(lineVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, lineNumIndices, GL_UNSIGNED_SHORT, (void*)lineIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * window1Transform;
	glBindVertexArray(wirePlaneVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, wirePlaneNumIndices, GL_UNSIGNED_SHORT, (void*)wirePlaneIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * window2Transform;
	glBindVertexArray(wirePlaneVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, wirePlaneNumIndices, GL_UNSIGNED_SHORT, (void*)wirePlaneIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * smokeTransform;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperAtomBase;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperAtomE1;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperAtomE2;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperAtomE3;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperAtomE4;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperAtomE5;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperAtomE6;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

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

	newColor = vec3(-0.5f, -0.8f, -0.5f);
	glUniform3fv(newColorLocation, 1, &newColor[0]);

	fullTransformMatrix = worldToProjectionMatrix * potTransform;
	glBindVertexArray(teapotVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, teapotNumIndices, GL_UNSIGNED_SHORT, (void*)teapotIndexDataByteOffset);

	/*fullTransformMatrix = worldToProjectionMatrix * cubeTransform;
	glBindVertexArray(cubeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * sphereTransform;
	glBindVertexArray(sphereVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * pedestalTopperWireTransform;
	glBindVertexArray(wirePlaneVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, wirePlaneNumIndices, GL_UNSIGNED_SHORT, (void*)wirePlaneIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * planeTransform;
	glBindVertexArray(planeVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexDataByteOffset);

	fullTransformMatrix = worldToProjectionMatrix * lineTransform;
	glBindVertexArray(lineVertexArrayObjectID);
	glUniformMatrix4fv(fullTransformMatrixLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_LINES, lineNumIndices, GL_UNSIGNED_SHORT, (void*)lineIndexDataByteOffset);*/
}
