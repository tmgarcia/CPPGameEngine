#include "NonPlayerCharacter.h"

#include "../Renderer/GeneralGLWindow.h"
#include "../AStarData/PathCreator.h"
#include "../GameObjects/GameLevel.h"
#include "FetchingFlagState.h"
#include "ReturningToBaseState.h"

NonPlayerCharacter::NonPlayerCharacter(QString modelFile, DebugNode* base, mat4 worldToProjectionMatrix)
{
	cout << "character Construction" << endl;

	baseNode = base;
	currentNode = baseNode;
	position = baseNode->position;
	isPathing = false;
	hasFlag = false;
	speed = 0.5f;
	modelToWorldTransform = glm::translate(position);
	worldToProjection = worldToProjectionMatrix;
	state = new FetchingFlagState();
	loadModel(modelFile);
}

void NonPlayerCharacter::updatePathPosition()
{
	if(isPathing)
	{
		cout << "updating Path Position" << endl;
		vec3 newPosition = path.getNextPathPosition();
		mat4 nextTranslation = glm::translate(newPosition);
		mat4 nextRotation = path.currentRotation;
		modelToWorldTransform = nextTranslation * nextRotation;
		fullTransform = worldToProjection* modelToWorldTransform;
		position = newPosition;
		cout << "position "<< position.x <<","<<position.y<<","<<position.z << endl;

		renderable->whereMatrix = modelToWorldTransform;
		rotation = nextRotation;
		currentNode = path.getCurrentNode();

		state->update(this);
	}
}

void NonPlayerCharacter::updateFullTransform(mat4 worldToProjectionMatrix)
{
	worldToProjection = worldToProjectionMatrix;
	fullTransform = worldToProjectionMatrix * modelToWorldTransform;
}

vec3 NonPlayerCharacter::getPosition()
{
	return position;
}
mat4 NonPlayerCharacter::getRotation()
{
	return rotation;
}
State* NonPlayerCharacter::getState()
{
	return state;
}
DebugNode* NonPlayerCharacter::getBaseNode()
{
	return baseNode;
}
DebugNode* NonPlayerCharacter::getCurrentNode()
{
	return currentNode;
}
void NonPlayerCharacter::setVisible(bool visible)
{
	cout << "character visible "<< visible << endl;
	renderable->visible = visible;
}
void NonPlayerCharacter::setSpeed(float s)
{
	speed = s;
}
void NonPlayerCharacter::setState(State* s)
{
	state = s;
}
void NonPlayerCharacter::startPathing(DebugNode* endNode)
{
	cout << "character started pathing" << endl;
	currentGoalNode = endNode;
	setupPath();
	isPathing = true;
}
void NonPlayerCharacter::stopPathing()
{
	cout << "character stopped pathing" << endl;
	isPathing = false;
}
void NonPlayerCharacter::setNewPathGoal(DebugNode* endNode)
{
	cout << "character got new path goal" << endl;
	currentGoalNode = endNode;
	setupPath();
}
bool NonPlayerCharacter::reachedCurrentGoalNode()
{
	return (position == currentGoalNode->position);
}
bool NonPlayerCharacter::isCurrentlyPathing()
{
	return isPathing;
}
void NonPlayerCharacter::highlightPathNodes(vec3 color)
{
	path.highlightPathNodes(color);
}
void NonPlayerCharacter::hidePathNodes()
{
	path.hidePathNodes();
}
void NonPlayerCharacter::highlightPathConnections(vec3 color)
{
	path.highlightPathConnections(color);
}
void NonPlayerCharacter::hidePathConnections()
{
	path.hidePathConnections();
}

//--------------------------------------------------------------------

void NonPlayerCharacter::loadModel(QString fileName)
{
	cout << "Loading Character Model" << endl;
	QString command("ObjToBinaryWriter.exe ");
	const char* nativeFileName = "Character.bin";
	command += "\"" + QString(fileName) + "\" \"" + nativeFileName + "\"";
	cout << command.toUtf8().constData() << endl;
	int result = system(command.toUtf8().constData());
	assert(result == 0);

	BinReader reader;
	shapeData = reader.readInShape("Character.bin");
	modelToWorldTransform = glm::translate(baseNode->position);
	rotation = mat4();
	renderModel();
}


void NonPlayerCharacter::renderModel()
{
	cout << "setting up character for renderer" << endl;
	geometry = GeneralGLWindow::getInstance().addGeometry(shapeData.vertices, shapeData.vertexDataSize, shapeData.indices, shapeData.numIndices, GL_TRIANGLES);
	
	shader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/justLightingVertexShader.glsl", "../Resources/Shaders/justLightingFragmentShader.glsl");

	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, BinReader::POSITION_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, BinReader::NORMAL_OFFSET, BinReader::STRIDE);

	renderable = GeneralGLWindow::getInstance().addRenderable(geometry, modelToWorldTransform, shader, true, PRIORITY_1, true);

	fullTransform = worldToProjection* modelToWorldTransform;
	
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &GameLevel::getInstance().lightPosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &GameLevel::getInstance().diffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &GameLevel::getInstance().specularColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &GameLevel::getInstance().specularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &GameLevel::getInstance().eyePosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &GameLevel::getInstance().overridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &GameLevel::getInstance().ambientLight[0]);
																 
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, &fullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, &rotation[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
}
void NonPlayerCharacter::setupPath()
{	
	cout << "character setting up new path" << endl;
	PathCreator pathCreator;
	Path p;
	p = pathCreator.calculatePath(baseNode, currentGoalNode);
	p.speed = speed;
	if(path.pathHighlighted)
	{
		p.highlightPathNodes(path.pathHighlightColor);
		path.hidePathNodes();
	}
	if(path.pathConnectionsHighlighted)
	{
		p.highlightPathConnections(path.pathConnectionHighlightColor);
		path.hidePathConnections();
	}
	path = p;
	
}