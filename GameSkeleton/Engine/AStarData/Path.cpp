#include "Path.h"

#include "../MathTools/TransformationMatrixMaker.h"

using glm::vec2;

mat4 Path::getNextPathTransform()
{
	//if haven't reached end
	//A*t + (1-t)*B   A = to B = from?
	mat4 fullTransformation = lastTransform;

	if(!reachedEndNode)
	{
		vec3 B = path[currentPathIndex]->position;//current node
		vec3 A = path[currentPathIndex+1]->position;//next node
		currentStretch += (speed * 0.01f);
		if(currentStretch > 1)
		{
			currentStretch = 1;
		}
		vec3 newPosition = A*currentStretch + (1-currentStretch)*B;
		mat4 translation = glm::translate(newPosition);

		//theta = acos(A dot B)
		vec3 path = vec3(B.x, 0, B.z)-vec3(A.x, 0, A.z);
		mat4 rotation = TransformationMatrixMaker::getInstance().getRotationFromVector(path);
		currentRotation = rotation;
		fullTransformation = translation * rotation;

		if(currentStretch==1)
		{
			currentPathIndex++;
			currentStretch = 0;
			if(currentPathIndex==totalNodes-1)
			{
				cout << "End of path" << endl;
				reachedEndNode = true;
				lastTransform = fullTransformation;
			}
		}
	}
	return fullTransformation;
}