#include "LevelDisplay.h"
#include "ObjReader.h"

#include <iostream>

using std::cout;
using std::endl;


vec3 lightPosition = vec3(0.0f, 50.0f, -30.0f);
float diffusionIntensity = 1;
vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
float specularExponent = 10;
vec3 eyePosition ;
vec3 overridingObjectColor = vec3(0.4,0.4,0.4);
mat4 fullTransformMatrix;
vec3 ambientLight = vec3(0.9f, 0.9f, 0.9f);

vec3 red = vec3(1, 0, 0);
vec3 yellow = vec3(1, 1, 0);
vec3 blue = vec3(0, 0, 1);

GeometryInfo* levelGeometry;
RenderableInfo* levelRenderable;
ShaderInfo* lightingShader;

mat4 levelTransform = mat4();
mat4 levelRotation = mat4();
mat4 levelFullTransform = mat4();

void LevelDisplay::setup()
{
	//GeneralGLWindow::getInstance();
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));
}

void LevelDisplay::loadLevelMap(QString fileName)
{
	//prepForNewLevel();
	//int i = system("cd .");
	//i = system("dir");
	//cout << i << endl;

	QString command("ObjToBinaryWriter.exe ");
	const char* nativeFileName = "ObjToBinaryResult.bin";
	command += QString(fileName) + " " + nativeFileName;
	cout << command.toUtf8().constData() << endl;
	int result = system(command.toUtf8().constData());
	assert(result == 0);

	setupLevelGeometry();
}

void LevelDisplay::setupLevelGeometry()
{
	ObjReader reader;
	
	ObjReader::ShapeData levelData = reader.readInShape("../LevelEditor/ObjToBinaryResult.Bin");
	levelGeometry = GeneralGLWindow::getInstance().addGeometry(levelData.vertices, levelData.vertexDataSize, levelData.indices, levelData.numIndices, GL_TRIANGLES);
	
	lightingShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/justLightingVertexShader.glsl", "../Resources/Shaders/justLightingFragmentShader.glsl");

	GeneralGLWindow::getInstance().addShaderStreamedParameter(levelGeometry, 0, PT_VEC3, ObjReader::POSITION_OFFSET, ObjReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(levelGeometry, 2, PT_VEC3, ObjReader::NORMAL_OFFSET, ObjReader::STRIDE);

	levelRenderable = GeneralGLWindow::getInstance().addRenderable(levelGeometry, levelTransform, lightingShader, true, PRIORITY_1, true);

	updateLevelProjectionView();

	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "diffusionIntensity", PT_FLOAT, &diffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "specularColor", PT_VEC4, &specularColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "specularExponent", PT_FLOAT, &specularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "overridingObjectColor", PT_VEC3, &overridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "ambientLight", PT_VEC3, &ambientLight[0]);

	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "fullTransformMatrix", PT_MAT4, &levelFullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "rotationMatrix", PT_MAT4, &levelRotation[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(levelRenderable, "modelToWorldMatrix", PT_MAT4, &levelRenderable->whereMatrix[0][0]);

}

void LevelDisplay::updateLevelProjectionView()
{
	eyePosition = camera.getPosition();
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 100.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	//DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	levelFullTransform = worldToProjectionMatrix * levelTransform;
}

void LevelDisplay::keyPressReaction(QKeyEvent* e)
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
	updateLevelProjectionView();

	GeneralGLWindow::getInstance().repaint();
}

void LevelDisplay::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	updateLevelProjectionView();
	GeneralGLWindow::getInstance().repaint();
}

LevelDisplay::LevelDisplay()
{

}

LevelDisplay::~LevelDisplay()
{

}
