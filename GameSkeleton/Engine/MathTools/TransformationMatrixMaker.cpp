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
	//vwu faces with belly
	//wvu faces with side upside-down
	//vuw on side facing with tail
	//uvw upside-down facing with tail
	//wuv head down facing with side
	//uwv head down facing with stomach
	mat4 result = mat4(vec4(u, 0), vec4(-v,0), vec4(w,0), vec4(0,0,0,1));//-w for camera
	//u-v-w - original
	//u-vw
	//uvw
	//-uvw
	//uwv
	return result;
}