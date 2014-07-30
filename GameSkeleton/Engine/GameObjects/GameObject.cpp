#include "GameObject.h"

void GameObject::setupTransforms(vec3 _position, vec3 _scale, float xRotation, float yRotation, float zRotation, mat4 worldToProjectionMatrix)
{
	position = _position;
	scale = _scale;
	xRotationAngle = xRotation;
	yRotationAngle = yRotation;
	zRotationAngle = zRotation;
	updateTransforms(worldToProjectionMatrix);
}
void GameObject::updateTransforms(mat4 worldToProjectionMatrix)
{
	translationMatrix = glm::translate(position);
	rotationMatrix = glm::rotate(xRotationAngle, vec3(1,0,0)) * glm::rotate(yRotationAngle, vec3(0,1,0)) * glm::rotate(zRotationAngle, vec3(0,0,1));
	scalingMatrix = glm::scale(scale);
	modelToWorldMatrix = translationMatrix * rotationMatrix * scalingMatrix;
	fullTransformMatrix = (project)? worldToProjectionMatrix * modelToWorldMatrix : modelToWorldMatrix;
}