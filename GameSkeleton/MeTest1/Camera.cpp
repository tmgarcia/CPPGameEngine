#include "Camera.h"
#include <glm\gtx\transform.hpp>

const float Camera::MOVEMENT_SPEED = 0.1f;

Camera::Camera() : 
	viewDirection(0.0f, 0.0f, -1.0f),
	UP(0.0f,1.0f,0.0f),
	position(0.0f, 1.0f, 0.0f)
{
}

glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position, position + viewDirection, UP);
}

void Camera::mouseUpdate(const glm::vec2& newMousePosition)
{
	glm::vec2 mouseDelta = newMousePosition-oldMousePosition;
	if(!(glm::length(mouseDelta) > 70.0f))
	{
		const float ROTATIONAL_SPEED = 0.5f;
		strafeDirection = glm::cross(viewDirection, UP);
		glm::mat4 rotator = glm::rotate(-mouseDelta.x * ROTATIONAL_SPEED, UP) * 
							glm::rotate(-mouseDelta.y * ROTATIONAL_SPEED, strafeDirection);
		viewDirection = glm::mat3(rotator) * viewDirection;

	}
	oldMousePosition = newMousePosition;
}

void Camera::moveForward()
{
	position += MOVEMENT_SPEED * viewDirection;
}
void Camera::moveBackward()
{
	position -= MOVEMENT_SPEED * viewDirection;
}
void Camera::strafeLeft()
{
	position -= MOVEMENT_SPEED * strafeDirection;

}
void Camera::strafeRight()
{
	position += MOVEMENT_SPEED * strafeDirection;

}
void Camera::moveUp()
{
	position += MOVEMENT_SPEED * UP;
}
void Camera::moveDown()
{
	position -= MOVEMENT_SPEED * UP;
}