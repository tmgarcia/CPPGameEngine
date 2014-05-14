#pragma once
#include "PhysicsGui\GuiBase.h"

class Momentum : public GuiBase
{
	Q_OBJECT

public:
	void initialize();
	void newFrame();
	void vectorGraphicMouseDrag(uint vectorGraphicINdex, const glm::vec3& dragDelta);
	glm::vec3 getUserDirection();

	Momentum(){}
	~Momentum(){}
private:
	VectorGraphic* particleGraphic;
	VectorGraphic* velocityGraphic;
	VectorGraphic* momentumGraphic;
	bool momentumConserved;

private slots:
	void particleMassChanged(float);
	void toggleMomentumConservation(int);
};

