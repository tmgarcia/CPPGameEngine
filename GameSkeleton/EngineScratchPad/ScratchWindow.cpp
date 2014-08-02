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

GameObject* reflector;
GameObject* map;
TextureInfo* cubeMapA;
TextureInfo* cubeMapB;
TextureInfo* cubeMapC;
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

	GeneralGLWindow::getInstance().WINDOW_HEIGHT = WINDOW_HEIGHT;
	GeneralGLWindow::getInstance().WINDOW_WIDTH = WINDOW_WIDTH;
	/*pass1 = GeneralGLWindow::getInstance().addPass(false,false);
	GeneralGLWindow::getInstance().storePassColorTexture(pass1,DIMENSIONS,DIMENSIONS);
	GeneralGLWindow::getInstance().storePassDepthTexture(pass1,DIMENSIONS,DIMENSIONS);
	pass2 = GeneralGLWindow::getInstance().addPass(false,false);*/

	setupGeometry();
	setupTextures();
	setupGameObjects();
	/*GeneralGLWindow::getInstance().setupFrameBuffer(pass1);
	GeneralGLWindow::getInstance().setupFrameBuffer(pass2);*/

	QMap<QString,GLuint> textureOptions;
	textureOptions["Debug Map"] = cubeMapC->textureID;
	textureOptions["Minecraft cube map"] = cubeMapA->textureID;
	textureOptions["Fishing cube map"] = cubeMapB->textureID;
	dMenu->addComboBox("tab",&(reflector->renderable->cubeMap->textureID), textureOptions, "Cube Map");
}

void ScratchWindow::setupGeometry()
{
	renderHelper->addNUGeo(RendererHelper::NUShapes::NU_CUBE, "NUCube");
	//renderHelper->addGeoFromBin("../Resources/Models/plane.bin","plane");
	renderHelper->addNUGeo(RendererHelper::NUShapes::NU_SPHERE, "NUSphere");
}
//GameObject* colorPlane;
//GameObject* depthPlane;
void ScratchWindow::setupTextures()
{
	renderHelper->addShader("../Resources/Shaders/LightingAndTextureMapsVertexShader.glsl", "../Resources/Shaders/LightingAndTextureMapsFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "textureLightingShader");
	renderHelper->addShader("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl",RendererHelper::ShaderType::SHADER_PASSTHROUGH, "passThroughShader");
	renderHelper->addShader("../Resources/Shaders/JustTextureVertexShader.glsl", "../Resources/Shaders/JustTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_TEXTURE, "textureShader");
	renderHelper->addShader("../Resources/Shaders/CubeMapReflectionTextureVertexShader.glsl", "../Resources/Shaders/CubeMapReflectionTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "cubeReflectionShader");
	renderHelper->addShader("../Resources/Shaders/CubeMapTextureVertexShader.glsl", "../Resources/Shaders/CubeMapTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "cubeMapShader");
	//renderHelper->addShader("../Resources/Shaders/DepthTextureVertexShader.glsl", "../Resources/Shaders/DepthTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_TEXTURE, "depthTextureShader");

	//renderHelper->addTexture(pass1->colorTexture, "pass1Color");
	//renderHelper->addTexture(pass1->depthTexture, "pass1Depth");
	//renderHelper->addTexture("../Resources/Textures/lava1Texture.bmp","lavaText");
	//pos x, neg x, pos y, neg y, pos z, neg z
	const char* fileNamesA[6] = {
		"../Resources/Textures/CubeMapMinecraft/posX.png",
		"../Resources/Textures/CubeMapMinecraft/negX.png",
		"../Resources/Textures/CubeMapMinecraft/negY.png",
		"../Resources/Textures/CubeMapMinecraft/posY.png",
		"../Resources/Textures/CubeMapMinecraft/posZ.png",
		"../Resources/Textures/CubeMapMinecraft/negZ.png",
	};
	cubeMapA = GeneralGLWindow::getInstance().addCubeMap(fileNamesA);
	renderHelper->addTexture(cubeMapA, "cubeMapTextureA");

	const char* fileNamesB[6] = {
		"../Resources/Textures/CubeMapFishermans/posX.png",
		"../Resources/Textures/CubeMapFishermans/negX.png",
		"../Resources/Textures/CubeMapFishermans/negY.png",
		"../Resources/Textures/CubeMapFishermans/posY.png",
		"../Resources/Textures/CubeMapFishermans/posZ.png",
		"../Resources/Textures/CubeMapFishermans/negZ.png",
	};
	cubeMapB = GeneralGLWindow::getInstance().addCubeMap(fileNamesB);
	renderHelper->addTexture(cubeMapB, "cubeMapTextureB");

	const char* fileNamesC[6] = {
		"../Resources/Textures/CubeMapDebug/posX.png",
		"../Resources/Textures/CubeMapDebug/negX.png",
		"../Resources/Textures/CubeMapDebug/negY.png",
		"../Resources/Textures/CubeMapDebug/posY.png",
		"../Resources/Textures/CubeMapDebug/posZ.png",
		"../Resources/Textures/CubeMapDebug/negZ.png",
	};
	cubeMapC = GeneralGLWindow::getInstance().addCubeMap(fileNamesC);
	renderHelper->addTexture(cubeMapC, "cubeMapTextureC");
}

float reflectionFactor = 1.0f;
void ScratchWindow::setupGameObjects()
{
	renderHelper->eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	reflector = renderHelper->addGameObject(vec3(0,0,0),vec3(1,1,1),0,0,0,worldToProjectionMatrix,"reflectingSphere");
	reflector = renderHelper->setupGameObjectRenderable("reflectingSphere", "NUSphere","cubeReflectionShader",true,PRIORITY_1,true,"","","","","cubeMapTextureB");
	GeneralGLWindow::getInstance().addRenderableUniformParameter(reflector->renderable,"reflectionFactor",PT_FLOAT,&reflectionFactor);

	map = renderHelper->addGameObject(vec3(0,0,0),vec3(12,12,12),0,0,0,worldToProjectionMatrix,"skyMap");
	renderHelper->setupGameObjectRenderable(map, "NUCube","cubeMapShader",true,PRIORITY_1,true,"","","","","cubeMapTextureB");
	//GeneralGLWindow::getInstance().addRenderableUniformParameter(map->renderable,"reflectionFactor",PT_FLOAT,&reflectionFactor);

	//GeneralGLWindow::getInstance().setCurrentPass(pass1);
	//renderHelper->addGameObject(vec3(0,0,0),vec3(1,1,1),0,45,0,worldToProjectionMatrix,"Cube");
	//renderHelper->setupGameObjectRenderable("Cube","NUCube","textureLightingShader",true,PRIORITY_1,true,"","","","","");
	//GeneralGLWindow::getInstance().setCurrentPass(pass2);
	//colorPlane = renderHelper->addGameObject(vec3(0.2f,0.7f,-0.9999f),vec3(0.25f,1,0.25f),90,0,0,worldToProjectionMatrix,"ColorPlane", false);
	//renderHelper->setupGameObjectRenderable("ColorPlane","plane","textureShader",true,PRIORITY_1,true,"pass1Color","","","");
	//depthPlane = renderHelper->addGameObject(vec3(0.7f,0.7f,-0.9999f),vec3(0.25f,1,0.25f),90,0,0,worldToProjectionMatrix,"DepthPlane", false);
	//renderHelper->setupGameObjectRenderable("DepthPlane","plane","depthTextureShader",true,PRIORITY_1,true,"pass1Depth","","","");
}

int frame = 0;
GLuint lastTextureId = 0;
void ScratchWindow::update()
{
	//cout << "update" << endl;
	updateShaderInfo();
	frame++;
}

void ScratchWindow::updateShaderInfo()
{
	vec3 eyePosition = camera.getPosition();
	//viewToProjectionMatrix = glm::perspective(60.0f, 1.0f, 0.1f, 90.0f);
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;
	renderHelper->eyePosition = eyePosition;

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