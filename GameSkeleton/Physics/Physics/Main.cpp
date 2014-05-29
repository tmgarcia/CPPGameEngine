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

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	//VelocityAcceleration demo = VelocityAcceleration();
	//Momentum demo = Momentum();
	//AccumulatingForces demo = AccumulatingForces();
	//DragForces demo = DragForces();
	//SpringForces demo = SpringForces();
	//MultipleSprings demo = MultipleSprings();
	//OneDCollision demo = OneDCollision();
	//RestingContact demo = RestingContact();
	MultipleContacts demo = MultipleContacts();

	demo.initialize();
	demo.show();

	return app.exec();
}