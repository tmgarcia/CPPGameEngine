#include "NonPlayerCharacter.h"

#include "../Renderer/GeneralGLWindow.h"
#include "../AStarData/PathCreator.h"
#include "../GameObjects/GameLevel.h"
#include "FetchingFlagState.h"
#include "ReturningToBaseState.h"

NonPlayerCharacter::NonPlayerCharacter(QString modelFile, DebugNode* base, mat4 worldToProjectionMatrix)
{
	cout << "---character Construction started---" << endl;

	baseNode = base;
	currentNode = baseNode;
	position = baseNode->position;
	cout << "Position= " << position.x << "," << position.y << "," << position.z << endl;
	isPathing = false;
	hasFlag = false;
	speed = 0.5f;
	modelToWorldTransform = glm::translate(position);
	cout << "Model To World= " << endl;
	cout << "    " << modelToWorldTransform[0][0] << "," <<  modelToWorldTransform[0][1] << "," <<  modelToWorldTransform[0][2] << "," <<  modelToWorldTransform[0][3] << endl;
	cout << "    " << modelToWorldTransform[1][0] << "," <<  modelToWorldTransform[1][1] << "," <<  modelToWorldTransform[0][2] << "," <<  modelToWorldTransform[1][3] << endl;
	cout << "    " << modelToWorldTransform[2][0] << "," <<  modelToWorldTransform[2][1] << "," <<  modelToWorldTransform[0][2] << "," <<  modelToWorldTransform[2][3] << endl;
	cout << "    " << modelToWorldTransform[3][0] << "," <<  modelToWorldTransform[3][1] << "," <<  modelToWorldTransform[0][2] << "," <<  modelToWorldTransform[3][3] << endl;
	worldToProjection = worldToProjectionMatrix;

	gettingFlagState = new FetchingFlagState();
	returningHomeState = new ReturningToBaseState();

	state = gettingFlagState;
	loadModel(modelFile);

	cout << "---character Construction done---" << endl;
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
void NonPlayerCharacter::setStateToReturnHome()
{
	state = returningHomeState;
}
void NonPlayerCharacter::setStateToFetchingFlag()
{
	state = gettingFlagState;
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
	cout << "Geometry data: vertexDataSize="<< shapeData.vertexDataSize << ", numIndices=" << shapeData.numIndices << endl;
	
	shader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/justLightingVertexShader.glsl", "../Resources/Shaders/justLightingFragmentShader.glsl");

	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, BinReader::POSITION_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, BinReader::NORMAL_OFFSET, BinReader::STRIDE);

	renderable = GeneralGLWindow::getInstance().addRenderable(geometry, modelToWorldTransform, shader, true, PRIORITY_2, true);

	fullTransform = worldToProjection* modelToWorldTransform;
	
	cout << "World To Projection= " << endl;
	cout << "    " << worldToProjection[0][0] << "," <<  worldToProjection[0][1] << "," <<  worldToProjection[0][2] << "," <<  worldToProjection[0][3] << endl;
	cout << "    " <<worldToProjection[1][0] << "," <<  worldToProjection[1][1] << "," <<  worldToProjection[0][2] << "," <<  worldToProjection[1][3] << endl;
	cout << "    " <<worldToProjection[2][0] << "," <<  worldToProjection[2][1] << "," <<  worldToProjection[0][2] << "," <<  worldToProjection[2][3] << endl;
	cout << "    " <<worldToProjection[3][0] << "," <<  worldToProjection[3][1] << "," <<  worldToProjection[0][2] << "," <<  worldToProjection[3][3] << endl;

	cout << "Full Transform= " << endl;
	cout << "    " << fullTransform[0][0] << "," <<  fullTransform[0][1] << "," <<  fullTransform[0][2] << "," <<  fullTransform[0][3] << endl;
	cout << "    " << fullTransform[1][0] << "," <<  fullTransform[1][1] << "," <<  fullTransform[0][2] << "," <<  fullTransform[1][3] << endl;
	cout << "    " << fullTransform[2][0] << "," <<  fullTransform[2][1] << "," <<  fullTransform[0][2] << "," <<  fullTransform[2][3] << endl;
	cout << "    " << fullTransform[3][0] << "," <<  fullTransform[3][1] << "," <<  fullTransform[0][2] << "," <<  fullTransform[3][3] << endl;

	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "lightPosition", PT_VEC3, &GameLevel::getInstance().lightPosition[0]);
	cout << "Light postition: " << GameLevel::getInstance().lightPosition.x << "," << GameLevel::getInstance().lightPosition.y << "," << GameLevel::getInstance().lightPosition.z << endl;
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "diffusionIntensity", PT_FLOAT, &GameLevel::getInstance().diffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularColor", PT_VEC4, &GameLevel::getInstance().specularColor[0]);
	cout << "Specular Color: " << GameLevel::getInstance().specularColor.x << "," << GameLevel::getInstance().specularColor.y << "," << GameLevel::getInstance().specularColor.z << endl;
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "specularExponent", PT_FLOAT, &GameLevel::getInstance().specularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "eyePosition", PT_VEC3, &GameLevel::getInstance().eyePosition[0]);
	cout << "Eye position: " << GameLevel::getInstance().eyePosition.x << "," << GameLevel::getInstance().eyePosition.y << "," << GameLevel::getInstance().eyePosition.z << endl;
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "overridingObjectColor", PT_VEC3, &GameLevel::getInstance().overridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "ambientLight", PT_VEC3, &GameLevel::getInstance().ambientLight[0]);
																 
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, &fullTransform[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "rotationMatrix", PT_MAT4, &rotation[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "modelToWorldMatrix", PT_MAT4, &renderable->whereMatrix[0][0]);
	cout << "renderable-> where Matrix = " << endl;
	cout << "    " << renderable->whereMatrix[0][0] << "," <<  renderable->whereMatrix[0][1] << "," <<  renderable->whereMatrix[0][2] << "," <<  renderable->whereMatrix[0][3] << endl;
	cout << "    " << renderable->whereMatrix[1][0] << "," <<  renderable->whereMatrix[1][1] << "," <<  renderable->whereMatrix[0][2] << "," <<  renderable->whereMatrix[1][3] << endl;
	cout << "    " << renderable->whereMatrix[2][0] << "," <<  renderable->whereMatrix[2][1] << "," <<  renderable->whereMatrix[0][2] << "," <<  renderable->whereMatrix[2][3] << endl;
	cout << "    " << renderable->whereMatrix[3][0] << "," <<  renderable->whereMatrix[3][1] << "," <<  renderable->whereMatrix[0][2] << "," <<  renderable->whereMatrix[3][3] << endl;

	cout << "PROGRAM ID "<< shader->programID << endl;

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