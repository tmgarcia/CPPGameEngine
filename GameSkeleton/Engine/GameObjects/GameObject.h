#pragma once

#include "..\Renderer\GeneralGLWindow.h"
//#include <glm\glm.hpp>
//#include "glm\gtx\transform.hpp"
//#include "Renderer\RenderableInfo.h"

using glm::vec3;
using glm::vec4;
using glm::vec2;
using glm::mat4;

class __declspec(dllexport) GameObject
{
public:
	RenderableInfo* renderable;

	mat4 rotationMatrix;
	mat4 translationMatrix;
	mat4 scalingMatrix;
	mat4 modelToWorldMatrix;
	mat4 fullTransformMatrix;

	vec3 position;
	vec3 scale;

	float xRotationAngle;
	float yRotationAngle;
	float zRotationAngle;

	bool project;

	void setupTransforms(vec3 _position, vec3 _scale, float xRotation, float yRotation, float zRotation, mat4 worldToProjectionMatrix);
	void updateTransforms(mat4 worldToProjectionMatrix);
};
