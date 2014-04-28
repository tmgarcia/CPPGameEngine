#include "PathCreator.h"


Path PathCreator::calculatePath(EditorNode* start, EditorNode* end)
{
	startNode = start;
	endNode = end;

	PathingNode* currentParentNode;
	for(processNode(start, 0, NULL), currentParentNode=processedNodes[0]; !endNodeHasLowestTEC() && openNodesRemaining(); currentParentNode = getOpenNodeWithLowestTEC())
	{
		currentParentNode->open=false;
		for(int i = 0; i<currentParentNode->node->numAttachedNodes; i++)
		{
			float connectionCostSquared = glm::pow(currentParentNode->node->attachedNodes[i]->cost, 2.0f);
			float costSoFar = connectionCostSquared + currentParentNode->costSoFar;
			processNode(currentParentNode->node->attachedNodes[i]->node, costSoFar, currentParentNode);
		}
	}
	Path p = Path(nullptr, 0);
	if(openNodesRemaining())//If the end node could actually be reached
	{
		QList <EditorNode*> reversePath;
		bool reachedStartNode = false;
		uint numNodesInPath = 0;
		PathingNode* currentNode = currentParentNode;//current parent node will be end node
		while(!reachedStartNode)
		{
			reversePath.prepend(currentNode->node);
			numNodesInPath++;
			if(currentNode->node == startNode)
			{
				reachedStartNode = true;
			}
			else
			{
				currentNode = currentNode->parentNode;
			}
		}
		EditorNode** path = new EditorNode*[numNodesInPath];
		for(int i = 0; i<numNodesInPath; i++)
		{
			path[i] = reversePath[i];
		}
		reversePath.clear();
		p = Path(path, numNodesInPath);
	}
	else
	{
		cout << "IMPOSSIBLE PATH" << endl;
	}
	return p;
}
void PathCreator::processNode(EditorNode* node, float costSoFar, PathingNode* parent)
{
	vec3 nodeToEnd = endNode->position - node->position;
	float h = (nodeToEnd.x*nodeToEnd.x)+(nodeToEnd.y*nodeToEnd.y)+(nodeToEnd.z*nodeToEnd.z);//from node to end, squared
	float tec = h + costSoFar;//total estimated cost -  squared h, squared cost

	PathingNode* n;
	int index = nodePreviouslyProcessed(node);
	
	if(index == -1)//Node has not been previously processed
	{
		n = new PathingNode(node, h);
		n->costSoFar = costSoFar;
		n->totalEstimatedCost = tec; 
		n->parentNode = parent;
		n->open = true;
		processedNodes.append(n);
	}
	else if(processedNodes[index]->totalEstimatedCost>tec)//Node has been previously processed, but new route results in lower costs
	{
		processedNodes[index]->costSoFar = costSoFar;
		processedNodes[index]->totalEstimatedCost = tec;
		processedNodes[index]->parentNode = parent;
		processedNodes[index]->open = true;
	}
}
bool PathCreator::endNodeHasLowestTEC()
{
	bool endHasLowestTEC = false;
	int endNodeIndex = nodePreviouslyProcessed(endNode);
	if(endNodeIndex != -1)
	{
		endHasLowestTEC = (getOpenNodeWithLowestTEC() == processedNodes[endNodeIndex]);
	}

	return endHasLowestTEC;
}
bool PathCreator::openNodesRemaining()
{
	bool foundOpenNode = false;
	for(int i = 0; i<processedNodes.size() && !foundOpenNode; i++)
	{
		foundOpenNode = processedNodes[i]->open;
	}
	return foundOpenNode;
}
PathingNode* PathCreator::getOpenNodeWithLowestTEC()
{
	int index = 0;
	float currentLowestTec = FLT_MAX;
	for(int i = 0; i<processedNodes.size(); i++)
	{
		if(processedNodes[i]->open && processedNodes[i]->totalEstimatedCost <  currentLowestTec)
		{
			currentLowestTec = processedNodes[i]->totalEstimatedCost;
			index = i;
		}
	}
	return processedNodes[index];
}
int PathCreator::nodePreviouslyProcessed(EditorNode* node)
{
	int index = -1;
	for(int i = 0; i < processedNodes.size(); i++)
	{
		if(processedNodes[i]->node== node)
		{
			index = i;
		}
	}
	return index;
}