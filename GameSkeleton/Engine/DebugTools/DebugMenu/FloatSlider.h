#pragma once
#include <QtOpenGL\qglwidget>
#include <Qt\qstring.h>
#include <Qt\qlabel.h>
#include <Qt\qboxlayout.h>

#include "..\DebugSlider.h"

class FloatSlider: public QWidget
{
	Q_OBJECT

	DebugSlider* slider;
	QHBoxLayout* layout;

public:
	QString label;
	float* trackingVariable;
	FloatSlider(float* variable, float min, float max, QString labelText="")
	{
		trackingVariable = variable;

		layout = new QHBoxLayout();

		slider = new DebugSlider(min, max, false, (max-min)*10);
		slider->setValue(*variable);

		QObject::connect(slider, SIGNAL(valueChanged(float)), this, SLOT(updateValue(float)));
		label = labelText;
		if(!labelText.isNull() && !labelText.isEmpty())
		{
			QLabel* qlabel = new QLabel(labelText);
			layout->addWidget(qlabel);
		}
		layout->addWidget(slider);
		this->setLayout(layout);
	}

private slots:
	void updateValue(float value)
	{
		*trackingVariable = value;
	}
};