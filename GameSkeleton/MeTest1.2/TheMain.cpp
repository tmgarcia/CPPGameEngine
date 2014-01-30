#include "TheMain.h"
#include "MainWindow.h"
#include <Qt\qapplication.h>

int main(int count, char* args[])
{
	QApplication app(count,args);
	MainWindow widg;
	widg.show();
	return app.exec();
}
