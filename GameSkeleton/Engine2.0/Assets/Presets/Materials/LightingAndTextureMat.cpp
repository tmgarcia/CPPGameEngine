#include "LightingAndTextureMat.h"
#include "Renderer/GeneralGLWindow.h"
#include "SceneManager.h"

vec3 overridingObjectColor;

ShaderInfo* LightingAndTextureMat::LightTextureShader;
LightingAndTextureMat::LightingAndTextureMat()
{
	if(LightTextureShader == 0)
	{
		LightTextureShader = GeneralGLWindow::getInstance().createShaderInfo("Assets/Shaders/LightingAndTextureMapsVertexShader.glsl", "Assets/Shaders/LightingAndTextureMapsFragmentShader.glsl");
	}
	shader = LightTextureShader;
	overridingObjectColor = vec3(1.0f,1.0f,1.0f);
}

void LightingAndTextureMat::addDiffuseMap(const char* fileName)
{
	diffuseMap = GeneralGLWindow::getInstance().addTexture(fileName);
	usingDiffuseMap = true;
}
void LightingAndTextureMat::addAlphaMap(const char* fileName)
{
	alphaMap = GeneralGLWindow::getInstance().addTexture(fileName);
	usingAlphaMap = true;
}
void LightingAndTextureMat::addNormalMap(const char* fileName)
{
	normalMap = GeneralGLWindow::getInstance().addTexture(fileName);
	usingNormalMap = true;
}
void LightingAndTextureMat::addAmbientOcclusionMap(const char* fileName)
{
	ambientOcclusionMap = GeneralGLWindow::getInstance().addTexture(fileName);
	usingAmbientOcclusionMap = true;
}
void LightingAndTextureMat::addCubeMap(const char* fileName)
{
	cubeMap = GeneralGLWindow::getInstance().addTexture(fileName);
	usingCubeMap = true;
}
void LightingAndTextureMat::addShadowMap(const char* fileName)
{
	shadowMap = GeneralGLWindow::getInstance().addTexture(fileName);
	usingShadowMap = true;
}
void LightingAndTextureMat::addLightingParameters(RenderableInfo* renderable)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &SceneManager::getInstance().LIGHT_POSITION[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &SceneManager::getInstance().LIGHT_DIFFUSIONINTENSITY);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &SceneManager::getInstance().LIGHT_SPECULARCOLOR[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &SceneManager::getInstance().LIGHT_SPECULAREXPONENT);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &SceneManager::getInstance().camera.getPosition()[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &overridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &SceneManager::getInstance().LIGHT_AMBIENTCOLOR[0]);
}