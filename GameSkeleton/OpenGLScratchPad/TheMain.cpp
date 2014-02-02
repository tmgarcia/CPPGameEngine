#include <Qt\qapplication.h>
#include "CoolGLWindow.h"
#include "FullWidget.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	FullWidget widg;
	widg.setFixedSize(900, 900);
	widg.show();
	//widg.move(500,0);
	//widg.show();

	return app.exec();
}