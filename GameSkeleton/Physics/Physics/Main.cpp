#include <Qt\qapplication.h>
#include "VelocityAcceleration.h"
#include "Momentum.h"
#include "AccumulatingForces.h"
#include "DragForces.h"
#include "SpringForces.h"
#include "MultipleSprings.h"
#include "OneDCollision.h"
#include "RestingContact.h"
#include "MultipleContacts.h"
#include "ThreeDCube.h"
#include "AngularVelocity.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	//VelocityAcceleration demo;
	//Momentum demo;
	//AccumulatingForces demo;
	//DragForces demo;
	//SpringForces demo;
	//MultipleSprings demo;
	//OneDCollision demo;
	//RestingContact demo;
	//MultipleContacts demo;
	//ThreeDCube demo;
	AngularVelocity demo;

	demo.initialize();
	demo.show();

	return app.exec();
}