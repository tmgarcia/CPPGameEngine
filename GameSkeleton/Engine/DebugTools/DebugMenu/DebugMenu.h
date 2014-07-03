#pragma once
#include <GL\glew.h>
#include <Qt\qdebug.h>
#include <QtGui\qwidget>
#include <Qt\qboxlayout.h>
#include <Qt\qlist.h>
#include <glm\glm.hpp>
#include <Qt\qtabwidget.h>
#include <Qt\qlist.h>
#include <Qt\qstring.h>
#include <iostream>

#include "FloatSlider.h"
#include "..\ConsolePrinter.h"

#include "..\DebugSlider.h"

using glm::vec4;
using glm::vec3;
using glm::vec2;

using std::cout;
using std::endl;

class  __declspec(dllexport) DebugMenu: public QTabWidget
{
	Q_OBJECT

public:
	DebugMenu()
	{
		ConsolePrinter::getInstance();
		numTabs = 0;
		this->show();
	}
	void addFloatSlider(QString tabName, float* variable, float min, float max, QString labelText);
	void addIntSlider(QString tabName, int* variable, int min, int max, QString labelText);
	void addCheckBox(QString tabName, bool* variable, QString labelText);
	void addDisplay(QString tabName, float* variable, QString labelText);
	int tabExists(QString name);

private:
	struct DebugTab : public QWidget
	{
		QString name;
		int numCheckBoxes;
		int numDisplays;
		QVBoxLayout* mainLayout;
		QVBoxLayout* slidersLayout;
		QVBoxLayout* displayLayouts;
		QVBoxLayout* checkBoxLayouts;
		float value;
		DebugTab(QString n)
		{
			cout << "Constructing DebugTab "<< endl;
			name = n;
			numCheckBoxes = 0;
			numDisplays = 0;

			mainLayout = new QVBoxLayout();
			this->setLayout(mainLayout);
			mainLayout->setMargin(0);
			mainLayout->setContentsMargins(0,0,0,0);
			mainLayout->setSpacing(0);

			slidersLayout = new QVBoxLayout();
			slidersLayout->setMargin(0);
			slidersLayout->setContentsMargins(0,0,0,0);
			slidersLayout->setSpacing(0);
			mainLayout->addLayout(slidersLayout);
			checkBoxLayouts = new QVBoxLayout();
			mainLayout->addLayout(checkBoxLayouts);
			displayLayouts = new QVBoxLayout();
			mainLayout->addLayout(displayLayouts);
		}
	};
	int numTabs;
	QList<DebugTab*> tabs;
	


signals:

};

