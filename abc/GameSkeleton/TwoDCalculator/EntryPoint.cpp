#include "RenderUI.h"
#include "Engine.h"
#include <Vector2D.h>

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

	//renderUI.setLineEquationData(
	//	p, n, d, myLineEquationDataCallback);

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}