#include <Qt\qapplication.h>
#include "Controller.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	Controller widg = Controller();

	return app.exec();
}