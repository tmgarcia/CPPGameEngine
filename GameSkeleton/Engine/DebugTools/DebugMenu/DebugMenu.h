#pragma once
#include <GL\glew.h>
#include <Qt\qdebug.h>
#include <QtGui\qwidget>
#include <Qt\qboxlayout.h>
#include <Qt\qlist.h>
#include <glm\glm.hpp>

#include "..\DebugSlider.h"

using glm::vec4;
using glm::vec3;
using glm::vec2;


class  __declspec(dllexport) DebugMenu: public QWidget
{
	Q_OBJECT

public:
	DebugMenu()
	{
		numCheckBoxes = 0;
		numDisplays = 0;

		mainLayout = new QVBoxLayout();
		this->setLayout(mainLayout);

		slidersLayout = new QVBoxLayout();
		mainLayout->addLayout(slidersLayout);
		checkBoxLayouts = new QVBoxLayout();
		mainLayout->addLayout(checkBoxLayouts);
		displayLayouts = new QVBoxLayout();
		mainLayout->addLayout(displayLayouts);
	}
	void addFloatSlider(float* variable, float min, float max, QString labelText);
	void addIntSlider(int* variable, int min, int max, QString labelText);
	void addCheckBox(bool* variable, QString labelText);
	void addDisplay(float* variable, QString labelText);
	void addDisplay(int* variable, QString labelText);
	void addDisplay(vec4* variable, QString labelText);
	void addDisplay(vec3* variable, QString labelText);
	void addDisplay(vec2* variable, QString labelText);

private:
	int numCheckBoxes;
	int numDisplays;

	QVBoxLayout* mainLayout;

	QVBoxLayout* slidersLayout;

	QVBoxLayout* displayLayouts;
	QVBoxLayout* checkBoxLayouts;


signals:

};

