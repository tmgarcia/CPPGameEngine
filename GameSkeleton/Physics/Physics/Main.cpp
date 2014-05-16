#include <Qt\qapplication.h>
#include "VelocityAcceleration.h"
#include "Momentum.h"
#include "AccumulatingForces.h"
#include "DragForces.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	//VelocityAcceleration demo = VelocityAcceleration();
	//Momentum demo = Momentum();
	//AccumulatingForces demo = AccumulatingForces();
	DragForces demo = DragForces();
	demo.initialize();
	demo.show();

	return app.exec();
}