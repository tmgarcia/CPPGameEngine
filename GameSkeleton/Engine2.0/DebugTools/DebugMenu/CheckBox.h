#pragma once
#include <QtOpenGL\qglwidget>
#include <Qt\qstring.h>
#include <Qt\qlabel.h>
#include <Qt\qboxlayout.h>
#include <Qt\qcheckbox.h>

class CheckBox: public QWidget
{
	Q_OBJECT

	bool* trackingVariable;
	QCheckBox* box;
	QHBoxLayout* layout;

public:
	CheckBox(bool* variable, QString labelText="")
	{
		trackingVariable = variable;

		layout = new QHBoxLayout();

		box = new QCheckBox();
		box->setChecked(*variable);

		QObject::connect(box, SIGNAL(stateChanged(int)), this, SLOT(updateValue(int)));

		if(!labelText.isNull() && !labelText.isEmpty())
		{
			box->setText(labelText);
		}
		
		layout->addWidget(box);
		this->setLayout(layout);
	}

private slots:
	void updateValue(int value)
	{
		*trackingVariable = value;
	}
};