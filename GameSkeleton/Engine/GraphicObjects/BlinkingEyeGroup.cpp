#include "BlinkingEyeGroup.h"


BlinkingEyeGroup::BlinkingEyeGroup(int numOfEyes, vec3 center)
{
	numEyes = numOfEyes;
	minEyeDistance = 1.0f;
	maxEyeDistance = 10.0f;
	minEyeScale = 0.125f;
	maxEyeScale = 1.0f;
	minBlinkFrame = 20.0f;
	maxBlinkFrame = 80.0f;
	triggeredInitialBlink = false;
	initialBlinkFrame = 50;
	eyesCenter = center;

	setup();
}
void BlinkingEyeGroup::setup()
{
	setupEyeRendererObjects();
	setupEyes();
}
void BlinkingEyeGroup::setupEyeRendererObjects()
{
	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(2);
	plane = GeneralGLWindow::getInstance().addGeometry(planeData.verts, planeData.vertexBufferSize(), planeData.indices, planeData.numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(plane, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(plane, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(plane, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(plane, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);

	alphaTextureShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/TextureAndAlphaMapVertexShader.glsl", "../Resources/Shaders/TextureAndAlphaMapFragmentShader.glsl");

	eyeTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/madEyeTexture.bmp");
	
	eyeAlpha1 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap1.bmp");
	eyeAlpha2 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap2.bmp");
	eyeAlpha3 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap3.bmp");
	eyeAlpha4 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap4.bmp");
	eyeAlpha5 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap5.bmp");
	eyeAlpha6 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap6.bmp");

}
void BlinkingEyeGroup::setupEyes()
{
	Random::getInstance();
	for(int i = 0; i<numEyes; i++)
	{
		float distanceFromCenter = Random::getInstance().randomFloatRange(minEyeDistance, maxEyeDistance);
		float angle = Random::getInstance().randomFloatRange(0, 359);
		mat4 transform = glm::rotate(angle, vec3(0,1,0));
		vec3 position = vec3((vec4(0,-0.05f,distanceFromCenter,1) * transform)+vec4(eyesCenter,0));
		float scale = Random::getInstance().randomFloatRange(minEyeScale, maxEyeScale);
		int blinkFrame = (int)Random::getInstance().randomFloatRange(minBlinkFrame, maxBlinkFrame);
		BlinkingEye* e = new BlinkingEye(position, scale, blinkFrame);
		e->setupRenderable(plane, alphaTextureShader, eyeTexture, eyeAlpha1);
		eyes.append(e);
	}
}

void BlinkingEyeGroup::updateBlinkFrames(int frame)
{
	if(frame!= 0 && frame%initialBlinkFrame == 0 && !triggeredInitialBlink)
	{
		massBlink();
		triggeredInitialBlink = true;
	}
	for(int i = 0; i<numEyes; i++)
	{
		eyes[i]->checkBlinkFrame(frame);
	}
}
void BlinkingEyeGroup::updateEyeTransforms(vec3 cameraPosition, vec3 cameraUp, mat4 worldToProjection)
{
	TransformationMatrixMaker::getInstance();
	for(int i = 0; i<numEyes; i++)
	{
		eyes[i]->updateTransforms(cameraPosition,cameraUp,worldToProjection);
		if(eyes[i]->isBlinking)
		{
			updateBlinkAlpha(eyes[i]);
		}
	}
}
void BlinkingEyeGroup::updateBlinkAlpha(BlinkingEye* eye)
{
	AlphaMapInfo* nextAlpha = new AlphaMapInfo();
	switch(eye->blinkStage)
	{
	case 0: nextAlpha = eyeAlpha1;
		break;
	case 1: nextAlpha = eyeAlpha2;
		break;
	case 2: nextAlpha = eyeAlpha3;
		break;
	case 3: nextAlpha = eyeAlpha4;
		break;
	case 4: nextAlpha = eyeAlpha5;
		break;
	case 5: nextAlpha = eyeAlpha6;
		break;
	}
	eye->updateBlinkStage(nextAlpha);
}

void BlinkingEyeGroup::massBlink()
{
	for(int i = 0; i<numEyes; i++)
	{
		eyes[i]->startBlink();
	}
}

