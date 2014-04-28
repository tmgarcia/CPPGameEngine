#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

using glm::mat4;
using glm::vec3;
using glm::vec4;

class __declspec(dllexport) TransformationMatrixMaker
{
public:
	static TransformationMatrixMaker& getInstance();
private:
	static TransformationMatrixMaker* theInstance;
	TransformationMatrixMaker(){}
	TransformationMatrixMaker(const TransformationMatrixMaker&);
	TransformationMatrixMaker& operator = (const TransformationMatrixMaker&);

public:
	mat4 getRotationFromVector(vec3 v);
};

