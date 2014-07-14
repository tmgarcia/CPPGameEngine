#include "ScratchWindow.h"
#include "GameObjects\GameLevel.h"
#include "DebugMenu\DebugMenu.h"
#include "GameObject.h"
#include "DebugMenu\TrackingFloat.h"
#include <iostream>

using std::cout;
using std::endl;

vec3 lightPosition = vec3(1.2f,6.2f,16.5f);
float diffusionIntensity = 0.5f;
vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
float specularExponent = 10;
vec3 overridingObjectColor = vec3(0.9f,0.9f,0.9f);
vec3 ambientLight = vec3(0.4f, 0.4f, 0.4f);
vec3 eyePosition;

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

ShaderInfo* mapsAndLightingShader;
ShaderInfo* passThroughShader;

GeometryInfo* cube;
GeometryInfo* nucube;

mat4 cubeModelToWorld;
mat4 cubeRotation;
mat4 cubeFullTransform;

mat4 lightBulbModelToWorld;
mat4 lightBulbFullTransform;

GameObject* normalMapCube;
GameObject* lightBulb;

NormalMapInfo* testNormal;

void ScratchWindow::makeCube()
{
	//NXT
	//X-U-T
	//Y-V-B
	Neumont::Vertex stackVerts[]=
	{
		// Top
		vec3(-1.0f, +1.0f, +1.0f), // 0
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent //was Coor
		vec3(+0.0f, +1.0f, +0.0f), // Normal
		vec2(+0.0f, +1.0f), // UV
		vec3(+1.0f, +1.0f, +1.0f), // 1
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +1.0f, +0.0f), // Normal
		vec2(+1.0f, +1.0f), // UV
		vec3(+1.0f, +1.0f, -1.0f), // 2
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +1.0f, +0.0f), // Normal
		vec2(+1.0f, +0.0f), // UV
		vec3(-1.0f, +1.0f, -1.0f), // 3
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +1.0f, +0.0f), // Normal
		vec2(+0.0f, +0.0f), // UV

		// Front
		vec3(-1.0f, +1.0f, -1.0f), // 4
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +0.0f, -1.0f), // Normal -z,-x, +y
		vec2(+0.0f, +1.0f), // UV
		vec3(+1.0f, +1.0f, -1.0f), // 5
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +0.0f, -1.0f), // Normal
		vec2(+1.0f, +1.0f), // UV
		vec3(+1.0f, -1.0f, -1.0f), // 6
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +0.0f, -1.0f), // Normal
		vec2(+1.0f, +0.0f), // UV
		vec3(-1.0f, -1.0f, -1.0f), // 7
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +0.0f, -1.0f), // Normal
		vec2(+0.0f, +0.0f), // UV

		// Right
		vec3(+1.0f, +1.0f, -1.0f), // 8
		vec4(+0.0f, +0.0f, -1.0f, -1.0f), // Tangent
		vec3(+1.0f, +0.0f, +0.0f), // Normal +x,+z,+y
		vec2(+1.0f, +0.0f), // UV
		vec3(+1.0f, +1.0f, +1.0f), // 9
		vec4(+0.0f, +0.0f, -1.0f, -1.0f), // Tangent
		vec3(+1.0f, +0.0f, +0.0f), // Normal
		vec2(+0.0f, +0.0f), // UV
		vec3(+1.0f, -1.0f, +1.0f), // 10
		vec4(+0.0f, +0.0f, -1.0f, -1.0f), // Tangent
		vec3(+1.0f, +0.0f, +0.0f), // Normal
		vec2(+0.0f, +1.0f), // UV
		vec3(+1.0f, -1.0f, -1.0f), // 11
		vec4(+0.0f, +0.0f, -1.0f, -1.0f), // Tangent
		vec3(+1.0f, +0.0f, +0.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		// Left
		vec3(-1.0f, +1.0f, +1.0f), // 12
		vec4(+0.0f, +0.0f, +1.0f, -1.0f), // Tangent
		vec3(-1.0f, +0.0f, +0.0f), // Normal -x -z +y
		vec2(+1.0f, +0.0f), // UV
		vec3(-1.0f, +1.0f, -1.0f), // 13
		vec4(+0.0f, +0.0f, +1.0f, -1.0f), // Tangent
		vec3(-1.0f, +0.0f, +0.0f), // Normal
		vec2(+0.0f, +0.0f), // UV
		vec3(-1.0f, -1.0f, -1.0f), // 14
		vec4(+0.0f, +0.0f, +1.0f, -1.0f), // Tangent
		vec3(-1.0f, +0.0f, +0.0f), // Normal
		vec2(+0.0f, +1.0f), // UV
		vec3(-1.0f, -1.0f, +1.0f), // 15
		vec4(+0.0f, +0.0f, +1.0f, -1.0f), // Tangent
		vec3(-1.0f, +0.0f, +0.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		// Back
		vec3(+1.0f, +1.0f, +1.0f), // 16
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +0.0f, +1.0f), // Normal +z +x +y
		vec2(+1.0f, +0.0f), // UV
		vec3(-1.0f, +1.0f, +1.0f), // 17
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +0.0f, +1.0f), // Normal
		vec2(+0.0f, +0.0f), // UV
		vec3(-1.0f, -1.0f, +1.0f), // 18
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +0.0f, +1.0f), // Normal
		vec2(+0.0f, +1.0f), // UV
		vec3(+1.0f, -1.0f, +1.0f), // 19
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, +0.0f, +1.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		// Bottom
		vec3(+1.0f, -1.0f, -1.0f), // 20
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, -1.0f, +0.0f), // Normal -y +x +z
		vec2(+1.0f, +1.0f), // UV
		vec3(-1.0f, -1.0f, -1.0f), // 21
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, -1.0f, +0.0f), // Normal
		vec2(+0.0f, +1.0f), // UV
		vec3(-1.0f, -1.0f, +1.0f), // 22
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, -1.0f, +0.0f), // Normal
		vec2(+0.0f, +0.0f), // UV
		vec3(+1.0f, -1.0f, +1.0f), // 23
		vec4(+1.0f, +0.0f, +0.0f, -1.0f), // Tangent
		vec3(+0.0f, -1.0f, +0.0f), // Normal
		vec2(+1.0f, +0.0f), // UV
	};
	unsigned short stackIndices[] = {
		0, 1, 2, 0, 2, 3, // Top
		4, 5, 6, 4, 6, 7, // Front
		8, 9, 10, 8, 10, 11, // Right
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom
	};

	GLuint numVerts = 24;
	GLuint vertexBufferSize = numVerts*sizeof(Neumont::Vertex);
	GLuint numIndices = 36;

	GLuint positionOffset = 0;
	GLuint tangentOffset = sizeof(vec3);//where color used to be
	GLuint normalOffset = tangentOffset + sizeof(vec4);
	GLuint uvOffset = normalOffset + sizeof(vec3);
	GLuint stride = 12*sizeof(float);

	cube = GeneralGLWindow::getInstance().addGeometry(stackVerts, vertexBufferSize, stackIndices, numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 0, PT_VEC3, positionOffset, stride);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 1, PT_VEC4, tangentOffset, stride);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 2, PT_VEC3, normalOffset, stride);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 3, PT_VEC2, uvOffset, stride);
}

void ScratchWindow::setup()
{
	camera.setPosition(vec3(0,5,7));
	camera.setViewDirection(vec3(0,-0.5f,-1));
	makeCube();
	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	nucube = GeneralGLWindow::getInstance().addGeometry(cubeData.verts, cubeData.vertexBufferSize(), cubeData.indices, cubeData.numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(nucube, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(nucube, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(nucube, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(nucube, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);

	eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	testNormal = GeneralGLWindow::getInstance().addNormalMap("../Resources/NormalMaps/Shapes.png");

	normalMapCube = new GameObject();
	normalMapCube->setupTransforms(vec3(0,2,0),vec3(0.5f,0.5f,0.5f),0,0,0,worldToProjectionMatrix);
	lightBulb = new GameObject();
	lightBulb->setupTransforms(vec3(0,3,0),vec3(0.25f,0.25f,0.25f),0,0,0,worldToProjectionMatrix);

	mapsAndLightingShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/LightingTextureAlphaNormalVertexShader.glsl", "../Resources/Shaders/LightingTextureAlphaNormalFragmentShader.glsl");
	passThroughShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl");
	
	QList<TrackingFloat*> floats;
	TrackingFloat* f1 = new TrackingFloat(&normalMapCube->xRotationAngle, 0, 360, "X Angle");
	TrackingFloat* f2 = new TrackingFloat(&normalMapCube->yRotationAngle, 0, 360, "Y Angle");
	TrackingFloat* f3 = new TrackingFloat(&normalMapCube->zRotationAngle, 0, 360, "Z Angle");
	floats.append(f1);
	floats.append(f2);
	floats.append(f3);
	dMenu->addMultipleFloatSlider("Cube controls", floats, "Rotation");
	dMenu->addVec3Slider("Cube controls", &normalMapCube->position,-5,5,-5,5,-5,5,"Position");
	dMenu->addVec3Slider("Light Controls", &lightBulb->position, -5,5,-5,5,-5,5,"Light");
	dMenu->addFloatSlider("Light Controls", &diffusionIntensity, 0,5,"Diffusion Intensity");
	dMenu->addFloatSlider("Light Controls", &specularExponent, 0.1,100,"Specular Exponent");
	dMenu->addVec3Slider("Light Controls", &ambientLight, 0,1,0,1,0,1,"Ambient Light");

	lightBulb->renderable = GeneralGLWindow::getInstance().addRenderable(nucube, lightBulb->modelToWorldMatrix, passThroughShader, true, PRIORITY_1, true, NULL, NULL, NULL);
	addLightingAndTextureShaderUniforms(lightBulb->renderable, &lightBulb->fullTransformMatrix[0][0], &lightBulb->rotationMatrix[0][0]);

	normalMapCube->renderable = GeneralGLWindow::getInstance().addRenderable(cube, normalMapCube->modelToWorldMatrix, mapsAndLightingShader, true, PRIORITY_1, true, NULL, NULL, testNormal);
	addLightingAndTextureShaderUniforms(normalMapCube->renderable, &normalMapCube->fullTransformMatrix[0][0], &normalMapCube->rotationMatrix[0][0]);
}

void ScratchWindow::addLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &diffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &specularColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &specularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &overridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &ambientLight[0]);

	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, rotationMatrix);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}

int frame = 0;
void ScratchWindow::update()
{
	updateShaderInfo();
	frame++;
	lightPosition = lightBulb->position;
}

void ScratchWindow::updateShaderInfo()
{
	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	lightBulb->updateTransforms(worldToProjectionMatrix);
	normalMapCube->updateTransforms(worldToProjectionMatrix);
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
	case Qt::Key::Key_0:
		cameraFrozen = !cameraFrozen;
		break;
	}
	update();
}

void ScratchWindow::mouseMoveReaction(QMouseEvent* e)
{
	if(!cameraFrozen)
	{
		camera.mouseUpdate(glm::vec2(e->x(), e->y()));
		update();
	}
}