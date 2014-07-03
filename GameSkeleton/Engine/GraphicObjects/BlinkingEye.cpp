#include "BlinkingEye.h"

BlinkingEye::BlinkingEye(vec3 pos, float _scale, int _blinkFrame)
{
	position = pos;
	scale = _scale;
	blinkFrame = _blinkFrame;
	isBlinking = false;
	isClosing = false;
}
void BlinkingEye::setupRenderable(GeometryInfo* plane, ShaderInfo* alphaTextureShader, TextureInfo* eyeTexture, AlphaMapInfo* eyeAlpha1)
{
	renderable = GeneralGLWindow::getInstance().addRenderable(plane, modelToWorld, alphaTextureShader, true, PRIORITY_1, true, eyeTexture, eyeAlpha1);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, &fullTransform[0][0]);
}
void BlinkingEye::checkBlinkFrame(int frame)
{
	if(frame%blinkFrame==0 && !isBlinking)
	{
		startBlink();
	}
}
void BlinkingEye::updateTransforms(vec3 cameraPosition, vec3 cameraUp, mat4 worldToProjection)
{
	mat4 billboardTransform = TransformationMatrixMaker::getInstance().getBillboardTransformation(position, cameraPosition, cameraUp, true);
	modelToWorld = billboardTransform * glm::rotate(90.0f, vec3(1,0,0)) * glm::scale(vec3(scale, 1, scale));
	fullTransform = worldToProjection * modelToWorld;
}
void BlinkingEye::startBlink()
{
	isBlinking = true;
	isClosing = true;
	blinkStage = 0;
}
void BlinkingEye::stopBlink()
{
	isBlinking = false;
	isClosing = false;
	blinkStage = 0;
}
void BlinkingEye::updateBlinkStage(AlphaMapInfo* nextAlpha)
{
	if(blinkStage < 0)
	{
		stopBlink();
		blinkStage = 0;
	}
	else
	{
		if(blinkStage!=6)
		{
			blink(nextAlpha);
		}
		else
		{
			isClosing = false;
		}
		if(isClosing)
		{
			blinkStage++;
		}
		else
		{
			blinkStage--;
		}
	}
}
void BlinkingEye::blink(AlphaMapInfo* nextAlpha)
{
	renderable->alphaMap = nextAlpha;
}