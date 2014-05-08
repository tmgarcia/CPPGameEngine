#include "Path.h"

#include "../MathTools/TransformationMatrixMaker.h"
#include <math.h>

using glm::vec2;
int turnSteps = 8;
int currentTurnStep = 0;
vec3 Path::getNextPathPosition()
{
	//if haven't reached end
	//A*t + (1-t)*B   A = to B = from?
	vec3 newPosition = lastPosition;

	if(!reachedEndNode)
	{
		vec3 B = path[currentPathIndex]->position;//current node
		vec3 A = path[currentPathIndex+1]->position;//next node
		vec3 direction = vec3(B.x, 0, B.z)-vec3(A.x, 0, A.z);
		float distance = glm::length(direction);
		int numStretches = ceil(distance/speed);
		currentStretch += (speed/numStretches);
		if(currentStretch > 1)
		{
			currentStretch = 1;
		}
		newPosition = A*currentStretch + (1-currentStretch)*B;
		//newPosition = glm::translate(newPosition);
		
		mat4 rotation;
		if(currentTurnStep<=turnSteps && currentPathIndex!=0)
		{
			//cout<<"step " << currentTurnStep<<endl;
			float lerpAmount = (float)currentTurnStep/(float)turnSteps;
			//cout<<"turn lerp " << lerpAmount<<endl;
			vec3 B1 = path[currentPathIndex-1]->position;//current node
			vec3 A1 = path[currentPathIndex]->position;
			vec3 previousDirection = vec3(B1.x, 0, B1.z)-vec3(A1.x, 0, A1.z);
			vec3 midTurnPosition = direction*lerpAmount + (1-lerpAmount)*previousDirection;
			rotation = TransformationMatrixMaker::getInstance().getRotationFromVector(midTurnPosition);
			currentTurnStep++;
		}
		else
		{
			rotation = TransformationMatrixMaker::getInstance().getRotationFromVector(direction);
		}
		currentRotation = rotation;

		if(currentStretch==1)
		{
			currentPathIndex++;
			currentStretch = 0;
			currentTurnStep = 0;
			if(currentPathIndex==totalNodes-1)
			{
				cout << "End of path" << endl;
				reachedEndNode = true;
				lastPosition = newPosition;
			}
			else
			{
				if(pathHighlighted)
				{
					path[currentPathIndex]->highlight(pathHighlightColor);
					path[currentPathIndex+1]->highlight(vec3(1,1,0));
				}
			}
		}
	}
	return newPosition;
}

void Path::highlightPathNodes(vec3 color)
{
	for(int i = 0; i<totalNodes; i++)
	{
		path[i]->setVisible(true);
		path[i]->highlight(color);
	}
	path[totalNodes-1]->highlight(vec3(0,1,0));
	if(currentPathIndex!=totalNodes-1)
	{
		path[currentPathIndex+1]->highlight(vec3(1,1,0));
	}
	pathHighlightColor = color;
	pathHighlighted = true;
}
void Path::highlightPathConnections(vec3 color)
{
	for(int i = 0; i<totalNodes-1; i++)
	{
		path[i]->highlightConnection(path[i+1], color);
	}
	pathConnectionsHighlighted = true;
	pathConnectionHighlightColor = color;
}
void Path::hidePathNodes()
{
	for(int i = 0; i<totalNodes; i++)
	{
		path[i]->setVisible(false);
	}
	pathHighlighted = false;
}
void Path::hidePathConnections()
{
	for(int i = 0; i<totalNodes-1; i++)
	{
		path[i]->hideConnections();
	}
	pathConnectionsHighlighted = false;
}
DebugNode* Path::getCurrentNode()
{
	return path[currentPathIndex];
}
