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
const unsigned int NUM_M_POINTS = sizeof(mousePoints) / sizeof(*mousePoints);

void Instructions::clear()
{
	for(int i=0; i< NUM_M_POINTS; i++)
	{
		delete mousePoints[i];
	}
}

void Instructions::drawDebugInfo(Core::Graphics& g, size_t counts, size_t size, size_t high)
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

	string count = std::to_string(counts);
	string cLabel = "Counts: " + count;
	char *costr = &cLabel[0];
	g.DrawString(20,530, costr);

	string si = std::to_string(size);
	string siLabel = "Sizes: " + si;
	char *sistr = &siLabel[0];
	g.DrawString(20,545, sistr);

	string hi = std::to_string(high);
	string hiLabel = "Highwater: " + hi;
	char *histr = &hiLabel[0];
	g.DrawString(20,560, histr);

}

void Instructions::draw(Core::Graphics& g, int type)
{
	if(type==0)
	{
		g.SetColor(RGB(200, 200, 200));
		g.DrawString(150,200, "Welcome AGENT_DEBUGGER");
		g.DrawString(150,220, "As usual we're dealing with a rogue programmer who has clearly never even heard of TOP_AGENT_HALLADAY.");
		g.DrawString(150,235, "The bugs in his code are rutheless and unforgiving.");
		g.DrawString(150,250, "There isn't a line of documentation, so once again we're sending you in blind.");
		g.DrawString(150,265, "We've sent AGENT_INTELLISENSE in first.");
		g.DrawString(150,280, "We know he isn't all that useful but hopefully his running around through the code will help you.");
		g.DrawString(150,295, "If not, you might just have to stumble through yourself and try to get your own picture of what's doing what.");
		g.DrawString(150,310, "REMEMBER:");
		g.DrawString(165,325, "DO NOT compile until all bugs have been cleaned from the program.");
		g.DrawString(165,340, "DO NOT let the bugs get to you, or we'll have a full scale RUNTIME_ERROR on our hands.");
		g.DrawString(150,355, "Good luck.");




		g.DrawString(350, 425, "[P] Pause [U] Return");
		g.DrawString(350, 450, "Instructions");
		g.DrawString(360, 465, "Movement:");
		g.DrawString(390, 475, "^");
		g.DrawString(390, 482, "|");
		g.DrawString(385, 490, "[W]");
		g.DrawString(385, 510, "[S]");
		g.DrawString(390, 522, "|");
		g.DrawString(390, 530, "v");
		g.DrawString(350, 540, "<-[A] Rotate left");
		g.DrawString(350, 550, "[D]-> Rotate right");
		g.DrawString(445, 503, "*");
		g.DrawString(465, 503, "Fire Missile");

		g.DrawString(350,580, "[PRESS SPACE TO ENTER PROGRAM]");


		const Matrix3D mtrans = translate(450, 510);
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

	if(type==1)
	{
		g.SetColor(RGB(150, 150, 150));
		g.DrawString(350, 425, "[P] Pause [U] Return");
		g.DrawString(350, 450, "Instructions");
		g.DrawString(360, 465, "Movement:");
		g.DrawString(390, 475, "^");
		g.DrawString(390, 482, "|");
		g.DrawString(385, 490, "[W]");
		g.DrawString(385, 510, "[S]");
		g.DrawString(390, 522, "|");
		g.DrawString(390, 530, "v");
		g.DrawString(350, 540, "<-[A] Rotate left");
		g.DrawString(350, 550, "[D]-> Rotate right");
		g.DrawString(445, 503, "*");
		g.DrawString(465, 503, "Fire Missile");

		const unsigned int NUM_M_POINTS = sizeof(mousePoints) / sizeof(*mousePoints);
		const Matrix3D mtrans = translate(450, 510);
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
}
