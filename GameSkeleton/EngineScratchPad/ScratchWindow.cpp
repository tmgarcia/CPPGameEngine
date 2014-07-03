#include "ScratchWindow.h"
#include "GameObjects\GameLevel.h"
#include "DebugMenu\DebugMenu.h"
#include <iostream>

using std::cout;
using std::endl;

vec3 cube1Position;
vec3 sphere1Position;

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

ShaderInfo* passThroughShader;

GeometryInfo* cube;
GeometryInfo* sphere;

mat4 cube1ModelToWorld;
mat4 cube1FullTransform;
mat4 sphere1ModelToWorld;
mat4 sphere1FullTransform;

RenderableInfo* cube1;
RenderableInfo* sphere1;

void ScratchWindow::setup()
{
	camera.setPosition(vec3(0,5,7));
	camera.setViewDirection(vec3(0,-0.5f,-1));
	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	cube = GeneralGLWindow::getInstance().addGeometry(cubeData.verts, cubeData.vertexBufferSize(), cubeData.indices, cubeData.numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	Neumont::ShapeData sphereData = Neumont::ShapeGenerator::makeSphere(12);
	sphere = GeneralGLWindow::getInstance().addGeometry(sphereData.verts, sphereData.vertexBufferSize(), sphereData.indices, sphereData.numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(sphere, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(sphere, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);

	DebugShapes::getInstance();
	DebugShapes::getInstance().addGrid(vec3(0,0,0),11,11,true,100000);
	DebugShapes::getInstance().addPoint(vec3(0,0.01f,0),true,100000);


	passThroughShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl");

	cube1Position = vec3(cubePosX,0,cubePosZ);
	cube1ModelToWorld = glm::translate(cube1Position);
	sphere1Position = vec3(spherePosX,0,spherePosZ);
	sphere1ModelToWorld = glm::translate(sphere1Position);

	cube1 = GeneralGLWindow::getInstance().addRenderable(cube, cube1ModelToWorld, passThroughShader, true, PRIORITY_1, true);
	sphere1 = GeneralGLWindow::getInstance().addRenderable(sphere, sphere1ModelToWorld, passThroughShader, true, PRIORITY_1, true);
	dMenu->addCheckBox("CubeTab",&(cube1->visible),"Cube Visible");
	dMenu->addCheckBox("SphereTab",&(sphere1->visible),"Sphere Visible");

	cube1FullTransform = worldToProjectionMatrix * cube1ModelToWorld;
	sphere1FullTransform = worldToProjectionMatrix * sphere1ModelToWorld;

	GeneralGLWindow::getInstance().addRenderableUniformParameter(cube1, "fullTransformMatrix", PT_MAT4, &cube1FullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(sphere1, "fullTransformMatrix", PT_MAT4, &sphere1FullTransform[0][0]);
}

int frame = 0;
void ScratchWindow::update()
{
	updateShaderInfo();
	frame++;
}

void ScratchWindow::updateShaderInfo()
{
	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	cube1Position = vec3(cubePosX,0,cubePosZ);
	cube1ModelToWorld = glm::translate(cube1Position);
	cube1FullTransform = worldToProjectionMatrix * cube1ModelToWorld;

	sphere1Position = vec3(spherePosX,0,spherePosZ);
	sphere1ModelToWorld = glm::translate(sphere1Position);
	sphere1FullTransform = worldToProjectionMatrix * sphere1ModelToWorld;

	GeneralGLWindow::getInstance().repaint();
}

void ScratchWindow::keyPressEvent(QKeyEvent *event)
{
	keyPressReaction(event);
}
void ScratchWindow::keyPressReaction(QKeyEvent* e)
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
	}
	update();
}

void ScratchWindow::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	//updateShaderUniforms();
	update();
	//GeneralGLWindow::getInstance().repaint();
}