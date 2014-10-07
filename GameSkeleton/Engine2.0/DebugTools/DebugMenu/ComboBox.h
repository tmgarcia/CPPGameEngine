#pragma once
#include <QtOpenGL\qglwidget>
#include <Qt\qstring.h>
#include <Qt\qmap.h>
#include <Qt\qlabel.h>
#include <Qt\qboxlayout.h>
#include <Qt\qcombobox.h>
#include <iostream>
#include <typeinfo>
#include "../../Renderer/TextureInfo.h"

using std::cout;
using std::endl;

//template<class T>
class ComboBox : public QWidget
{
	Q_OBJECT

public:
	
	GLuint* variable;
	QMap<QString,GLuint> options;
	QComboBox* comboBox;
	QHBoxLayout* layout;
	QLabel* label;
	//Type* vType;
	//class VType;

	ComboBox(GLuint* variableToTrack, QMap<QString,GLuint>optionsList, QString labelText="")
	{
		setFocusPolicy(Qt::NoFocus);
		variable = variableToTrack;
		options = optionsList;

		layout = new QHBoxLayout();

		comboBox = new QComboBox();
		comboBox->setFocusPolicy(Qt::NoFocus);
		QMapIterator<QString,GLuint> i(options);
		while(i.hasNext())
		{
			i.next();
			comboBox->addItem(i.key(),i.value());
		}

		QObject::connect(comboBox, SIGNAL(activated(int)), this, SLOT(updateValue(int)));

		if(!labelText.isNull() && !labelText.isEmpty())
		{
			label = new QLabel(labelText);
			layout->addWidget(label);
		}
		
		layout->addWidget(comboBox);
		this->setLayout(layout);
		//vType = new TypeImpl<T>;
	}


private slots:
	//template<class T>
	void updateValue(int optionIndex)
	{
		comboBox->setFocusPolicy(Qt::NoFocus);
		comboBox->clearFocus();
		clearFocus();
		int index = 0;
		bool foundOption = false;
		int option = 0;
		QMapIterator<QString,GLuint> i(options);
		while(i.hasNext() && !foundOption)
		{
			i.next();
			if(index == optionIndex)
			{
				option = i.value();
				foundOption = true;
			}
			index++;
		}
		*variable = option;
		//
		////variable = option;
		////void* typeRoot = vType->allocate();
		//TextureInfo* v = (TextureInfo*)variable.value<void *>();
		//int* o = (int*)option.value<void *>();
		//v->textureID = o;
		///*
		//ComboBox* a = (T*)option.value<void *>();
		//ComboBox* a = (T*)option.value<void *>();
		//int b = option.value<int>();*/
		//cout << "done setting option" << endl;
	}

};
