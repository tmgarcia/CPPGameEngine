#include <Qt\qapplication.h>
#include "VelocityAcceleration.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	VelocityAcceleration velocityDemo = VelocityAcceleration();
	velocityDemo.initialize();
	velocityDemo.show();

	return app.exec();
}