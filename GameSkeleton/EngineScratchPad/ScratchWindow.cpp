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

mat4 lightWorldToProjectionMatrix;
vec3 lightPosition = vec3(-3.0f,4.5f,0.5f);
vec3 lightView = vec3(1,-1,0);

vec3 camOPos = vec3(0,0,10);
//vec3 camOPos = lightPosition;
vec3 camOV = vec3(0,0,-1);
//vec3 camOV = lightView;

uint DIMENSIONS = 512;

PassInfo* pass1;
PassInfo* pass2;

bool controllingLight = false;

void ScratchWindow::setup()
{
	cout << "setup" << endl;
	camera.setPosition(camOPos);
	camera.setViewDirection(camOV);

	renderHelper = new RendererHelper();

	renderHelper->lightPosition = vec3(0.0f,5.0f,0.0f);
	renderHelper->diffusionIntensity = 0.9f;
	renderHelper->specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	renderHelper->specularExponent = 10;
	renderHelper->overridingObjectColor = vec3(0.5f,0.5f,0.5f);
	renderHelper->ambientLight = vec3(0.2f, 0.2f, 0.2f);
	renderHelper->eyePosition;

	vec3 cameraPosition = camera.getPosition();
	vec3 cameraView = camera.viewDirection;

	camera.setPosition(lightPosition);
	camera.setViewDirection(lightView);
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	lightWorldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	camera.setPosition(cameraPosition);
	camera.setViewDirection(cameraView);

	GeneralGLWindow::getInstance().WINDOW_HEIGHT = WINDOW_HEIGHT;
	GeneralGLWindow::getInstance().WINDOW_WIDTH = WINDOW_WIDTH;
	pass1 = GeneralGLWindow::getInstance().addPass(false,false);
	GeneralGLWindow::getInstance().storePassDepthTexture(pass1,DIMENSIONS,DIMENSIONS);
	GeneralGLWindow::getInstance().addPassUniformParameter(pass1, "worldToProjectionMatrix", PT_MAT4, &lightWorldToProjectionMatrix[0][0]);
	pass1->uniformParametersOverrideBufferDraw = true;
	pass2 = GeneralGLWindow::getInstance().addPass(false,false);

	setupGeometry();
	setupTextures();
	setupGameObjects();
	GeneralGLWindow::getInstance().setupFrameBuffer(pass1);
	GeneralGLWindow::getInstance().setupFrameBuffer(pass2);

	//dMenu->addVec3Slider("tab", &lightPosition, -10,10,-10,10,-10,10,"pos");
	//dMenu->addVec3Slider("tab", &lightView, -10,10,-10,10,-10,10,"pos");

	dMenu->addCheckBox("tab", &controllingLight, "Control Light");
}

void ScratchWindow::setupGeometry()
{
	cout << "setup geometry" << endl;

	renderHelper->addNUGeo(RendererHelper::NUShapes::NU_SPHERE, "NUCube");
	renderHelper->addGeoFromBin("../Resources/Models/plane.bin","plane");

}
GameObject* colorPlane;
GameObject* depthPlane;
TextureInfo* depthText;
void ScratchWindow::setupGameObjects()
{
	vec3 cameraPosition = camera.getPosition();
	vec3 cameraView = camera.viewDirection;

	camera.setPosition(lightPosition);
	camera.setViewDirection(lightView);
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	lightWorldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	camera.setPosition(cameraPosition);
	camera.setViewDirection(cameraView);

	renderHelper->eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;


	renderHelper->addGameObject(vec3(0,0,0),vec3(0.25f,0.25f,0.25f),-90,0,0,worldToProjectionMatrix,"Cube");
	renderHelper->addGameObject(vec3(0,-0.5,0),vec3(1.25f,1.25f,1.25f),0,00,0,worldToProjectionMatrix,"Plane");
	GeneralGLWindow::getInstance().setCurrentPass(pass1);

	GameObject* cube = renderHelper->setupGameObjectRenderable("Cube","NUCube","shadowShader",true,PRIORITY_1,true,"","","","","");
	cube->renderable->shadowMap = pass1->depthTexture;
	cube->renderable->usingShadowMap = true;
	GeneralGLWindow::getInstance().addRenderableUniformParameter(cube->renderable, "worldToLightProjectionMatrix", PT_MAT4, &lightWorldToProjectionMatrix[0][0]);

	GameObject* plane = renderHelper->setupGameObjectRenderable("Plane","plane","shadowShader",true,PRIORITY_1,true,"","","","","");
	plane->renderable->shadowMap = pass1->depthTexture;
	plane->renderable->usingShadowMap = true;
	GeneralGLWindow::getInstance().addRenderableUniformParameter(plane->renderable, "worldToLightProjectionMatrix", PT_MAT4, &lightWorldToProjectionMatrix[0][0]);


	//colorPlane = renderHelper->addGameObject(vec3(0.2f,0.7f,-0.9999f),vec3(0.25f,1,0.25f),90,0,0,worldToProjectionMatrix,"ColorPlane", false);
	depthPlane = renderHelper->addGameObject(vec3(0.7f,0.7f,-0.9999f),vec3(0.25f,1,0.25f),90,0,0,worldToProjectionMatrix,"DepthPlane", false);
	GeneralGLWindow::getInstance().setCurrentPass(pass2);
	//renderHelper->setupGameObjectRenderable("ColorPlane","plane","textureShader",true,PRIORITY_1,true,"pass1Color","","","","");
	GameObject* dc= renderHelper->setupGameObjectRenderable("DepthPlane","plane","deptTextureShader",true,PRIORITY_1,true,"pass1Depth","","","","");
	dc->renderable->usingShadowMap = false;
}


void ScratchWindow::setupTextures()
{
	renderHelper->addShader("../Resources/Shaders/LightingAndTextureMapsVertexShader.glsl", "../Resources/Shaders/LightingAndTextureMapsFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "textureLightingShader");
	renderHelper->addShader("../Resources/Shaders/LightingTextureShadowVertexShader.glsl", "../Resources/Shaders/LightingTextureShadowFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "shadowShader");
	renderHelper->addShader("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl",RendererHelper::ShaderType::SHADER_PASSTHROUGH, "passThroughShader");
	renderHelper->addShader("../Resources/Shaders/JustTextureVertexShader.glsl", "../Resources/Shaders/JustTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_TEXTURE, "textureShader");
	renderHelper->addShader("../Resources/Shaders/DepthTextureVertexShader.glsl", "../Resources/Shaders/DepthTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_TEXTURE, "deptTextureShader");

	renderHelper->addTexture(pass1->colorTexture, "pass1Color");
	renderHelper->addTexture(pass1->depthTexture, "pass1Depth");
	renderHelper->addTexture("../Resources/Textures/lava1Texture.bmp","lavaText");
}

bool lastControlState = controllingLight;
int frame = 0;
vec3 lastCameraPos;
vec3 lastCameraView;
void ScratchWindow::update()
{
	updateShaderInfo();
	frame++;

	if(controllingLight)
	{
		if(lastControlState != controllingLight)
		{
			lastCameraPos = camera.getPosition();
			lastCameraView = camera.viewDirection;

			camera.setPosition(lightPosition);
			camera.setViewDirection(lightView);
		}
		lightPosition = camera.getPosition();
		lightView = camera.viewDirection;
	}
	else
	{
		if(lastControlState != controllingLight)
		{
			camera.setPosition(lastCameraPos);
			camera.setViewDirection(lastCameraView);
		}
	}
	
	lastControlState = controllingLight;
	//renderHelper->lightPosition = renderHelper->getGameObject("lightBulb")->position;
}

void ScratchWindow::updateShaderInfo()
{
	vec3 cameraPosition = camera.getPosition();
	vec3 cameraView = camera.viewDirection;

	camera.setPosition(lightPosition);
	camera.setViewDirection(lightView);
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	lightWorldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	camera.setPosition(cameraPosition);
	camera.setViewDirection(cameraView);

	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, 1.0f, 0.1f, 90.0f);
	//viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	renderHelper->eyePosition = eyePosition;
	renderHelper->lightPosition = lightPosition;
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