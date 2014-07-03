#include "MainWindow.h"
#include "DebugMenu\DebugMenu.h"

#pragma region Variables
GeometryInfo* plane;
ShaderInfo* alphaTextureShader;

AlphaMapInfo* discAlpha;
AlphaMapInfo* textAAlpha;
AlphaMapInfo* textBAlpha;

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
#pragma endregion

void MainWindow::setup()
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

	discAlpha = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madnessDiscAlphaMap.bmp");
	textAAlpha = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madnessTextAAlphaMap.bmp");
	textBAlpha = GeneralGLWindow::getInstance().addAlphaMap("../Resources/AlphaMaps/madnessTextBAlphaMap.bmp");

	disc = GeneralGLWindow::getInstance().addRenderable(plane, discModelToWorld, alphaTextureShader, true, PRIORITY_1, true, discTexture, discAlpha);
	textA = GeneralGLWindow::getInstance().addRenderable(plane, textAModelToWorld, alphaTextureShader, true, PRIORITY_1, true, textATexture, textAAlpha);
	textB = GeneralGLWindow::getInstance().addRenderable(plane, textBModelToWorld, alphaTextureShader, true, PRIORITY_1, true, textBTexture, textBAlpha);

	discFullTransform = worldToProjectionMatrix * discModelToWorld;
	textAFullTransform = worldToProjectionMatrix * textAModelToWorld;
	textBFullTransform = worldToProjectionMatrix * textBModelToWorld;

	GeneralGLWindow::getInstance().addRenderableUniformParameter(disc, "fullTransformMatrix", PT_MAT4, &discFullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(textA, "fullTransformMatrix", PT_MAT4, &textAFullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(textB, "fullTransformMatrix", PT_MAT4, &textBFullTransform[0][0]);
	eyes = new BlinkingEyeGroup(200, vec3(0,0,0));
}
float rotateA = 0;
float rotateB = 0;
float rotateIncrementA = 0.3f;
float rotateIncrementB = 0.2f;
int frame = 0;
bool massBlink = false;
void MainWindow::update()
{
	textARotation = glm::rotate(rotateA, vec3(0,1,0));
	textBRotation = glm::rotate(rotateB, vec3(0,1,0));
	rotateA += rotateIncrementA;
	rotateB -= rotateIncrementB;
	eyes->updateBlinkFrames(frame);
	updateShaderInfo();
	frame++;
}

void MainWindow::updateShaderInfo()
{
	vec3 eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	discFullTransform = worldToProjectionMatrix * discModelToWorld;
	textAModelToWorld =  textARotation * textATranslate;
	textAFullTransform = worldToProjectionMatrix * textAModelToWorld;
	textBModelToWorld =  textBRotation* textBTranslate;
	textBFullTransform = worldToProjectionMatrix * textBModelToWorld;
	eyes->updateEyeTransforms(eyePosition, vec3(0,1,0),worldToProjectionMatrix);

	GeneralGLWindow::getInstance().repaint();
}
void MainWindow::keyPressEvent(QKeyEvent* e)
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
		eyes->massBlink();
		break;
	}
	update();
}
void MainWindow::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	update();
}