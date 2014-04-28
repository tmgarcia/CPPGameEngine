#include <Qt\qapplication.h>
#include "FullDisplay.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	FullDisplay widg = FullDisplay();
	//widg.setFixedSize(900, 900);
	widg.show();

	return app.exec();
}