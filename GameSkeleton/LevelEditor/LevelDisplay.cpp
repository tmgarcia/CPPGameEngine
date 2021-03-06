#include "LevelDisplay.h"
#include "BinReader.h"
#include "DebugShapes.h"

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

vec3 red = vec3(1, 0, 0);
vec3 yellow = vec3(1, 1, 0);
vec3 blue = vec3(0, 0, 1);

GeometryInfo* levelGeometry;
RenderableInfo* levelRenderable;
ShaderInfo* lightingShader;

BinReader::ShapeData levelData;

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
	levelLoaded = false;
	cameraFrozen=false;
}

void LevelDisplay::setupForNewLevel()
{
}

#define R_CS(a) reinterpret_cast<char*>(&a), sizeof(a)
#define R_C(t,a) reinterpret_cast<t>(a)//cast a to t
uint HEADER_BYTE_SIZE = 2*sizeof(uint);//how many bites in header
uint SERIALIZED_NODE_SIZE1 = sizeof(vec3) + sizeof(uint) + sizeof(uint);
uint SERIALIZED_CONNECTION_SIZE1 = sizeof(float) + sizeof(uint);

void LevelDisplay::loadLevel(QString filename)
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
		BinReader reader;
		levelData = reader.readInShape("ObjToBinaryResult.bin");
		setupLevelGeometry();
	}

	uint nodeDataSize = numTotalBytes - (HEADER_BYTE_SIZE+geometryDataSize);
	char* nodeData = new char[nodeDataSize];//Reading in the node & connection data
	in.read(nodeData, nodeDataSize);
	in.close();

	cout << "numNodes " << numNodes << endl;

	nodes.loadInNodes(numNodes, nodeData);
	levelLoaded = true;
	cout << "Done loading" << endl;
}


void LevelDisplay::saveLevel(QString filename)
{
	cout << "Saving" << endl;

	uint NUM_NODES = nodes.numNodes;

	//Reading in level file
	uint numLevelBytes = 0;
	char* levelBuf = nullptr;
	if(levelLoaded)
	{
		ifstream levelIn("ObjToBinaryResult.bin", std::ios::binary | std::ios::in);
		levelIn.seekg(0, std::ios::end);
		numLevelBytes = levelIn.tellg();
		levelIn.seekg(0, std::ios::beg);
		levelBuf = new char[numLevelBytes];
		levelIn.read(levelBuf, numLevelBytes);
		levelIn.close();
	}

	uint NODE_DATA_BASE = HEADER_BYTE_SIZE + numLevelBytes;//Where node data starts

	ofstream out(filename.toUtf8().constData(), std::ios::binary | std::ios::out);
	
	//Writing out header 
	out.write(R_CS(numLevelBytes));//size of the geometry data
	out.write(R_CS(NUM_NODES));//Number of nodes
	
	if(levelLoaded)
	{
		//Writing out level data
		out.write(levelBuf, numLevelBytes);
	}

	//Writing out node and connection data
	nodes.serializeNodes(&out, NODE_DATA_BASE);

	out.close();
}


void LevelDisplay::loadLevelMap(QString fileName)
{
	//setupForNewLevel();
	//int i = system("cd .");
	//i = system("dir");
	//cout << i << endl;
	if(levelLoaded)
		levelRenderable->visible = false;
	QString command("ObjToBinaryWriter.exe ");
	const char* nativeFileName = "ObjToBinaryResult.bin";
	command += "\"" + QString(fileName) + "\" \"" + nativeFileName + "\"";
	cout << command.toUtf8().constData() << endl;
	int result = system(command.toUtf8().constData());
	assert(result == 0);

	BinReader reader;
	levelData = reader.readInShape("ObjToBinaryResult.bin");

	setupLevelGeometry();
	levelLoaded = true;
}

void LevelDisplay::setupLevelGeometry()
{
	levelGeometry = GeneralGLWindow::getInstance().addGeometry(levelData.vertices, levelData.vertexDataSize, levelData.indices, levelData.numIndices, GL_TRIANGLES);
	
	lightingShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/justLightingVertexShader.glsl", "../Resources/Shaders/justLightingFragmentShader.glsl");

	GeneralGLWindow::getInstance().addShaderStreamedParameter(levelGeometry, 0, PT_VEC3, BinReader::POSITION_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(levelGeometry, 2, PT_VEC3, BinReader::NORMAL_OFFSET, BinReader::STRIDE);

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
		if(!cameraFrozen)
			camera.moveForward();
		break;
	case Qt::Key::Key_S:
		if(!cameraFrozen)
			camera.moveBackward();
		break;
	case Qt::Key::Key_A:
		if(!cameraFrozen)
			camera.strafeLeft();
		break;
	case Qt::Key::Key_D:
		if(!cameraFrozen)
			camera.strafeRight();
		break;
	case Qt::Key::Key_R:
		if(!cameraFrozen)
			camera.moveUp();
		break;
	case Qt::Key::Key_F:
		if(!cameraFrozen)
			camera.moveDown();
		break;
	case Qt::Key::Key_Delete:
		if(aNodeIsSelected)
		{
			nodes.deleteSelectedNode();
		}
		break;
	case Qt::Key::Key_0:
		cameraFrozen = !cameraFrozen;
		break;
	}
	updateLevelProjectionView();

	GeneralGLWindow::getInstance().repaint();
}

void LevelDisplay::mouseMoveReaction(QMouseEvent* e)
{
	if(!cameraFrozen)
	{
		camera.mouseUpdate(glm::vec2(e->x(), e->y()));
		updateLevelProjectionView();
		GeneralGLWindow::getInstance().repaint();
	}
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
