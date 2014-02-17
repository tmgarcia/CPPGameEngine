#include <Qt\qapplication.h>
#include "ClientGLWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	ClientGLWindow widg = ClientGLWindow();

	return app.exec();
}