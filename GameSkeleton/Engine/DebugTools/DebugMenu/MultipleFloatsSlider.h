#pragma once
#include <QtOpenGL\qglwidget>
#include <Qt\qstring.h>
#include <Qt\qlabel.h>
#include <Qt\qboxlayout.h>
#include <glm\glm.hpp>

using glm::vec3;

#include "..\DebugSlider.h"
#include "TrackingFloat.h"

class MultipleFloatsSlider: public QWidget
{
	DebugSlider* sliderZ;
	QHBoxLayout* layout;
	QList<TrackingFloat*> trackingFloats;

public:
	QString label;
	MultipleFloatsSlider(QList<TrackingFloat*> floatsToTrack, QString labelText="")
	{
		trackingFloats = floatsToTrack;

		layout = new QHBoxLayout();

		label = labelText;

		if(!labelText.isNull() && !labelText.isEmpty())
		{
			QLabel* label = new QLabel(labelText);
			layout->addWidget(label);
		}

		for(int i = 0; i < trackingFloats.size(); i++)
		{
			if(!trackingFloats[i]->label.isNull() && !trackingFloats[i]->label.isEmpty())
			{
				QLabel* label = new QLabel(trackingFloats[i]->label);
				layout->addWidget(label);
			}

			QLabel* label = new QLabel(trackingFloats[i]->label);
			float min = trackingFloats[i]->minimumValue;
			float max = trackingFloats[i]->maximumValue;
			DebugSlider* slider = new DebugSlider(min, max, false, (max-min)*10);
			slider->setValue(*trackingFloats[i]->value);
			QObject::connect(slider, SIGNAL(valueChanged(float)), trackingFloats[i], SLOT(updateValue(float)));
			layout->addWidget(slider);
		}
		
		this->setLayout(layout);
	}
};