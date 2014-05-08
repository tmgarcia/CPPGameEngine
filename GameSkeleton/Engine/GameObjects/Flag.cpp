#include "Flag.h"

#include "GameLevel.h"
void Flag::setAtNode(DebugNode* node)
{
	currentNode = node;
	position = currentNode->position;
	modelToWorldTransform = glm::translate(position)*glm::rotate(90.0f,vec3(0,1,0))*glm::scale(vec3(0.5f, 0.5f, 0.5f));
	fullTransform = worldToProjection* modelToWorldTransform;
}
void Flag::setPosition(vec3 p)
{
	position = p;
	position.y = 0.5;
	modelToWorldTransform = glm::translate(position)*glm::rotate(90.0f,vec3(0,1,0))*glm::scale(vec3(0.5f, 0.5f, 0.5f));
	fullTransform = worldToProjection* modelToWorldTransform;
}
DebugNode* Flag::getCurrentNode()
{
	return currentNode;
}
vec3 Flag::getPosition()
{
	return position;
}
void Flag::update(mat4 worldToProjectionMatrix)
{
	worldToProjection = worldToProjectionMatrix;
	fullTransform = worldToProjectionMatrix * modelToWorldTransform;
}



void Flag::loadModel(char* modelFile)
{
	BinReader reader;
	shapeData = reader.readInShape(modelFile);
	modelToWorldTransform = glm::translate(position)*glm::rotate(90.0f,vec3(0,1,0))*glm::scale(vec3(0.5f, 0.5f, 0.5f));
	rotation = mat4();
	renderModel();
}

void Flag::renderModel()
{
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