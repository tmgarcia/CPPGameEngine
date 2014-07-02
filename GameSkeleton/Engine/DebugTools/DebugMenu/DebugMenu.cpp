#include "DebugMenu.h"

#include "FloatSlider.h"
#include "IntSlider.h"
#include "CheckBox.h"

void DebugMenu::addFloatSlider(float* variable, float min, float max, QString labelText="")
{
	FloatSlider* f = new FloatSlider(variable, min, max, labelText);
	slidersLayout->addWidget(f);
}

void DebugMenu::addIntSlider(int* variable, int min, int max, QString labelText="")
{
	IntSlider* f = new IntSlider(variable, min, max, labelText);
	slidersLayout->addWidget(f);
}

void DebugMenu::addCheckBox(bool* variable, QString labelText="")
{
	QHBoxLayout* checkBoxGroup = new QHBoxLayout();
	if(numCheckBoxes == 0 || numCheckBoxes%4==0)
	{
		checkBoxGroup->setObjectName("group" + QString::number(numCheckBoxes/4));
		checkBoxLayouts->addLayout(checkBoxGroup);
	}
	else
	{
		checkBoxGroup = checkBoxLayouts->findChild<QHBoxLayout*>("group" + QString::number(numCheckBoxes - numCheckBoxes%4));
	}

	CheckBox* c = new CheckBox(variable, labelText);
	checkBoxGroup->addWidget(c);
}

void DebugMenu::addDisplay(float* variable, QString labelText="")
{
	QHBoxLayout* displayGroup = new QHBoxLayout();
	if(numDisplays == 0 || numDisplays%4==0)
	{
		displayGroup->setObjectName("group" + QString::number(numDisplays/4));
		displayLayouts->addLayout(displayGroup);
	}
	else
	{
		displayGroup = checkBoxLayouts->findChild<QHBoxLayout*>("group" + QString::number(numDisplays - numDisplays%4));
	}

	/*QLabel* variableDisplay = new QLabel();
	variableDisplay->set*/
}