#pragma once

#include <Qt\qobject.h>
#include <Qt\qstring.h>
#include <glm\glm.hpp>

using glm::vec3;

class TrackingFloat : public QObject
{
	Q_OBJECT

public:
	float* value;
	float minimumValue;
	float maximumValue;
	QString label;

	TrackingFloat(float* variable, float min, float max, QString labelText)
	{
		value = variable;
		minimumValue = min;
		maximumValue = max;
		label = labelText;
	}

public slots:
	void updateValue(float newValue)
	{
		*value = newValue;
	}
};