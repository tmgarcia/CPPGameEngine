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
		projectionVector = dot(vector2, vector1.normalized())*vector1.normalized();
		rejectionVector = vector2 - projectionVector;
	}
	else
	{
		projectionVector = dot(vector1, vector2.normalized())*vector2.normalized();
		rejectionVector = vector1 - projectionVector;
	}
}


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
	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}