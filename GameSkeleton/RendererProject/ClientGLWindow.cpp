#include "ClientGLWindow.h"
#include "Camera.h"



vec3 lightPosition = vec3(0.0f, 4.0f, 3.0f);
float diffusionIntensity = 1;
vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
float specularExponent = 10;
vec3 eyePosition = vec3(0.0f, 1.0f, 0.0f);

mat4 fullTransformMatrix;
vec3 overridingObjectColor = vec3(1.0f, 0.0f, 0.0f);
vec3 ambientLight = vec3(0.0f, 0.0f, 0.0f);
mat4 rotationMatrix = mat4();
mat4 modelToWorldMatrix;

Camera camera;

TextureInfo* coloredStripes;

GeometryInfo* sphere;
GeometryInfo* cube;
GeometryInfo* torus;
GeometryInfo* teapot;
GeometryInfo* arrow;
GeometryInfo* plane;

ShaderInfo* lightingAndTextureShader;
ShaderInfo* passThroughShader;

RenderableInfo* smallSphere;
mat4 smallSphereTransform;

RenderableInfo* longCube;
mat4 longCubeTransform;

void ClientGLWindow::setup()
{
	setupGeometries();
	setupShaders();
	setupTransforms();
	setupTextures();
	setupRenderables();
	
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 20.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	fullTransformMatrix = worldToProjectionMatrix * smallSphereTransform;
	addLightingAndTextureShaderUniforms(smallSphere);
}

void ClientGLWindow::addLightingAndTextureShaderUniforms(RenderableInfo* renderable)
{
	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, &fullTransformMatrix[0][0]);
}

void ClientGLWindow::addPassThroughShaderUniforms(RenderableInfo* renderable)
{
	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, &fullTransformMatrix[0][0]);
}

void ClientGLWindow::setupRenderables()
{
	smallSphere = meWindow.addRenderable(sphere, smallSphereTransform, passThroughShader);
	longCube = meWindow.addRenderable(cube, longCubeTransform, lightingAndTextureShader, coloredStripes);
}

void ClientGLWindow::setupTransforms()
{
	smallSphereTransform = glm::translate(vec3(0.0f, 0.0f, -5.0f));
	smallSphereTransform *= glm::scale(vec3(0.5f,0.5f,0.5f));

	longCubeTransform = glm::translate(vec3(-4.0f, 2.0f, -3.0f));
	longCubeTransform *= glm::scale(vec3(1.0f, 2.0f, 1.0f));
}

void ClientGLWindow::setupTextures()
{
	coloredStripes = meWindow.addTexture("texturetestColors.bmp");
}

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
	passThroughShader = meWindow.createShaderInfo("LightingAndTextureVertexShader.glsl", "LightingAndTextureFragmentShader.glsl");
	lightingAndTextureShader = meWindow.createShaderInfo("PassThroughVertexShader.glsl", "PassThroughFragmentShader.glsl");
}