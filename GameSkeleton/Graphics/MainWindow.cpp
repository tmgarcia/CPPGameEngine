#include "MainWindow.h"
#include "DebugMenu\DebugMenu.h"
#include "BinReader.h"

#pragma region Variables
#pragma region GeometryInfos
GeometryInfo* cube;
GeometryInfo* plane;
GeometryInfo* alchemyTableGeo;
GeometryInfo* alchemyTableAperturesGeo;
GeometryInfo* alchemyTableGlasswareGeo;
GeometryInfo* alchemyTableLiquidsGeo;
GeometryInfo* potionLargeGeo;
GeometryInfo* potionSmallGeo;
GeometryInfo* potionThinGeo;
GeometryInfo* potionWideGeo;
GeometryInfo* potionVialGeo;
GeometryInfo* alchemyRoomGeo;
GeometryInfo* alchemyRoomOuterGeo;
#pragma endregion

ShaderInfo* lightingTextureAlphaNormalShader;
ShaderInfo* passThroughShader;

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

vec3 lightPosition = vec3(1.2f,6.2f,16.5f);
float diffusionIntensity = 0.5f;
vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
float specularExponent = 10;
vec3 overridingObjectColor = vec3(0.9f,0.9f,0.9f);
vec3 ambientLight = vec3(0.4f, 0.4f, 0.4f);
vec3 eyePosition;


#pragma region Objects
MainWindow::GameObject* alchRoom;
MainWindow::GameObject* alchRoomOuter;
MainWindow::GameObject* alchTable;
MainWindow::GameObject* alchTableGlass;
MainWindow::GameObject* alchTableMetal;
MainWindow::GameObject* alchTableLiquids;
MainWindow::GameObject* potL1;
MainWindow::GameObject* potS1;
MainWindow::GameObject* potT1;
MainWindow::GameObject* potW1;
MainWindow::GameObject* potV1;
MainWindow::GameObject* potV2;
MainWindow::GameObject* potV3;
MainWindow::GameObject* potV4;
MainWindow::GameObject* potV5;
MainWindow::GameObject* normalPlane;

MainWindow::GameObject* lightBulb;
#pragma endregion

mat4 cube1ModelToWorld;
mat4 cube1FullTransform;

#pragma region TextureInfos
TextureInfo* testTexture1;
TextureInfo* alchRoomTexture;
TextureInfo* alchRoomOuterTexture;
TextureInfo* alchTableTexture;
TextureInfo* alchTableGlassTexture;
TextureInfo* alchTableMetalTexture;
TextureInfo* alchTableLiquidsTexture;
TextureInfo* potLTexture1;
TextureInfo* potSTexture1;
TextureInfo* potTTexture1;
TextureInfo* potWTexture1;
TextureInfo* potVTexture1;

#pragma endregion
NormalMapInfo* testNormal;

#pragma endregion

void MainWindow::setup()
{
	camera.setPosition(vec3(0,5,20.0f));
	camera.setViewDirection(vec3(0,0.0f,-1));

	/*Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	cube = GeneralGLWindow::getInstance().addGeometry(cubeData.verts, cubeData.vertexBufferSize(), cubeData.indices, cubeData.numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);*/

	setupGeometry();

	setupTransforms();

	lightingTextureAlphaNormalShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/LightingTextureAlphaNormalVertexShader.glsl", "../Resources/Shaders/LightingTextureAlphaNormalFragmentShader.glsl");
	passThroughShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl");

	//cube1ModelToWorld = glm::translate(vec3(0.5f,0,0.5f));

	setupTextures();

	setupRenderables();

	dMenu->addFloatSlider("Lighting", &diffusionIntensity, 0,1.5f, "Diffusion intensity");
	dMenu->addFloatSlider("Lighting", &specularExponent, 0,50, "Specular Exponent");

	//cube1FullTransform = worldToProjectionMatrix * cube1ModelToWorld;

	//GeneralGLWindow::getInstance().addRenderableUniformParameter(cube1, "fullTransformMatrix", PT_MAT4, &cube1FullTransform[0][0]);
}

void MainWindow::setupGeometry()
{
	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	cube = GeneralGLWindow::getInstance().addGeometry(cubeData.verts, cubeData.vertexBufferSize(), cubeData.indices, cubeData.numIndices, GL_TRIANGLES);
	setupNuGeometryVertexArrayInfo(cube);

	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(2);
	plane = GeneralGLWindow::getInstance().addGeometry(planeData.verts, planeData.vertexBufferSize(), planeData.indices, planeData.numIndices, GL_TRIANGLES);
	setupNuGeometryVertexArrayInfo(plane);

	BinReader reader;

	BinReader::ShapeData alchemyRoomData = reader.readInShape("../Resources/Models/alchemyRoom.bin");
	alchemyRoomGeo = GeneralGLWindow::getInstance().addGeometry(alchemyRoomData.vertices, alchemyRoomData.vertexDataSize, alchemyRoomData.indices, alchemyRoomData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(alchemyRoomGeo);

	BinReader::ShapeData alchemyRoomOuterData = reader.readInShape("../Resources/Models/alchemyRoomOuter.bin");
	alchemyRoomOuterGeo = GeneralGLWindow::getInstance().addGeometry(alchemyRoomOuterData.vertices, alchemyRoomOuterData.vertexDataSize, alchemyRoomOuterData.indices, alchemyRoomOuterData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(alchemyRoomOuterGeo);

	BinReader::ShapeData alchemyTableData = reader.readInShape("../Resources/Models/alchemyTable.bin");
	alchemyTableGeo = GeneralGLWindow::getInstance().addGeometry(alchemyTableData.vertices, alchemyTableData.vertexDataSize, alchemyTableData.indices, alchemyTableData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(alchemyTableGeo);

	BinReader::ShapeData alchemyTableAperturesData = reader.readInShape("../Resources/Models/alchemyTableApertures.bin");
	alchemyTableAperturesGeo = GeneralGLWindow::getInstance().addGeometry(alchemyTableAperturesData.vertices, alchemyTableAperturesData.vertexDataSize, alchemyTableAperturesData.indices, alchemyTableAperturesData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(alchemyTableAperturesGeo);

	BinReader::ShapeData alchemyTableGlasswareData = reader.readInShape("../Resources/Models/alchemyTableGlassware.bin");
	alchemyTableGlasswareGeo = GeneralGLWindow::getInstance().addGeometry(alchemyTableGlasswareData.vertices, alchemyTableGlasswareData.vertexDataSize, alchemyTableGlasswareData.indices, alchemyTableGlasswareData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(alchemyTableGlasswareGeo);

	BinReader::ShapeData alchemyTableLiquidsData = reader.readInShape("../Resources/Models/alchemyTableLiquids.bin");
	alchemyTableLiquidsGeo = GeneralGLWindow::getInstance().addGeometry(alchemyTableLiquidsData.vertices, alchemyTableLiquidsData.vertexDataSize, alchemyTableLiquidsData.indices, alchemyTableLiquidsData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(alchemyTableLiquidsGeo);

	BinReader::ShapeData potionLargeData = reader.readInShape("../Resources/Models/potionLarge.bin");
	potionLargeGeo = GeneralGLWindow::getInstance().addGeometry(potionLargeData.vertices, potionLargeData.vertexDataSize, potionLargeData.indices, potionLargeData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(potionLargeGeo);

	BinReader::ShapeData potionSmallData = reader.readInShape("../Resources/Models/potionSmall.bin");
	potionSmallGeo = GeneralGLWindow::getInstance().addGeometry(potionSmallData.vertices, potionSmallData.vertexDataSize, potionSmallData.indices, potionSmallData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(potionSmallGeo);

	BinReader::ShapeData potionThinData = reader.readInShape("../Resources/Models/potionThin.bin");
	potionThinGeo = GeneralGLWindow::getInstance().addGeometry(potionThinData.vertices, potionThinData.vertexDataSize, potionThinData.indices, potionThinData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(potionThinGeo);

	BinReader::ShapeData potionWideData = reader.readInShape("../Resources/Models/potionWide.bin");
	potionWideGeo = GeneralGLWindow::getInstance().addGeometry(potionWideData.vertices, potionWideData.vertexDataSize, potionWideData.indices, potionWideData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(potionWideGeo);

	BinReader::ShapeData potionVialData = reader.readInShape("../Resources/Models/potionVial.bin");
	potionVialGeo = GeneralGLWindow::getInstance().addGeometry(potionVialData.vertices, potionVialData.vertexDataSize, potionVialData.indices, potionVialData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(potionVialGeo);
}

vec3 noScale = vec3(1,1,1);
void MainWindow::setupTransforms()
{
	eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	lightBulb = new GameObject();
	lightBulb->setupTransforms(0, vec3(0,1,0),lightPosition, vec3(0.25f, 0.25f, 0.25f), worldToProjectionMatrix);
	dMenu->addVec3Slider("Lighting", &lightBulb->position, -10,10,0,30,-20,20,"Light position");

	normalPlane = new GameObject();
	normalPlane->setupTransforms(90, vec3(1,0,0),vec3(0,4,15),noScale,worldToProjectionMatrix);

	alchRoom = new GameObject();
	alchRoom->setupTransforms(0,vec3(0,1,0),vec3(0,0,0),noScale,worldToProjectionMatrix);

	alchRoomOuter = new GameObject();
	alchRoomOuter->setupTransforms(0,vec3(0,1,0),vec3(0,0,8),noScale,worldToProjectionMatrix);

	alchTable = new GameObject();
	alchTable->setupTransforms(0,vec3(0,1,0),vec3(0,0,0),noScale,worldToProjectionMatrix);

	alchTableGlass = new GameObject();
	alchTableGlass->setupTransforms(0,vec3(0,1,0),vec3(0,0,0),noScale,worldToProjectionMatrix);

	alchTableMetal = new GameObject();
	alchTableMetal->setupTransforms(0,vec3(0,1,0),vec3(0,0,0),noScale,worldToProjectionMatrix);

	alchTableLiquids = new GameObject();
	alchTableLiquids->setupTransforms(0,vec3(0,1,0),vec3(0,0,0),noScale,worldToProjectionMatrix);

	potL1 = new GameObject();
	potL1->setupTransforms(0,vec3(0,1,0),vec3(-1.1f,3.8f, -2.5f),noScale,worldToProjectionMatrix);
	
	potS1 = new GameObject();
	potS1->setupTransforms(0,vec3(0,1,0),vec3(-2.5f,4.6f, -2.8f),noScale,worldToProjectionMatrix);

	potT1 = new GameObject();
	potT1->setupTransforms(0,vec3(0,1,0),vec3(-3.6f,4.5f, -1.9f),noScale,worldToProjectionMatrix);

	potW1 = new GameObject();
	potW1->setupTransforms(180,vec3(0,1,0),vec3(-1.9f,3.8f, -1.5f),noScale,worldToProjectionMatrix);

	potV1 = new GameObject();
	potV1->setupTransforms(96.5f,vec3(0.5f,1,-1),vec3(-2.6f,3.8f,0.2f),noScale,worldToProjectionMatrix);
	potV2 = new GameObject();
	potV2->setupTransforms(79.7f,vec3(-0.3f,0.6f,0.1f),vec3(-3.5f,3.8f,-0.2f),noScale,worldToProjectionMatrix);
	potV3 = new GameObject();
	potV3->setupTransforms(256.9f,vec3(0.6f,1,-1),vec3(-3.1f,3.8f,0.5f),noScale,worldToProjectionMatrix);
	potV4 = new GameObject();
	potV4->setupTransforms(88.1f,vec3(-0.3f,1,0.4f),vec3(-3.4f,3.8f,-0.6f),noScale,worldToProjectionMatrix);
	potV5 = new GameObject();
	potV5->setupTransforms(99,vec3(-0.9f,1,-1),vec3(-3,3.8f,-0.2f),noScale,worldToProjectionMatrix);

	//dMenu->addVec3Slider("tab1", &potionL1Angle, -10,10,-10,10,-10,10,"Large");
	//dMenu->addFloatSlider("tab1", &potionL1Angle,0,360,"Large");
	/*dMenu->addVec3Slider("V1", &potV1->position, -5,5,-5,5,-5,5,"Pos");
	dMenu->addVec3Slider("V1", &potV1->rotateAxis, -1,1,-1,1,-1,1,"Angle Axis");
	dMenu->addFloatSlider("V1", &potV1->angle,0,360,"Angle");
	dMenu->addVec3Slider("V2", &potV2->position, -5,5,-5,5,-5,5,"Pos");
	dMenu->addVec3Slider("V2", &potV2->rotateAxis, -1,1,-1,1,-1,1,"Angle Axis");
	dMenu->addFloatSlider("V2", &potV2->angle,0,360,"Angle");
	dMenu->addVec3Slider("V3", &potV3->position, -5,5,-5,5,-5,5,"Pos");
	dMenu->addVec3Slider("V3", &potV3->rotateAxis, -1,1,-1,1,-1,1,"Angle Axis");
	dMenu->addFloatSlider("V3", &potV3->angle,0,360,"Angle");
	dMenu->addVec3Slider("V4", &potV4->position, -5,5,-5,5,-5,5,"Pos");
	dMenu->addVec3Slider("V4", &potV4->rotateAxis, -1,1,-1,1,-1,1,"Angle Axis");
	dMenu->addFloatSlider("V4", &potV4->angle,0,360,"Angle");
	dMenu->addVec3Slider("V5", &potV5->position, -5,5,-5,5,-5,5,"Pos");
	dMenu->addVec3Slider("V5", &potV5->rotateAxis, -1,1,-1,1,-1,1,"Angle Axis");
	dMenu->addFloatSlider("V5", &potV5->angle,0,360,"Angle");*/
}

void MainWindow::setupReadInGeometryVertexArrayInfo(GeometryInfo* geometry)
{
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, BinReader::POSITION_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, BinReader::NORMAL_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 3, PT_VEC2, BinReader::UV_OFFSET, BinReader::STRIDE);
}

void MainWindow::setupNuGeometryVertexArrayInfo(GeometryInfo* geometry)
{
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);
}

void MainWindow::setupTextures()
{
	//testTexture1 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/alchemyTableTexture.png");
	testNormal = GeneralGLWindow::getInstance().addNormalMap("../Resources/NormalMaps/Shapes.png");
	alchRoomTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/alchemyRoomTexture.png");
	alchRoomOuterTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/alchemyRoomOuterTexture.png");
	alchTableTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/alchemyTableTexture.png");
	alchTableGlassTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/glassTexture.png");
	alchTableMetalTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/metalBitsTexture.png");
	alchTableLiquidsTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/liquidsTexture.png");
	potLTexture1 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/potionLargeTexture1.png");
	potSTexture1 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/potionSmallTexture1.png");
	potTTexture1 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/potionThinTexture1.png");
	potWTexture1 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/potionWideTexture1.png");
	potVTexture1 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/potionSkoomaTexture1.png");
}

void MainWindow::setupRenderables()
{
	//normalCube = GeneralGLWindow::getInstance().addRenderable(cube, cube1ModelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, testTexture1);
	lightBulb->renderable = GeneralGLWindow::getInstance().addRenderable(cube, lightBulb->modelToWorld, passThroughShader, true, PRIORITY_1, true, NULL, NULL, NULL);
	addLightingAndTextureShaderUniforms(lightBulb->renderable, &lightBulb->fullTransform[0][0], &lightBulb->rotation[0][0]);

	normalPlane->renderable = GeneralGLWindow::getInstance().addRenderable(plane, normalPlane->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, NULL, NULL, testNormal);
	addLightingAndTextureShaderUniforms(normalPlane->renderable, &normalPlane->fullTransform[0][0], &normalPlane->rotation[0][0]);

	alchRoomOuter->renderable = GeneralGLWindow::getInstance().addRenderable(alchemyRoomOuterGeo, alchRoomOuter->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, alchRoomOuterTexture);
	addLightingAndTextureShaderUniforms(alchRoomOuter->renderable, &alchRoomOuter->fullTransform[0][0], &alchRoomOuter->rotation[0][0]);

	alchRoom->renderable = GeneralGLWindow::getInstance().addRenderable(alchemyRoomGeo, alchRoom->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, alchRoomTexture);
	addLightingAndTextureShaderUniforms(alchRoom->renderable, &alchRoom->fullTransform[0][0], &alchRoom->rotation[0][0]);

	alchTable->renderable = GeneralGLWindow::getInstance().addRenderable(alchemyTableGeo, alchTable->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, alchTableTexture);
	addLightingAndTextureShaderUniforms(alchTable->renderable, &alchTable->fullTransform[0][0], &alchTable->rotation[0][0]);
		
	alchTableMetal->renderable = GeneralGLWindow::getInstance().addRenderable(alchemyTableAperturesGeo, alchTableMetal->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, alchTableMetalTexture);
	addLightingAndTextureShaderUniforms(alchTableMetal->renderable, &alchTableMetal->fullTransform[0][0], &alchTableMetal->rotation[0][0]);

	alchTableLiquids->renderable = GeneralGLWindow::getInstance().addRenderable(alchemyTableLiquidsGeo, alchTableLiquids->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, alchTableLiquidsTexture);
	addLightingAndTextureShaderUniforms(alchTableLiquids->renderable, &alchTableLiquids->fullTransform[0][0], &alchTableLiquids->rotation[0][0]);

	alchTableGlass->renderable = GeneralGLWindow::getInstance().addRenderable(alchemyTableGlasswareGeo, alchTableGlass->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, alchTableGlassTexture);
	addLightingAndTextureShaderUniforms(alchTableGlass->renderable, &alchTableGlass->fullTransform[0][0], &alchTableGlass->rotation[0][0]);
	
	potL1->renderable = GeneralGLWindow::getInstance().addRenderable(potionLargeGeo, potL1->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potLTexture1);
	addLightingAndTextureShaderUniforms(potL1->renderable, &potL1->fullTransform[0][0], &potL1->rotation[0][0]);

	potS1->renderable = GeneralGLWindow::getInstance().addRenderable(potionSmallGeo, potS1->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potSTexture1);
	addLightingAndTextureShaderUniforms(potS1->renderable, &potS1->fullTransform[0][0], &potS1->rotation[0][0]);

	potT1->renderable = GeneralGLWindow::getInstance().addRenderable(potionThinGeo, potT1->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potTTexture1);
	addLightingAndTextureShaderUniforms(potT1->renderable, &potT1->fullTransform[0][0], &potT1->rotation[0][0]);

	potW1->renderable = GeneralGLWindow::getInstance().addRenderable(potionWideGeo, potW1->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potWTexture1);
	addLightingAndTextureShaderUniforms(potW1->renderable, &potW1->fullTransform[0][0], &potW1->rotation[0][0]);

	potV1->renderable = GeneralGLWindow::getInstance().addRenderable(potionVialGeo, potV1->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potVTexture1);
	addLightingAndTextureShaderUniforms(potV1->renderable, &potV1->fullTransform[0][0], &potV1->rotation[0][0]);

	potV2->renderable = GeneralGLWindow::getInstance().addRenderable(potionVialGeo, potV2->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potVTexture1);
	addLightingAndTextureShaderUniforms(potV2->renderable, &potV2->fullTransform[0][0], &potV2->rotation[0][0]);

	potV3->renderable = GeneralGLWindow::getInstance().addRenderable(potionVialGeo, potV3->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potVTexture1);
	addLightingAndTextureShaderUniforms(potV3->renderable, &potV3->fullTransform[0][0], &potV3->rotation[0][0]);

	potV4->renderable = GeneralGLWindow::getInstance().addRenderable(potionVialGeo, potV4->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potVTexture1);
	addLightingAndTextureShaderUniforms(potV4->renderable, &potV4->fullTransform[0][0], &potV4->rotation[0][0]);

	potV5->renderable = GeneralGLWindow::getInstance().addRenderable(potionVialGeo, potV5->modelToWorld, lightingTextureAlphaNormalShader, true, PRIORITY_1, true, potVTexture1);
	addLightingAndTextureShaderUniforms(potV5->renderable, &potV5->fullTransform[0][0], &potV5->rotation[0][0]);

}

void MainWindow::addLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
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
void MainWindow::update()
{
	alchRoomOuter->angle+= 0.4f;
	updateShaderInfo();
	frame++;
	lightPosition = lightBulb->position;
}

void MainWindow::updateShaderInfo()
{
	eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	lightBulb->updateTransforms(worldToProjectionMatrix);
	normalPlane->updateTransforms(worldToProjectionMatrix);

	alchRoom->updateTransforms(worldToProjectionMatrix);
	alchRoomOuter->updateTransforms(worldToProjectionMatrix);
	alchTable->updateTransforms(worldToProjectionMatrix);
	alchTableGlass->updateTransforms(worldToProjectionMatrix);
	alchTableMetal->updateTransforms(worldToProjectionMatrix);
	alchTableLiquids->updateTransforms(worldToProjectionMatrix);

	potL1->updateTransforms(worldToProjectionMatrix);
	potS1->updateTransforms(worldToProjectionMatrix);
	potT1->updateTransforms(worldToProjectionMatrix);
	potW1->updateTransforms(worldToProjectionMatrix);
	potV1->updateTransforms(worldToProjectionMatrix);
	potV2->updateTransforms(worldToProjectionMatrix);
	potV3->updateTransforms(worldToProjectionMatrix);
	potV4->updateTransforms(worldToProjectionMatrix);
	potV5->updateTransforms(worldToProjectionMatrix);
	
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