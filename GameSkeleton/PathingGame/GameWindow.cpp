#include "GameWindow.h"
#include "ObjReader.h"
#include "DebugShapes.h"
#include "AStarData\PathCreator.h"
#include "AStarData\Path.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

vec3 lightPosition = vec3(0.0f, 50.0f, -30.0f);
float diffusionIntensity = 1;
vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
float specularExponent = 100;
vec3 eyePosition;
vec3 overridingObjectColor = vec3(0.3,0.3,0.3);
vec3 ambientLight = vec3(0.9f, 0.9f, 0.9f);

GeometryInfo* levelGeometry;
RenderableInfo* levelRenderable;
ShaderInfo* lightingShader;

ObjReader::ShapeData levelData;

mat4 levelTransform = mat4();
mat4 levelRotation = mat4();
mat4 levelFullTransform = mat4();

mat4 viewToProjectionMatrix;
mat4 worldToViewMatrix;
mat4 worldToProjectionMatrix;

void GameWindow::setup()
{
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	//aNodeIsSelected = false;
	levelLoaded = false;
	testCharacterLoaded = false;
	frames = 0;
	timer.setInterval(1);
	timer.start(0);
}


void GameWindow::loadTestCharacter()
{
	QString fileName = "../Resources/Models/turtle.obj";
	QString command("ObjToBinaryWriter.exe ");
	const char* nativeFileName = "Character.bin";
	command += "\"" + QString(fileName) + "\" \"" + nativeFileName + "\"";
	cout << command.toUtf8().constData() << endl;
	int result = system(command.toUtf8().constData());
	assert(result == 0);

	ObjReader reader;
	character.shapeData = reader.readInShape("Character.bin");
	EditorNode* characterStart = nodes.getRandomNode();
	character.modelToWorldTransform = glm::translate(characterStart->position);
	character.rotation = mat4();
	setupCharacterGeometry();
	setupCharacterPath(characterStart);
	testCharacterLoaded = true;
}

void GameWindow::setupCharacterPath(EditorNode* start)
{
	cout << "Getting new Path" << endl;
	EditorNode* end = nullptr;
	PathCreator pathCreator;
	Path p;
	bool foundValidPath = false;
	while(!foundValidPath)
	{
		end = nodes.getRandomNode();
		if(!(end == start))
		{
			p = pathCreator.calculatePath(start, end);
			foundValidPath = (p.isValidPath);
		}
	}
	currentCharacterGoal = end;
	cout << "Nodes in path: " << p.totalNodes << endl;
	p.speed = 1;
	character.path = p;
}

void GameWindow::setupCharacterGeometry()
{
	character.geometry = GeneralGLWindow::getInstance().addGeometry(character.shapeData.vertices, character.shapeData.vertexDataSize, character.shapeData.indices, character.shapeData.numIndices, GL_TRIANGLES);
	
	character.shader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/justLightingVertexShader.glsl", "../Resources/Shaders/justLightingFragmentShader.glsl");

	GeneralGLWindow::getInstance().addShaderStreamedParameter(character.geometry, 0, PT_VEC3, ObjReader::POSITION_OFFSET, ObjReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(character.geometry, 2, PT_VEC3, ObjReader::NORMAL_OFFSET, ObjReader::STRIDE);

	character.renderable = GeneralGLWindow::getInstance().addRenderable(character.geometry, character.modelToWorldTransform, character.shader, true, PRIORITY_1, true);

	character.fullTransform = worldToProjectionMatrix * character.modelToWorldTransform;
	
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "diffusionIntensity", PT_FLOAT, &diffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "specularColor", PT_VEC4, &specularColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "specularExponent", PT_FLOAT, &specularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "overridingObjectColor", PT_VEC3, &overridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "ambientLight", PT_VEC3, &ambientLight[0]);
																 
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "fullTransformMatrix", PT_MAT4, &character.fullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "rotationMatrix", PT_MAT4, &character.rotation[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(character.renderable, "modelToWorldMatrix", PT_MAT4, &character.renderable->whereMatrix[0][0]);
}

#define R_CS(a) reinterpret_cast<char*>(&a), sizeof(a)
#define R_C(t,a) reinterpret_cast<t>(a)//cast a to t
uint HEADER_BYTE_SIZE = 2*sizeof(uint);//how many bites in header
uint SERIALIZED_NODE_SIZE1 = sizeof(vec3) + sizeof(uint) + sizeof(uint);
uint SERIALIZED_CONNECTION_SIZE1 = sizeof(float) + sizeof(uint);

void GameWindow::loadLevel(QString filename)
{
	if(levelLoaded)
		levelRenderable->visible = false;
	nodes.clearAllNodes();
	cout << "Loading" << endl;
	ifstream in(filename.toUtf8().constData(), std::ios::binary | std::ios::in);
	
	in.seekg(0, std::ios::end);
	uint numTotalBytes = in.tellg();
	in.seekg(0, std::ios::beg);

	char* header = new char[HEADER_BYTE_SIZE];//Reading in the header
	in.read(header, HEADER_BYTE_SIZE);

	uint geometryDataSize = * R_C(uint*, header);
	uint numNodes = * R_C(uint*, header + sizeof(uint));

	if(geometryDataSize>0)
	{
		char* geometryData = new char[geometryDataSize];//Reading in geometry data
		in.read(geometryData, geometryDataSize);
		ofstream out("ObjToBinaryResult.bin", std::ios::binary | std::ios::out);
		out.write(geometryData, geometryDataSize);
		out.close();
		ObjReader reader;
		levelData = reader.readInShape("ObjToBinaryResult.bin");
		setupLevelGeometry();
		levelLoaded = true;
		delete(geometryData);
	}

	uint nodeDataSize = numTotalBytes - (HEADER_BYTE_SIZE+geometryDataSize);
	char* nodeData = new char[nodeDataSize];//Reading in the node & connection data
	in.read(nodeData, nodeDataSize);
	in.close();

	cout << "numNodes " << numNodes << endl;

	nodes.loadInNodes(numNodes, nodeData);
	delete(nodeData);
	delete(header);
}


void GameWindow::loadLevelMap(QString fileName)
{
	if(levelLoaded)
		levelRenderable->visible = false;
	QString command("ObjToBinaryWriter.exe ");
	const char* nativeFileName = "ObjToBinaryResult.bin";
	command += "\"" + QString(fileName) + "\" \"" + nativeFileName + "\"";
	cout << command.toUtf8().constData() << endl;
	int result = system(command.toUtf8().constData());
	assert(result == 0);

	ObjReader reader;
	levelData = reader.readInShape("ObjToBinaryResult.bin");

	setupLevelGeometry();
	levelLoaded = true;
}

void GameWindow::setupLevelGeometry()
{
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


void GameWindow::updateLevelProjectionView()
{
	eyePosition = camera.getPosition();
	viewToProjectionMatrix = glm::perspective(60.0f, ((float)windowWidth) / windowHeight, 0.1f, 100.0f);
	worldToViewMatrix = camera.getWorldToViewMatrix();
	worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	DebugShapes::getInstance();
	DebugShapes::updateWorldToProjection(worldToProjectionMatrix);

	levelFullTransform = worldToProjectionMatrix * levelTransform;
	if(testCharacterLoaded)
	{
		character.fullTransform = worldToProjectionMatrix * character.modelToWorldTransform;
	}
}

void GameWindow::setupDebugShapes()
{

}

void GameWindow::keyPressReaction(QKeyEvent* e)
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

void GameWindow::mouseMoveReaction(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	updateLevelProjectionView();
	GeneralGLWindow::getInstance().repaint();
}

void GameWindow::update()
{
	frames++;
	GeneralGLWindow::getInstance().repaint();
	if(testCharacterLoaded)
	{
		if(!character.path.reachedEndNode)
		{
			character.modelToWorldTransform = character.path.getNextPathTransform();
			character.renderable->whereMatrix = character.modelToWorldTransform;
			character.rotation = character.path.currentRotation;
		}
		else
		{
			setupCharacterPath(currentCharacterGoal);
		}
	}
	updateLevelProjectionView();
}

GameWindow::GameWindow(void)
{
}


GameWindow::~GameWindow(void)
{
}