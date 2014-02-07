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
		//Object Color Labels
		QLabel* rLabel = new QLabel("Red");
		QLabel* gLabel = new QLabel("Green");
		QLabel* bLabel = new QLabel("Blue");
		labels->addWidget(rLabel);
		labels->addWidget(gLabel);
		labels->addWidget(bLabel);
		labels->setMargin(0);
		row1->addLayout(labels);
		//Object Color Sliders
		QVBoxLayout* objectColors = new QVBoxLayout();
		row1->addLayout(objectColors);

		DebugSlider* objectR = new DebugSlider(0, 255, true);
		objectR->setValue(255);
		DebugSlider* objectG = new DebugSlider(0, 255, true);
		objectG->setValue(255);
		DebugSlider* objectB = new DebugSlider(0, 255, true);
		objectB->setValue(255);
		QLabel* sectionLabel = new QLabel("Objects Color");
		sectionLabel->setAlignment(Qt::AlignCenter);
		objectColors->addWidget(sectionLabel);
		objectColors->addWidget(objectR);
		objectColors->addWidget(objectG);
		objectColors->addWidget(objectB);

		//Ambient Labels
		QVBoxLayout* labels2 = new QVBoxLayout();
		QLabel* rLabel2 = new QLabel("Red");
		QLabel* gLabel2 = new QLabel("Green");
		QLabel* bLabel2 = new QLabel("Blue");
		labels2->addWidget(rLabel2);
		labels2->addWidget(gLabel2);
		labels2->addWidget(bLabel2);
		labels2->setMargin(0);
		row1->addLayout(labels2);
		//Ambient Sliders
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

		//Specular color Labels
		QVBoxLayout* specLabels = new QVBoxLayout();
		QLabel* rLabel4 = new QLabel("Red");
		QLabel* gLabel4 = new QLabel("Green");
		QLabel* bLabel4 = new QLabel("Blue");
		specLabels->addWidget(rLabel4);
		specLabels->addWidget(gLabel4);
		specLabels->addWidget(bLabel4);
		specLabels->setMargin(0);
		row1->addLayout(specLabels);
		//Spec Color Sliders
		QVBoxLayout* specSliders = new QVBoxLayout();
		row1->addLayout(specSliders);
		DebugSlider* specR = new DebugSlider(0, 255, true);
		specR->setValue(255);
		DebugSlider* specG = new DebugSlider(0, 255, true);
		specG->setValue(255);
		DebugSlider* specB = new DebugSlider(0, 255, true);
		specB->setValue(255);
		QLabel* specSectionLabel = new QLabel("Specularity Color");
		specSectionLabel->setAlignment(Qt::AlignCenter);
		specSliders->addWidget(specSectionLabel);
		specSliders->addWidget(specR);
		specSliders->addWidget(specG);
		specSliders->addWidget(specB);


		QHBoxLayout* row2 = new QHBoxLayout();
		mainLayout->addLayout(row2);

		QVBoxLayout* diffuseSlider = new QVBoxLayout();
		//Diffusion Intensity Label & Slider
		QLabel* section5Label = new QLabel("Diffusion Intensity");
		section5Label->setAlignment(Qt::AlignCenter);
		diffuseSlider->addWidget(section5Label);
		DebugSlider* diffuseIntensity = new DebugSlider(0, 5, true);
		diffuseIntensity->setValue(1);
		diffuseSlider->addWidget(diffuseIntensity);
		row2->addLayout(diffuseSlider);

		//Specular exponent
		QVBoxLayout* specularSlider = new QVBoxLayout();
		QLabel* specSliderLabel = new QLabel("Specular Exponent");
		specSliderLabel->setAlignment(Qt::AlignCenter);
		specularSlider->addWidget(specSliderLabel);
		DebugSlider* specularExponent = new DebugSlider(1, 150, true);
		specularExponent ->setValue(10);
		specularSlider->addWidget(specularExponent);
		row2->addLayout(specularSlider);

		//Ligh position Labels
		QVBoxLayout* labels3 = new QVBoxLayout();
		QLabel* rLabel3 = new QLabel("X");
		QLabel* gLabel3 = new QLabel("Y");
		QLabel* bLabel3 = new QLabel("Z");
		labels3->addWidget(rLabel3);
		labels3->addWidget(gLabel3);
		labels3->addWidget(bLabel3);
		labels3->setMargin(0);
		row2->addLayout(labels3);
		//Ligh position Sliders
		QVBoxLayout* lightPosition = new QVBoxLayout();
		row2->addLayout(lightPosition);
		DebugSlider* lightX = new DebugSlider(-10, 10, true);
		lightX->setValue(0);
		DebugSlider* lightY = new DebugSlider(0, 8, true);
		lightY->setValue(6);
		DebugSlider* lightZ = new DebugSlider(0, -48, true);
		lightZ->setValue(-10);
		QLabel* section3Label= new QLabel("Light Source Position");
		section3Label->setAlignment(Qt::AlignCenter);
		lightPosition->addWidget(section3Label);
		lightPosition->addWidget(lightX);
		lightPosition->addWidget(lightY);
		lightPosition->addWidget(lightZ);

		QHBoxLayout* checkboxRow = new QHBoxLayout();
		QLabel* checkLabel = new QLabel("Apply lighting");
		checkLabel->setAlignment(Qt::AlignRight);
		checkboxRow->addWidget(checkLabel);
		QCheckBox* lightingCheck = new QCheckBox();
		lightingCheck->setChecked(true);
		checkboxRow->addWidget(lightingCheck);
		mainLayout->addLayout(checkboxRow);

		//Scene display
		display = new CoolGLWindow();
		display->setFixedSize(this->width(), this->height() * 0.7);
		mainLayout->addWidget(display);

		//Connecting the signals and slots
		QObject::connect(objectR, SIGNAL(valueChanged(float)), display, SLOT(setObjectColorRed(float)));
		QObject::connect(objectG, SIGNAL(valueChanged(float)), display, SLOT(setObjectColorGreen(float)));
		QObject::connect(objectB, SIGNAL(valueChanged(float)), display, SLOT(setObjectColorBlue(float)));

		QObject::connect(ambientR, SIGNAL(valueChanged(float)), display, SLOT(setAmbientColorRed(float)));
		QObject::connect(ambientG, SIGNAL(valueChanged(float)), display, SLOT(setAmbientColorGreen(float)));
		QObject::connect(ambientB, SIGNAL(valueChanged(float)), display, SLOT(setAmbientColorBlue(float)));

		QObject::connect(lightX, SIGNAL(valueChanged(float)), display, SLOT(setLightPositionX(float)));
		QObject::connect(lightY, SIGNAL(valueChanged(float)), display, SLOT(setLightPositionY(float)));
		QObject::connect(lightZ, SIGNAL(valueChanged(float)), display, SLOT(setLightPositionZ(float)));

		QObject::connect(specR, SIGNAL(valueChanged(float)), display, SLOT(setSpecularColorRed(float)));
		QObject::connect(specG, SIGNAL(valueChanged(float)), display, SLOT(setSpecularColorGreen(float)));
		QObject::connect(specB, SIGNAL(valueChanged(float)), display, SLOT(setSpecularColorBlue(float)));
		
		QObject::connect(diffuseIntensity, SIGNAL(valueChanged(float)), display, SLOT(setDiffusionIntensity(float)));
		QObject::connect(specularExponent, SIGNAL(valueChanged(float)), display, SLOT(setSpecularExponent(float)));
		QObject::connect(lightingCheck, SIGNAL(stateChanged(int)), display, SLOT(setApplyLighting(int)));


		
	}
		CoolGLWindow* display;
	    void keyPressEvent(QKeyEvent *event);
};

