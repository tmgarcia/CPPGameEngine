#define assert(a)
#include "RenderUI.h"
#include "Engine.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

using glm::vec2;
using glm::vec3;
using glm::mat2x2;
using glm::mat3x3;
using glm::mat4x4;

vec2 left;
vec2 right;
vec2 result;

vec2 original;
vec2 normal;
vec2 cwPerp;
vec2 ccwPerp;

vec2 vector1;
vec2 vector2;
vec2 projectionVector;
vec2 rejectionVector;

vec2 aVector;
vec2 bVector;
vec2 aMinusBVector;
vec2 aVectorLerpPortion;
vec2 bVectorLerpPortion;
vec2 lerpResultVector;

vec2 p;
vec2 n;
vec2 d;

void MyBasicVectorEquationCallback(const BasicVectorEquationInfo& info)
{
	left = info.scalar1 * vec2(info.x1, info.y1);
	right = info.scalar2 * vec2(info.x2, info.y2);

	if(info.add)
	{
		result = left + right;
	}
	else
	{
		result = left - right;
	}
	
}

void MyPerpendicularDataCallback(const PerpendicularData& data)
{
	original = vec2(data.x, data.y);
	normal = glm::normalize(original);
	cwPerp = vec2(original.y*-1, original.x);
	ccwPerp = vec2(original.y, original.x*-1);

}

void MyDotProductDataCollback(const DotProductData& data)
{
	vector1 = vec2(data.v1i, data.v1j);
	vector2 = vec2(data.v2i, data.v2j);
	if(data.projectOntoLeftVector)
	{
		projectionVector = glm::dot(vector2, vector1) / glm::dot(vector1, vector1) * vector1;
		rejectionVector = vector2 - projectionVector;
	}
	else
	{
		projectionVector = glm::dot(vector1, vector2) / glm::dot(vector2, vector2) * vector2;
		rejectionVector = vector1 - projectionVector;
	}
}

void MyLerpDataCallback(const LerpData& data)
{
	aVector = vec2(data.a_i, data.a_j);
	bVector = vec2(data.b_i, data.b_j);
	aMinusBVector = bVector-aVector;
	aVectorLerpPortion = (1-data.beta)*aVector;
	bVectorLerpPortion = data.beta * bVector;
	lerpResultVector = (((1-data.beta)*aVector) + (data.beta*bVector));
}


vec2 linResult;
void MyLinearTransformationCallback(const LinearTransformationData& data)
{
	mat2x2 op = mat2x2(data.m00,data.m01, data.m10, data.m11);
	vec2 v = vec2(data.v0, data.v1);
	linResult = op*v;
}

vec3 affResult[5];
void MyAffineTransformationCallback(const AffineTransformationData& data)
{
	mat3x3 mat(data.data[0],data.data[3],data.data[6],data.data[1],data.data[4],data.data[7],data.data[2],data.data[5],data.data[8]);

	affResult[0].x = data.data[9];
	affResult[0].y = data.data[10];
	affResult[0].z = data.data[11];

	affResult[1].x = data.data[12];
	affResult[1].y = data.data[13];
	affResult[1].z = data.data[14];

	affResult[2].x = data.data[15];
	affResult[2].y = data.data[16];
	affResult[2].z = data.data[17];

	affResult[3].x = data.data[18];
	affResult[3].y = data.data[19];
	affResult[3].z = data.data[20];

	affResult[4].x = data.data[21];
	affResult[4].y = data.data[22];
	affResult[4].z = data.data[23];

	for(int i = 0; i < 5; i++)
	{
		affResult[i] = mat * affResult[i];
	}
}

const float span = .3f;
vec2 bottomLeft(-span, -span);
vec2 topLeft(-span, span);
vec2 topRight(span, span);
vec2 bottomRight(span, -span);
vec2 roofTop(0, span + .25f);

vec2 lines[] = { 
	bottomLeft, topLeft,
	topLeft, topRight,
	topRight, bottomRight,
	bottomRight, bottomLeft,
	topLeft, roofTop,
	topRight, roofTop
};

const int numLines = sizeof(lines) / (sizeof(*lines) * 2);
const int numMatrices = 10;
mat3x3 matrices[numMatrices];
mat3x3 currentTransform;

void MyMatrixTransformCallback2D(const MatrixTransformData2D& data)
{
	mat3x3 temp;
	mat3x3 scalar = mat3x3(glm::scale(mat4x4(), vec3(data.scaleX, data.scaleY, 0)));
	mat3x3 rotate = mat3x3(glm::rotate(glm::degrees(data.rotate),vec3(0,0,1)));
	mat3x3 translate;
	temp = scalar * rotate;
	temp[0].z = data.translateX;
	temp[1].z = data.translateY;
	temp[2].z = 1.0f;
	matrices[data.selectedMatrix] = temp;
	currentTransform = mat3x3();
	for(int i = 0; i < numMatrices; i++)
	{
		currentTransform = currentTransform * matrices[i];
	}
}

mat4x4 matrices3d[numMatrices];
mat4x4 fullTransform;
void MyMatrixTransformCallBack3D(const MatrixTransformData3D& data)
{
	mat4x4 temp;
	mat4x4 scale = glm::scale(mat4x4(), vec3(data.scaleX,data.scaleY,data.scaleZ));
	mat4x4 rotateX = glm::rotate(glm::degrees(data.rotateX), vec3(1,0,0));
	mat4x4 rotateY = glm::rotate(glm::degrees(data.rotateY), vec3(0,1,0));
	mat4x4 rotateZ = glm::rotate(glm::degrees(data.rotateZ), vec3(0,0,1));
	mat4x4 totalRotate = rotateX*rotateY*rotateZ;
	mat4x4 translate = glm::translate(vec3(data.translateX,data.translateY,data.translateZ));
	temp = scale*totalRotate*translate;
	matrices3d[data.selectedMatrix] = temp;
	fullTransform = mat4x4();
	for(int i = 0; i< numMatrices; i++)
	{
		fullTransform = fullTransform * matrices3d[i];
	}
}

int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;
	renderUI.setBasicVectorEquationData(
		MyBasicVectorEquationCallback,
		reinterpret_cast<float*>(&left), reinterpret_cast<float*>(&right), reinterpret_cast<float*>(&result));

	renderUI.setPerpendicularData(
		reinterpret_cast<float*>(&original), reinterpret_cast<float*>(&normal), reinterpret_cast<float*>(&cwPerp), reinterpret_cast<float*>(&ccwPerp), 
		MyPerpendicularDataCallback);

	renderUI.setDotProductData(
		reinterpret_cast<float*>(&vector1), reinterpret_cast<float*>(&vector2), reinterpret_cast<float*>(&projectionVector), reinterpret_cast<float*>(&rejectionVector), 
		MyDotProductDataCollback);

	renderUI.setLerpData(
		reinterpret_cast<float*>(&aVector), reinterpret_cast<float*>(&bVector), reinterpret_cast<float*>(&aMinusBVector), reinterpret_cast<float*>(&aVectorLerpPortion), 
		reinterpret_cast<float*>(&bVectorLerpPortion), reinterpret_cast<float*>(&lerpResultVector), 
		MyLerpDataCallback);

	renderUI.setLinearTransformationData(
		reinterpret_cast<float*>(&linResult), MyLinearTransformationCallback);

	renderUI.setAffineTransformationData(
		reinterpret_cast<float*>(&affResult[0]), MyAffineTransformationCallback);
	for(int i=0;i<numMatrices;i++)
	{
		matrices[i] = matrices[i];
	}
	renderUI.set2DMatrixVerticesTransformData(
		reinterpret_cast<const float*>(&lines[0]), 
		numLines, 
		reinterpret_cast<const float*>(&matrices), 
		reinterpret_cast<const float*>(&currentTransform), 
		MyMatrixTransformCallback2D);

	renderUI.set3DMatrixCallback(
		reinterpret_cast<const float*>(&matrices3d),
		reinterpret_cast<const float*>(&fullTransform),
		MyMatrixTransformCallBack3D);

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}