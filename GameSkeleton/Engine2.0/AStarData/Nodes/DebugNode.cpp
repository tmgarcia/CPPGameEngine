#include "DebugNode.h"
#include "..\..\MathTools\Random.h"

bool DebugNode::connectedToNode(DebugNode* n)
{
	return(findConnection(n)!=-1);
}

int DebugNode::findConnection(DebugNode* n)
{
	bool foundNode = false;
	int index = -1;
	for(int i = 0; i<numConnections && !foundNode; i++)
	{
		if(connections[i]->node==n)
		{
			foundNode = true;
			index = i;
		}
	}
	return index;
}

void DebugNode::addConnection(DebugNode* n, float cost)
{
	Connection* cn = new Connection();
	cn->node = n;
	cn->arrowInfo = DebugShapes::addVectorArrow(position, n->position);
	cn->cost = cost;
	connections.push_back(cn);
	numConnections++;
}

void DebugNode::removeConnection(DebugNode* n)
{
	n->nodeInfo->color = vec3(0.6f,0,1);
	int i = findConnection(n);
	connections[i]->arrowInfo->head->renderables[0]->visible = false;
	connections[i]->arrowInfo->stem->renderables[0]->visible = false;
	connections[i]->arrowInfo->head->remainingLife = 0;
	connections[i]->arrowInfo->stem->remainingLife = 0;
	connections.removeAt(i);
	numConnections--;
}

DebugNode* DebugNode::getRandomConnection()
{
	int randomIndex = (int)Random::getInstance().randomFloatRange(0, numConnections-1);
	DebugNode* randomNode = connections.at(randomIndex)->node;
	
	return randomNode;
}

void DebugNode::hideConnections()
{
	for(int i = 0; i<numConnections; i++)
	{
		connections[i]->arrowInfo->head->renderables[0]->visible = false;
		connections[i]->arrowInfo->stem->renderables[0]->visible = false;
	}
}

void DebugNode::highlightAllConnections(vec3 color)
{
	for(int i = 0; i<numConnections; i++)
	{
		connections[i]->node->nodeInfo->color = color;
		connections[i]->arrowInfo->head->renderables[0]->visible = true;
		connections[i]->arrowInfo->stem->renderables[0]->visible = true;
	}
}

void DebugNode::highlight(vec3 color)
{
	nodeInfo->color = color;
}
void DebugNode::highlightConnection(DebugNode* n,vec3 color)
{
	int connectionIndex = findConnection(n);
	if(connectionIndex!=-1)
	{
		connections[connectionIndex]->arrowInfo->head->renderables[0]->visible = true;
		connections[connectionIndex]->arrowInfo->stem->renderables[0]->visible = true;
		connections[connectionIndex]->arrowInfo->head->color = color;
		connections[connectionIndex]->arrowInfo->stem->color = color;
	}
}

void DebugNode::setVisible(bool isVisible)
{
	nodeInfo->renderables[0]->visible = isVisible;
}

void DebugNode::clearConnections()
{
	for(int i = 0; i<numConnections; i++)
	{
		connections[i]->arrowInfo->head->renderables[0]->visible = false;
		connections[i]->arrowInfo->stem->renderables[0]->visible = false;
		connections[i]->arrowInfo->head->remainingLife = 0;
		connections[i]->arrowInfo->stem->remainingLife = 0;
	}
	connections.clear();
}