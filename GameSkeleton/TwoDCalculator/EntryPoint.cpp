#include "RenderUI.h"
#include "Engine.h"
#include <Vector2D.h>
#include <Matrix2D.h>
#include <Vector3D.h>
#include <Matrix3D.h>

Vector2D left;
Vector2D right;
Vector2D result;

Vector2D original;
Vector2D normal;
Vector2D cwPerp;
Vector2D ccwPerp;

Vector2D vector1;
Vector2D vector2;
Vector2D projectionVector;
Vector2D rejectionVector;

Vector2D aVector;
Vector2D bVector;
Vector2D aMinusBVector;
Vector2D aVectorLerpPortion;
Vector2D bVectorLerpPortion;
Vector2D lerpResultVector;

Vector2D p;
Vector2D n;
Vector2D d;

void MyBasicVectorEquationCallback(const BasicVectorEquationInfo& info)
{
	left = info.scalar1 * Vector2D(info.x1, info.y1);
	right = info.scalar2 * Vector2D(info.x2, info.y2);

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
	original = Vector2D(data.x, data.y);
	normal = original.normalized();
	cwPerp = original.perpCW();
	ccwPerp = original.perpCCW();
}

void MyDotProductDataCollback(const DotProductData& data)
{
	vector1 = Vector2D(data.v1i, data.v1j);
	vector2 = Vector2D(data.v2i, data.v2j);
	if(data.projectOntoLeftVector)
	{
		//projectionVector = dot(vector2, vector1.normalized())*vector1.normalized();
		projectionVector = vector2.projectOnto(vector1);
		rejectionVector = vector2 - projectionVector;
	}
	else
	{
		//projectionVector = dot(vector1, vector2.normalized())*vector2.normalized();
		projectionVector = vector1.projectOnto(vector2);
		rejectionVector = vector1 - projectionVector;
	}
}

void MyLerpDataCallback(const LerpData& data)
{
	aVector = Vector2D(data.a_i, data.a_j);
	bVector = Vector2D(data.b_i, data.b_j);
	aMinusBVector = bVector-aVector;
	aVectorLerpPortion = (1-data.beta)*aVector;
	bVectorLerpPortion = data.beta * bVector;
	lerpResultVector = LERP(aVector, bVector, data.beta);
}


Vector2D linResult;
void MyLinearTransformationCallback(const LinearTransformationData& data)
{
	Matrix2D op = Matrix2D(Vector2D(data.m00,data.m10), Vector2D(data.m01, data.m11));
	Vector2D v = Vector2D(data.v0, data.v1);
	linResult = op*v;
}

Vector3D affResult[5];
void MyAffineTransformationCallback(const AffineTransformationData& data)
{
	Matrix3D mat;
	mat.a.x = data.data[0];
	mat.b.x = data.data[1];
	mat.c.x = data.data[2];
	mat.a.y = data.data[3];
	mat.b.y = data.data[4];
	mat.c.y = data.data[5];
	mat.a.z = data.data[6];
	mat.b.z = data.data[7];
	mat.c.z = data.data[8];

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
Vector2D bottomLeft(-span, -span);
Vector2D topLeft(-span, span);
Vector2D topRight(span, span);
Vector2D bottomRight(span, -span);
Vector2D roofTop(0, span + .25f);

Vector2D lines[] = { 
	bottomLeft, topLeft,
	topLeft, topRight,
	topRight, bottomRight,
	bottomRight, bottomLeft,
	topLeft, roofTop,
	topRight, roofTop
};

const int numLines = sizeof(lines) / (sizeof(*lines) * 2);
const int numMatrices = 10;
Matrix3D matrices[numMatrices];
Matrix3D currentTransform;

void MyMatrixTransformCallback2D(const MatrixTransformData2D& data)
{

	Matrix3D temp = 
		scale(data.scaleX, data.scaleY) * 
		rotate(data.rotate) *
		translate(data.translateX, data.translateY);

	matrices[data.selectedMatrix] = temp;
	currentTransform = Matrix3D();
	for(int i = 0; i < numMatrices; i++)
	{
		currentTransform = currentTransform * matrices[i];
	}
}
//void myLineEquationDataCallback(const LineEquationData& data)
//{
//	n = Vector2D(data.n_i, data.n_j);
//	p = Vector2D(data.p_x, data.n_i*data.p_x + data.d);
//	//d = n.x*p.x + n.y*p.y;
//	d = data.d;
//}

int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;
	renderUI.setBasicVectorEquationData(
		MyBasicVectorEquationCallback,
		left, right, result);

	renderUI.setPerpendicularData(
		original, normal, cwPerp, ccwPerp, 
		MyPerpendicularDataCallback);

	renderUI.setDotProductData(
		vector1, vector2, projectionVector, rejectionVector, 
		MyDotProductDataCollback);

	renderUI.setLerpData(
		aVector, bVector, aMinusBVector, aVectorLerpPortion, 
		bVectorLerpPortion, lerpResultVector, 
		MyLerpDataCallback);

	renderUI.setLinearTransformationData(
		linResult, MyLinearTransformationCallback);

	renderUI.setAffineTransformationData(
		affResult[0], MyAffineTransformationCallback);

	renderUI.set2DMatrixVerticesTransformData(
		lines[0], numLines, reinterpret_cast<float*>(&matrices), reinterpret_cast<float*>(&currentTransform), 
		MyMatrixTransformCallback2D);
		  
	//renderUI.setLineEquationData(
	//	p, n, d, myLineEquationDataCallback);

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}