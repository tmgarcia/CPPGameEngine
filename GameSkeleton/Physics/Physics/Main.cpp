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
#include "ChaslesTheorem.h"
#include "Torque.h"
#include "TorqueSquare.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	//VelocityAcceleration demo;/*1*/
	//Momentum demo;/*2*/
	//AccumulatingForces demo;/*3*/
	//DragForces demo;/*4*/
	//SpringForces demo;/*5*/
	//MultipleSprings demo;/*6*/
	//OneDCollision demo;/*7,8*/
	//RestingContact demo;/*9*/
	//MultipleContacts demo;/*10*/
	//ThreeDCube demo;/*11*/
	////AngularVelocity demo;/*12*/
	//ChaslesTheorem demo = ChaslesTheorem(15);/*13*/
	//Torque demo = Torque(15); /*14*/
	TorqueSquare demo;

	demo.initialize();
	demo.show();

	return app.exec();
}