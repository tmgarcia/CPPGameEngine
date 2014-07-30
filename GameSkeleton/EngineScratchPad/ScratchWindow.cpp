#include "ScratchWindow.h"
#include "GameObjects\GameLevel.h"
#include "DebugMenu\DebugMenu.h"
#include "GameObjects\GameObject.h"
#include "DebugMenu\TrackingFloat.h"
#include <iostream>

using std::cout;
using std::endl;

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

uint DIMENSIONS = 256;

PassInfo* pass1;
PassInfo* pass2;
void ScratchWindow::setup()
{
	camera.setPosition(vec3(0,0,10));
	camera.setViewDirection(vec3(0,0,-1));

	renderHelper = new RendererHelper();

	renderHelper->lightPosition = vec3(0.0f,5.0f,0.0f);
	renderHelper->diffusionIntensity = 0.5f;
	renderHelper->specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	renderHelper->specularExponent = 10;
	renderHelper->overridingObjectColor = vec3(0.9f,0.9f,0.9f);
	renderHelper->ambientLight = vec3(0.4f, 0.4f, 0.4f);
	renderHelper->eyePosition;

	pass1 = GeneralGLWindow::getInstance().addPass(false,false);
	GeneralGLWindow::getInstance().storePassColorTexture(pass1,DIMENSIONS,DIMENSIONS);
	GeneralGLWindow::getInstance().storePassDepthTexture(pass1,DIMENSIONS,DIMENSIONS);
	pass2 = GeneralGLWindow::getInstance().addPass(false,false);

	setupGeometry();
	setupTransforms();
	setupTextures();
	setupRenderables();
	GeneralGLWindow::getInstance().setupFrameBuffer(pass1);
	GeneralGLWindow::getInstance().setupFrameBuffer(pass2);
}

void ScratchWindow::setupGeometry()
{
	renderHelper->addNUGeo(RendererHelper::NUShapes::NU_TEAPOT, "NUCube");
	renderHelper->addGeoFromBin("../Resources/Models/plane.bin","plane");

}
GameObject* colorPlane;
GameObject* depthPlane;
void ScratchWindow::setupTransforms()
{
	renderHelper->eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	renderHelper->addGameObject(vec3(0,0,0),vec3(1,1,1),0,45,0,worldToProjectionMatrix,"Cube");
	colorPlane = renderHelper->addGameObject(vec3(0.2f,0.7f,-0.9999f),vec3(0.25f,1,0.25f),90,0,0,worldToProjectionMatrix,"ColorPlane", false);
	depthPlane = renderHelper->addGameObject(vec3(0.7f,0.7f,-0.9999f),vec3(0.25f,1,0.25f),90,0,0,worldToProjectionMatrix,"DepthPlane", false);
}

void ScratchWindow::setupTextures()
{
	renderHelper->addShader("../Resources/Shaders/LightingTextureAlphaNormalVertexShader.glsl", "../Resources/Shaders/LightingTextureAlphaNormalFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "textureLightingShader");
	renderHelper->addShader("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl",RendererHelper::ShaderType::SHADER_PASSTHROUGH, "passThroughShader");
	renderHelper->addShader("../Resources/Shaders/JustTextureVertexShader.glsl", "../Resources/Shaders/JustTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_TEXTURE, "textureShader");
	renderHelper->addShader("../Resources/Shaders/DepthTextureVertexShader.glsl", "../Resources/Shaders/DepthTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_TEXTURE, "deptTextureShader");

	renderHelper->addTexture(pass1->colorTexture, "pass1Color");
	renderHelper->addTexture(pass1->depthTexture, "pass1Depth");
	renderHelper->addTexture("../Resources/Textures/lava1Texture.bmp","lavaText");
}

void ScratchWindow::setupRenderables()
{
	GeneralGLWindow::getInstance().setCurrentPass(pass1);
	renderHelper->setupGameObjectRenderable("Cube","NUCube","textureLightingShader",true,PRIORITY_1,true,"","","","");

	GeneralGLWindow::getInstance().setCurrentPass(pass2);
	renderHelper->setupGameObjectRenderable("ColorPlane","plane","textureShader",true,PRIORITY_1,true,"pass1Color","","","");
	renderHelper->setupGameObjectRenderable("DepthPlane","plane","deptTextureShader",true,PRIORITY_1,true,"pass1Depth","","","");
}

int frame = 0;
void ScratchWindow::update()
{
	updateShaderInfo();
	frame++;
	//renderHelper->lightPosition = renderHelper->getGameObject("lightBulb")->position;
}

void ScratchWindow::updateShaderInfo()
{
	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, 1.0f, 0.1f, 90.0f);
	//viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	renderHelper->updateShaderInfo(worldToProjectionMatrix);
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