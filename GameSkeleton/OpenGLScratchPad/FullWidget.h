#pragma once
#include <QtGui\QHboxlayout>
#include <QtGui\QVboxlayout>
#include <QtGui\qwidget>
#include <QtGui\qpushbutton.h>
#include <QtGui\qcheckbox.h>
#include <QtGui\qlabel.h>
#include "DebugSlider.h"
#include "CoolGLWindow.h"

class FullWidget : public QWidget
{
	Q_OBJECT

public:
	FullWidget()
	{
		this->setFixedSize(900, 900);
		QVBoxLayout* mainLayout = new QVBoxLayout();
		setLayout(mainLayout);
		QHBoxLayout* row1 = new QHBoxLayout();
		mainLayout->addLayout(row1);

		QVBoxLayout* labels = new QVBoxLayout();

		QLabel* rLabel = new QLabel("Red");
		QLabel* gLabel = new QLabel("Green");
		QLabel* bLabel = new QLabel("Blue");
		labels->addWidget(rLabel);
		labels->addWidget(gLabel);
		labels->addWidget(bLabel);
		labels->setMargin(0);
		row1->addLayout(labels);

		QVBoxLayout* objectColors = new QVBoxLayout();
		row1->addLayout(objectColors);
		DebugSlider* objectR = new DebugSlider(0, 255, true);
		
		DebugSlider* objectG = new DebugSlider(0, 255, true);
		DebugSlider* objectB = new DebugSlider(0, 255, true);
		QLabel* sectionLabel = new QLabel("Objects Color");
		sectionLabel->setAlignment(Qt::AlignCenter);
		objectColors->addWidget(sectionLabel);
		objectColors->addWidget(objectR);
		objectColors->addWidget(objectG);
		objectColors->addWidget(objectB);

		
		QVBoxLayout* labels2 = new QVBoxLayout();
		QLabel* rLabel2 = new QLabel("Red");
		QLabel* gLabel2 = new QLabel("Green");
		QLabel* bLabel2 = new QLabel("Blue");
		labels2->addWidget(rLabel2);
		labels2->addWidget(gLabel2);
		labels2->addWidget(bLabel2);
		labels2->setMargin(0);
		row1->addLayout(labels2);

		QVBoxLayout* ambientColors = new QVBoxLayout();
		row1->addLayout(ambientColors);
		DebugSlider* ambientR = new DebugSlider(0, 255, true);
		DebugSlider* ambientG = new DebugSlider(0, 255, true);
		DebugSlider* ambientB = new DebugSlider(0, 255, true);
		QLabel* section2Label = new QLabel("Ambient Colors");
		section2Label->setAlignment(Qt::AlignCenter);
		ambientColors->addWidget(section2Label);
		ambientColors->addWidget(ambientR);
		ambientColors->addWidget(ambientG);
		ambientColors->addWidget(ambientB);

		QVBoxLayout* labels3 = new QVBoxLayout();
		QLabel* rLabel3 = new QLabel("X");
		QLabel* gLabel3 = new QLabel("Y");
		QLabel* bLabel3 = new QLabel("Z");
		labels3->addWidget(rLabel3);
		labels3->addWidget(gLabel3);
		labels3->addWidget(bLabel3);
		labels3->setMargin(0);
		row1->addLayout(labels3);

		QVBoxLayout* lightPosition = new QVBoxLayout();
		row1->addLayout(lightPosition);
		DebugSlider* lightX = new DebugSlider(-10, 10, true);
		lightX->setValue(0);
		DebugSlider* lightY = new DebugSlider(0, 8, true);
		DebugSlider* lightZ = new DebugSlider(0, -48, true);
		QLabel* section3Label = new QLabel("Light Source Position");
		section3Label->setAlignment(Qt::AlignCenter);
		lightPosition->addWidget(section3Label);
		lightPosition->addWidget(lightX);
		lightPosition->addWidget(lightY);
		lightPosition->addWidget(lightZ);

		QLabel* section5Label = new QLabel("Diffusion Intensity");
		section5Label->setAlignment(Qt::AlignCenter);
		mainLayout->addWidget(section5Label);
		DebugSlider* diffuseIntensity = new DebugSlider(0, 100, true);
		mainLayout->addWidget(diffuseIntensity);

		CoolGLWindow* display = new CoolGLWindow();
		display->setFixedSize(this->width(), this->height() * 0.7);
		mainLayout->addWidget(display);

		//mainLayout->addWidget(new QPushButton);
		//mainLayout->addWidget(new QPushButton);
		//row1->addWidget(new DebugSlider);
		//row1->addWidget(new QCheckBox);
	}
};

