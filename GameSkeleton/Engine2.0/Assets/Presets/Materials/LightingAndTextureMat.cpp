#include "LightingAndTextureMat.h"
#include "../../../Renderer/GeneralGLWindow.h"

LightingAndTextureMat::LightingAndTextureMat()
{
	shader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/LightingAndTextureMapsVertexShader.glsl", "../Resources/Shaders/LightingAndTextureMapsFragmentShader.glsl");
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