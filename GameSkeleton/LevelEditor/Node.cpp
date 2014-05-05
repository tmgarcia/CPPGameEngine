#include "Node.h"
#include "MathTools\Random.h"

bool Node::connectedToNode(Node* n)
{
	return(findConnection(n)!=-1);
}

int Node::findConnection(Node* n)
{
	bool foundNode = false;
	int index = -1;
	for(int i = 0; i<numAttachedNodes && !foundNode; i++)
	{
		if(attachedNodes[i]->node==n)
		{
			foundNode = true;
			index = i;
		}
	}
	return index;
}

void Node::toggleAttachedNode(Node* n)
{
	if(findConnection(n)!=-1)
	{
		removeAttachedNode(n);
	}
	else
	{
		addAttachedNode(n, glm::length(position-n->position));
	}
}

void Node::addAttachedNode(Node* n, float cost)
{
	ConnectingNode* cn = new ConnectingNode();
	cn->node = n;
	cn->arrowInfo = DebugShapes::addVectorArrow(position, n->position);
	cn->cost = cost;
	attachedNodes.push_back(cn);
	numAttachedNodes++;
}

void Node::removeAttachedNode(Node* n)
{
	n->nodeInfo->color = vec3(0.6f,0,1);
	int i = findConnection(n);
	attachedNodes[i]->arrowInfo->head->renderables[0]->visible = false;
	attachedNodes[i]->arrowInfo->stem->renderables[0]->visible = false;
	attachedNodes[i]->arrowInfo->head->remainingLife = 0;
	attachedNodes[i]->arrowInfo->stem->remainingLife = 0;
	attachedNodes.removeAt(i);
	numAttachedNodes--;
}

Node* Node::getRandomAttachedNode()
{
	int randomIndex = (int)Random::getInstance().randomFloatRange(0, numAttachedNodes-1);
	Node* randomNode = attachedNodes.at(randomIndex)->node;
	
	return randomNode;
}

void Node::hideAttachedNodes()
{
	for(int i = 0; i<numAttachedNodes; i++)
	{
		attachedNodes[i]->arrowInfo->head->renderables[0]->visible = false;
		attachedNodes[i]->arrowInfo->stem->renderables[0]->visible = false;
	}
}

void Node::highlightAttachedNodes(vec3 color)
{
	for(int i = 0; i<numAttachedNodes; i++)
	{
		attachedNodes[i]->node->nodeInfo->color = color;
		attachedNodes[i]->arrowInfo->head->renderables[0]->visible = true;
		attachedNodes[i]->arrowInfo->stem->renderables[0]->visible = true;
	}
}

void Node::clearAttachedNodes()
{
	for(int i = 0; i<numAttachedNodes; i++)
	{
		attachedNodes[i]->arrowInfo->head->renderables[0]->visible = false;
		attachedNodes[i]->arrowInfo->stem->renderables[0]->visible = false;
		attachedNodes[i]->arrowInfo->head->remainingLife = 0;
		attachedNodes[i]->arrowInfo->stem->remainingLife = 0;
	}
	attachedNodes.clear();
}