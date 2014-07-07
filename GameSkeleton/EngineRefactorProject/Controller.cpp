#include "Controller.h"
#include "Camera.h"
#include "BinReader.h"


Camera camera;

/*----------General shader uniform variables----------*/
vec3 lightPosition = vec3(0.0f, 50.0f, -30.0f);

float diffusionIntensity = 1;
vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
float specularExponent = 10;
vec3 eyePosition ;
mat4 fullTransformMatrix;
vec3 overridingObjectColor = vec3(0.4f, 0.4f, 0.4f);
vec3 ambientLight = vec3(0.9f, 0.9f, 0.9f);
mat4 rotationMatrix = mat4();
mat4 modelToWorldMatrix;

/*----------Bright shader uniform variables----------*/
vec3 brightOverridingObjectColor = vec3(1.0f, 1.0f, 1.0f);
vec3 brightAmbientLight = vec3(1.0f, 0.9f, 0.9f);
float brightDiffusionIntensity = 1;
vec4 brightSpecularColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
float brightSpecularExponent = 1;

/*----------Dark shader uniform variables----------*/
vec3 darkOverridingObjectColor = vec3(0.5f, 0.5f, 0.5f);
vec3 darkAmbientLight = vec3(0.7f, 0.6f, 1.0f);
float darkDiffusionIntensity = 0.5f;
vec4 darkSpecularColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);
float darkSpecularExponent = 20;

/*----------Textures----------*/
TextureInfo* coloredStripes;
TextureInfo* brightGrass;
TextureInfo* brightMushroomTop;
TextureInfo* brightMushroomUnder;
TextureInfo* brightWall;
TextureInfo* darkBark;
TextureInfo* darkGround;
TextureInfo* singleColor;
TextureInfo* lava1;
TextureInfo* lava2;
TextureInfo* lava3;
TextureInfo* lava4;
TextureInfo* lava5;
TextureInfo* lava6;
TextureInfo* lava7;
TextureInfo* sky;

/*----------Geometries----------*/
GeometryInfo* sphere;
GeometryInfo* cube;
GeometryInfo* torus;
GeometryInfo* teapot;
GeometryInfo* arrow;
GeometryInfo* plane;
GeometryInfo* readInCube;
GeometryInfo* mushroom;
GeometryInfo* chair;
GeometryInfo* table;
GeometryInfo* metronome;
GeometryInfo* newSphere;

/*----------Shaders----------*/
ShaderInfo* lightingAndTextureShader;
ShaderInfo* passThroughShader;
ShaderInfo* justTextureShader;
ShaderInfo* justLightingShader;

/*----------Renderables & their transforms----------*/
RenderableInfo* readCubeRenderable;
	mat4 readCubeTransform;
	mat4 readCubeFullTransform;
	mat4 readCubeRotation = mat4();
RenderableInfo* ltSphere;
	mat4 ltSphereTransform;
	mat4 ltSphereFullTransform;
	mat4 ltSphereRotation = mat4();
RenderableInfo* rightPlane;
	mat4 rightPlaneTransform;
	mat4 rightPlaneFullTransform;
	mat4 rightPlaneRotation = mat4();
RenderableInfo* leftPlane;
	mat4 leftPlaneTransform;
	mat4 leftPlaneFullTransform;
	mat4 leftPlaneRotation = mat4();
RenderableInfo* lightBulb;
	mat4 lightBulbTransform;
	mat4 lightBulbFullTransform;
RenderableInfo* table1;
	mat4 table1Transform;
	mat4 table1FullTransform;
	mat4 table1Rotation = mat4();
RenderableInfo* tableMetronome;
	mat4 tableMetronomeTransform;
	mat4 tableMetronomeFullTransform;
	mat4 tableMetronomeRotation = mat4();
RenderableInfo* chair1;
	mat4 chair1Transform;
	mat4 chair1FullTransform;
	mat4 chair1Rotation = mat4();
RenderableInfo* chair2;
	mat4 chair2Transform;
	mat4 chair2FullTransform;
	mat4 chair2Rotation = mat4();
RenderableInfo* mushroom1;
	mat4 mushroom1FullTransform;
	mat4 mushroom1Transform;
	mat4 mushroom1Rotation = mat4();
RenderableInfo* tree1;
	mat4 tree1Transform;
	mat4 tree1FullTransform;
	mat4 tree1Rotation = mat4();
RenderableInfo* lavaCube;
	mat4 lavaCubeTransform;
	mat4 lavaCubeFullTransform;
	mat4 lavaCubeRotation = mat4();
RenderableInfo* lavaCube2;
	mat4 lavaCube2Transform;
	mat4 lavaCube2FullTransform;
	mat4 lavaCube2Rotation = mat4();
RenderableInfo* lavaCube3;
	mat4 lavaCube3Transform;
	mat4 lavaCube3FullTransform;
	mat4 lavaCube3Rotation = mat4();

RenderableInfo* skySphere;
	mat4 skySphereTransform;
	mat4 skySphereFullTransform;
	mat4 skySphereRotation = mat4();
void Controller::setup()
{
	DebugShapes::getInstance();
	setupGeometries();
	setupShaders();
	setupTransforms();
	setupTextures();
	setupRenderables();
	setupShaderUniforms();
	setupDebugShapes();
}
int frame = 0;
int lavaState = 1;
void Controller::myUpdate()
{
	if(frame%20==0)
	{
		switch(lavaState)
		{
		case 1: lavaCube->texture = lava1;
			lavaCube2->texture = lava2;
			lavaCube3->texture = lava3;
			break;
		case 2: lavaCube->texture = lava2;
			lavaCube2->texture = lava3;
			lavaCube3->texture = lava4;
			break;
		case 3: lavaCube->texture = lava3;
			lavaCube2->texture = lava4;
			lavaCube3->texture = lava5;
			break;
		case 4: lavaCube->texture = lava4;
			lavaCube2->texture = lava5;
			lavaCube3->texture = lava6;
			break;
		case 5: lavaCube->texture = lava5;
			lavaCube2->texture = lava6;
			lavaCube3->texture = lava7;
			break;
		case 6: lavaCube->texture = lava6;
			lavaCube2->texture = lava7;
			lavaCube3->texture = lava1;
			break;
		case 7: lavaCube->texture = lava7;
			lavaCube2->texture = lava1;
			lavaCube3->texture = lava2;
			lavaState = 0;
			break;
		}
		lavaState++;
	}
	frame++;
	GeneralGLWindow::getInstance().repaint();
}

/*----------Non Renderable-specific set ups----------*/

void Controller::setupGeometries()
{
	Neumont::ShapeData sphereData = Neumont::ShapeGenerator::makeSphere(10);
	sphere = GeneralGLWindow::getInstance().addGeometry(sphereData.verts, sphereData.vertexBufferSize(), sphereData.indices, sphereData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(sphere);

	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	cube = GeneralGLWindow::getInstance().addGeometry(cubeData.verts, cubeData.vertexBufferSize(), cubeData.indices, cubeData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(cube);

	Neumont::ShapeData torusData = Neumont::ShapeGenerator::makeTorus(10);
	torus = GeneralGLWindow::getInstance().addGeometry(torusData.verts, torusData.vertexBufferSize(), torusData.indices, torusData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(torus);

	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(2);
	plane = GeneralGLWindow::getInstance().addGeometry(planeData.verts, planeData.vertexBufferSize(), planeData.indices, planeData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(plane);

	Neumont::ShapeData teapotData = Neumont::ShapeGenerator::makeTeapot(10, mat4());
	teapot = GeneralGLWindow::getInstance().addGeometry(teapotData.verts, teapotData.vertexBufferSize(), teapotData.indices, teapotData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(teapot);

	Neumont::ShapeData arrowData = Neumont::ShapeGenerator::makeArrow();
	arrow = GeneralGLWindow::getInstance().addGeometry(arrowData.verts, arrowData.vertexBufferSize(), arrowData.indices, arrowData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(arrow);

	BinReader reader;

	BinReader::ShapeData mushroomData = reader.readInShape("../Resources/Models/mushroom1.bin");
	mushroom = GeneralGLWindow::getInstance().addGeometry(mushroomData.vertices, mushroomData.vertexDataSize, mushroomData.indices, mushroomData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(mushroom);

	BinReader::ShapeData chairData = reader.readInShape("../Resources/Models/chair1.bin");
	chair = GeneralGLWindow::getInstance().addGeometry(chairData.vertices, chairData.vertexDataSize, chairData.indices, chairData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(chair);

	BinReader::ShapeData tableData = reader.readInShape("../Resources/Models/table.bin");
	table = GeneralGLWindow::getInstance().addGeometry(tableData.vertices, tableData.vertexDataSize, tableData.indices, tableData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(table);

	BinReader::ShapeData metronomeData = reader.readInShape("../Resources/Models/metronome.bin");
	metronome = GeneralGLWindow::getInstance().addGeometry(metronomeData.vertices, metronomeData.vertexDataSize, metronomeData.indices, metronomeData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(metronome);

	BinReader::ShapeData newSphereData = reader.readInShape("../Resources/Models/sphere.bin");
	newSphere = GeneralGLWindow::getInstance().addGeometry(newSphereData.vertices, newSphereData.vertexDataSize, newSphereData.indices, newSphereData.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(newSphere);

	/*BinReader::ShapeData experimentCube = reader.readInShape("$(ProjectDir)..\Resources\Models\chair1.bin");
	readInCube = GeneralGLWindow::getInstance().addGeometry(experimentCube.vertices, experimentCube.vertexDataSize, experimentCube.indices, experimentCube.numIndices, GL_TRIANGLES);
	setupReadInGeometryVertexArrayInfo(readInCube);*/
}

void Controller::setupGeometryVertexArrayInfo(GeometryInfo* geometry)
{
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);
}


void Controller::setupReadInGeometryVertexArrayInfo(GeometryInfo* geometry)
{
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, ObjReader::POSITION_OFFSET, ObjReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, ObjReader::NORMAL_OFFSET, ObjReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 3, PT_VEC2, ObjReader::UV_OFFSET, ObjReader::STRIDE);
}


void Controller::setupShaders()
{
	lightingAndTextureShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/LightingAndTextureVertexShader.glsl", "../Resources/Shaders/LightingAndTextureFragmentShader.glsl");
	passThroughShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/PassThroughVertexShader.glsl", "../Resources/Shaders/PassThroughFragmentShader.glsl");
	justTextureShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/JustTextureVertexShader.glsl", "../Resources/Shaders/JustTextureFragmentShader.glsl");
	justLightingShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/JustLightingVertexShader.glsl", "../Resources/Shaders/JustLightingFragmentShader.glsl");
}

void Controller::setupTextures()
{
	coloredStripes = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/texturetestColors.bmp");
	brightGrass = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/brightGrassTexture.bmp");
	brightMushroomTop = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/brightMushroomTopTexture.bmp");
	brightMushroomUnder = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/brightMushroomUnderTexture.bmp");
	brightWall = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/brightWallTexture.bmp");
	darkBark = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/darkBarkTexture.bmp");
	darkGround = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/darkGroundTexture.bmp");
	singleColor = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/textureSingleColor.bmp");
	lava1 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/lava1Texture.bmp");
	lava2 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/lava2Texture.bmp");
	lava3 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/lava3Texture.bmp");
	lava4 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/lava4Texture.bmp");
	lava5 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/lava5Texture.bmp");
	lava6 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/lava6Texture.bmp");
	lava7 = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/lava7Texture.bmp");
	sky = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/skyTexture.bmp");
}

/*----------Renderable-specific set ups----------*/

void Controller::setupTransforms()
{
	leftPlaneTransform = glm::translate(vec3(0.0f, 0.0f, 5.0f));
	leftPlaneTransform *= glm::scale(vec3(60.0f, 1.0f, 60.0f));

	rightPlaneTransform = glm::translate(vec3(60.0f, 0.0f, 5.0f));
	rightPlaneTransform *= glm::scale(vec3(60.0f, 1.0f, 60.0f));

	lightBulbTransform = glm::translate(lightPosition);
	lightBulbTransform *= glm::scale(0.5f, 0.5f, 0.5f);

	table1Transform = glm::translate(vec3(0.0f, 1.1f, -3.0f));
	table1Transform *= glm::scale(vec3(2.0f, 2.0f, 1.5f));

	tableMetronomeTransform = glm::translate(vec3(-1.25f, 2.88f, -3.5f));
	tableMetronomeTransform *= glm::rotate(35.0f, vec3(0,1,0));
	tableMetronomeTransform *= glm::scale(vec3(0.5f, 0.5f, 0.5f));
	tableMetronomeRotation = glm::rotate(35.0f, vec3(0,1,0));

	chair1Transform = glm::translate(vec3(0.0f, 1.6f, -5.0f));
	chair1Transform *= glm::scale(vec3(2.0f, 2.5f, 2.0f));

	chair2Transform = glm::translate(vec3(0.0f, 1.6f, -1.0f));
	chair2Transform *= glm::rotate(180.0f, vec3(0,1,0));
	chair2Transform *= glm::scale(vec3(2.0f, 2.5f, 2.0f));
	chair2Rotation = glm::rotate(180.0f, vec3(0,1,0));

	mushroom1Transform = glm::translate(vec3(-20.0f, 10.0f, -25.0f));
	mushroom1Transform *= glm::scale(vec3(6.0f, 10.f, 6.0f));

	tree1Transform = glm::translate(vec3(10.0f, 6.0f, -8.0f));
	tree1Transform *= glm::scale(vec3(0.5f, 6.0f, 0.5f));

	lavaCubeTransform = glm::translate(vec3(60.0f, 20.0f, -20.0f));
	lavaCubeTransform *= glm::rotate(180.0f, vec3(0,0,1));
	lavaCubeTransform *= glm::scale(vec3(0.25f, 20.0f, 5.0f));
	lavaCubeRotation = glm::rotate(180.0f, vec3(0,0,1));

	lavaCube2Transform = glm::translate(vec3(45.0f, 0.25f, -20.0f));
	lavaCube2Transform *= glm::rotate(180.0f, vec3(0,0,1));
	lavaCube2Transform *= glm::scale(vec3(15.0f, 0.25f, 5.0f));
	lavaCube2Rotation = glm::rotate(180.0f, vec3(0,0,1));

	lavaCube3Transform = glm::translate(vec3(15.0f, 0.25f, -20.0f));
	lavaCube3Transform *= glm::rotate(180.0f, vec3(0,0,1));
	lavaCube3Transform *= glm::scale(vec3(15.0f, 0.25f, 5.0f));
	lavaCube3Rotation = glm::rotate(180.0f, vec3(0,0,1));
	
	//readCubeTransform = glm::translate(vec3(0.0f, 4.0f, -4.0f));
	skySphereTransform = glm::translate(vec3(0.0f, 0.0f, -30.0f));
	skySphereTransform *= glm::scale(vec3(80.0f, 70.0f, 65.0f));
}

void Controller::setupRenderables()
{
	leftPlane = GeneralGLWindow::getInstance().addRenderable(plane, leftPlaneTransform, lightingAndTextureShader, true, PRIORITY_1, true, brightGrass);
	rightPlane = GeneralGLWindow::getInstance().addRenderable(plane, rightPlaneTransform, lightingAndTextureShader,true, PRIORITY_1, true, darkGround);
	lightBulb = GeneralGLWindow::getInstance().addRenderable(sphere, lightBulbTransform, justTextureShader, true, PRIORITY_1, true, singleColor);
	
	table1 = GeneralGLWindow::getInstance().addRenderable(table, table1Transform, justLightingShader, true, PRIORITY_1);
	tableMetronome = GeneralGLWindow::getInstance().addRenderable(metronome, tableMetronomeTransform, justLightingShader, true, PRIORITY_1);
	
	chair1 = GeneralGLWindow::getInstance().addRenderable(chair, chair1Transform, justLightingShader, true, PRIORITY_1);
	chair2 = GeneralGLWindow::getInstance().addRenderable(chair, chair2Transform, justLightingShader, true, PRIORITY_1);
	
	mushroom1 = GeneralGLWindow::getInstance().addRenderable(mushroom, mushroom1Transform, lightingAndTextureShader, true, PRIORITY_1, true, brightWall);
	tree1 = GeneralGLWindow::getInstance().addRenderable(cube, tree1Transform, lightingAndTextureShader, true, PRIORITY_1, true, darkBark);
	lavaCube = GeneralGLWindow::getInstance().addRenderable(cube, lavaCubeTransform, lightingAndTextureShader, true, PRIORITY_1, true, lava1);
	lavaCube2 = GeneralGLWindow::getInstance().addRenderable(cube, lavaCube2Transform, lightingAndTextureShader, true, PRIORITY_1, true, lava2);
	lavaCube3 = GeneralGLWindow::getInstance().addRenderable(cube, lavaCube3Transform, lightingAndTextureShader, true, PRIORITY_1, true, lava3);

	skySphere = GeneralGLWindow::getInstance().addRenderable(newSphere, skySphereTransform, justTextureShader, true, PRIORITY_1, true, sky);
	//readCubeRenderable = GeneralGLWindow::getInstance().addRenderable(readInCube, readCubeTransform, lightingAndTextureShader, brightWall);
}

void Controller::setupShaderUniforms()
{
	eyePosition = camera.getPosition();
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 100.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	leftPlaneFullTransform = worldToProjectionMatrix * leftPlaneTransform;
	addBrightLightingAndTextureShaderUniforms(leftPlane, &leftPlaneFullTransform[0][0], &leftPlaneRotation[0][0]);

	rightPlaneFullTransform = worldToProjectionMatrix * rightPlaneTransform;
	addDarkLightingAndTextureShaderUniforms(rightPlane, &rightPlaneFullTransform[0][0], &rightPlaneRotation[0][0]);

	lightBulbFullTransform = worldToProjectionMatrix * lightBulbTransform;
	addJustTextureShaderUniforms(lightBulb, &lightBulbFullTransform[0][0]);

	table1FullTransform = worldToProjectionMatrix * table1Transform;
	addJustLightingShaderUniforms(table1, &table1FullTransform[0][0], &table1Rotation[0][0]);

	tableMetronomeFullTransform = worldToProjectionMatrix * tableMetronomeTransform;
	addJustLightingShaderUniforms(tableMetronome, &tableMetronomeFullTransform[0][0], &tableMetronomeRotation[0][0]);

	chair1FullTransform = worldToProjectionMatrix * chair1Transform;
	addJustLightingShaderUniforms(chair1, &chair1FullTransform[0][0], &chair1Rotation[0][0]);

	chair2FullTransform = worldToProjectionMatrix * chair2Transform;
	addJustLightingShaderUniforms(chair2, &chair2FullTransform[0][0], &chair2Rotation[0][0]);

	mushroom1FullTransform = worldToProjectionMatrix * mushroom1Transform;
	addBrightLightingAndTextureShaderUniforms(mushroom1, &mushroom1FullTransform[0][0], &mushroom1Rotation[0][0]);

	tree1FullTransform = worldToProjectionMatrix * tree1Transform;
	addDarkLightingAndTextureShaderUniforms(tree1, &tree1FullTransform[0][0], &tree1Rotation[0][0]);

	lavaCubeFullTransform = worldToProjectionMatrix * lavaCubeTransform;
	addDarkLightingAndTextureShaderUniforms(lavaCube, &lavaCubeFullTransform[0][0], &lavaCubeRotation[0][0]);

	lavaCube2FullTransform = worldToProjectionMatrix * lavaCube2Transform;
	addDarkLightingAndTextureShaderUniforms(lavaCube2, &lavaCube2FullTransform[0][0], &lavaCube2Rotation[0][0]);

	lavaCube3FullTransform = worldToProjectionMatrix * lavaCube3Transform;
	addDarkLightingAndTextureShaderUniforms(lavaCube3, &lavaCube3FullTransform[0][0], &lavaCube3Rotation[0][0]);

	skySphereFullTransform = worldToProjectionMatrix * skySphereTransform;
	addJustTextureShaderUniforms(skySphere, &skySphereFullTransform[0][0]);
	/*readCubeFullTransform = worldToProjectionMatrix * readCubeTransform;
	addLightingAndTextureShaderUniforms(readCubeRenderable, &readCubeFullTransform[0][0], &readCubeRotation[0][0]);*/
}

void Controller::updateShaderUniforms()
{
	
	eyePosition = camera.getPosition();
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 100.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	leftPlaneFullTransform = worldToProjectionMatrix * leftPlaneTransform;
	rightPlaneFullTransform = worldToProjectionMatrix * rightPlaneTransform;
	lightBulbFullTransform = worldToProjectionMatrix * lightBulbTransform;//if don't update fulltransform down here - shape will follow camera <stick>
	table1FullTransform = worldToProjectionMatrix * table1Transform;
	tableMetronomeFullTransform = worldToProjectionMatrix * tableMetronomeTransform;
	chair1FullTransform = worldToProjectionMatrix * chair1Transform;
	chair2FullTransform = worldToProjectionMatrix * chair2Transform;

	mushroom1FullTransform = worldToProjectionMatrix * mushroom1Transform;

	tree1FullTransform = worldToProjectionMatrix * tree1Transform;
	lavaCubeFullTransform = worldToProjectionMatrix * lavaCubeTransform;
	lavaCube2FullTransform = worldToProjectionMatrix * lavaCube2Transform;
	lavaCube3FullTransform = worldToProjectionMatrix * lavaCube3Transform;
	readCubeFullTransform = worldToProjectionMatrix * readCubeTransform;

	skySphereFullTransform = worldToProjectionMatrix * skySphereTransform;

}

void Controller::addPassThroughShaderUniforms(RenderableInfo* renderable, float* fullTransform)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
}

void Controller::addJustTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
}

void Controller::addJustLightingShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
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

void Controller::addLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
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

void Controller::addBrightLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &brightDiffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &brightSpecularColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &brightSpecularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &brightOverridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &brightAmbientLight[0]);

	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, rotationMatrix);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}

void Controller::addDarkLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &darkDiffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &darkSpecularColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &darkSpecularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &darkOverridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &darkAmbientLight[0]);

	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, rotationMatrix);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}

void Controller::setupDebugShapes()
{
	mat4 cubeTransform = glm::translate(-2.0f, 3.0f, -3.0f) * glm::scale(vec3(0.25f, 0.25f, 0.25f));
	DebugShapes::addCube(cubeTransform, vec3(5,0,4), true, 5);

	mat4 sphereTransform = glm::translate(2.0f, 3.0f, -3.0f) * glm::scale(vec3(0.25f, 0.25f, 0.25f));
	DebugShapes::addSphere(sphereTransform, vec3(0,0,1), true, 10);

	DebugShapes::addLine(vec3(-1.0f,3.0f,-2.5f), vec3(1.0f,3.0f,-2.5f), vec3(1,1,0), true, 15);

	DebugShapes::addPoint(vec3(0,3,-3), true, 20);

	DebugShapes::addVector(vec3(0, 2.5, -2.5), vec3(1, 1, 1), vec3(0.5f, 0.5f, 0.5f), true, 25);


	mat4 sphereTransform1 = glm::translate(0.0f, 3.0f, -5.0f) * glm::scale(vec3(0.25f, 0.25f, 0.25f));
	DebugShapes::addSphere(sphereTransform1, vec3(0,1,0), false, 200);

}

void Controller::keyPressReaction(QKeyEvent* e)
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
	updateShaderUniforms();

	GeneralGLWindow::getInstance().repaint();
}

void Controller::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	updateShaderUniforms();
	GeneralGLWindow::getInstance().repaint();
}