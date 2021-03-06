#pragma once
#include "BlinkingEye.h"
#include "..\MathTools\Random.h"

#include <Qt/qlist.h>

class __declspec(dllexport) BlinkingEyeGroup
{
private:
	TextureInfo* eyeTexture;
	GeometryInfo* plane;
	ShaderInfo* alphaTextureShader;

	TextureInfo* eyeAlpha1;
	TextureInfo* eyeAlpha2;
	TextureInfo* eyeAlpha3;
	TextureInfo* eyeAlpha4;
	TextureInfo* eyeAlpha5;
	TextureInfo* eyeAlpha6;

	int numEyes;
	vec3 eyesCenter;
	QList<BlinkingEye*> eyes;
	float minEyeDistance;
	float maxEyeDistance;
	float minEyeScale;
	float maxEyeScale;
	float minBlinkFrame;
	float maxBlinkFrame;
	bool triggeredInitialBlink;
	int initialBlinkFrame;
public:
	BlinkingEyeGroup(int numOfEyes, vec3 center);
	void updateBlinkFrames(int frame);
	void updateEyeTransforms(vec3 cameraPosition, vec3 cameraUp, mat4 worldToProjection);
	void massBlink();

private:
	void setup();
	void setupEyeRendererObjects();
	void setupEyes();
	void updateBlinkAlpha(BlinkingEye* eye);
};

