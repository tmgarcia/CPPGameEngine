#include "MainWindow.h"
#include "DebugMenu\DebugMenu.h"
#include "BinReader.h"
#include "noise.h"

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

AlphaMapInfo* noiseMap;

float heightMin = -0.5f;
float heightMax = 0.5f;
float heightIncrement = 0.01f;

float heightScalar = 0.5f;
float burnThreshold = 0.0f;
void MainWindow::setup()
{
	camera.setPosition(vec3(0,5,13.0f));
	camera.setViewDirection(vec3(0,-0.6f,-1));
	
	renderer = new RendererHelper();

	renderer->lightPosition = vec3(0,4,6);
	renderer->diffusionIntensity = 0.5f;
	renderer->specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	renderer->specularExponent = 10;
	renderer->overridingObjectColor = vec3(0.5f,0.5f,0.5f);
	renderer->ambientLight = vec3(0.7f, 0.7f, 0.7f);
	renderer->eyePosition;

	setupGeometry();
	setupTransforms();
	renderer->addShader("../Resources/Shaders/LightingTextureAlphaNormalVertexShader.glsl", "../Resources/Shaders/LightingTextureAlphaNormalFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "textureLightingShader");
	renderer->addShader("../Resources/Shaders/LightingNoiseVertexShader.glsl", "../Resources/Shaders/LightingNoiseFragmentShader.glsl",RendererHelper::ShaderType::SHADER_LIGHTING_TEXTURE, "lightingNoiseShader");
	renderer->addShader("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl",RendererHelper::ShaderType::SHADER_PASSTHROUGH, "passThroughShader");
	setupTextures();
	setupRenderables();


	dMenu->addVec3Slider("tab", &(renderer->lightPosition),-20,20,-20,20,-20,20,"light");
	/*dMenu->addFloatSlider("tab", &heightMin, -1, 0, "Height Min");
	dMenu->addFloatSlider("tab", &heightMax, 0,1, "Height Max");
	dMenu->addFloatSlider("tab", &heightIncrement, 0.01f, 1, "Increment");
	dMenu->addFloatSlider("tab", &burnThreshold, 0.0f, 1, "burnThreshold");*/
}

float octaveIndex = 3;
int noiseWidth = 128;
int noiseHeight = 128;
uchar* MainWindow::createNoiseTexture()
{
	noise::module::Perlin perlinNoise;
	float frequency = Random::getInstance().randomFloatRange(1,5);
	perlinNoise.SetFrequency(frequency);
	uchar *data = new GLubyte[ noiseWidth * noiseHeight * 4 ];
	uint BYTES_PER_COLOR = 4;
	float xRange = 1.0;
	float yRange = 1.0;
	float xFactor = xRange / noiseWidth;
	float yFactor = yRange / noiseHeight;
	//GLubyte SCALE = 0xFF;

	for( int oct = 0; oct< 4; oct++ ) 
	{
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

				data[((j * noiseWidth + i) * 4) + oct] =( val * 255.0f );
			}
		}
	}
	//noiseMap = renderer->addDiffuseMap(data, noiseWidth, noiseHeight, "noiseTexture");

	//dMenu->addFloatSlider("tab", &octaveIndex, 0,3,"Octave");
	return data;
}

void MainWindow::setupGeometry()
{
	renderer->addNUGeo(RendererHelper::NUShapes::NU_CUBE, "NUCube");

	renderer->addNUGeo(RendererHelper::NUShapes::NU_PLANE, "NUPlane");

	renderer->addGeoFromBin("../Resources/AssetGroups/Cauldron/cauldron.bin","cauldronGeo");
	renderer->addGeoFromBin("../Resources/AssetGroups/Cauldron/cauldronInner.bin","cauldronInnerGeo");

	renderer->addGeoFromBin("../Resources/Models/alchemyRoom.bin","alchemyRoomGeo");

	renderer->addGeoFromBin("../Resources/Models/alchemyRoomOuter.bin","alchemyRoomOuterGeo");

	renderer->addGeoFromBin("../Resources/Models/alchemyTable.bin","alchemyTableGeo");

	renderer->addGeoFromBin("../Resources/Models/alchemyTableApertures.bin","alchemyTableAperturesGeo");

	renderer->addGeoFromBin("../Resources/Models/alchemyTableGlassware.bin","alchemyTableGlasswareGeo");

	renderer->addGeoFromBin("../Resources/Models/alchemyTableLiquids.bin","alchemyTableLiquidsGeo");

	renderer->addGeoFromBin("../Resources/Models/potionLarge.bin","potionLargeGeo");

	renderer->addGeoFromBin("../Resources/Models/potionSmall.bin","potionSmallGeo");

	renderer->addGeoFromBin("../Resources/Models/potionThin.bin","potionThinGeo");

	renderer->addGeoFromBin("../Resources/Models/potionWide.bin","potionWideGeo");

	renderer->addGeoFromBin("../Resources/Models/potionVial.bin","potionVialGeo");
}

void MainWindow::setupTransforms()
{
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	//renderer->addGameObject(vec3(0,5,18),vec3(1,1,1),0.0f,0,0,worldToProjectionMatrix,"noisePlane");

	renderer->addGameObject(vec3(0,1,10),vec3(1,1,1),0,0,0,worldToProjectionMatrix,"cauldron");
	renderer->addGameObject(vec3(0,1,10),vec3(1,1,1),0,0,0,worldToProjectionMatrix,"cauldronInner");
	renderer->addGameObject(vec3(0,1.01,10),vec3(1,1,1),0,0,0,worldToProjectionMatrix,"cauldronInnerBurn");

	renderer->addGameObject(renderer->lightPosition,vec3(0.1f,0.1f,0.1f),0,0,0,worldToProjectionMatrix, "lightBulb");

	renderer->addGameObject(vec3(0,0,0),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "alchRoom");

	renderer->addGameObject(vec3(0,0,8),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "alchRoomOuter");
	
	renderer->addGameObject(vec3(0,0,0),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "alchTable");
	
	renderer->addGameObject(vec3(0,0,0),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "alchTableGlass");
	
	renderer->addGameObject(vec3(0,0,0),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "alchTableMetal");
	
	renderer->addGameObject(vec3(0,0,0),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "alchTableLiquids");
	
	renderer->addGameObject(vec3(-1.1f,3.8f, -2.5f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potL1");
	
	renderer->addGameObject(vec3(-2.5f,4.6f, -2.8f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potS1");
	
	renderer->addGameObject(vec3(-3.6f,4.5f, -1.9f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potT1");
	
	renderer->addGameObject(vec3(-1.9f,3.8f, -1.5f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potW1");
	
	renderer->addGameObject(vec3(-2.6f,3.8f,0.2f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potV1");
	renderer->addGameObject(vec3(-3.5f,3.8f,-0.2f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potV2");
	renderer->addGameObject(vec3(-3.1f,3.8f,0.5f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potV3");
	renderer->addGameObject(vec3(-3.1f,3.8f,0.5f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potV3");
	renderer->addGameObject(vec3(-3.4f,3.8f,-0.6f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potV4");
	renderer->addGameObject(vec3(-3,3.8f,-0.2f),vec3(1,1,1),0,0,0,worldToProjectionMatrix, "potV5");
}


void MainWindow::setupTextures()
{
	//renderer->addNormalMap("../Resources/AssetGroups/Ogre/ogre_normalmap.png", "ogreNormal");
	//renderer->addDiffuseMap("../Resources/AssetGroups/Ogre/diffuse.png", "ogreDiffuse");
	//renderer->addAmbientOcclusionMap("../Resources/AssetGroups/Ogre/ao_ears.png", "ogreAO");

	renderer->addNormalMap("../Resources/AssetGroups/Cauldron/cauldronNormal.png", "cauldronNormal");
	renderer->addDiffuseMap("../Resources/AssetGroups/Cauldron/cauldronDiffuse.png", "cauldronDiffuse");
	renderer->addNormalMap("../Resources/AssetGroups/Cauldron/liquidBurnNormal.png", "liquidBurnNormal");
	renderer->addNormalMap("../Resources/AssetGroups/Cauldron/liquidNormal.png", "liquidNormal");
	renderer->addDiffuseMap("../Resources/AssetGroups/Cauldron/liquidBurnDiffuse.png", "liquidBurnDiffuse");
	renderer->addDiffuseMap("../Resources/AssetGroups/Cauldron/liquidDiffuse.png", "liquidDiffuse");
	renderer->addDiffuseMap("../Resources/Textures/alchemyRoomTexture.png", "alchRoomTexture");
	renderer->addDiffuseMap("../Resources/Textures/alchemyRoomOuterTexture.png", "alchRoomOuterTexture");
	renderer->addDiffuseMap("../Resources/Textures/alchemyTableTexture.png", "alchTableTexture");
	renderer->addDiffuseMap("../Resources/Textures/glassTexture.png", "alchTableGlassTexture");
	renderer->addDiffuseMap("../Resources/Textures/metalBitsTexture.png", "alchTableMetalTexture");
	renderer->addDiffuseMap("../Resources/Textures/liquidsTexture.png", "alchTableLiquidsTexture");
	renderer->addDiffuseMap("../Resources/Textures/potionLargeTexture1.png", "potLTexture1");
	renderer->addDiffuseMap("../Resources/Textures/potionSmallTexture1.png", "potSTexture1");
	renderer->addDiffuseMap("../Resources/Textures/potionThinTexture1.png", "potTTexture1");
	renderer->addDiffuseMap("../Resources/Textures/potionWideTexture1.png", "potWTexture1");
	renderer->addDiffuseMap("../Resources/Textures/potionSkoomaTexture1.png", "potVTexture1");

	uchar* data = createNoiseTexture();
	noiseMap = renderer->addAlphaMap(data, noiseWidth, noiseHeight, "noiseTexture");
	dMenu->addFloatSlider("tab", &octaveIndex, 0,3,"Octave");
	data = createNoiseTexture();
	renderer->addAmbientOcclusionMap(data, noiseWidth, noiseHeight, "burnNoise");
}


void MainWindow::setupRenderables()
{
	//GameObject* noise = renderer->setupGameObjectRenderable("noisePlane","NUPlane","lightingNoiseShader",true,PRIORITY_1,true,"noiseTexture","","","");
	//GeneralGLWindow::getInstance().addRenderableUniformParameter(noise->renderable, "octaveIndex", PT_FLOAT, &octaveIndex);

	GameObject* noise = renderer->setupGameObjectRenderable("cauldronInner","cauldronInnerGeo","lightingNoiseShader",true,PRIORITY_1,true,"liquidDiffuse","noiseTexture","liquidNormal","");
	GeneralGLWindow::getInstance().addRenderableUniformParameter(noise->renderable, "octaveIndex", PT_FLOAT, &octaveIndex);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(noise->renderable, "heightScalar", PT_FLOAT, &heightScalar);
	
	GameObject* noiseB = renderer->setupGameObjectRenderable("cauldronInnerBurn","cauldronInnerGeo","lightingNoiseShader",true,PRIORITY_1,true,"liquidBurnDiffuse","noiseTexture","liquidBurnNormal","burnNoise");
	GeneralGLWindow::getInstance().addRenderableUniformParameter(noiseB->renderable, "octaveIndex", PT_FLOAT, &octaveIndex);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(noiseB->renderable, "heightScalar", PT_FLOAT, &heightScalar);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(noiseB->renderable, "burnThreshold", PT_FLOAT, &burnThreshold);
	//dMenu->addFloatSlider("tab", &heightScalar, 0,1,"Height Scalar");

	//GameObject* noise = renderer->setupGameObjectRenderable("cauldronInner","cauldronInnerGeo","lightingNoiseShader",true,PRIORITY_1,true,"","noiseTexture","liquidNormal","");


	renderer->setupGameObjectRenderable("cauldron","cauldronGeo","textureLightingShader",true,PRIORITY_1,true,"cauldronDiffuse","","cauldronNormal","");

	renderer->setupGameObjectRenderable("lightBulb","NUCube","passThroughShader",true,PRIORITY_1,true,"","","","");

	renderer->setupGameObjectRenderable("alchRoomOuter","alchemyRoomOuterGeo","textureLightingShader",true,PRIORITY_1,true,"alchRoomOuterTexture","","","");

	renderer->setupGameObjectRenderable("alchRoom","alchemyRoomGeo","textureLightingShader",true,PRIORITY_1,true,"alchRoomTexture","","","");

	renderer->setupGameObjectRenderable("alchTable","alchemyTableGeo","textureLightingShader",true,PRIORITY_1,true,"alchTableTexture","","","");
		
	renderer->setupGameObjectRenderable("alchTableMetal","alchemyTableAperturesGeo","textureLightingShader",true,PRIORITY_1,true,"alchTableMetalTexture","","","");

	renderer->setupGameObjectRenderable("alchTableLiquids","alchemyTableLiquidsGeo","textureLightingShader",true,PRIORITY_1,true,"alchTableLiquidsTexture","","","");

	renderer->setupGameObjectRenderable("alchTableGlass","alchemyTableGlasswareGeo","textureLightingShader",true,PRIORITY_1,true,"alchTableGlassTexture","","","");
	
	renderer->setupGameObjectRenderable("potL1","potionLargeGeo","textureLightingShader",true,PRIORITY_1,true,"potLTexture1","","","");

	renderer->setupGameObjectRenderable("potS1","potionSmallGeo","textureLightingShader",true,PRIORITY_1,true,"potSTexture1","","","");

	renderer->setupGameObjectRenderable("potT1","potionThinGeo","textureLightingShader",true,PRIORITY_1,true,"potTTexture1","","","");

	renderer->setupGameObjectRenderable("potW1","potionWideGeo","textureLightingShader",true,PRIORITY_1,true,"potWTexture1","","","");

	renderer->setupGameObjectRenderable("potV1","potionVialGeo","textureLightingShader",true,PRIORITY_1,true,"potVTexture1","","","");

	renderer->setupGameObjectRenderable("potV2","potionVialGeo","textureLightingShader",true,PRIORITY_1,true,"potVTexture1","","","");

	renderer->setupGameObjectRenderable("potV3","potionVialGeo","textureLightingShader",true,PRIORITY_1,true,"potVTexture1","","","");

	renderer->setupGameObjectRenderable("potV4","potionVialGeo","textureLightingShader",true,PRIORITY_1,true,"potVTexture1","","","");

	renderer->setupGameObjectRenderable("potV5","potionVialGeo","textureLightingShader",true,PRIORITY_1,true,"potVTexture1","","","");
}

int frame = 0;

bool heightUp = true;

float burnMax = 0.8f;
float burnMin = 0.1f;
float burnIncrement = 0.001f;
bool burnUp = true;

void MainWindow::update()
{
	renderer->getGameObject("alchRoomOuter")->yRotationAngle+= 0.4f;
	updateShaderInfo();
	frame++;
	renderer->getGameObject("lightBulb")->position = renderer->lightPosition;
	//renderer->lightPosition = renderer->getGameObject("lightBulb")->position;

	burnThreshold += (burnUp)? burnIncrement: -burnIncrement;
	if(burnThreshold >= burnMax)
	{
		burnThreshold = burnMax;
		burnUp = false;
	}
	if(burnThreshold <= burnMin)
	{
		burnThreshold = burnMin;
		burnUp = true;
	}
	heightScalar += (heightUp)? heightIncrement: -heightIncrement;
	if(heightScalar>=heightMax)
	{
		heightScalar = heightMax;
		heightUp = false;
	}
	if(heightScalar<=heightMin)
	{
		heightScalar = heightMin;
		heightUp = true;
	}
}

void MainWindow::updateShaderInfo()
{
	renderer->eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	renderer->updateShaderInfo(worldToProjectionMatrix);
	
	GeneralGLWindow::getInstance().repaint();
}
void MainWindow::keyPressEvent(QKeyEvent* e)
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
void MainWindow::mouseMoveReaction(QMouseEvent* e)
{
	if(!cameraFrozen)
	{
		camera.mouseUpdate(glm::vec2(e->x(), e->y()));
		update();
	}
}