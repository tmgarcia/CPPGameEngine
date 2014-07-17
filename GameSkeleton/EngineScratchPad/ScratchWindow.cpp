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

void ScratchWindow::setup()
{
	camera.setPosition(vec3(0,0,5));
	camera.setViewDirection(vec3(0,0,-1));

	renderer = new RendererHelper();

	renderer->lightPosition = vec3(1.2f,6.2f,16.5f);
	renderer->diffusionIntensity = 0.5f;
	renderer->specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	renderer->specularExponent = 10;
	renderer->overridingObjectColor = vec3(0.9f,0.9f,0.9f);
	renderer->ambientLight = vec3(0.4f, 0.4f, 0.4f);
	renderer->eyePosition;

	setupGeometry();
	setupTransforms();
	setupTextures();
	setupRenderables();

	/*QList<TrackingFloat*> cubeRfloats;
	TrackingFloat* rf1 = new TrackingFloat(&normalMapCube->xRotationAngle, 0, 360, "X Angle");
	TrackingFloat* rf2 = new TrackingFloat(&normalMapCube->yRotationAngle, 0, 360, "Y Angle");
	TrackingFloat* rf3 = new TrackingFloat(&normalMapCube->zRotationAngle, 0, 360, "Z Angle");
	cubeRfloats.append(rf1);
	cubeRfloats.append(rf2);
	cubeRfloats.append(rf3);
	dMenu->addMultipleFloatSlider("Normal Map Cube", cubeRfloats, "Rotation");
	dMenu->addVec3Slider("Normal Map Cube", &normalMapCube->position,-5,5,-5,5,-5,5,"Position");
	dMenu->addCheckBox("Normal Map Cube", &normalMapCube->renderable->visible, "Show Normal Map Cube");

	QList<TrackingFloat*> floats;
	TrackingFloat* f1 = new TrackingFloat(&ogre->xRotationAngle, 0, 360, "X Angle");
	TrackingFloat* f2 = new TrackingFloat(&ogre->yRotationAngle, 0, 360, "Y Angle");
	TrackingFloat* f3 = new TrackingFloat(&ogre->zRotationAngle, 0, 360, "Z Angle");
	floats.append(f1);
	floats.append(f2);
	floats.append(f3);
	dMenu->addMultipleFloatSlider("Ogre", floats, "Rotation");
	dMenu->addCheckBox("Ogre", &ogre->renderable->visible, "Show Ogre");
	dMenu->addCheckBox("Ogre", &ogre->renderable->usingAmbientOcclusionMap, "Toggle Ambient Occlusion");
	dMenu->addCheckBox("Ogre", &ogre->renderable->usingNormalMap, "Toggle Normal Map");
	dMenu->addCheckBox("Ogre", &ogre->renderable->usingDiffuseMap, "Toggle Diffuse Map");

	dMenu->addVec3Slider("Light Controls", &lightBulb->position, -5,5,-5,5,-5,5,"Light");
	dMenu->addFloatSlider("Light Controls", &diffusionIntensity, 0,5,"Diffusion Intensity");
	dMenu->addFloatSlider("Light Controls", &specularExponent, 0.1,100,"Specular Exponent");
	dMenu->addVec3Slider("Light Controls", &ambientLight, 0,1,0,1,0,1,"Ambient Light");*/
}

void ScratchWindow::setupGeometry()
{
	renderer->addNUGeo(RendererHelper::NUShapes::NU_CUBE, "NUCube");

	renderer->addGeoFromBin("../Resources/AssetGroups/Ogre/Ogre.bin","ogreGeo");
}

void ScratchWindow::setupTransforms()
{
	renderer->eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	renderer->addGameObject(vec3(0,0,0),vec3(0.25f,0.25f,0.25f),0,0,0,worldToProjectionMatrix, "lightBulb");

	renderer->addGameObject(vec3(1,-2,0),vec3(1,1,1),0,0,0,worldToProjectionMatrix,"ogre");
}

void ScratchWindow::setupTextures()
{
	renderer->addShader("../Resources/Shaders/LightingTextureAlphaNormalVertexShader.glsl", "../Resources/Shaders/LightingTextureAlphaNormalFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "textureLightingShader");
	renderer->addShader("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl",RendererHelper::ShaderType::SHADER_PASSTHROUGH, "passThroughShader");

	renderer->addNormalMap("../Resources/AssetGroups/Ogre/ogre_normalmap.png", "ogreNormal");
	renderer->addDiffuseMap("../Resources/AssetGroups/Ogre/diffuse.png", "ogreDiffuse");
	renderer->addAmbientOcclusionMap("../Resources/AssetGroups/Ogre/ao_ears.png", "ogreAO");
}

void ScratchWindow::setupRenderables()
{
	renderer->setupGameObjectRenderable("lightBulb","NUCube","passThroughShader",true,PRIORITY_1,true,"","","","");

	renderer->setupGameObjectRenderable("ogre","ogreGeo","textureLightingShader",true,PRIORITY_1,true,"ogreDiffuse","","ogreNormal","ogreAO");
}

int frame = 0;
void ScratchWindow::update()
{
	updateShaderInfo();
	frame++;
	renderer->lightPosition = renderer->getGameObject("lightBulb")->position;
}

void ScratchWindow::updateShaderInfo()
{
	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	renderer->updateShaderInfo(worldToProjectionMatrix);
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