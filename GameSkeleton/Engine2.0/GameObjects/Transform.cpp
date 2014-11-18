#include "Transform.h"
#include "DebugTools/ConsolePrinter.h"
#include "SceneManager.h"

Transform::Transform()
{
	initializeValues();
}
void Transform::initializeValues()
{
	position = vec3(0,0,0);
	scale = vec3(1,1,1);
	xRotationAngle = 0;
	yRotationAngle = 0;
	zRotationAngle = 0;

	project = true;

	update();
}
void Transform::update()
{
	translationMatrix = glm::translate(position);
	rotationMatrix = glm::rotate(xRotationAngle, vec3(1,0,0)) * glm::rotate(yRotationAngle, vec3(0,1,0)) * glm::rotate(zRotationAngle, vec3(0,0,1));
	scaleMatrix = glm::scale(scale);
	modelToWorldMatrix = translationMatrix;
	fullTransformMatrix = SceneManager::getInstance().WORLD_TO_PROJECTION* modelToWorldMatrix;
}

void Transform::rotateX(float angle)
{
	xRotationAngle = angle;
}
void Transform::rotateY(float angle)
{
	yRotationAngle = angle;
}
void Transform::rotateZ(float angle)
{
	zRotationAngle = angle;
}

void Transform::scaleX(float scale)
{
	this->scale.x = scale;
}
void Transform::scaleY(float scale)
{
	this->scale.y = scale;
}
void Transform::scaleZ(float scale)
{
	this->scale.z = scale;
}
void Transform::uniformScale(float scale)
{
	this->scale = vec3(scale,scale,scale);
}

void Transform::lerpPosition(vec3 start, vec3 end, float progress)
{
	position = end*progress + (1-progress)*start;
}