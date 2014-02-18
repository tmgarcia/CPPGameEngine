#include "ClientGLWindow.h"
#include "Camera.h"


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

/*----------Geometries----------*/
GeometryInfo* sphere;
GeometryInfo* cube;
GeometryInfo* torus;
GeometryInfo* teapot;
GeometryInfo* arrow;
GeometryInfo* plane;

/*----------Shaders----------*/
ShaderInfo* lightingAndTextureShader;
ShaderInfo* passThroughShader;
ShaderInfo* justTextureShader;
ShaderInfo* justLightingShader;

/*----------Renderables & their transforms----------*/
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
RenderableInfo* tableTop;
	mat4 tableTopTransform;
	mat4 tableTopFullTransform;
	mat4 tableTopRotation = mat4();
RenderableInfo* tableSupport;
	mat4 tableSupportTransform;
	mat4 tableSupportFullTransform;
	mat4 tableSupportRotation = mat4();
RenderableInfo* tableBase;
	mat4 tableBaseTransform;
	mat4 tableBaseFullTransform;
	mat4 tableBaseRotation = mat4();
RenderableInfo* tableTeapot;
	mat4 tableTeapotTransform;
	mat4 tableTeapotFullTransform;
	mat4 tableTeapotRotation = mat4();
RenderableInfo* tableMetronome;
	mat4 tableMetronomeTransform;
	mat4 tableMetronomeFullTransform;
	mat4 tableMetronomeRotation = mat4();
RenderableInfo* tableMetronomeArrow;
	mat4 tableMetronomeArrowTransform;
	mat4 tableMetronomeArrowFullTransform;
	mat4 tableMetronomeArrowRotation = mat4();
RenderableInfo* mushroom1Base;
	mat4 mushroom1BaseTransform;
	mat4 mushroom1BaseFullTransform;
	mat4 mushroom1BaseRotation = mat4();
RenderableInfo* mushroom1Under;
	mat4 mushroom1UnderTransform;
	mat4 mushroom1UnderFullTransform;
	mat4 mushroom1UnderRotation = mat4();
RenderableInfo* mushroom1Top;
	mat4 mushroom1TopTransform;
	mat4 mushroom1TopFullTransform;
	mat4 mushroom1TopRotation = mat4();
RenderableInfo* mushroom2Base;
	mat4 mushroom2BaseTransform;
	mat4 mushroom2BaseFullTransform;
	mat4 mushroom2BaseRotation = mat4();
RenderableInfo* mushroom2Under;
	mat4 mushroom2UnderTransform;
	mat4 mushroom2UnderFullTransform;
	mat4 mushroom2UnderRotation = mat4();
RenderableInfo* mushroom2Top;
	mat4 mushroom2TopTransform;
	mat4 mushroom2TopFullTransform;
	mat4 mushroom2TopRotation = mat4();
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
void ClientGLWindow::setup()
{
	setupGeometries();
	setupShaders();
	setupTransforms();
	setupTextures();
	setupRenderables();
	setupShaderUniforms();
}
int frame = 0;
int lavaState = 1;
void ClientGLWindow::myUpdate()
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
	meWindow.repaint();
}

/*----------Non Renderable-specific set ups----------*/

void ClientGLWindow::setupGeometries()
{
	Neumont::ShapeData sphereData = Neumont::ShapeGenerator::makeSphere(10);
	sphere = meWindow.addGeometry(sphereData.verts, sphereData.vertexBufferSize(), sphereData.indices, sphereData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(sphere);

	Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
	cube = meWindow.addGeometry(cubeData.verts, cubeData.vertexBufferSize(), cubeData.indices, cubeData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(cube);

	Neumont::ShapeData torusData = Neumont::ShapeGenerator::makeTorus(10);
	torus = meWindow.addGeometry(torusData.verts, torusData.vertexBufferSize(), torusData.indices, torusData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(torus);

	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(2);
	plane = meWindow.addGeometry(planeData.verts, planeData.vertexBufferSize(), planeData.indices, planeData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(plane);

	Neumont::ShapeData teapotData = Neumont::ShapeGenerator::makeTeapot(10, mat4());
	teapot = meWindow.addGeometry(teapotData.verts, teapotData.vertexBufferSize(), teapotData.indices, teapotData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(teapot);

	Neumont::ShapeData arrowData = Neumont::ShapeGenerator::makeArrow();
	arrow = meWindow.addGeometry(arrowData.verts, arrowData.vertexBufferSize(), arrowData.indices, arrowData.numIndices, GL_TRIANGLES);
	setupGeometryVertexArrayInfo(arrow);

}

void ClientGLWindow::setupGeometryVertexArrayInfo(GeometryInfo* geometry)
{
	meWindow.addShaderStreamedParameter(geometry, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	meWindow.addShaderStreamedParameter(geometry, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	meWindow.addShaderStreamedParameter(geometry, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	meWindow.addShaderStreamedParameter(geometry, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);
}

void ClientGLWindow::setupShaders()
{
	lightingAndTextureShader = meWindow.createShaderInfo("LightingAndTextureVertexShader.glsl", "LightingAndTextureFragmentShader.glsl");
	passThroughShader = meWindow.createShaderInfo("PassThroughVertexShader.glsl", "PassThroughFragmentShader.glsl");
	justTextureShader = meWindow.createShaderInfo("JustTextureVertexShader.glsl", "JustTextureFragmentShader.glsl");
	justLightingShader = meWindow.createShaderInfo("JustLightingVertexShader.glsl", "JustLightingFragmentShader.glsl");
}

void ClientGLWindow::setupTextures()
{
	coloredStripes = meWindow.addTexture("texturetestColors.bmp");
	brightGrass = meWindow.addTexture("brightGrassTexture.bmp");
	brightMushroomTop = meWindow.addTexture("brightMushroomTopTexture.bmp");
	brightMushroomUnder = meWindow.addTexture("brightMushroomUnderTexture.bmp");
	brightWall = meWindow.addTexture("brightWallTexture.bmp");
	darkBark = meWindow.addTexture("darkBarkTexture.bmp");
	darkGround = meWindow.addTexture("darkGroundTexture.bmp");
	singleColor = meWindow.addTexture("textureSingleColor.bmp");
	lava1 = meWindow.addTexture("lava1Texture.bmp");
	lava2 = meWindow.addTexture("lava2Texture.bmp");
	lava3 = meWindow.addTexture("lava3Texture.bmp");
	lava4 = meWindow.addTexture("lava4Texture.bmp");
	lava5 = meWindow.addTexture("lava5Texture.bmp");
	lava6 = meWindow.addTexture("lava6Texture.bmp");
	lava7 = meWindow.addTexture("lava7Texture.bmp");
}

/*----------Renderable-specific set ups----------*/

void ClientGLWindow::setupTransforms()
{
	leftPlaneTransform = glm::translate(vec3(0.0f, 0.0f, 5.0f));
	leftPlaneTransform *= glm::scale(vec3(60.0f, 1.0f, 60.0f));

	rightPlaneTransform = glm::translate(vec3(60.0f, 0.0f, 5.0f));
	rightPlaneTransform *= glm::scale(vec3(60.0f, 1.0f, 60.0f));

	lightBulbTransform = glm::translate(lightPosition);
	lightBulbTransform *= glm::scale(0.5f, 0.5f, 0.5f);

	tableTopTransform = glm::translate(vec3(0.0f, 2.0f, -3.0f));
	tableTopTransform *= glm::scale(vec3(2.5f, 0.125f, 1.5f));

	tableSupportTransform = glm::translate(vec3(0.0f, 1.0f, -3.0f));
	tableSupportTransform *= glm::scale(vec3(1.5f, 1.0f, 0.25f));

	tableBaseTransform = glm::translate(vec3(0.0f, 0.125f, -3.0f));
	tableBaseTransform *= glm::scale(vec3(2.0f, 0.125f, 0.5f));

	tableTeapotTransform = glm::translate(vec3(1.5f, 2.125f, -3.0f));
	tableTeapotTransform *= glm::rotate(-90.0f, vec3(1, 0, 0));
	tableTeapotTransform *= glm::rotate(180.0f, vec3(0, 0, 1));
	tableTeapotTransform *= glm::scale(vec3(0.125f, 0.125f, 0.5f));
	tableTeapotRotation = glm::rotate(-90.0f, vec3(1, 0, 0));
	tableTeapotRotation *= glm::rotate(180.0f, vec3(0, 0, 1));

	tableMetronomeTransform = glm::translate(vec3(-1.5f, 2.5, -3.25f));
	tableMetronomeTransform *= glm::rotate(30.0f, vec3(0, 1, 0));
	tableMetronomeTransform *= glm::rotate(-10.0f, vec3(1, 0, 0));
	tableMetronomeTransform *= glm::scale(vec3(0.25f, 0.5f, 0.125f));
	tableMetronomeRotation = glm::rotate(30.0f, vec3(0, 1, 0));
	tableMetronomeRotation *= glm::rotate(-10.0f, vec3(1, 0, 0));

	tableMetronomeArrowTransform = glm::translate(vec3(-1.40f, 2.5, -3.10f));
	tableMetronomeArrowTransform *= glm::rotate(30.0f, vec3(0, 1, 0));
	tableMetronomeArrowTransform *= glm::rotate(80.0f, vec3(1, 0, 0));
	tableMetronomeArrowTransform *= glm::scale(vec3(0.1025f, 0.125f, 0.5f));
	tableMetronomeArrowRotation = glm::rotate(30.0f, vec3(0, 1, 0));
	tableMetronomeArrowRotation *= glm::rotate(80.0f, vec3(1, 0, 0));

	mushroom1BaseTransform = glm::translate(vec3(-6.0f, 20.0f, -15.0f));
	mushroom1BaseTransform *= glm::scale(vec3(1.0f, 20.0f, 1.0f));
	mushroom1UnderTransform = glm::translate(vec3(-6.0f, 40.0f, -15.0f));
	mushroom1UnderTransform *= glm::scale(vec3(6.0f, 0.25f, 6.0f));
	mushroom1TopTransform = glm::translate(vec3(-6.0f, 44.25f, -15.0f));
	mushroom1TopTransform *= glm::scale(vec3(6.0f, 4.0f, 6.0f));

	mushroom2BaseTransform = glm::translate(vec3(-20.0f, 6.0f, -25.0f));
	mushroom2BaseTransform *= glm::scale(vec3(0.5f, 6.0f, 0.5f));
	mushroom2UnderTransform = glm::translate(vec3(-20.0f, 12.0f, -25.0f));
	mushroom2UnderTransform *= glm::scale(vec3(4.0f, 0.25f, 4.0f));
	mushroom2TopTransform = glm::translate(vec3(-20.0f, 14.25f, -25.0f));
	mushroom2TopTransform *= glm::scale(vec3(4.0f, 2.0f, 4.0f));

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
	
}

void ClientGLWindow::setupRenderables()
{
	leftPlane = meWindow.addRenderable(plane, leftPlaneTransform, lightingAndTextureShader, brightGrass);
	rightPlane = meWindow.addRenderable(plane, rightPlaneTransform, lightingAndTextureShader, darkGround);
	lightBulb = meWindow.addRenderable(sphere, lightBulbTransform, justTextureShader, singleColor);
	tableTop = meWindow.addRenderable(cube, tableTopTransform, justLightingShader);
	tableSupport = meWindow.addRenderable(cube, tableSupportTransform, justLightingShader);
	tableBase = meWindow.addRenderable(cube, tableBaseTransform, justLightingShader);
	tableTeapot = meWindow.addRenderable(teapot, tableTeapotTransform, justLightingShader);
	tableMetronome = meWindow.addRenderable(cube, tableMetronomeTransform, justLightingShader);
	tableMetronomeArrow = meWindow.addRenderable(arrow, tableMetronomeArrowTransform, justLightingShader);
	mushroom1Base = meWindow.addRenderable(cube, mushroom1BaseTransform, lightingAndTextureShader, brightWall);
	mushroom1Under = meWindow.addRenderable(cube, mushroom1UnderTransform, lightingAndTextureShader, brightMushroomUnder);
	mushroom1Top = meWindow.addRenderable(cube, mushroom1TopTransform, lightingAndTextureShader, brightMushroomTop);
	mushroom2Base = meWindow.addRenderable(cube, mushroom2BaseTransform, lightingAndTextureShader, brightWall);
	mushroom2Under = meWindow.addRenderable(cube, mushroom2UnderTransform, lightingAndTextureShader, brightMushroomUnder);
	mushroom2Top = meWindow.addRenderable(cube, mushroom2TopTransform, lightingAndTextureShader, brightMushroomTop);
	tree1 = meWindow.addRenderable(cube, tree1Transform, lightingAndTextureShader, darkBark);
	lavaCube = meWindow.addRenderable(cube, lavaCubeTransform, lightingAndTextureShader, lava1);
	lavaCube2 = meWindow.addRenderable(cube, lavaCube2Transform, lightingAndTextureShader, lava2);
	lavaCube3 = meWindow.addRenderable(cube, lavaCube3Transform, lightingAndTextureShader, lava3);
}

void ClientGLWindow::setupShaderUniforms()
{
	eyePosition = camera.getPosition();
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 60.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	leftPlaneFullTransform = worldToProjectionMatrix * leftPlaneTransform;
	addBrightLightingAndTextureShaderUniforms(leftPlane, &leftPlaneFullTransform[0][0], &leftPlaneRotation[0][0]);

	rightPlaneFullTransform = worldToProjectionMatrix * rightPlaneTransform;
	addDarkLightingAndTextureShaderUniforms(rightPlane, &rightPlaneFullTransform[0][0], &rightPlaneRotation[0][0]);

	lightBulbFullTransform = worldToProjectionMatrix * lightBulbTransform;
	addJustTextureShaderUniforms(lightBulb, &lightBulbFullTransform[0][0]);

	tableTopFullTransform = worldToProjectionMatrix * tableTopTransform;
	addJustLightingShaderUniforms(tableTop, &tableTopFullTransform[0][0], &tableTopRotation[0][0]);

	tableSupportFullTransform = worldToProjectionMatrix * tableSupportTransform;
	addJustLightingShaderUniforms(tableSupport, &tableSupportFullTransform[0][0], &tableSupportRotation[0][0]);

	tableBaseFullTransform = worldToProjectionMatrix * tableBaseTransform;
	addJustLightingShaderUniforms(tableBase, &tableBaseFullTransform[0][0], &tableBaseRotation[0][0]);

	tableTeapotFullTransform = worldToProjectionMatrix * tableTeapotTransform;
	addJustLightingShaderUniforms(tableTeapot, &tableTeapotFullTransform[0][0], &tableTeapotRotation[0][0]);

	tableMetronomeFullTransform = worldToProjectionMatrix * tableMetronomeTransform;
	addJustLightingShaderUniforms(tableMetronome, &tableMetronomeFullTransform[0][0], &tableMetronomeRotation[0][0]);

	tableMetronomeArrowFullTransform = worldToProjectionMatrix * tableMetronomeArrowTransform;
	addJustLightingShaderUniforms(tableMetronomeArrow, &tableMetronomeArrowFullTransform[0][0], &tableMetronomeArrowRotation[0][0]);

	mushroom1BaseFullTransform = worldToProjectionMatrix * mushroom1BaseTransform;
	addBrightLightingAndTextureShaderUniforms(mushroom1Base, &mushroom1BaseFullTransform[0][0], &mushroom1BaseRotation[0][0]);

	mushroom1UnderFullTransform = worldToProjectionMatrix * mushroom1UnderTransform;
	addBrightLightingAndTextureShaderUniforms(mushroom1Under, &mushroom1UnderFullTransform[0][0], &mushroom1UnderRotation[0][0]);

	mushroom1TopFullTransform = worldToProjectionMatrix * mushroom1TopTransform;
	addBrightLightingAndTextureShaderUniforms(mushroom1Top, &mushroom1TopFullTransform[0][0], &mushroom1TopRotation[0][0]);

	mushroom2BaseFullTransform = worldToProjectionMatrix * mushroom2BaseTransform;
	addBrightLightingAndTextureShaderUniforms(mushroom2Base, &mushroom2BaseFullTransform[0][0], &mushroom2BaseRotation[0][0]);

	mushroom2UnderFullTransform = worldToProjectionMatrix * mushroom2UnderTransform;
	addBrightLightingAndTextureShaderUniforms(mushroom2Under, &mushroom2UnderFullTransform[0][0], &mushroom2UnderRotation[0][0]);

	mushroom2TopFullTransform = worldToProjectionMatrix * mushroom2TopTransform;
	addBrightLightingAndTextureShaderUniforms(mushroom2Top, &mushroom2TopFullTransform[0][0], &mushroom2TopRotation[0][0]);

	tree1FullTransform = worldToProjectionMatrix * tree1Transform;
	addDarkLightingAndTextureShaderUniforms(tree1, &tree1FullTransform[0][0], &tree1Rotation[0][0]);

	lavaCubeFullTransform = worldToProjectionMatrix * lavaCubeTransform;
	addDarkLightingAndTextureShaderUniforms(lavaCube, &lavaCubeFullTransform[0][0], &lavaCubeRotation[0][0]);

	lavaCube2FullTransform = worldToProjectionMatrix * lavaCube2Transform;
	addDarkLightingAndTextureShaderUniforms(lavaCube2, &lavaCube2FullTransform[0][0], &lavaCube2Rotation[0][0]);

	lavaCube3FullTransform = worldToProjectionMatrix * lavaCube3Transform;
	addDarkLightingAndTextureShaderUniforms(lavaCube3, &lavaCube3FullTransform[0][0], &lavaCube3Rotation[0][0]);
}

void ClientGLWindow::updateShaderUniforms()
{
	eyePosition = camera.getPosition();
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 70.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	leftPlaneFullTransform = worldToProjectionMatrix * leftPlaneTransform;
	rightPlaneFullTransform = worldToProjectionMatrix * rightPlaneTransform;
	lightBulbFullTransform = worldToProjectionMatrix * lightBulbTransform;//if don't update fulltransform down here - shape will follow camera <stick>
	tableTopFullTransform = worldToProjectionMatrix * tableTopTransform;
	tableSupportFullTransform = worldToProjectionMatrix * tableSupportTransform;
	tableBaseFullTransform = worldToProjectionMatrix * tableBaseTransform;
	tableTeapotFullTransform = worldToProjectionMatrix * tableTeapotTransform;
	tableMetronomeFullTransform = worldToProjectionMatrix * tableMetronomeTransform;
	tableMetronomeArrowFullTransform = worldToProjectionMatrix * tableMetronomeArrowTransform;
	mushroom1BaseFullTransform = worldToProjectionMatrix * mushroom1BaseTransform;
	mushroom1UnderFullTransform = worldToProjectionMatrix * mushroom1UnderTransform;
	mushroom1TopFullTransform = worldToProjectionMatrix * mushroom1TopTransform;
	mushroom2BaseFullTransform = worldToProjectionMatrix * mushroom2BaseTransform;
	mushroom2UnderFullTransform = worldToProjectionMatrix * mushroom2UnderTransform;
	mushroom2TopFullTransform = worldToProjectionMatrix * mushroom2TopTransform;
	tree1FullTransform = worldToProjectionMatrix * tree1Transform;
	lavaCubeFullTransform = worldToProjectionMatrix * lavaCubeTransform;
	lavaCube2FullTransform = worldToProjectionMatrix * lavaCube2Transform;
	lavaCube3FullTransform = worldToProjectionMatrix * lavaCube3Transform;

}

void ClientGLWindow::addPassThroughShaderUniforms(RenderableInfo* renderable, float* fullTransform)
{
	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
}

void ClientGLWindow::addJustTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform)
{
	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
}

void ClientGLWindow::addJustLightingShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
{
	meWindow.addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &diffusionIntensity);
	meWindow.addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &specularColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &specularExponent);
	meWindow.addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &overridingObjectColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &ambientLight[0]);

	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
	meWindow.addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, rotationMatrix);
	meWindow.addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}

void ClientGLWindow::addLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
{
	meWindow.addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &diffusionIntensity);
	meWindow.addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &specularColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &specularExponent);
	meWindow.addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &overridingObjectColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &ambientLight[0]);

	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
	meWindow.addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, rotationMatrix);
	meWindow.addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}

void ClientGLWindow::addBrightLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
{
	meWindow.addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &brightDiffusionIntensity);
	meWindow.addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &brightSpecularColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &brightSpecularExponent);
	meWindow.addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &brightOverridingObjectColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &brightAmbientLight[0]);

	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
	meWindow.addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, rotationMatrix);
	meWindow.addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}

void ClientGLWindow::addDarkLightingAndTextureShaderUniforms(RenderableInfo* renderable, float* fullTransform, float* rotationMatrix)
{
	meWindow.addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &darkDiffusionIntensity);
	meWindow.addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &darkSpecularColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &darkSpecularExponent);
	meWindow.addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &darkOverridingObjectColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &darkAmbientLight[0]);

	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, fullTransform);
	meWindow.addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, rotationMatrix);
	meWindow.addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}

void ClientGLWindow::keyPressReaction(QKeyEvent* e)
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

	meWindow.repaint();
}

void ClientGLWindow::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	updateShaderUniforms();
	meWindow.repaint();
}