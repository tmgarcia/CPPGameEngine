#include "LevelDisplay.h"
#include "ObjReader.h"
#include "DebugShapes.h"

#include <iostream>

using std::cout;
using std::endl;


vec3 lightPosition = vec3(0.0f, 50.0f, -30.0f);
float diffusionIntensity = 1;
vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
float specularExponent = 100;
vec3 eyePosition;
vec3 overridingObjectColor = vec3(0.3,0.3,0.3);
vec3 ambientLight = vec3(0.9f, 0.9f, 0.9f);

vec3 red = vec3(1, 0, 0);
vec3 yellow = vec3(1, 1, 0);
vec3 blue = vec3(0, 0, 1);

GeometryInfo* levelGeometry;
RenderableInfo* levelRenderable;
ShaderInfo* lightingShader;

//mat4 levelTransform = glm::translate(vec3(0,0,-10.0f));
mat4 levelTransform = mat4();
mat4 levelRotation = mat4();
mat4 levelFullTransform = mat4();

void LevelDisplay::setup()
{
	//GeneralGLWindow::getInstance();
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseClicked(QMouseEvent*)), this, SLOT(mouseClickReaction(QMouseEvent*)));
	aNodeIsSelected = false;
}

void LevelDisplay::setupForNewLevel()
{

}

void LevelDisplay::loadLevelMap(QString fileName)
{
	//setupForNewLevel();
	//int i = system("cd .");
	//i = system("dir");
	//cout << i << endl;

	QString command("ObjToBinaryWriter.exe ");
	const char* nativeFileName = "ObjToBinaryResult.bin";
	command += "\"" + QString(fileName) + "\" \"" + nativeFileName + "\"";
	cout << command.toUtf8().constData() << endl;
	int result = system(command.toUtf8().constData());
	assert(result == 0);

	setupLevelGeometry();
}

void LevelDisplay::setupLevelGeometry()
{
	ObjReader reader;
	
	ObjReader::ShapeData levelData = reader.readInShape("ObjToBinaryResult.bin");
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

	setupDebugShapes();
}

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;
void LevelDisplay::updateLevelProjectionView()
{
	eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)windowWidth) / windowHeight, 0.1f, 100.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::getInstance();
	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	levelFullTransform = worldToProjectionMatrix * levelTransform;
}

void LevelDisplay::setupDebugShapes()
{
	//float edgePoint = 5;
	DebugShapes::getInstance();
	DebugShapes::addPoint(vec3(0,0.01f,0),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,-5),vec3(-5,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-4,0.001f,-5),vec3(-4,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-3,0.001f,-5),vec3(-3,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-2,0.001f,-5),vec3(-2,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-1,0.001f,-5),vec3(-1,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(0,0.001f,-5),vec3(0,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(5,0.001f,-5),vec3(5,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(4,0.001f,-5),vec3(4,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(3,0.001f,-5),vec3(3,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(2,0.001f,-5),vec3(2,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(1,0.001f,-5),vec3(1,0.001f,5),vec3(1,1,1),true,100000);

	DebugShapes::addLine(vec3(-5,0.001f,-5),vec3(5,0.001f,-5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,-4),vec3(5,0.001f,-4),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,-3),vec3(5,0.001f,-3),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,-2),vec3(5,0.001f,-2),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,-1),vec3(5,0.001f,-1),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,0),vec3(5,0.001f,0),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,5),vec3(5,0.001f,5),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,4),vec3(5,0.001f,4),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,3),vec3(5,0.001f,3),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,2),vec3(5,0.001f,2),vec3(1,1,1),true,100000);
	DebugShapes::addLine(vec3(-5,0.001f,1),vec3(5,0.001f,1),vec3(1,1,1),true,100000);

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
	case Qt::Key::Key_Delete:
		if(aNodeIsSelected)
		{
			nodes.deleteSelectedNode();
		}
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


void LevelDisplay::mouseClickReaction(QMouseEvent* e)
{
	int xPX = e->x();
	int yPX = e->y();
	
	float xFraction = (float)xPX/windowWidth;
	float yFraction = (float)(windowHeight-yPX)/windowHeight;

	float vectorXPosition = (float)(xFraction*2)-1.0f;
	float vectorYPosition = (float)(yFraction*2)-1.0f;
	float vectorZPosition = -1.0f;

	mat4 invertedVP = glm::inverse(viewToProjectionMatrix);

	vec4 clickVectorVP = vec4(vectorXPosition, vectorYPosition, vectorZPosition, 1.0f);
	vec4 clickVectorWP = invertedVP * clickVectorVP;

	clickVectorWP.z = -1.0f;
	clickVectorWP.w = 0.0f;

	mat4 invertedWV = glm::inverse(worldToViewMatrix);
	vec4 clickVectorW = invertedWV * clickVectorWP;

	vec3 direction = glm::normalize(vec3(clickVectorW));//normalized
	vec3 origin = camera.getPosition();


	vec3 pointOnPlane = vec3(0,0,0);
	vec3 surfaceNormal = glm::normalize(vec3(0,1,0));

	float numerator = glm::dot((origin - pointOnPlane), surfaceNormal);
	float denominator = glm::dot(direction, surfaceNormal);
	float distance = - numerator/denominator;

	if(e->button()==Qt::RightButton)
	{
		aNodeIsSelected = nodes.nodeRightClicked(direction, origin);
	}
	else
	{
		if(aNodeIsSelected)
		{
			nodes.nodeLeftClicked(direction, origin);
		}
		else
		{
			vec3 intersectionPoint = origin + (direction * distance);

			float perpDot = glm::dot(intersectionPoint-pointOnPlane,surfaceNormal);
			cout << "(p-po)*n = " << perpDot << endl;

			if(distance>=0)
				nodes.addNode(intersectionPoint);
		}
	}
}


LevelDisplay::LevelDisplay()
{
	//windowHeight = 900;
	//windowWidth = 900;
}

LevelDisplay::~LevelDisplay()
{

}
