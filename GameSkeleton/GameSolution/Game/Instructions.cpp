#include "Instructions.h"
#include <string>

using std::string;

Vector3D* mousePoints[] = 
{
	new Vector3D(0.0f, 0.0f),
	new Vector3D(0.22f, -10.0f),
	new Vector3D(4.48f, -7.6f),
	new Vector3D(7.5f, 0.0f),
	new Vector3D(5.7f, 6.5f),
	new Vector3D(0.0f, 10.0f),
	new Vector3D(-5.7f, 6.5f),
	new Vector3D(-7.5f, 0.0f),
	new Vector3D(-4.48f, -7.6f),
	new Vector3D(-0.22f, -10.0f),
};


void Instructions::draw(Core::Graphics& g)
{

	float spfTime = timer.Interval();
	string spfStr = std::to_string(spfTime);
	g.SetColor(RGB(200, 200, 200));
	string spfLabel = "SPF: " + spfStr;
	char *sstr = &spfLabel[0];

	g.DrawString(20,500, sstr);

	float fpsTime = 1/spfTime;
	string fpsStr = std::to_string(fpsTime);
	string fpsLabel = "FPS: " + fpsStr;
	char *fstr = &fpsLabel[0];

	g.DrawString(20,515, fstr);

	g.SetColor(RGB(150, 150, 150));
	g.DrawString(50, 50, "Instructions");
	g.DrawString(60, 65, "Movement:");
	g.DrawString(90, 75, "^");
	g.DrawString(90, 82, "|");
	g.DrawString(85, 90, "[W]");
	g.DrawString(85, 110, "[S]");
	g.DrawString(90, 122, "|");
	g.DrawString(90, 130, "v");
	g.DrawString(50, 140, "<-[A] Rotate left");
	g.DrawString(50, 150, "[D]-> Rotate right");
	g.DrawString(150, 50, "[1] Toggle Bouncing");
	g.DrawString(150, 65, "[2] Toggle Walls");
	g.DrawString(150, 80, "[3] Toggle Wrapping");
	g.DrawString(145, 103, "*");
	g.DrawString(165, 103, "Fire Missile");

	const unsigned int NUM_M_POINTS = sizeof(mousePoints) / sizeof(*mousePoints);
	const Matrix3D mtrans = translate(150, 110);
	for(unsigned int i = 0; i< NUM_M_POINTS; i++)
	{
		const Vector3D& p1 = mtrans * *mousePoints[i];
		const Vector3D& p2 = mtrans * *mousePoints [(i+1) % NUM_M_POINTS];
		g.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
	const Vector3D& ml1 = mtrans * Vector3D(-7.5f, 0);
	const Vector3D& ml2 = mtrans * Vector3D(7.5f, 0);
	g.DrawLine(ml1.x, ml1.y, ml2.x, ml2.y);
}
