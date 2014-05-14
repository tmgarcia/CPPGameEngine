#include <Qt\qapplication.h>
#include "VelocityAcceleration.h"
#include "Momentum.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	//VelocityAcceleration demo = VelocityAcceleration();
	Momentum demo = Momentum();
	demo.initialize();
	demo.show();

	return app.exec();
}