#include "DebugShapes.h"

vector <DebugShapes::DebugShapeInfo*> DebugShapes::debugInfos;
mat4 DebugShapes::currentWorldToProjection;
DebugShapes* DebugShapes::theInstance;

DebugShapes& DebugShapes::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new DebugShapes();
		setup();
	}
	return *theInstance;
}

void DebugShapes::updateWorldToProjection(mat4 newWorldToProjection)
{
	currentWorldToProjection = newWorldToProjection;
	update();
}

void DebugShapes::update()
{
	for(int i = 0; i< debugInfos.size(); i++)
	{
		uint limit = (debugInfos[i]->type == Point)? 3 : 1;
		for(int j = 0; j<limit; j++)
		{
			debugInfos[i]->fullTransforms[j] = currentWorldToProjection * debugInfos[i]->renderables[j]->whereMatrix;
			//debugInfos[i]->renderables[j]->visible = debugInfos[i]->remainingLife > 0;
		}
		debugInfos[i]->remainingLife -= (getInstance().timer.interval() - debugInfos[i]->startTime);
	}
	GeneralGLWindow::getInstance().repaint();
}

GeometryInfo* sphere;
bool sphereGeoAdded;
GeometryInfo* cube;
bool cubeGeoAdded;
GeometryInfo* line;
bool lineGeoAdded;


ShaderInfo* debugShader;

void DebugShapes::setup()
{
	connect(&(DebugShapes::getInstance().timer), SIGNAL(timeout()), &DebugShapes::getInstance(), SLOT(update()));
	DebugShapes::getInstance().timer.start(0);
	debugShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/debugVertexShader.glsl", "../Resources/Shaders/debugFragmentShader.glsl");
}
float notCross = 0.0f;
float isCross = 1.0f;
void DebugShapes::addSphere(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime)
{
	if(!sphereGeoAdded)
	{
		Neumont::ShapeData sphereData = Neumont::ShapeGenerator::makeSphere(10);
		sphere = GeneralGLWindow::getInstance().addGeometry(sphereData.verts, sphereData.vertexBufferSize(), sphereData.indices, sphereData.numIndices, GL_TRIANGLES);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(sphere, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(sphere, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
		sphereGeoAdded = true;
	}
	
	DebugShapeInfo* shape;

	int existingShapeIndex = existingAvailableShapeIndex(Sphere);
	if(existingShapeIndex!=-1)
	{
		shape = debugInfos[existingShapeIndex];

		shape->remainingLife = lifeTime * 1000;
		shape->color = color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * modelToWorld;

		shape->renderables[0]->enableDepth = enableDepth;
		shape->renderables[0]->visible = true;
		shape->renderables[0]->whereMatrix = modelToWorld;
	}
	else
	{
		shape = new DebugShapeInfo();

		shape->remainingLife = lifeTime * 1000;
		shape->color = color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * modelToWorld;

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(sphere, modelToWorld, debugShader, true, PRIORITY_2, enableDepth);
		shape->type = Sphere;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &notCross);
		debugInfos.push_back(shape);
	}

	shape->startTime = getInstance().timer.interval();
}

void DebugShapes::addCube(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime)
{
	if(!cubeGeoAdded)
	{
		Neumont::ShapeData cubeData = Neumont::ShapeGenerator::makeCube();
		cube = GeneralGLWindow::getInstance().addGeometry(cubeData.verts, cubeData.vertexBufferSize(), cubeData.indices, cubeData.numIndices, GL_TRIANGLES);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(cube, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
		cubeGeoAdded = true;
	}
	
	DebugShapeInfo* shape;

	int existingShapeIndex = existingAvailableShapeIndex(Cube);
	if(existingShapeIndex!=-1)
	{
		shape = debugInfos[existingShapeIndex];

		shape->remainingLife = lifeTime * 1000;
		shape->color = color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * modelToWorld;

		shape->renderables[0]->enableDepth = enableDepth;
		shape->renderables[0]->visible = true;
		shape->renderables[0]->whereMatrix = modelToWorld;
	}
	else
	{
		shape = new DebugShapeInfo();

		shape->remainingLife = lifeTime * 1000;
		shape->color = color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * modelToWorld;

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(cube, modelToWorld, debugShader, true, PRIORITY_2, enableDepth);
		shape->type = Cube;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &notCross);
		debugInfos.push_back(shape);
	}

	shape->startTime = getInstance().timer.interval();
}
void DebugShapes::addVector(vec3 tailPosition, vec3 vector, vec3 color, bool enableDepth, float lifeTime)
{
	if(!lineGeoAdded)
	{
		Neumont::ShapeData lineData = Neumont::ShapeGenerator::makeLine();
		line = GeneralGLWindow::getInstance().addGeometry(lineData.verts, lineData.vertexBufferSize(), lineData.indices, lineData.numIndices, GL_LINES);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(line, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(line, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
		lineGeoAdded = true;
	}

	mat4 firstTransform = glm::translate(vec3(0.5f, 0.0f, 0.0f));
	firstTransform *= glm::scale(vec3(0.5f, 1, 1));
	vec3 originalPosition = vec3(0.5f, 0, 0);
	vec3 newPosition = tailPosition - vector;
	mat4 transformation = MathTools::getAlignMatrix(originalPosition, newPosition);
	
	DebugShapeInfo* shape;
	int existingShapeIndex = existingAvailableShapeIndex(Vector);
	if(existingShapeIndex!=-1)
	{
		shape = debugInfos[existingShapeIndex];

		shape->remainingLife = lifeTime * 1000;
		shape->color = color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * transformation;

		shape->renderables[0]->enableDepth = enableDepth;
		shape->renderables[0]->visible = true;
		shape->renderables[0]->whereMatrix = transformation;
	}
	else
	{
		shape = new DebugShapeInfo();

		shape->remainingLife = lifeTime * 1000;
		shape->color = color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * transformation;

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(line, transformation, debugShader, true, PRIORITY_2, enableDepth);
		shape->type = Vector;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &notCross);
		debugInfos.push_back(shape);
	}
	shape->startTime = getInstance().timer.interval();
}
void DebugShapes::addLine(vec3 startPoint, vec3 endPoint, vec3 Color, bool enableDepth, float lifeTime)
{
	if(!lineGeoAdded)
	{
		Neumont::ShapeData lineData = Neumont::ShapeGenerator::makeLine();
		line = GeneralGLWindow::getInstance().addGeometry(lineData.verts, lineData.vertexBufferSize(), lineData.indices, lineData.numIndices, GL_LINES);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(line, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(line, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
		lineGeoAdded = true;
	}

	
	vec3 originalStart = vec3(0,0,0);
	vec3 originalEnd = vec3(1,0,0);
	vec3 originalPosition = originalEnd-originalStart;

	vec3 newPosition = endPoint - startPoint;
	mat4 orientation = MathTools::getAlignMatrix(originalPosition, newPosition);
	
	float startMagnitude = glm::sqrt((startPoint.x*startPoint.x) + (startPoint.y*startPoint.y) + (startPoint.z*startPoint.z));
	float endMagnitude = glm::sqrt((endPoint.x*endPoint.x) + (endPoint.y*endPoint.y) + (endPoint.z*endPoint.z));
	float newMagnitude = endMagnitude - startMagnitude;

	mat4 fullModelToWorld =  orientation * glm::scale(vec3(newMagnitude, newMagnitude, newMagnitude));

	DebugShapeInfo* shape;
	int existingShapeIndex = existingAvailableShapeIndex(Line);
	if(existingShapeIndex!=-1)
	{
		shape = debugInfos[existingShapeIndex];

		shape->remainingLife = lifeTime * 1000;
		shape->color = Color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * fullModelToWorld;

		shape->renderables[0]->enableDepth = enableDepth;
		shape->renderables[0]->visible = true;
		shape->renderables[0]->whereMatrix = fullModelToWorld;
	}
	else
	{
		shape = new DebugShapeInfo();

		shape->remainingLife = lifeTime * 1000;
		shape->color = Color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * fullModelToWorld;

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(line, fullModelToWorld, debugShader, true, PRIORITY_2, enableDepth);
		shape->type = Line;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &notCross);
		debugInfos.push_back(shape);
	}
	shape->startTime = getInstance().timer.interval();
}

mat4 xLineRotation= glm::translate(vec3(-1, 0, 0)) * glm::scale(vec3(2, 1, 1));
mat4 yLineRotation= glm::translate(vec3(0, -1, 0)) * glm::rotate(90.0f, vec3(0,0,1)) * glm::scale(vec3(2, 1, 1));
mat4 zLineRotation= glm::translate(vec3(0, 0, -1)) * glm::rotate(-90.0f, vec3(0,1,0)) *glm::scale(vec3(2, 1, 1));
void DebugShapes::addPoint(vec3 position, bool enableDepth, float lifeTime)
{
	if(!lineGeoAdded)
	{
		Neumont::ShapeData lineData = Neumont::ShapeGenerator::makeLine();
		line = GeneralGLWindow::getInstance().addGeometry(lineData.verts, lineData.vertexBufferSize(), lineData.indices, lineData.numIndices, GL_LINES);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(line, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(line, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
		lineGeoAdded = true;
	}

	DebugShapeInfo* shape;

	mat4 translate = glm::translate(position);
	mat4 xLineTransform = translate * xLineRotation;
	mat4 yLineTransform = translate * yLineRotation;
	mat4 zLineTransform = translate * zLineRotation;

	int existingShapeIndex = existingAvailableShapeIndex(Point);
	if(existingShapeIndex!=-1)
	{
		shape = debugInfos[existingShapeIndex];

		shape->remainingLife = lifeTime * 1000;
		shape->color = vec3(0,0,0);
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * xLineTransform;
		shape->fullTransforms[1] = currentWorldToProjection * yLineTransform;
		shape->fullTransforms[2] = currentWorldToProjection * zLineTransform;

		shape->renderables[0]->enableDepth = enableDepth;
		shape->renderables[0]->visible = true;
		shape->renderables[0]->whereMatrix = xLineTransform;
		shape->renderables[1]->enableDepth = enableDepth;
		shape->renderables[1]->visible = true;
		shape->renderables[1]->whereMatrix = yLineTransform;
		shape->renderables[2]->enableDepth = enableDepth;
		shape->renderables[2]->visible = true;
		shape->renderables[2]->whereMatrix = zLineTransform;
	}
	else
	{
		shape = new DebugShapeInfo();

		shape->remainingLife = lifeTime * 1000;
		shape->color = vec3(0,0,0);
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * xLineTransform;
		shape->fullTransforms[1] = currentWorldToProjection * yLineTransform;
		shape->fullTransforms[2] = currentWorldToProjection * zLineTransform;

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(line, xLineTransform, debugShader, true, PRIORITY_2, enableDepth);
		shape->renderables[1] = GeneralGLWindow::getInstance().addRenderable(line, yLineTransform, debugShader, true, PRIORITY_2, enableDepth);
		shape->renderables[2] = GeneralGLWindow::getInstance().addRenderable(line, zLineTransform, debugShader, true, PRIORITY_2, enableDepth);
		shape->type = Point;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &isCross);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "rotation", PT_MAT4, &xLineRotation[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[1], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[1])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[1], "isCrossHair", PT_FLOAT, &isCross);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[1], "rotation", PT_MAT4, &yLineRotation[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[2], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[2])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[2], "isCrossHair", PT_FLOAT, &isCross);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[2], "rotation", PT_MAT4, &zLineRotation[0][0]);
		debugInfos.push_back(shape);
	}

	shape->startTime = getInstance().timer.interval();

}

int DebugShapes::existingAvailableShapeIndex(ShapeType type)
{
	int index = -1;
	bool foundAvailableShape = false;
	for(int i = 0; i< debugInfos.size() && !foundAvailableShape; i++)
	{
		if(debugInfos[i]->type==type && debugInfos[i]->remainingLife<0)
		{
			foundAvailableShape = true;
			index = i;
		}
	}
	return index;
}