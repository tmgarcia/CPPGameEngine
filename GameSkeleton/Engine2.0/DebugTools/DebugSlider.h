#ifndef DEBUG_SLIDER_H
#define DEBUG_SLIDER_H
#include <QtGui\qwidget>
class QSlider;
class QLabel;
#include "ExportHeader.h"

class DECL_DLL_EXPORT DebugSlider : public QWidget
{
	Q_OBJECT

	QSlider* slider;
	QLabel* label;
	float sliderGranularity;
	float min;
	float max;

	private slots:
	void sliderValueChanged();



	signals:
	void valueChanged(float newValue);

	public:
		DebugSlider(
		float min = -10.0f, float max = 10.0f,
		bool textOnLeft = false, float granularity = 40.0);
		float value() const;
		void setValue(float newValue);
};

#endif