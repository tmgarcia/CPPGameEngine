#include "Turret.h"


//Turret's Shape
Vector3D* turretPoints[] =
{
	new Vector3D(0.0f, -25.0f),
	new Vector3D(2.50f, -5.0f),
	new Vector3D(10.0f, -5.0f),
	new Vector3D(5.0f, 0.0f),
	new Vector3D(-5.0f, 0.0f),
	new Vector3D(-10.0f, -5.0f),
	new Vector3D(-2.5f, -5.0f),
};
const unsigned int NUM_T_POINTS = sizeof(turretPoints) / sizeof(*turretPoints);

void Turret::clear()
{
	for(int i=0; i<NUM_T_POINTS; i++)
	{
		delete turretPoints[i];
	}
}

void Turret::draw(Core::Graphics& g, Vector3D shipPosition)
{
	g.SetColor(RGB(50, 50, 255));
	//Drawing the turret
	Vector3D mouse = Vector3D((float)Core::Input::GetMouseX(), (float)Core::Input::GetMouseY());
	Vector3D ptm = shipPosition-mouse;
	Vector3D bmt = ptm.normalized(); //b
	Vector3D bmtperp = bmt.perpCCW(); //a
	turnTurret = Matrix3D(bmtperp.x, bmt.x, 0.0f, bmtperp.y, bmt.y, 0.0f, 0.0f, 0.0f, 1.0f);
	Matrix3D transTurret = translate(shipPosition.x, shipPosition.y) * turnTurret;
	tip = transTurret * *turretPoints[0];
	for(unsigned int i = 0; i<NUM_T_POINTS; i++)
	{
		const Vector3D& t1 = transTurret * *turretPoints[i];
		const Vector3D& t2 = transTurret * *turretPoints[(i+1) % NUM_T_POINTS];
		g.DrawLine(t1.x, t1.y, t2.x, t2.y);
	}
}

