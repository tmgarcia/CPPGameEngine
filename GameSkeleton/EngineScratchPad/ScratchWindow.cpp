#include "ScratchWindow.h"
#include "GameObjects\GameLevel.h"
#include "DebugMenu\DebugMenu.h"
#include "GameObjects\GameObject.h"
#include "DebugMenu\TrackingFloat.h"
#include "noise.h"
#include <iostream>

TextureInfo* emptyTreeDiffuse;
TextureInfo* emptyTreeAlpha;
TextureInfo* tree1Alpha;
TextureInfo* tree2Alpha;
TextureInfo* tree3Alpha;
TextureInfo* tree4Alpha;
TextureInfo* tree1Diffuse;
TextureInfo* tree2Diffuse;
TextureInfo* tree3Diffuse;
TextureInfo* tree4Diffuse;
TextureInfo* creep1Alpha;
TextureInfo* creep2Alpha;
TextureInfo* creep3Alpha;
TextureInfo* creep4Alpha;
TextureInfo* noise1;
TextureInfo* noise2;
TextureInfo* noise3;
TextureInfo* noise4;
TextureInfo* noise5;
TextureInfo* noise6;
TextureInfo* noise7;
TextureInfo* noise8;
TextureInfo* noise9;
TextureInfo* noise10;
TextureInfo* noise11;
TextureInfo* noise12;
TextureInfo* noise13;
TextureInfo* noise14;
TextureInfo* noise15;
using std::cout;
using std::endl;

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

vec3 camOPos = vec3(0,-0.5f,2);
//vec3 camOPos = lightPosition;
vec3 camOV = vec3(0,0,-1);
//vec3 camOV = lightView;

uint DIMENSIONS = 512;

GameObject* reflector;
GameObject* map;
TextureInfo* cubeMapA;
TextureInfo* cubeMapB;
TextureInfo* cubeMapC;
void ScratchWindow::setup()
{
	camera.setPosition(camOPos);
	camera.setViewDirection(camOV);

	renderHelper = new RendererHelper();

	renderHelper->lightPosition = vec3(0.0f,5.0f,0.0f);
	renderHelper->diffusionIntensity = -1.0f;
	renderHelper->specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	renderHelper->specularExponent = 10;
	renderHelper->overridingObjectColor = vec3(0.5f,0.5f,0.5f);
	renderHelper->ambientLight = vec3(0.0f, 0.0f, 0.0f);
	renderHelper->eyePosition = camera.getPosition();


	GeneralGLWindow::getInstance().WINDOW_HEIGHT = WINDOW_HEIGHT;
	GeneralGLWindow::getInstance().WINDOW_WIDTH = WINDOW_WIDTH;

	setupGeometry();
	setupTextures();
	setupGameObjects();

	//QMap<QString,GLuint> textureOptions;
	//textureOptions["Debug Map"] = cubeMapC->textureID;
	//textureOptions["Minecraft cube map"] = cubeMapA->textureID;
	//textureOptions["Fishing cube map"] = cubeMapB->textureID;
	//dMenu->addComboBox("tab",&(reflector->renderable->cubeMap->textureID), textureOptions, "Cube Map");
}
void ScratchWindow::setupGeometry()
{
	//cout << "setup geometry" << endl;

	renderHelper->addNUGeo(RendererHelper::NUShapes::NU_CUBE, "NUCube");
	renderHelper->addNUGeo(RendererHelper::NUShapes::NU_SPHERE, "NUSphere");
	renderHelper->addGeoFromBin("../Resources/Models/plane.bin","plane");
	renderHelper->addGeoFromBin("../Resources/Models/wall.bin","wall");
}
float reflectionFactor = 1.0f;
GameObject* test1;
GameObject* tree1;
GameObject* creep1;
int numTrees = 150;
float minTreeDistance = 1;
float maxTreeDistance = 20;
float creepSpawnDistance = 5;
void ScratchWindow::setupGameObjects()
{
	vec3 cameraPosition = camera.getPosition();
	vec3 cameraView = camera.viewDirection;

	renderHelper->eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;
	
	Random::getInstance();
	for(int i = 0; i<numTrees; i++)
	{
		float distanceFromCenter = Random::getInstance().randomFloatRange(minTreeDistance, maxTreeDistance);
		float angle = Random::getInstance().randomFloatRange(0, 359);
		mat4 transform = glm::rotate(angle, vec3(0,1,0));
		vec3 position = vec3((vec4(0,-0.05f,distanceFromCenter,1) * transform));
		Tree* t = new Tree();
		char* treeDiffuse = "emptyTreeDiffuse";
		char* treeAlpha = "emptyTreeAlpha";
		char* creepAlpha = "creep1Alpha";
		//bool creeping = true;
		bool creeping = distanceFromCenter>creepSpawnDistance;
		GameObject* tree = renderHelper->addGameObject(position,vec3(1,1,1),0,0,0,worldToProjectionMatrix,"tree"+i);
		renderHelper->setupGameObjectRenderable(tree,"plane","textureLightingShader",true,PRIORITY_1,true,"emptyTreeDiffuse","emptyTreeAlpha","","","");
		GameObject* creep = renderHelper->addGameObject(position,vec3(1,1,1),0,0,0,worldToProjectionMatrix,"creep"+i);
		renderHelper->setupGameObjectRenderable(creep,"plane","textureLightingShader",creeping,PRIORITY_1,true,"noise10","creep1Alpha","","","");
		t->treeObject = tree;
		t->creepObject = creep;
		setupTreeTextures(t, creeping);
		trees.append(t);
	}

	//reflector = renderHelper->addGameObject(vec3(0,-1.3f,0),vec3(1,2,1),0,0,0,worldToProjectionMatrix,"reflectingSphere");
	//reflector = renderHelper->setupGameObjectRenderable("reflectingSphere", "wall","cubeReflectionShader",true,PRIORITY_1,true,"","","","","skyMap");
	//GeneralGLWindow::getInstance().addRenderableUniformParameter(reflector->renderable,"reflectionFactor",PT_FLOAT,&reflectionFactor);
	//reflector->renderable->usingShadowMap = false;

	map = renderHelper->addGameObject(vec3(0,0,0),vec3(15,15,15),0,0,0,worldToProjectionMatrix,"skyBox");
	renderHelper->setupGameObjectRenderable(map, "NUCube","cubeMapShader",true,PRIORITY_1,true,"","","","","skyMap");
	//map->renderable->usingShadowMap = false;

	//renderHelper->addGameObject(vec3(0,-0.9f,0),vec3(15.0f,1.0f,15.0f),0,0,0,worldToProjectionMatrix,"ground");
	//renderHelper->setupGameObjectRenderable("ground", "plane","textureLightingShader",true,PRIORITY_1,true,"darkGround","","","","");
	//GeneralGLWindow::getInstance().addRenderableUniformParameter(ground->renderable,"reflectionFactor",PT_FLOAT,&reflectionFactor);
}

float octaveIndex = 3;
int noiseWidth = 128;
int noiseHeight = 128;
//float frequency = 1;
uchar* ScratchWindow::createNoiseTexture(float frequency)
{
	noise::module::Perlin perlinNoise;
	perlinNoise.SetFrequency(frequency);
	uchar *data = new GLubyte[ noiseWidth * noiseHeight * 4 ];
	uint BYTES_PER_COLOR = 4;
	float xRange = 1.0;
	float yRange = 1.0;
	float xFactor = xRange / noiseWidth;
	float yFactor = yRange / noiseHeight;
	int oct = 20;
	perlinNoise.SetOctaveCount(oct+1);
	for( int i = 0; i < noiseWidth; i++ ) 
	{
		for( int j = 0 ; j < noiseHeight; j++ ) 
		{
			float x = xFactor * i;
			float y = yFactor * j;
			float z = 0.0;
			float val = 0.0f;

			float a, b, c, d;
			a = perlinNoise.GetValue(x ,y ,z);
			b = perlinNoise.GetValue(x+xRange,y ,z);
			c = perlinNoise.GetValue(x ,y+yRange,z);
			d = perlinNoise.GetValue(x+xRange,y+yRange,z);

			float xmix = 1.0 - x / xRange;
			float ymix = 1.0 - y / yRange;
			float x1 = glm::mix( a, b, xmix );
			float x2 = glm::mix( c, d, xmix );

			val = glm::mix(x1, x2, ymix );
			val = (val + 1.0f) * 0.5f;
			val = val> 1.0 ? 1.0 :val;
			val = val< 0.0 ? 0.0 :val;

			data[((j * noiseWidth + i) * 4) + 0] =( val * 255.0f );
			data[((j * noiseWidth + i) * 4) + 1] =( val * 255.0f );
			data[((j * noiseWidth + i) * 4) + 2] =( val * 255.0f );
			data[((j * noiseWidth + i) * 4) + 3] =( val * 255.0f );
		}
	}
	return data;
}

void ScratchWindow::setupTextures()
{
	renderHelper->addShader("../Resources/Shaders/LightingAndTextureMapsVertexShader.glsl", "../Resources/Shaders/LightingAndTextureMapsFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "textureLightingShader");
	renderHelper->addShader("../Resources/Shaders/LightingTextureShadowVertexShader.glsl", "../Resources/Shaders/LightingTextureShadowFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "shadowShader");
	renderHelper->addShader("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl",RendererHelper::ShaderType::SHADER_PASSTHROUGH, "passThroughShader");
	renderHelper->addShader("../Resources/Shaders/JustTextureVertexShader.glsl", "../Resources/Shaders/JustTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_TEXTURE, "textureShader");
	renderHelper->addShader("../Resources/Shaders/CubeMapReflectionTextureVertexShader.glsl", "../Resources/Shaders/CubeMapReflectionTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "cubeReflectionShader");
	renderHelper->addShader("../Resources/Shaders/CubeMapTextureVertexShader.glsl", "../Resources/Shaders/CubeMapTextureFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "cubeMapShader");

	noise1 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise10.png", "noise10");
	noise2 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise11.png", "noise11");
	noise3 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise12.png", "noise12");
	noise4 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise13.png", "noise13");
	noise5 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise14.png", "noise14");
	noise6 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise15.png", "noise15");
	noise7 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise16.png", "noise16");
	noise8 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise17.png", "noise17");
	noise9 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise18.png", "noise18");
	noise10 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise19.png", "noise19");
	noise11= renderHelper->addTexture("../Resources/AssetGroups/Noise/noise20.png", "noise20");
	noise12 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise21.png", "noise21");
	noise13 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise22.png", "noise22");
	noise14 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise23.png", "noise23");
	noise15 = renderHelper->addTexture("../Resources/AssetGroups/Noise/noise24.png", "noise24");

	//1-14 = noise
	emptyTreeAlpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/emptyTreeAlpha.png","emptyTreeAlpha");
	emptyTreeDiffuse = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/emptyTreeDiffuse.png","emptyTreeDiffuse");
	//15-16 = empty tree
	tree1Alpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creepTree1Alpha.png","tree1Alpha");
	tree2Alpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creepTree2Alpha.png","tree2Alpha");
	tree3Alpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creepTree3Alpha.png","tree3Alpha");
	tree4Alpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creepTree4Alpha.png","tree4Alpha");
	//17-20 = tree alpha
	tree1Diffuse = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creepTree1Diffuse.png","tree1Diffuse");
	tree2Diffuse = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creepTree2Diffuse.png","tree2Diffuse");
	tree3Diffuse = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creepTree3Diffuse.png","tree3Diffuse");
	tree4Diffuse = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creepTree4Diffuse.png","tree4Diffuse");
	//21-24 = tree diffuse
	creep1Alpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creep1Alpha.png","creep1Alpha");
	creep2Alpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creep2Alpha.png","creep2Alpha");
	creep3Alpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creep3Alpha.png","creep3Alpha");
	creep4Alpha = renderHelper->addTexture("../Resources/AssetGroups/CreepTrees/creep4Alpha.png","creep4Alpha");

	renderHelper->addTexture("../Resources/Textures/darkGroundTexture.bmp","darkGround");
	//25-28 = creep alpha
	const char* fileNamesA[6] = {
		"../Resources/Textures/CubeMapNight/posX.png",
		"../Resources/Textures/CubeMapNight/negX.png",
		"../Resources/Textures/CubeMapNight/negY.png",
		"../Resources/Textures/CubeMapNight/posY.png",
		"../Resources/Textures/CubeMapNight/posZ.png",
		"../Resources/Textures/CubeMapNight/negZ.png",
	};
	cubeMapA = GeneralGLWindow::getInstance().addCubeMap(fileNamesA);
	renderHelper->addTexture(cubeMapA, "skyMap");
}
bool wDown=false;
bool sDown=false;
bool aDown=false;
bool dDown=false;
bool rDown=false;
bool fDown=false;
int frame = 0;
GLuint lastTextureId = 0;
void ScratchWindow::update()
{
	renderHelper->lightPosition = camera.getPosition();
	updateShaderInfo();
	frame++;
	keyMove();
	if(frame == 50)
	{
		wDown=false;
		sDown=false;
		aDown=false;
		dDown=false;
		rDown=false;
		fDown=false;
	}
}



void ScratchWindow::updateShaderInfo()
{
	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;
	renderHelper->eyePosition = eyePosition;

	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	renderHelper->updateShaderInfo(worldToProjectionMatrix);

	for(int i = 0; i < numTrees; i++)
	{
		Tree* t = trees[i];
		mat4 rotation = TransformationMatrixMaker::getInstance().getRestrictedYBillboardTransformation(t->treeObject->position,camera.getPosition(),vec3(0,1,0),false);
		t->resetTransforms(rotation, worldToProjectionMatrix);
		if(trees[i]->empty)
		{
			if(glm::length(t->treeObject->position-camera.getPosition())>creepSpawnDistance)
			{
				setupTreeTextures(t, true);
			}
		}
		else
		{
			
			if(glm::length(t->treeObject->position -camera.getPosition())<creepSpawnDistance)
			{
				setupTreeTextures(t, false);
			}
		}
		if(frame%5 == 0)
		{
			int ind = (int)(Random::getInstance().randomFloatRange(1,16));
			switch(ind)
			{
			case 1:
				t->creepObject->renderable->diffuseMap = noise1;
				break;
			case 2:
				t->creepObject->renderable->diffuseMap = noise2;
				break;
			case 3:
				t->creepObject->renderable->diffuseMap = noise3;
				break;
			case 4:
				t->creepObject->renderable->diffuseMap = noise4;
				break;
			case 5:
				t->creepObject->renderable->diffuseMap = noise5;
				break;
			case 6:
				t->creepObject->renderable->diffuseMap = noise6;
				break;
			case 7:
				t->creepObject->renderable->diffuseMap = noise7;
				break;
			case 8:
				t->creepObject->renderable->diffuseMap = noise8;
				break;
			case 9:
				t->creepObject->renderable->diffuseMap = noise9;
				break;
			case 10:
				t->creepObject->renderable->diffuseMap = noise10;
				break;
			case 11:
				t->creepObject->renderable->diffuseMap = noise11;
				break;
			case 12:
				t->creepObject->renderable->diffuseMap = noise12;
				break;
			case 13:
				t->creepObject->renderable->diffuseMap = noise13;
				break;
			case 14:
				t->creepObject->renderable->diffuseMap = noise14;
				break;
			case 15:
				t->creepObject->renderable->diffuseMap = noise15;
				break;
			defautl:
				t->creepObject->renderable->diffuseMap = noise15;
				break;
			}
		}
	}

	GeneralGLWindow::getInstance().repaint();
}
void ScratchWindow::setupTreeTextures(Tree* tree, bool creeping)
{
		if(creeping)
		{
			int index = (int)Random::getInstance().randomFloatRange(0,4);
			//cout << index << endl;
			tree->creepObject->renderable->visible = true;
			switch(index)
			{
			case 0:
				tree->treeObject->renderable->diffuseMap = tree1Diffuse;
				tree->treeObject->renderable->alphaMap = tree1Alpha;
				tree->creepObject->renderable->alphaMap = creep1Alpha;
				break;
			case 1:
				tree->treeObject->renderable->diffuseMap = tree2Diffuse;
				tree->treeObject->renderable->alphaMap = tree2Alpha;
				tree->creepObject->renderable->alphaMap = creep2Alpha;
				break;
			case 2:
				tree->treeObject->renderable->diffuseMap = tree3Diffuse;
				tree->treeObject->renderable->alphaMap = tree3Alpha;
				tree->creepObject->renderable->alphaMap = creep3Alpha;
				break;
			case 3:
				tree->treeObject->renderable->diffuseMap = tree4Diffuse;
				tree->treeObject->renderable->alphaMap = tree4Alpha;
				tree->creepObject->renderable->alphaMap = creep4Alpha;
				break;
			}
		}
		else
		{
			tree->treeObject->renderable->alphaMap = emptyTreeAlpha;
			tree->treeObject->renderable->diffuseMap = emptyTreeDiffuse;

			tree->creepObject->renderable->visible = false;
		}
	tree->empty = !creeping;
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
		wDown = true;
		sDown = false;
		break;
	case Qt::Key::Key_S:
		sDown = true;
		wDown = false;
		break;
	case Qt::Key::Key_A:
		aDown = true;
		dDown = false;
		break;
	case Qt::Key::Key_D:
		dDown = true;
		aDown = false;
		break;
	//case Qt::Key::Key_R:
	//	rDown = true;
	//	break;
	//case Qt::Key::Key_F:
	//	fDown = true;
	//	break;
	case Qt::Key::Key_0:
		cameraFrozen = !cameraFrozen;
		break;
	}
	update();
}
void ScratchWindow::keyReleaseReaction(QKeyEvent* e)
{
	switch(e->key())
	{
	case Qt::Key::Key_W:
		wDown = false;
		break;
	case Qt::Key::Key_S:
		sDown = false;
		break;
	case Qt::Key::Key_A:
		aDown = false;
		break;
	case Qt::Key::Key_D:
		dDown = false;
		break;
	//case Qt::Key::Key_R:
	//	rDown = false;
	//	break;
	//case Qt::Key::Key_F:
	//	fDown = false;
	//	break;
	}
	update();
}

void ScratchWindow::keyMove()
{
	if(wDown)
	{
		camera.moveForward();
	}
	if(sDown)
	{
		camera.moveBackward();
	}
	if(aDown)
	{
		camera.strafeLeft();
	}
	if(dDown)
	{
		camera.strafeRight();
	}
	//if(rDown)
	//{
	//	camera.moveUp();
	//}
	//if(fDown)
	//{
	//	camera.moveDown();
	//}
}

void ScratchWindow::mouseMoveReaction(QMouseEvent* e)
{
	if(!cameraFrozen)
	{
		camera.mouseUpdate(glm::vec2(e->x(), 0));
		update();
	}
}