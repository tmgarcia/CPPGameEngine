#include "DebugMenu.h"

#include "IntSlider.h"
#include "CheckBox.h"
#include "Vec3Slider.h"

void DebugMenu::cleanup()
{
	delete printButton;
}

void DebugMenu::addPrintButton()
{
	this->setCornerWidget(printButton, Qt::TopRightCorner);
	printButtonAdded = true;
}

void DebugMenu::printAllValues()
{
	ConsolePrinter::getInstance().print("Printing All Current Values");
	for(int i = 0; i<numTabs; i++)
	{
		ConsolePrinter::getInstance().print(tabs[i]->name, "Values of tab: ");
		tabs[i]->printValues();
	}
}

DebugMenu::DebugTab* DebugMenu::getTab(QString tabName)
{
	DebugTab* tab;
	int tabIndex = tabExists(tabName);
	if(tabIndex!= -1)
	{
		tab = tabs[tabIndex];
	}
	else
	{
		tab = new DebugTab(tabName);
		tabs.append(tab);
		numTabs++;
		this->addTab(tab, tabName);
		if(!printButtonAdded)
		{
			addPrintButton();
		}
	}
	return tab;
}

int DebugMenu::tabExists(QString name)
{
	int index = -1;
	for(int i = 0; i<numTabs && index==-1; i++)
	{
		if(tabs[i]->name == name)
		{
			index = i;
		}
	}
	return index;
}

void DebugMenu::addFloatSlider(QString tabName, float* variable, float min, float max, QString labelText="")
{
	DebugTab* tab = getTab(tabName);
	FloatSlider* f = new FloatSlider(variable, min, max, labelText);
	f->setObjectName("floatSlider");
	tab->slidersLayout->addWidget(f);
}

void DebugMenu::addVec3Slider(QString tabName, vec3* vector, float minX, float maxX, float minY, float maxY, float minZ, float maxZ, QString labelText)
{
	DebugTab* tab = getTab(tabName);
	Vec3Slider* f = new Vec3Slider(vector, minX, maxX, minY, maxY, minZ, maxZ, labelText);
	f->setObjectName("vec3Slider");
	tab->slidersLayout->addWidget(f);
}

void DebugMenu::addIntSlider(QString tabName, int* variable, int min, int max, QString labelText="")
{
	DebugTab* tab = getTab(tabName);
	IntSlider* f = new IntSlider(variable, min, max, labelText);
	tab->slidersLayout->addWidget(f);
}

void DebugMenu::addMultipleFloatSlider(QString tabName, QList<TrackingFloat*> floatsToTrack, QString labelText)
{
	DebugTab* tab = getTab(tabName);
	MultipleFloatsSlider* f = new MultipleFloatsSlider(floatsToTrack, labelText);
	tab->slidersLayout->addWidget(f);
}
void DebugMenu::addComboBox(QString tabName, GLuint* variableToTrack, QMap<QString,GLuint>optionsList, QString labelText)
	{
		DebugTab* tab = getTab(tabName);
		QHBoxLayout* checkBoxGroup;
		if(tab->numCheckBoxes == 0 || tab->numCheckBoxes%4 ==0)
		{
			checkBoxGroup = new QHBoxLayout();
			checkBoxGroup->setDirection(QBoxLayout::RightToLeft);
			checkBoxGroup->setMargin(0);
			checkBoxGroup->setContentsMargins(0,0,0,0);
			checkBoxGroup->setSpacing(0);
			checkBoxGroup->setObjectName("group" + QString::number(tab->numCheckBoxes/4));
			checkBoxGroup->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Expanding));
			tab->checkBoxLayouts->addLayout(checkBoxGroup);
		}
		else
		{
			checkBoxGroup = tab->checkBoxLayouts->findChild<QHBoxLayout*>("group" + QString::number(tab->numCheckBoxes - tab->numCheckBoxes%4));
		}
		ComboBox* c = new ComboBox(variableToTrack, optionsList, labelText);
		checkBoxGroup->addWidget(c,0);
		tab->numCheckBoxes++;
	}
void DebugMenu::addCheckBox(QString tabName, bool* variable, QString labelText="")
{
	DebugTab* tab = getTab(tabName);
	QHBoxLayout* checkBoxGroup;
	if(tab->numCheckBoxes == 0 || tab->numCheckBoxes%4==0)
	{
		checkBoxGroup = new QHBoxLayout();
		checkBoxGroup->setDirection(QBoxLayout::RightToLeft);
		checkBoxGroup->setMargin(0);
		checkBoxGroup->setContentsMargins(0,0,0,0);
		checkBoxGroup->setSpacing(0);
		checkBoxGroup->setObjectName("group" + QString::number(tab->numCheckBoxes/4));
		checkBoxGroup->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Expanding));
		tab->checkBoxLayouts->addLayout(checkBoxGroup);
	}
	else
	{
		checkBoxGroup = tab->checkBoxLayouts->findChild<QHBoxLayout*>("group" + QString::number(tab->numCheckBoxes - tab->numCheckBoxes%4));
	}

	CheckBox* c = new CheckBox(variable, labelText);
	checkBoxGroup->addWidget(c,0,Qt::AlignLeft);
	tab->numCheckBoxes++;
}
//template<typename T>
//void DebugMenu::addComboBox(QString tabName, QVariant variableToTrack, QMap<QString,QVariant>optionsList, QString labelText)
//{
//	DebugTab* tab = getTab(tabName);
//	QHBoxLayout* checkBoxGroup;
//	if(tab->numCheckBoxes == 0 || tab->numCheckBoxes%4 ==0)
//	{
//		checkBoxGroup = new QHBoxLayout();
//		checkBoxGroup->setDirection(QBoxLayout::RightToLeft);
//		checkBoxGroup->setMargin(0);
//		checkBoxGroup->setContentsMargins(0,0,0,0);
//		checkBoxGroup->setSpacing(0);
//		checkBoxGroup->setObjectName("group" + QString::number(tab->numCheckBoxes/4));
//		checkBoxGroup->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Expanding));
//		tab->checkBoxLayouts->addLayout(checkBoxGroup);
//	}
//	else
//	{
//		checkBoxGroup = tab->checkBoxLayouts->findChild<QHBoxLayout*>("group" + QString::number(tab->numCheckBoxes - tab->numCheckBoxes%4));
//	}
//	ComboBox* c = new ComboBox<T>(variableToTrack, optionsList, labelText);
//	checkBoxGroup->addWidget(c,0);
//	tab->numCheckBoxes++;
//}

void DebugMenu::addDisplay(QString tabName, float* variable, QString labelText="")
{
	variable;
	DebugTab* tab = getTab(tabName);
	QHBoxLayout* displayGroup = new QHBoxLayout();
	if(tab->numDisplays == 0 || tab->numDisplays%4==0)
	{
		displayGroup->setObjectName("group" + QString::number(tab->numDisplays/4));
		tab->displayLayouts->addLayout(displayGroup);
	}
	else
	{
		displayGroup = tab->checkBoxLayouts->findChild<QHBoxLayout*>("group" + QString::number(tab->numDisplays - tab->numDisplays%4));
	}

	/*QLabel* variableDisplay = new QLabel();
	variableDisplay->set*/
	//tab->numDisplays++;
}