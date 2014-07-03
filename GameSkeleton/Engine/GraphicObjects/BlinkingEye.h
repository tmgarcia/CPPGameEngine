#pragma once

#include "..\Renderer\GeneralGLWindow.h"
#include "..\MathTools\TransformationMatrixMaker.h"

class __declspec(dllexport) BlinkingEye
{
public:
	int blinkStage;
	bool isBlinking;

private:
	int blinkFrame;
	float scale;
	bool isClosing;
	vec3 position;
	mat4 modelToWorld;
	mat4 fullTransform;
	RenderableInfo* renderable;
public:
	BlinkingEye(vec3 pos, float _scale, int _blinkFrame);

	void setupRenderable(GeometryInfo* plane, ShaderInfo* alphaTextureShader, TextureInfo* eyeTexture, AlphaMapInfo* eyeAlpha1);
	void checkBlinkFrame(int frame);
	void updateTransforms(vec3 cameraPosition, vec3 cameraUp, mat4 worldToProjection);
	void startBlink();
	void stopBlink();
	void updateBlinkStage(AlphaMapInfo* nextAlpha);
private:
	void blink(AlphaMapInfo* nextAlpha);
};