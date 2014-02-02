#pragma once
#include <QtGui\QHboxlayout>
#include <QtGui\QVboxlayout>
#include <QtGui\qwidget>
#include <QtGui\qpushbutton.h>
#include <QtGui\qcheckbox.h>
#include "DebugSlider.h"
#include "CoolGLWindow.h"

class FullWidget : public QWidget
{
public:
	FullWidget()
	{
		QVBoxLayout* mainLayout = new QVBoxLayout();
		setLayout(mainLayout);
		mainLayout->addWidget(new QPushButton);
		mainLayout->addWidget(new QPushButton);
		QHBoxLayout* row1 = new QHBoxLayout();
		mainLayout->addLayout(row1);
		row1->addWidget(new DebugSlider);
		row1->addWidget(new QCheckBox);
		mainLayout->addWidget(new CoolGLWindow);
	}
};

