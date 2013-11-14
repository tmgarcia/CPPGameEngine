#include "Gear.h"


Vector3D* gearPoints[] =
{
	new Vector3D(-12.5f, -58.5f),
	new Vector3D(12.5f, -58.5f),
	new Vector3D(12.5f, -43.5f),
	new Vector3D(21.92f, -39.6f),
	new Vector3D(32.53f, -50.2f),
	new Vector3D(50.2f, -32.53f),
	new Vector3D(39.6f, -21.92f),
	new Vector3D(43.5f, -12.5f),
	new Vector3D(58.5f, -12.5f),
	new Vector3D(58.5f, 12.5f),
	new Vector3D(43.5f, 12.5f),
	new Vector3D(39.6f, 21.92f),
	new Vector3D(50.2f, 32.53f),
	new Vector3D(32.53f, 50.2f),
	new Vector3D(21.92f, 39.6f),
	new Vector3D(12.5f, 43.5f),
	new Vector3D(12.5f, 58.5f),
	new Vector3D(-12.5f, 58.5f),
	new Vector3D(-12.5f, 43.5f),
	new Vector3D(-21.92f, 39.6f),
	new Vector3D(-32.53f, 50.2f),
	new Vector3D(-50.2f, 32.53f),
	new Vector3D(-39.6f, 21.92f),
	new Vector3D(-43.5f, 12.5f),
	new Vector3D(-58.5f, 12.5f),
	new Vector3D(-58.5f, -12.5f),
	new Vector3D(-43.5f, -12.5f),
	new Vector3D(-39.6f, -21.92f),
	new Vector3D(-50.2f, -32.53f),
	new Vector3D(-32.53f, -50.2f),
	new Vector3D(-21.92f, -39.6f),
	new Vector3D(-12.5f, -43.5f),
};

void Gear::draw(Core::Graphics& g, Vector3D parentPos)
{
	const unsigned int NUM_POINTS = sizeof(gearPoints) / sizeof(*gearPoints);
	const Matrix3D transform = 
		scale(gscale,gscale) * 
		translate(parentPos.x, parentPos.y) * 
		rotate(orientation) * 
		translate(offset, offset);
	for(unsigned int i = 0; i< NUM_POINTS; i++)
	{
		const Vector3D& g1 = transform * *gearPoints[i];
		const Vector3D& g2 = transform * *gearPoints [(i+1) % NUM_POINTS];
		g.DrawLine(g1.x, g1.y, g2.x, g2.y);
	}
	currentPosition = transform * currentPosition;
}
void Gear::update(float dt)
{
	orientation+=2.0f*dt;
}
