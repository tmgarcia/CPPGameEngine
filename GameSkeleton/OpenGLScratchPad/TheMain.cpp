#include <Qt\qapplication.h>
#include "CoolGLWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	CoolGLWindow widg;
	
	widg.show();

	return app.exec();
}