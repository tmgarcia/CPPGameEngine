#include "Material.h"
#include "../Renderer/GeneralGLWindow.h"
#include "../Renderer/ShaderInfo.h"
#include "../Renderer/TextureInfo.h"

void Material::bindAllTextures()
{
	if(usingDiffuseMap)
	{
		GeneralGLWindow::getInstance().bindTexture(shader->programID, "diffuseMap", 0, GL_TEXTURE_2D, diffuseMap->textureID);
	}
	if(usingAlphaMap)
	{
		GeneralGLWindow::getInstance().bindTexture(shader->programID, "alphaMap", 1, GL_TEXTURE_2D, alphaMap->textureID);
	}
	if(usingNormalMap)
	{
		GeneralGLWindow::getInstance().bindTexture(shader->programID, "normalMap", 2, GL_TEXTURE_2D, normalMap->textureID);
	}
	if(usingAmbientOcclusionMap)
	{
		GeneralGLWindow::getInstance().bindTexture(shader->programID, "ambientOcclusionMap", 3, GL_TEXTURE_2D, ambientOcclusionMap->textureID);
	}
	if(usingCubeMap)
	{
		GeneralGLWindow::getInstance().bindTexture(shader->programID, "cubeMap", 4, GL_TEXTURE_CUBE_MAP, cubeMap->textureID);
	}
	if(usingShadowMap)
	{
		GeneralGLWindow::getInstance().bindTexture(shader->programID, "shadowMap", 5, GL_TEXTURE_2D, shadowMap->textureID);
	}
}
void Material::sendDownShaderParameters()
{
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "hasDiffuseMap", usingDiffuseMap);
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "hasAlphaMap", usingAlphaMap);
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "hasNormalMap", usingNormalMap);
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "hasAmbientOcclusion", usingAmbientOcclusionMap);
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "hasCubeMap", usingCubeMap);
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "hasShadowMap", usingShadowMap);
}