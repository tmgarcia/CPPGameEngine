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
#include <Qt\qpushbutton.h>
#include <Qt\qlist.h>
#include <iostream>

#include "FloatSlider.h"
#include "Vec3Slider.h"
#include "MultipleFloatsSlider.h"
#include "TrackingFloat.h"
#include "ComboBox.h"
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
		printButtonAdded = false;
		printButton = new QPushButton("Print All Variables");
		QObject::connect(printButton, SIGNAL(clicked()), this, SLOT(printAllValues()));
		//QObject::connect(printButton, SIGNAL(
		this->show();
		setFocusPolicy(Qt::NoFocus);
	}
	void addFloatSlider(QString tabName, float* variable, float min, float max, QString labelText);
	void addVec3Slider(QString tabName, vec3* vector, float minX, float maxX, float minY, float maxY, float minZ, float maxZ, QString labelText);
	void addIntSlider(QString tabName, int* variable, int min, int max, QString labelText);
	void addMultipleFloatSlider(QString tabName, QList<TrackingFloat*> floatsToTrack, QString labelText);
	void addCheckBox(QString tabName, bool* variable, QString labelText);
	void addDisplay(QString tabName, float* variable, QString labelText);
	//template<typename T> void addComboBox(QString tabName, QVariant variableToTrack, QMap<QString,QVariant>optionsList, QString labelText="");
	void addPrintButton();
	int tabExists(QString name);
	void cleanup();
	//template<typename T>
	void addComboBox(QString tabName, GLuint* variableToTrack, QMap<QString,GLuint>optionsList, QString labelText);

private:
	QPushButton* printButton;
	bool printButtonAdded;
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
		void printValues()
		{
			QList<QWidget*> floatSliders = findChildren<QWidget*>("floatSlider");
			for(int i = 0; i < floatSliders.size(); i++)
			{
				ConsolePrinter::getInstance().print(*(((FloatSlider*)floatSliders[i])->trackingVariable),((FloatSlider*)floatSliders[i])->label+": ");
			}
			QList<QWidget*> vec3Sliders = findChildren<QWidget*>("vec3Slider");
			for(int i = 0; i < vec3Sliders.size(); i++)
			{
				ConsolePrinter::getInstance().print(*(((Vec3Slider*)vec3Sliders[i])->trackingVariable),((Vec3Slider*)vec3Sliders[i])->label+": ");
			}
		}
	};
	int numTabs;
	QList<DebugTab*> tabs;
	DebugTab* getTab(QString tabName);


private slots:
	void printAllValues();
};

