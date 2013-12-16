#include "Lerper.h"

//Lerper's lerping direction
//Vector3D* lerpPoints[] = 
//{
//	new Vector3D(100.0f, 100.0f),
//	new Vector3D(700.0f, 100.0f),
//	new Vector3D(700.0f, 500.0f),
//	new Vector3D(100.0f, 500.0f),
//};
float width = 15/2;
Vector3D lerpPoints[] = 
{
	Vector3D(101-width, 897-width),
	Vector3D(101-width, 631-width),
	Vector3D(201-width, 631-width),
	Vector3D(201-width, 451-width),
	Vector3D(101-width, 451-width),
	Vector3D(201-width, 451-width),
	Vector3D(201-width, 631-width),
	Vector3D(301-width, 631-width),
	Vector3D(301-width, 451-width),
	Vector3D(400-width, 451-width),
	Vector3D(301-width, 451-width),
	Vector3D(301-width, 631-width),
	Vector3D(301-width, 721-width),
	Vector3D(301-width, 631-width),
	Vector3D(101-width, 631-width),
	Vector3D(101-width, 897-width),
	Vector3D(501-width, 897-width),
	Vector3D(501-width, 812-width),
	Vector3D(801-width, 812-width),
	Vector3D(801-width, 631-width),
	Vector3D(701-width, 631-width),
	Vector3D(801-width, 631-width),
	Vector3D(801-width, 541-width),
	Vector3D(601-width, 541-width),
	Vector3D(601-width, 721-width),
	Vector3D(401-width, 721-width),
	Vector3D(401-width, 811-width),
	Vector3D(201-width, 811-width),
	Vector3D(201-width, 721-width),
	Vector3D(201-width, 811-width),
	Vector3D(401-width, 811-width),
	Vector3D(401-width, 541-width),
	Vector3D(501-width, 541-width),
	Vector3D(501-width, 451-width),
	Vector3D(501-width, 541-width),
	Vector3D(401-width, 541-width),
	Vector3D(401-width, 721-width),
	Vector3D(601-width, 721-width),
	Vector3D(601-width, 631-width),
	Vector3D(501-width, 631-width),
	Vector3D(601-width, 631-width),
	Vector3D(601-width, 361-width),
	Vector3D(301-width, 361-width),
	Vector3D(501-width, 361-width),
	Vector3D(501-width, 271-width),
	Vector3D(501-width, 361-width),
	Vector3D(601-width, 361-width),
	Vector3D(601-width, 451-width),
	Vector3D(701-width, 451-width),
	Vector3D(601-width, 451-width),
	Vector3D(601-width, 541-width),
	Vector3D(901-width, 541-width),
	Vector3D(801-width, 541-width),
	Vector3D(801-width, 721-width),
	Vector3D(901-width, 721-width),
	Vector3D(901-width, 811-width),
	Vector3D(901-width, 721-width),
	Vector3D(801-width, 721-width),
	Vector3D(801-width, 812-width),
	Vector3D(501-width, 812-width),
	Vector3D(501-width, 897-width),
	Vector3D(995-width, 897-width),
	Vector3D(995-width, 631-width),
	Vector3D(901-width, 631-width),
	Vector3D(995-width, 631-width),
	Vector3D(995-width, 451-width),
	Vector3D(801-width, 451-width),
	Vector3D(801-width, 361-width),
	Vector3D(801-width, 451-width),
	Vector3D(995-width, 451-width),
	Vector3D(995-width, 181-width),
	Vector3D(801-width, 181-width),
	Vector3D(801-width, 91-width),
	Vector3D(601-width, 91-width),
	Vector3D(601-width, 272-width),
	Vector3D(702-width, 272-width),
	Vector3D(701-width, 180-width),
	Vector3D(702-width, 272-width),
	Vector3D(901-width, 270-width),
	Vector3D(902-width, 360-width),
	Vector3D(902-width, 272-width),
	Vector3D(702-width, 270-width),
	Vector3D(701-width, 361-width),
	Vector3D(701-width, 271-width),
	Vector3D(601-width, 271-width),
	Vector3D(601-width, 91-width),
	Vector3D(501-width, 91-width),
	Vector3D(801-width, 91-width),
	Vector3D(801-width, 181-width),
	Vector3D(995-width, 181-width),
	Vector3D(995-width, 5-width),
	Vector3D(901-width, 5-width),
	Vector3D(901-width, 91-width),
	Vector3D(901-width, 5-width),
	Vector3D(5-width, 5-width),
	Vector3D(5-width, 181-width),
	Vector3D(201-width, 181-width),
	Vector3D(101-width, 181-width),
	Vector3D(101-width, 270-width),
	Vector3D(101-width, 181-width),
	Vector3D(5-width, 181-width),
	Vector3D(5-width, 361-width),
	Vector3D(201-width, 361-width),
	Vector3D(201-width, 271-width),
	Vector3D(301-width, 271-width),
	Vector3D(301-width, 91-width),
	Vector3D(101-width, 91-width),
	Vector3D(301-width, 91-width),
	Vector3D(301-width, 271-width),
	Vector3D(401-width, 271-width),
	Vector3D(401-width, 91-width),
	Vector3D(401-width, 181-width),
	Vector3D(501-width, 181-width),
	Vector3D(401-width, 181-width),
	Vector3D(401-width, 271-width),
	Vector3D(201-width, 271-width),
	Vector3D(201-width, 361-width),
	Vector3D(5-width, 361-width),
	Vector3D(5-width, 541-width),
	Vector3D(101-width, 541-width),
	Vector3D(5-width, 541-width),
	Vector3D(5-width, 897-width),
};

//Lerper's shape
Vector3D lerperPoints[] = 
{
	Vector3D(0.0f, 0.0f),
	Vector3D(15.0f, 0.0f),
	Vector3D(15.0f, 15.0f),
	Vector3D(0.0f, 15.0f),
};

//Lerper pathing
Vector3D lerperPosition = lerpPoints[0];
unsigned int sourceLerpPoint = 0;
unsigned int destinationLerpPoint = 1;
float alpha = 0.0f;
const unsigned int NUM_LERP_POINTS = sizeof(lerpPoints) / sizeof(lerpPoints[0]);
void lerpTheLerper(float dt)
{
	lerperPosition = LERP(lerpPoints[sourceLerpPoint], lerpPoints[destinationLerpPoint], alpha);
	alpha += 8*dt;
	if(alpha>=1)
	{
		alpha = 0.0f;
		sourceLerpPoint = destinationLerpPoint;
		destinationLerpPoint = (destinationLerpPoint+1) % NUM_LERP_POINTS;
	}
}

void Lerper::draw(Core::Graphics& g)
{
	//Drawing the lerper
	g.SetColor(RGB(100,100,100));
	const unsigned int NUM_LERPER_POINTS = sizeof(lerperPoints) / sizeof(lerperPoints[0]);
	for(unsigned int i = 0; i< NUM_LERPER_POINTS; i++)
	{
		const Vector3D& l1 = lerperPosition + lerperPoints[i];
		const Vector3D& l2 = lerperPosition + lerperPoints[(i+1) % NUM_LERPER_POINTS];
		g.DrawLine(l1.x, l1.y, l2.x, l2.y);
	}
}

void Lerper::update(float dt)
{
	lerpTheLerper(dt);
	position = lerperPosition;
}