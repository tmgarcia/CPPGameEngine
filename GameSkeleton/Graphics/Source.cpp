#include <glm\glm.hpp>
#include <iostream>
#include <glm\gtx\transform.hpp>
#include "MainWindow.h"

using glm::mat4;
using glm::vec3;
using glm::vec4;

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	MainWindow window;
	window.show();

	return app.exec();
}