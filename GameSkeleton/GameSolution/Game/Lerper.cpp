#include "Lerper.h"

//Lerper's lerping direction
Vector3D* lerpPoints[] = 
{
	new Vector3D(100.0f, 100.0f),
	new Vector3D(700.0f, 100.0f),
	new Vector3D(700.0f, 500.0f),
	new Vector3D(100.0f, 500.0f),
};

//Lerper's shape
Vector3D* lerperPoints[] = 
{
	new Vector3D(0.0f, 0.0f),
	new Vector3D(25.0f, 0.0f),
	new Vector3D(25.0f, 25.0f),
	new Vector3D(0.0f, 25.0f),
};

//Lerper pathing
Vector3D lerperPosition = *lerpPoints[0];
unsigned int sourceLerpPoint = 0;
unsigned int destinationLerpPoint = 1;
float alpha = 0.0f;
const unsigned int NUM_LERP_POINTS = sizeof(lerpPoints) / sizeof(*lerpPoints);
void lerpTheLerper(float dt)
{
	lerperPosition = LERP(*lerpPoints[sourceLerpPoint], *lerpPoints[destinationLerpPoint], alpha);
	alpha += dt;
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
	g.SetColor(RGB(255, 255, 100));
	const unsigned int NUM_LERPER_POINTS = sizeof(lerperPoints) / sizeof(*lerperPoints);
	for(unsigned int i = 0; i< NUM_LERPER_POINTS; i++)
	{
		const Vector3D& l1 = lerperPosition + *lerperPoints[i];
		const Vector3D& l2 = lerperPosition + *lerperPoints[(i+1) % NUM_LERPER_POINTS];
		g.DrawLine(l1.x, l1.y, l2.x, l2.y);
	}
}

void Lerper::update(float dt)
{
	lerpTheLerper(dt);
}