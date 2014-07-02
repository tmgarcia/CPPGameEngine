#include "ScratchWindow.h"
#include "GameObjects\GameLevel.h"
#include "DebugMenu\DebugMenu.h"
#include <iostream>;


using std::cout;
using std::endl;

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

mat4 discModelToWorld;
mat4 discFullTransform;
mat4 textAModelToWorld;
mat4 textATranslate;
mat4 textARotation;
mat4 textAFullTransform;
mat4 textBModelToWorld;
mat4 textBTranslate;
mat4 textBRotation;
mat4 textBFullTransform;

TextureInfo* discTexture;
TextureInfo* textATexture;
TextureInfo* textBTexture;

RenderableInfo* disc;
RenderableInfo* textA;
RenderableInfo* textB;

void ScratchWindow::setup()
{
	camera.setPosition(vec3(0,0.5f,0.7f));
	camera.setViewDirection(vec3(0,-1,-1));
	Neumont::ShapeData planeData = Neumont::ShapeGenerator::makePlane(2);
	plane = GeneralGLWindow::getInstance().addGeometry(planeData.verts, planeData.vertexBufferSize(), planeData.indices, planeData.numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(plane, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(plane, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(plane, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(plane, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);

	alphaTextureShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/TextureAndAlphaMapVertexShader.glsl", "../Resources/Shaders/TextureAndAlphaMapFragmentShader.glsl");

	discModelToWorld = glm::translate(vec3(0.5f,0,0.5f));

	textATranslate = glm::translate(vec3(0.5f,0.002f,0.5f));
	textAModelToWorld = textATranslate * textARotation;
	textBTranslate = glm::translate(vec3(0.5f,0.001f,0.5f));
	textBModelToWorld = textBTranslate * textBRotation;

	discTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/madnessDiscTexture.bmp");
	textATexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/madnessTextATexture.bmp");
	textBTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/madnessTextBTexture.bmp");
	eyeTexture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/madEyeTexture.bmp");

	discAlpha = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madnessDiscAlphaMap.bmp");
	textAAlpha = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madnessTextAAlphaMap.bmp");
	textBAlpha = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madnessTextBAlphaMap.bmp");

	eyeAlpha1 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap1.bmp");
	eyeAlpha2 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap2.bmp");
	eyeAlpha3 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap3.bmp");
	eyeAlpha4 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap4.bmp");
	eyeAlpha5 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap5.bmp");
	eyeAlpha6 = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madEyeAlphaMap6.bmp");

	disc = GeneralGLWindow::getInstance().addRenderable(plane, discModelToWorld, alphaTextureShader, true, PRIORITY_1, true, discTexture, discAlpha);
	textA = GeneralGLWindow::getInstance().addRenderable(plane, textAModelToWorld, alphaTextureShader, true, PRIORITY_1, true, textATexture, textAAlpha);
	textB = GeneralGLWindow::getInstance().addRenderable(plane, textBModelToWorld, alphaTextureShader, true, PRIORITY_1, true, textBTexture, textBAlpha);

	discFullTransform = worldToProjectionMatrix * discModelToWorld;
	textAFullTransform = worldToProjectionMatrix * textAModelToWorld;
	textBFullTransform = worldToProjectionMatrix * textBModelToWorld;

	GeneralGLWindow::getInstance().addRenderableUniformParameter(disc, "fullTransformMatrix", PT_MAT4, &discFullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(textA, "fullTransformMatrix", PT_MAT4, &textAFullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(textB, "fullTransformMatrix", PT_MAT4, &textBFullTransform[0][0]);
	setupEyes();
}

void ScratchWindow::setupEyes()
{
	numEyes = 200;

	float minDistance = 1.0f;
	float maxDistance = 10.0f;
	float minScale = 0.125f;
	float maxScale = 1.0f;
	float minBlinkFrame = 20.0f;
	float maxBlinkFrame = 80.0f;
	Random::getInstance();
	for(int i = 0; i<numEyes; i++)
	{
		float distanceFromCenter = Random::getInstance().randomFloatRange(minDistance, maxDistance);
		float angle = Random::getInstance().randomFloatRange(0, 359);
		mat4 transform = glm::rotate(angle, vec3(0,1,0));
		vec3 position = vec3(vec4(0,-0.05f,distanceFromCenter,1) * transform);
		float scale = Random::getInstance().randomFloatRange(minScale, maxScale);
		int blinkFrame = (int)Random::getInstance().randomFloatRange(minBlinkFrame, maxBlinkFrame);
		Eye* e = new Eye(position, scale, blinkFrame);
		e->setupRenderable(plane, alphaTextureShader, eyeTexture, eyeAlpha1);
		eyes.append(e);
	}
}

float rotateA = 0;
float rotateB = 0;

float rotateIncrementA = 0.3f;
float rotateIncrementB = 0.2f;

int frame = 0;

bool massBlink = false;
void ScratchWindow::update()
{
	textARotation = glm::rotate(rotateA, vec3(0,1,0));
	textBRotation = glm::rotate(rotateB, vec3(0,1,0));
	rotateA += rotateIncrementA;
	rotateB -= rotateIncrementB;
	if(frame!= 0 && frame%50 == 0 && !massBlink)
	{
		for(int i = 0; i<numEyes; i++)
		{
			eyes[i]->startBlink();
		}
		massBlink = true;
	}
	for(int i = 0; i<numEyes; i++)
	{
		eyes[i]->checkBlinkFrame(frame);
	}
	updateShaderInfo();
	frame++;
}

void ScratchWindow::updateShaderInfo()
{
	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::getInstance();
	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	discFullTransform = worldToProjectionMatrix * discModelToWorld;
	textAModelToWorld =  textARotation * textATranslate;
	textAFullTransform = worldToProjectionMatrix * textAModelToWorld;
	textBModelToWorld =  textBRotation* textBTranslate;
	textBFullTransform = worldToProjectionMatrix * textBModelToWorld;

	TransformationMatrixMaker::getInstance();
	for(int i = 0; i<numEyes; i++)
	{
		eyes[i]->updateTransforms(eyePosition, vec3(0,1,0),worldToProjectionMatrix);
		if(eyes[i]->isBlinking)
		{
			AlphaMapInfo* nextAlpha = new AlphaMapInfo();
			switch(eyes[i]->blinkStage)
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
			eyes[i]->updateBlinkStage(nextAlpha);
		}
	}

	GeneralGLWindow::getInstance().repaint();
}

void ScratchWindow::keyPressEvent(QKeyEvent *event)
{
	keyPressReaction(event);
}
void ScratchWindow::keyPressReaction(QKeyEvent* e)
{
	switch(e->key())
	{
	case Qt::Key::Key_W:
		camera.moveForward();
		break;
	case Qt::Key::Key_S:
		camera.moveBackward();
		break;
	case Qt::Key::Key_A:
		camera.strafeLeft();
		break;
	case Qt::Key::Key_D:
		camera.strafeRight();
		break;
	case Qt::Key::Key_R:
		camera.moveUp();
		break;
	case Qt::Key::Key_F:
		camera.moveDown();
		break;
	case Qt::Key::Key_Space:
		for(int i = 0; i<numEyes; i++)
		{
			eyes[i]->startBlink();
		}
		break;
	}
	//updateShaderUniforms();
	update();
	//GeneralGLWindow::getInstance().repaint();
}

void ScratchWindow::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	//updateShaderUniforms();
	update();
	//GeneralGLWindow::getInstance().repaint();
}