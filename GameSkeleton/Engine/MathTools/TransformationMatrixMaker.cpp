#include "TransformationMatrixMaker.h"


TransformationMatrixMaker* TransformationMatrixMaker::theInstance;

TransformationMatrixMaker& TransformationMatrixMaker::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new TransformationMatrixMaker();
	}
	return *theInstance;
}

//For objects facing in the negative Z direction
mat4 TransformationMatrixMaker::getRotationFromVector(vec3 a)
{
	vec3 m = vec3(0,1,0);
	vec3 n = vec3(1,0,0);
	vec3 w = glm::normalize(a);//y
	vec3 u = glm::cross(w, m);//z
	if(glm::pow(glm::length(u),2.0f)< 0.000000001)
	{
		u = glm::cross(w, n);
	}
	vec3 v = glm::cross(w, u);//x
	mat4 result = mat4(vec4(u, 0), vec4(-v,0), vec4(w,0), vec4(0,0,0,1));//-w for camera
	return result;
}

mat4 TransformationMatrixMaker::getBillboardTransformation(vec3 position, vec3 cameraPosition, vec3 cameraUp, bool translate)
{
	vec3 look = glm::normalize(cameraPosition - position);
	vec3 right = glm::cross(cameraUp, look);
	vec3 up2 = glm::cross(look, right);
	mat4 transform;
	transform[0] = vec4(right, 0);
	transform[1] = vec4(up2, 0);
	transform[2] = vec4(look, 0);
	if(translate)
	{
		transform[3] = vec4(position, 1);
	}
	return transform;
}