#include "OffsetTextureMat.h"
#include "Renderer/GeneralGLWindow.h"
#include "SceneManager.h"

ShaderInfo* OffsetTextureMat::OffsetTextureShader;

OffsetTextureMat::OffsetTextureMat()
{
	if(OffsetTextureShader == 0)
	{
		OffsetTextureShader = GeneralGLWindow::getInstance().createShaderInfo("Assets/Shaders/OffsetDiffuseAlphaMapsVertexShader.glsl", "Assets/Shaders/OffsetDiffuseAlphaMapsFragmentShader.glsl");
	}
	shader = OffsetTextureShader;
	currentOffset = glm::vec2(0, 0);
	offsetAlpha = true;
	offsetDiffuse = true;
}

void OffsetTextureMat::setDiffuseMap(const char* fileName)
{
	diffuseMap = GeneralGLWindow::getInstance().addTexture(fileName);
	usingDiffuseMap = true;
}
void OffsetTextureMat::setAlphaMap(const char* fileName)
{
	alphaMap = GeneralGLWindow::getInstance().addTexture(fileName);
	usingAlphaMap = true;
}

void OffsetTextureMat::sendOffsetParameters(RenderableInfo* renderable)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "UVOffset", PT_VEC2, &currentOffset[0]);
}

void OffsetTextureMat::sendDownShaderParameters()
{
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "hasDiffuseMap", usingDiffuseMap);
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "hasAlphaMap", usingAlphaMap);
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "offsetDiffuse", offsetDiffuse);
	GeneralGLWindow::getInstance().sendIntUniformParameter(shader->programID, "offsetAlpha", offsetAlpha);

}