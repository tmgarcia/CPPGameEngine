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

mat4 eye1ModelToWorld;
vec3 eye1Position;
mat4 eye1FullTransform;
mat4 eye2ModelToWorld;
vec3 eye2Position;
mat4 eye2FullTransform;
mat4 eye3ModelToWorld;
vec3 eye3Position;
mat4 eye3FullTransform;

ShaderInfo* alphaTextureShader;

TextureInfo* discTexture;
TextureInfo* textATexture;
TextureInfo* textBTexture;
TextureInfo* eyeTexture;

AlphaMapInfo* discAlpha;
AlphaMapInfo* textAAlpha;
AlphaMapInfo* textBAlpha;
AlphaMapInfo* eyeAlpha1;
AlphaMapInfo* eyeAlpha2;
AlphaMapInfo* eyeAlpha3;
AlphaMapInfo* eyeAlpha4;
AlphaMapInfo* eyeAlpha5;
AlphaMapInfo* eyeAlpha6;

GeometryInfo* plane;

RenderableInfo* disc;
RenderableInfo* textA;
RenderableInfo* textB;
RenderableInfo* eye1;
RenderableInfo* eye2;
RenderableInfo* eye3;

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

	eye1Position = vec3(0,0,-0.25);
	eye1ModelToWorld = billboard(eye1Position)*glm::rotate(90.0f, vec3(1,0,0)) * glm::scale(vec3(0.005f,1,0.005f));
	eye2Position = vec3(0.25f,0,0.0f);
	eye2ModelToWorld = billboard(eye2Position)*glm::rotate(90.0f, vec3(1,0,0)) * glm::scale(vec3(0.005f,1,0.005f));
	eye3Position = vec3(-0.25f,0,0.0f);
	eye3ModelToWorld = billboard(eye3Position)*glm::rotate(90.0f, vec3(1,0,0)) * glm::scale(vec3(0.005f,1,0.005f));

	DebugShapes::getInstance();
	//DebugShapes::addCube(eye1ModelToWorld, vec3(1,1,1),true, 100000);

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
	eye1 = GeneralGLWindow::getInstance().addRenderable(plane, eye1ModelToWorld, alphaTextureShader, true, PRIORITY_1, true, eyeTexture, eyeAlpha1);
	eye2 = GeneralGLWindow::getInstance().addRenderable(plane, eye1ModelToWorld, alphaTextureShader, true, PRIORITY_1, true, eyeTexture, eyeAlpha1);
	eye3 = GeneralGLWindow::getInstance().addRenderable(plane, eye1ModelToWorld, alphaTextureShader, true, PRIORITY_1, true, eyeTexture, eyeAlpha1);

	discFullTransform = worldToProjectionMatrix * discModelToWorld;
	textAFullTransform = worldToProjectionMatrix * textAModelToWorld;
	textBFullTransform = worldToProjectionMatrix * textBModelToWorld;
	eye1FullTransform = worldToProjectionMatrix * eye1ModelToWorld;
	eye2FullTransform = worldToProjectionMatrix * eye2ModelToWorld;
	eye3FullTransform = worldToProjectionMatrix * eye3ModelToWorld;

	GeneralGLWindow::getInstance().addRenderableUniformParameter(disc, "fullTransformMatrix", PT_MAT4, &discFullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(textA, "fullTransformMatrix", PT_MAT4, &textAFullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(textB, "fullTransformMatrix", PT_MAT4, &textBFullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(eye1, "fullTransformMatrix", PT_MAT4, &eye1FullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(eye2, "fullTransformMatrix", PT_MAT4, &eye2FullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(eye3, "fullTransformMatrix", PT_MAT4, &eye3FullTransform[0][0]);
}

float rotateA = 0;
float rotateB = 0;

float rotateIncrementA = 0.3f;
float rotateIncrementB = 0.2f;

int frame = 0;
void ScratchWindow::update()
{
	checkBlinks();
	textARotation = glm::rotate(rotateA, vec3(0,1,0));
	textBRotation = glm::rotate(rotateB, vec3(0,1,0));
	rotateA += rotateIncrementA;
	rotateB -= rotateIncrementB;
	updateShaderInfo();
	frame++;
}

int eye1Stage = 0;
bool eye1Blinking = false;
bool eye1Closing = false;
int eye2Stage = 0;
bool eye2Blinking = false;
bool eye2Closing = false;
int eye3Stage = 0;
bool eye3Blinking = false;
bool eye3Closing = false;
void ScratchWindow::checkBlinks()
{
	if(frame%40 == 0 && !eye1Blinking)
	{
		eye1Blinking = true;
		eye1Closing = true;
	}
	if(frame%50 == 0 && !eye2Blinking)
	{
		eye2Blinking = true;
		eye2Closing = true;
	}
	if(frame%60 == 0 && !eye3Blinking)
	{
		eye3Blinking = true;
		eye3Closing = true;
	}

	if(eye1Blinking)
	{
		if(eye1Stage < 0)
		{
			eye1Blinking = false;
			eye1Closing = false;
			eye1Stage = 0;
		}
		else
		{
			blinkEye(eye1, eye1Stage);
			if(eye1Stage == 6)
			{
				eye1Closing = false;
			}
			if(eye1Closing)
			{
				eye1Stage++;
			}
			else
			{
				eye1Stage--;
			}
		}
	}
	if(eye2Blinking)
	{
		if(eye2Stage < 0)
		{
			eye2Blinking = false;
			eye2Closing = false;
			eye2Stage = 0;
		}
		else
		{
			blinkEye(eye2, eye2Stage);
			if(eye2Stage == 6)
			{
				eye2Closing = false;
			}
			if(eye2Closing)
			{
				eye2Stage++;
			}
			else
			{
				eye2Stage--;
			}
		}
	}
	if(eye3Blinking)
	{
		if(eye3Stage < 0)
		{
			eye3Blinking = false;
			eye3Closing = false;
			eye3Stage = 0;
		}
		else
		{
			blinkEye(eye3, eye3Stage);
			if(eye3Stage == 6)
			{
				eye3Closing = false;
			}
			if(eye3Closing)
			{
				eye3Stage++;
			}
			else
			{
				eye3Stage--;
			}
		}
	}
}

void ScratchWindow::blinkEye(RenderableInfo* eye, int stage)
{
	switch(stage)
	{
	case 0: eye->alphaMap = eyeAlpha1;
		break;
	case 1: eye->alphaMap = eyeAlpha2;
		break;
	case 2: eye->alphaMap = eyeAlpha3;
		break;
	case 3: eye->alphaMap = eyeAlpha4;
		break;
	case 4: eye->alphaMap = eyeAlpha5;
		break;
	case 5: eye->alphaMap = eyeAlpha6;
		break;
	}
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

	eye1ModelToWorld = billboard(eye1Position)*glm::rotate(90.0f, vec3(1,0,0)) * glm::scale(vec3(0.15f,1,0.15f));
	eye1FullTransform = worldToProjectionMatrix * eye1ModelToWorld;
	eye2ModelToWorld = billboard(eye2Position)*glm::rotate(90.0f, vec3(1,0,0)) * glm::scale(vec3(0.15f,1,0.15f));
	eye2FullTransform = worldToProjectionMatrix * eye2ModelToWorld;
	eye3ModelToWorld = billboard(eye3Position)*glm::rotate(90.0f, vec3(1,0,0)) * glm::scale(vec3(0.15f,1,0.15f));
	eye3FullTransform = worldToProjectionMatrix * eye3ModelToWorld;

	GeneralGLWindow::getInstance().repaint();
}

mat4 ScratchWindow::billboard(vec3 position) 
{
	vec3 look = glm::normalize(camera.getPosition() - position);
	vec3 right = glm::cross(vec3(0,1,0), look);
	vec3 up2 = glm::cross(look, right);
	mat4 transform;
	transform[0] = vec4(right, 0);
	transform[1] = vec4(up2, 0);
	transform[2] = vec4(look, 0);
	transform[3] = vec4(position, 1);
	return transform;
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