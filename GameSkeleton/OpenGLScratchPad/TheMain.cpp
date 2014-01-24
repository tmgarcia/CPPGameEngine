#include <Qt\qapplication.h>
#include "CoolGLWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	CoolGLWindow widg;
	widg.setFixedSize(900, 900);
	widg.showFullScreen();
	//widg.move(500,0);
	//widg.show();

	return app.exec();
}