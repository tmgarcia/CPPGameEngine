#pragma once

#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
using glm::vec3;
using glm::mat4;

class __declspec(dllexport) MathTools
{
private:
	MathTools(const MathTools&);
	MathTools& operator = (const MathTools&);
	static MathTools theInstance;
public:
	MathTools(){}
	static MathTools& getInstance();
	static mat4 getAlignMatrix(const vec3& originalOrientation, const vec3& newOrientation);
};

