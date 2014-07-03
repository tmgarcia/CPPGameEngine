#include "DebugMenu.h"

#include "IntSlider.h"
#include "CheckBox.h"

int DebugMenu::tabExists(QString name)
{
	int index = -1;
	for(int i = 0; i<numTabs && index==-1; i++)
	{
		cout<< i << ": "<<tabs[i]->name.toLocal8Bit().constData() << endl;
		if(tabs[i]->name == name)
		{
			index = i;
		}
	}
	return index;
}

void DebugMenu::addFloatSlider(QString tabName, float* variable, float min, float max, QString labelText="")
{
	ConsolePrinter::getInstance().print(tabName, "Add float slider: ");
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
		tab->show();
	}
	FloatSlider* f = new FloatSlider(variable, min, max, labelText);
	//f->setFixedWidth(800);
	tab->slidersLayout->addWidget(f);
}

void DebugMenu::addIntSlider(QString tabName, int* variable, int min, int max, QString labelText="")
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
		tab->show();
	}
	IntSlider* f = new IntSlider(variable, min, max, labelText);
	tab->slidersLayout->addWidget(f);
}

void DebugMenu::addCheckBox(QString tabName, bool* variable, QString labelText="")
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
		tab->show();
	}
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

void DebugMenu::addDisplay(QString tabName, float* variable, QString labelText="")
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
		addTab(tab, tabName);
	}
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