#include "GameLevel.h"


#define R_CS(a) reinterpret_cast<char*>(&a), sizeof(a)
#define R_C(t,a) reinterpret_cast<t>(a)//cast a to t
uint HEADER_BYTE_SIZE = 2*sizeof(uint);//how many bites in header
uint SERIALIZED_NODE_SIZE1 = sizeof(vec3) + sizeof(uint) + sizeof(uint);
uint SERIALIZED_CONNECTION_SIZE1 = sizeof(float) + sizeof(uint);

using std::ofstream;
using std::ifstream;

void GameLevel::update(vec3 eye, mat4 worldToProjectionMatrix)
{
	eyePosition = eye;
	fullTransform = worldToProjectionMatrix * modelToWorldTransform;
}

void GameLevel::loadLevel(QString fileName)
{
	DebugNodeContainer::getInstance().clearAllNodes();
	cout << "Loading Level" << endl;
	ifstream in(fileName.toUtf8().constData(), std::ios::binary | std::ios::in);
	
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
		shapeData = reader.readInShape("ObjToBinaryResult.bin");
		setupLevelGeometry();
		delete(geometryData);
	}

	uint nodeDataSize = numTotalBytes - (HEADER_BYTE_SIZE+geometryDataSize);
	char* nodeData = new char[nodeDataSize];//Reading in the node & connection data
	in.read(nodeData, nodeDataSize);
	in.close();

	cout << "numNodes " << numNodes << endl;

	DebugNodeContainer::getInstance().loadInNodes(numNodes, nodeData);
	delete(nodeData);
	delete(header);

	baseNode = DebugNodeContainer::getInstance().getNode(0);
}

void GameLevel::setLightPosition(vec3 p)
{
	lightPosition = p;
}

void GameLevel::setEyePosition(vec3 p)
{
	eyePosition = p;
}

void GameLevel::setVisible(bool visible)
{
	renderable->visible = visible;
}


void GameLevel::setupLevelGeometry()
{
	geometry = GeneralGLWindow::getInstance().addGeometry(shapeData.vertices, shapeData.vertexDataSize, shapeData.indices, shapeData.numIndices, GL_TRIANGLES);
	texture = GeneralGLWindow::getInstance().addTexture("../Resources/Textures/skyTexture.bmp");
	shader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/LightingAndTextureVertexShader.glsl", "../Resources/Shaders/LightingAndTextureFragmentShader.glsl");

	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, BinReader::POSITION_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, BinReader::NORMAL_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 3, PT_VEC2, BinReader::UV_OFFSET, BinReader::STRIDE);

	renderable = GeneralGLWindow::getInstance().addRenderable(geometry, modelToWorldTransform, shader, true, PRIORITY_1, true, texture);

	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &diffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &specularColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &specularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &overridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &ambientLight[0]);
																 
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, &fullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, &rotation[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}

GameLevel* GameLevel::theInstance;

GameLevel& GameLevel::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new GameLevel();
	}
	return *theInstance;
}