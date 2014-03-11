#pragma once
#include "glm\glm.hpp"
#include <iostream>
#include <vector>
#include "ShapeData.h"
#include "ShapeGenerator.h"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
#include "..\Renderer\GeneralGLWindow.h"

using std::vector;
using glm::vec3;
using glm::mat4;

class __declspec(dllexport) DebugShapes : public QObject
{
	Q_OBJECT

public:
	static DebugShapes& getInstance();
private:
	QTimer timer;
	static DebugShapes* theInstance;
	DebugShapes(){}
	DebugShapes(const DebugShapes&);
	DebugShapes& operator = (const DebugShapes&);

#if DEBUGSHAPES_ON
private slots:
	static void tick();
private:
	static void update();
	static mat4 currentWorldToProjection;
	enum ShapeType {Sphere, Cube, Vector, Line, Point};
	struct DebugShapeInfo
	{
		RenderableInfo* renderables[3];
		mat4 fullTransforms[3];
		float remainingLife;
		float startTime;
		bool depthTest;
		vec3 color;
		ShapeType type;
	};
	static vector <DebugShapeInfo*> debugInfos;
	static int existingAvailableShapeIndex(ShapeType type);
	static void setup();
#endif
public:
#if DEBUGSHAPES_ON
	static void updateWorldToProjection(mat4 newWorldToProjection);
	static void addSphere(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime);
	static void addCube(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime);
	static void addVector(vec3 tailPosition, vec3 vector, vec3 color, bool enableDepth, float lifeTime);
	static void addLine(vec3 startPoint, vec3 endPoint, vec3 Color, bool enableDepth, float lifeTime);
	static void addPoint(vec3 position, bool enableDepth, float lifeTime);
#else
	static void updateWorldToProjection(mat4 newWorldToProjection){}
	static void addSphere(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime){}
	static void addCube(mat4 modelToWorld, vec3 color, bool enableDepth, float lifeTime){}
	static void addVector(vec3 tailPosition, vec3 vector, vec3 color, bool enableDepth, float lifeTime){}
	static void addLine(vec3 startPoint, vec3 endPoint, vec3 Color, bool enableDepth, float lifeTime){}
	static void addPoint(vec3 position, bool enableDepth, float lifeTime){}
	private slots:
		static void tick(){}
private:
	static void setup(){}

#endif
};