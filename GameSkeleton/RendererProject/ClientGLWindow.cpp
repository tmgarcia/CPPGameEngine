#include "ClientGLWindow.h"
#include "Camera.h"
vec3 lightPosition = vec3(0.0f, 4.0f, 3.0f);
float diffusionIntensity = 1;
vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
float specularExponent = 10;
vec3 eyePosition = vec3(0.0f, 1.0f, 0.0f);

mat4 fullTransformMatrix;
vec3 overridingObjectColor;
vec3 ambientLight;
mat4 rotationMatrix;
mat4 modelToWorldMatrix;


GeneralGLWindow meWindow;
RenderableInfo* smallSphere;
mat4 smallSphereTransform;
Camera camera;

void ClientGLWindow::initializeGL()
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glEnable( GL_TEXTURE_2D );
	setup();
}
void ClientGLWindow::setup()
{

	Neumont::ShapeData sphereData = Neumont::ShapeGenerator::makeSphere(10);
	GeometryInfo* sphere = meWindow.addGeometry(sphereData.verts, sphereData.vertexBufferSize, sphereData.indices, sphereData.numIndices, GL_TRIANGLES);
	ShaderInfo* lightingAndTextureShader = meWindow.createShaderInfo("LightingAndTextureVertexShader.glsl", "LightingAndTextureFragmentShader.glsl");
	TextureInfo* texture1 = meWindow.addTexture("texturetestColors.bmp");
	smallSphereTransform = glm::translate(vec3(0, 0, 5.0f));
	smallSphere = meWindow.addRenderable(sphere, smallSphereTransform, lightingAndTextureShader, texture1);
	
	meWindow.addShaderStreamedParameter(sphere, 0, GeneralGLWindow::PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	meWindow.addShaderStreamedParameter(sphere, 1, GeneralGLWindow::PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	meWindow.addShaderStreamedParameter(sphere, 2, GeneralGLWindow::PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	meWindow.addShaderStreamedParameter(sphere, 3, GeneralGLWindow::PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);
	
}

void ClientGLWindow::setLightingAndTextureUniforms(RenderableInfo* renderable)
{
	meWindow.addRenderableUniformParameter(renderable, "lightPosition", GeneralGLWindow::PT_VEC3, &lightPosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "diffusionIntensity", GeneralGLWindow::PT_FLOAT, &diffusionIntensity);
	meWindow.addRenderableUniformParameter(renderable, "specularColor", GeneralGLWindow::PT_VEC4, &specularColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "specularExponent", GeneralGLWindow::PT_FLOAT, &specularExponent);
	meWindow.addRenderableUniformParameter(renderable, "eyePosition", GeneralGLWindow::PT_VEC3, &eyePosition[0]);
	meWindow.addRenderableUniformParameter(renderable, "fullTransformMatrix", GeneralGLWindow::PT_MAT4, &fullTransformMatrix[0][0]);
	meWindow.addRenderableUniformParameter(renderable, "overridingObjectColor", GeneralGLWindow::PT_VEC3, &overridingObjectColor[0]);
	meWindow.addRenderableUniformParameter(renderable, "ambientLight", GeneralGLWindow::PT_VEC3, &ambientLight[0]);
	meWindow.addRenderableUniformParameter(renderable, "rotationMatrix", GeneralGLWindow::PT_MAT4, &rotationMatrix[0][0]);
	meWindow.addRenderableUniformParameter(renderable, "modelToWorldMatrix", GeneralGLWindow::PT_MAT4, &renderable->whereMatrix[0][0]);
}


void ClientGLWindow::paintGL()
{
	mat4 viewToProjectionMatrix = glm::perspective(90.0f, ((float)width()) / height(), 0.1f, 50.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	fullTransformMatrix = worldToProjectionMatrix * smallSphereTransform;
	setLightingAndTextureUniforms(smallSphere);
	glBindVertexArray(smallSphere->whatGeometry->vertexArrayID);
	glDrawElements(smallSphere->whatGeometry->indexingMode, smallSphere->whatGeometry->numIndices, GL_UNSIGNED_SHORT, (void*)smallSphere->whatGeometry->indexDataOffset);

}