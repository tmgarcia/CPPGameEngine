#pragma once
#pragma warning( disable : 4251 )
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"

using glm::vec3;
using glm::mat4;
#include "ExportHeader.h"

class DECL_DLL_EXPORT Transform
{
public:
	vec3 position;
	vec3 scale;

	float xRotationAngle;
	float yRotationAngle;
	float zRotationAngle;

	bool project;

	mat4 rotationMatrix;
	mat4 translationMatrix;
	mat4 scaleMatrix;
	mat4 modelToWorldMatrix;
	mat4 fullTransformMatrix;

	Transform();

	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	void scaleX(float scale);
	void scaleY(float scale);
	void scaleZ(float scale);
	void uniformScale(float scale);

	void lerpPosition(vec3 start, vec3 end, float progress);

	void update();

private:
	void initializeValues();
};

