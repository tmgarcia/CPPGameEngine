#include <Qt\qapplication.h>
#include "VelocityAcceleration.h"
#include "Momentum.h"
#include "AccumulatingForces.h"
#include "DragForces.h"
#include "SpringForces.h"
#include "MultipleSprings.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	//VelocityAcceleration demo = VelocityAcceleration();
	//Momentum demo = Momentum();
	//AccumulatingForces demo = AccumulatingForces();
	//DragForces demo = DragForces();
	//SpringForces demo = SpringForces();
	MultipleSprings demo = MultipleSprings();

	demo.initialize();
	demo.show();

	return app.exec();
}