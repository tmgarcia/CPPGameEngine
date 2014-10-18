#include "MainWindow.h"
#include <crtdbg.h>
#include "GameObjects\Entity.h"

int main(int argc, char* argv[])
{
	//_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);

	QApplication app(argc, argv);

	//Entity* e = new Entity();
	
	MainWindow window;
	window.show();
	return app.exec();
}