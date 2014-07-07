#pragma once
#include <QtOpenGL\qglwidget>
#include <Qt\qstring.h>
#include <Qt\qlabel.h>
#include <Qt\qboxlayout.h>
#include <glm\glm.hpp>

using glm::vec3;

#include "..\DebugSlider.h"

class Vec3Slider: public QWidget
{
	Q_OBJECT

	vec3* trackingVariable;
	DebugSlider* sliderX;
	DebugSlider* sliderY;
	DebugSlider* sliderZ;
	QHBoxLayout* layout;

public:
	Vec3Slider(vec3* variable, float minX, float maxX, float minY, float maxY, float minZ, float maxZ, QString labelText="")
	{
		trackingVariable = variable;

		layout = new QHBoxLayout();

		sliderX = new DebugSlider(minX, maxX, false, (maxX-minX)*10);
		sliderX->setValue((*variable).x);
		sliderY = new DebugSlider(minY, maxY, false, (maxY-minY)*10);
		sliderY->setValue((*variable).y);
		sliderZ = new DebugSlider(minZ, maxZ, false, (maxZ-minZ)*10);
		sliderZ->setValue((*variable).z);

		QObject::connect(sliderX, SIGNAL(valueChanged(float)), this, SLOT(updateValue(float)));
		QObject::connect(sliderY, SIGNAL(valueChanged(float)), this, SLOT(updateValue(float)));
		QObject::connect(sliderZ, SIGNAL(valueChanged(float)), this, SLOT(updateValue(float)));

		if(!labelText.isNull() && !labelText.isEmpty())
		{
			QLabel* label = new QLabel(labelText);
			layout->addWidget(label);
		}
		layout->addWidget(sliderX);
		layout->addWidget(sliderY);
		layout->addWidget(sliderZ);
		this->setLayout(layout);
	}

private slots:
	void updateValue(float value)
	{
		(*trackingVariable).x = sliderX->value();
		(*trackingVariable).y = sliderY->value();
		(*trackingVariable).z = sliderZ->value();
	}
};