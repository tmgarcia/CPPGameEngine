#include "EditorNode.h"
#include "..\MathTools\Random.h"

bool EditorNode::connectedToNode(EditorNode* n)
{
	return(findConnection(n)!=-1);
}

int EditorNode::findConnection(EditorNode* n)
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

void EditorNode::toggleAttachedNode(EditorNode* n)
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

void EditorNode::addAttachedNode(EditorNode* n, float cost)
{
	ConnectingNode* cn = new ConnectingNode();
	cn->node = n;
	cn->arrowInfo = DebugShapes::addVectorArrow(position, n->position);
	cn->cost = cost;
	attachedNodes.push_back(cn);
	numAttachedNodes++;
}

void EditorNode::removeAttachedNode(EditorNode* n)
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

EditorNode* EditorNode::getRandomAttachedNode()
{
	int randomIndex = (int)Random::getInstance().randomFloatRange(0, numAttachedNodes-1);
	EditorNode* randomNode = attachedNodes.at(randomIndex)->node;
	
	return randomNode;
}

void EditorNode::hideAttachedNodes()
{
	for(int i = 0; i<numAttachedNodes; i++)
	{
		attachedNodes[i]->arrowInfo->head->renderables[0]->visible = false;
		attachedNodes[i]->arrowInfo->stem->renderables[0]->visible = false;
	}
}

void EditorNode::highlightAttachedNodes(vec3 color)
{
	for(int i = 0; i<numAttachedNodes; i++)
	{
		attachedNodes[i]->node->nodeInfo->color = color;
		attachedNodes[i]->arrowInfo->head->renderables[0]->visible = true;
		attachedNodes[i]->arrowInfo->stem->renderables[0]->visible = true;
	}
}

void EditorNode::clearAttachedNodes()
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