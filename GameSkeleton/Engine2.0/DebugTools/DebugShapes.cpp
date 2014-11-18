#include "DebugShapes.h"

#include <glm\gtc\quaternion.hpp>

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

#ifdef DEBUGSHAPES_ON
vector <DebugShapes::DebugShapeInfo*> DebugShapes::debugInfos;
mat4 DebugShapes::currentWorldToProjection;

long timePassed;
void DebugShapes::updateWorldToProjection(mat4 newWorldToProjection)
{
	currentWorldToProjection = newWorldToProjection;
	update();
}

void DebugShapes::tick()
{
	timePassed++;
	update();
}

void DebugShapes::update()
{
	for(uint i = 0; i< debugInfos.size(); i++)
	{
		uint limit = (debugInfos[i]->type == Point)? 3 : 1;
		for(uint j = 0; j<limit; j++)
		{
			debugInfos[i]->fullTransforms[j] = currentWorldToProjection * debugInfos[i]->renderables[j]->whereMatrix;
			if(debugInfos[i]->remainingLife == 0)
			{
				debugInfos[i]->renderables[j]->visible = false;
			}
			else if(debugInfos[i]->remainingLife >0)
			{
				debugInfos[i]->remainingLife -= (timePassed - debugInfos[i]->startTime);
			}
		}
	}
	GeneralGLWindow::getInstance().repaint();
}

Geometry* sphere;
bool sphereGeoAdded;
Geometry* cube;
bool cubeGeoAdded;
Geometry* line;
bool lineGeoAdded;
Geometry* pointLine;
bool pointLineGeoAdded;
Geometry* cone;
Geometry* cylinder;
bool vectorArrowGeoAdded;
Material* debugMat;

//ShaderInfo* debugShader;
void DebugShapes::setup()
{
	timePassed = 0;
	getInstance().timer.setInterval(1);
	getInstance().timer.start(0);
	connect(&getInstance().timer, SIGNAL(timeout()), &getInstance(), SLOT(tick()));
	debugMat = new Material();
	debugMat->shader = GeneralGLWindow::getInstance().createShaderInfo("Assets/Shaders/debugVertexShader.glsl", "Assets/Shaders/debugFragmentShader.glsl");
	//debugShader = GeneralGLWindow::getInstance().createShaderInfo("../Resources/Shaders/debugVertexShader.glsl", "../Resources/Shaders/debugFragmentShader.glsl");
}
float notCross = 0.0f;
float isCross = 1.0f;
float isVector = 2.0f;
DebugShapes::DebugShapeInfo* DebugShapes::addSphere(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime)
{
	if(!sphereGeoAdded)
	{
		Neumont::ShapeData sphereData = Neumont::ShapeGenerator::makeSphere(10);
		GeometryInfo* sphereInfo = GeneralGLWindow::getInstance().addGeometry(sphereData.verts, sphereData.vertexBufferSize(), sphereData.indices, sphereData.numIndices, GL_TRIANGLES);
		GeneralGLWindow::getInstance().addShaderStreamedParameter(sphereInfo, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
		sphere = new Geometry(sphereInfo);
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
		
		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(sphere, modelToWorld, true, enableDepth, PRIORITY_2, debugMat);
		shape->type = Sphere;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &notCross);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "passedColor", PT_VEC4, &shape->color[0]);
		debugInfos.push_back(shape);
	}

	shape->startTime = timePassed;
	return shape;
}
void DebugShapes::setupSphereGeo()
{
	sphere = Geometry::Sphere(10);
	sphereGeoAdded = true;
}
DebugShapes::DebugShapeInfo* DebugShapes::addNodeSphere(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime)
{
	if(!sphereGeoAdded)
	{
		setupSphereGeo();
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
		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(sphere, modelToWorld, true,enableDepth, PRIORITY_2, debugMat);
		shape->type = Sphere;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &notCross);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "passedColor", PT_VEC4, &shape->color[0]);
		debugInfos.push_back(shape);
	}

	shape->startTime = timePassed;
	return shape;
}
void DebugShapes::setupCubeGeo()
{
	cube = Geometry::Cube();
	cubeGeoAdded = true;
}
DebugShapes::DebugShapeInfo*  DebugShapes::addCube(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime)
{
	if(!cubeGeoAdded)
	{
		setupCubeGeo();
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

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(cube, modelToWorld, true, enableDepth, PRIORITY_2, debugMat);
		shape->type = Cube;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &notCross);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "passedColor", PT_VEC4, &shape->color[0]);
		debugInfos.push_back(shape);
	}

	shape->startTime = timePassed;
	return shape;
}
void DebugShapes::setupLineGeo()
{
	vec3 lineVerts[2] = { vec3(0,0,0), vec3(1,1,1) };
	ushort lineIndices[2] = { 0, 1 };
	Neumont::ShapeData lineData = Neumont::ShapeGenerator::makeLine();
	GeometryInfo* lineInfo = GeneralGLWindow::getInstance().addGeometry((const void*)(&lineVerts[0]), 2*sizeof(vec3), lineIndices, 2, GL_LINES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(lineInfo, 0, PT_VEC3, 0, sizeof(vec3));
	line = new Geometry(lineInfo);
	lineGeoAdded = true;
}
DebugShapes::DebugShapeInfo*  DebugShapes::addVector(vec3 tailPosition, vec3 vector, vec3 color, bool enableDepth, float lifeTime)
{
	if(!lineGeoAdded)
	{
		setupLineGeo();
	}


	mat4 fullModelToWorld = glm::translate(tailPosition) * glm::scale(vector);

	
	DebugShapeInfo* shape;
	int existingShapeIndex = existingAvailableShapeIndex(Vector);
	if(existingShapeIndex!=-1)
	{
		shape = debugInfos[existingShapeIndex];

		shape->remainingLife = lifeTime * 1000;
		shape->color = color;
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
		shape->color = color;
		shape->depthTest = enableDepth;
		shape->fullTransforms[0] = currentWorldToProjection * fullModelToWorld;

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(line, fullModelToWorld, true, enableDepth, PRIORITY_2, debugMat);
		shape->type = Vector;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &isVector);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "passedColor", PT_VEC4, &shape->color[0]);
		debugInfos.push_back(shape);
	}
	shape->startTime = timePassed;
	return shape;
}
void  DebugShapes::addGrid(vec3 position, int numXLines, int numZLines, bool enableDepth, float lifeTime)
{
	mat4 transform = glm::translate(position);
	int xPointAz = numZLines/2;
	int xPointBz = -(numZLines/2);
	int x = -numXLines/2;
	for(int i = 0; i < numXLines; i++)
	{
		vec3 start = vec3(x, 0, xPointAz);
		vec3 end = vec3(x, 0, xPointBz);
		addLine(start, end, vec3(1,1,1),enableDepth, lifeTime);
		x++;
	}
	int zPointAx = numXLines/2;
	int zPointBx = -(numXLines/2);
	int z = -numZLines/2;
	for(int i = 0; i < numZLines; i++)
	{
		vec3 start = vec3(zPointAx, 0, z);
		vec3 end = vec3(zPointBx, 0, z);
		addLine(start, end, vec3(1,1,1),enableDepth, lifeTime);
		z++;
	}

}
DebugShapes::DebugShapeInfo*  DebugShapes::addLine(vec3 startPoint, vec3 endPoint, vec3 Color, bool enableDepth, float lifeTime)
{
	if(!lineGeoAdded)
	{
		setupLineGeo();
	}


	vec3 newPosition = endPoint - startPoint;

	mat4 fullModelToWorld = glm::translate(startPoint) * glm::scale(newPosition);

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

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(line, fullModelToWorld, true, enableDepth, PRIORITY_2, debugMat);
		shape->type = Line;
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "fullTransformMatrix", PT_MAT4, &(shape->fullTransforms[0])[0][0]);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "isCrossHair", PT_FLOAT, &notCross);
		GeneralGLWindow::getInstance().addRenderableUniformParameter(shape->renderables[0], "passedColor", PT_VEC4, &shape->color[0]);
		debugInfos.push_back(shape);
	}
	shape->startTime = timePassed;
	return shape;
}

void DebugShapes::setupPointLineGeo()
{
	Neumont::ShapeData lineData = Neumont::ShapeGenerator::makeLine();
	GeometryInfo* pointLineInfo = GeneralGLWindow::getInstance().addGeometry(lineData.verts, lineData.vertexBufferSize(), lineData.indices, lineData.numIndices, GL_LINES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(pointLineInfo, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(pointLineInfo, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	pointLine = new Geometry(pointLineInfo);
	pointLineGeoAdded = true;
}

mat4 xLineRotation= glm::translate(vec3(-1, 0, 0)) * glm::scale(vec3(2, 1, 1));
mat4 yLineRotation= glm::translate(vec3(0, -1, 0)) * glm::rotate(90.0f, vec3(0,0,1)) * glm::scale(vec3(2, 1, 1));
mat4 zLineRotation= glm::translate(vec3(0, 0, -1)) * glm::rotate(-90.0f, vec3(0,1,0)) *glm::scale(vec3(2, 1, 1));
DebugShapes::DebugShapeInfo*  DebugShapes::addPoint(vec3 position, bool enableDepth, float lifeTime)
{
	if(!pointLineGeoAdded)
	{
		setupPointLineGeo();
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

		shape->renderables[0] = GeneralGLWindow::getInstance().addRenderable(pointLine, xLineTransform, true, enableDepth, PRIORITY_2, debugMat);
		shape->renderables[1] = GeneralGLWindow::getInstance().addRenderable(pointLine, yLineTransform, true, enableDepth, PRIORITY_2, debugMat);
		shape->renderables[2] = GeneralGLWindow::getInstance().addRenderable(pointLine, zLineTransform, true, enableDepth, PRIORITY_2, debugMat);
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

	shape->startTime = timePassed;
	return shape;

}

DebugShapes::VectorArrowInfo* DebugShapes::addVectorArrow(const glm::vec3& from, const glm::vec3& to)
{
	vec3 color = vec3(0.5f,1.0f,0.5f);
	VectorArrowInfo* arrow = new VectorArrowInfo();
	arrow->stem = addLine(vec3(from.x,0.01f,from.z),vec3(to.x,0.01f,to.z),color,true,-1);
	//A*t + (1-t)*B = lerp
	vec3 arrowPosition = to*0.90f + from*(1-0.90f);
	mat4 arrowHead = glm::translate(arrowPosition) * glm::scale(0.125f, 0.125f, 0.125f);
	arrow->head = addCube(arrowHead,color,true,-1);

	return arrow;
}

int DebugShapes::existingAvailableShapeIndex(ShapeType type)
{
	int index = -1;
	bool foundAvailableShape = false;
	for(uint i = 0; i< debugInfos.size() && !foundAvailableShape; i++)
	{
		if(debugInfos[i]->type==type && debugInfos[i]->remainingLife==0)
		{
			foundAvailableShape = true;
			index = i;
		}
	}
	return index;
}
#endif