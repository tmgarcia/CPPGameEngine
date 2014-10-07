#pragma once
#include <glm\glm.hpp>

class __declspec(dllexport) Camera
{
	glm::vec3 position;
	const glm::vec3 UP;
	glm::vec2 oldMousePosition;
	static const float MOVEMENT_SPEED;
	glm::vec3 strafeDirection;
public:
	Camera(void);
	void mouseUpdate(const glm::vec2& newMousePosition);
	glm::mat4 getWorldToViewMatrix() const;
	glm::vec3 getPosition() const;
	glm::vec3 viewDirection;

	void moveForward();
	void moveBackward();
	void strafeLeft();
	void strafeRight();
	void moveUp();
	void moveDown();
	void resetPosition();
	void setPosition(glm::vec3 p);
	void setViewDirection(glm::vec3 p);

};

