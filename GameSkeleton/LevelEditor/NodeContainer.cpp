#include "NodeContainer.h"
#include <glm\gtx\projection.hpp>

#include "DebugShapes.h"
#include "Random.h"

float nodeRadius = 0.25f;
vec3 nodeColor = vec3(0.6f,0,1);
vec3 sourceNodeColor = vec3(1,0,0);
vec3 destinationnodeColor = vec3(0,1,0);

bool NodeContainer::nodeRightClicked(vec3 clickDirection, vec3 clickOrigin)
{
	bool nodeClicked = false;
	resetNodeColors();
	if(nodeHasBeenClicked(clickDirection, clickOrigin))
	{
		nodeClicked = true;
		selectedNode = clickedNode;
		selectedNode->nodeInfo->color = sourceNodeColor;
		if(selectedNode->numAttachedNodes>0)
			selectedNode->highlightAttachedNodes(destinationnodeColor);
	}
	return nodeClicked;
}

void NodeContainer::nodeLeftClicked(vec3 clickDirection, vec3 clickOrigin)
{
	if(nodeHasBeenClicked(clickDirection, clickOrigin))
	{
		if(clickedNode->position != selectedNode->position)
		{
			clickedNode->nodeInfo->color = destinationnodeColor;
			selectedNode->toggleAttachedNode(clickedNode);
		}
	}
}

bool NodeContainer::nodeHasBeenClicked(vec3 clickDirection, vec3 clickOrigin)
{
	bool foundClickedNode = false;
	if(numNodes>0)
	{
		for(int i = 0; i<numNodes && !foundClickedNode; i++)
		{
			vec3 sphereOrigin = nodes[i]->position;
			float sphereRadius = nodeRadius;
			vec3 cVec = clickOrigin-sphereOrigin;
			float cVal = glm::length(cVec);
			vec3 eVec = glm::proj(cVec, clickDirection);
			float eVal = glm::length(eVec);
			float b = glm::sqrt(glm::pow(cVal,2.0f) - glm::pow(eVal, 2.0f));
			if(b<=sphereRadius)
			{
				foundClickedNode = true;
				clickedNode = nodes[i];
				cout<< "Node clicked" << endl;
			}
		}
	}
	return foundClickedNode;
}

void NodeContainer::addNode(vec3 position)
{
	Node* n = new Node(position);
	numNodes++;
	mat4 modelToWorld = glm::translate(position) * glm::scale(vec3(nodeRadius,nodeRadius,nodeRadius));

	vec3 color = nodeColor;
	bool enableDepth = true;
	float lifeTime = 10000;
	n->nodeInfo = DebugShapes::getInstance().addNodeSphere(modelToWorld, color, enableDepth, lifeTime);
	nodes.push_back(n);
}

void NodeContainer::deleteSelectedNode()
{
	removeNode(selectedNode);
}

void NodeContainer::resetNodeColors()
{
	for(int i = 0; i<numNodes; i++)
	{
		nodes[i]->nodeInfo->color = nodeColor;
		nodes[i]->hideAttachedNodes();
	}
}

void NodeContainer::removeNode(Node* node)
{
	for(int i = 0; i<numNodes; i++)
	{
		if(nodes[i]->connectedToNode(node))
		{
			nodes[i]->toggleAttachedNode(node);
		}
	}
	node->clearAttachedNodes();
	node->nodeInfo->remainingLife = 0;
	node->nodeInfo->renderables[0]->visible = false;
	nodes.removeAt(nodes.indexOf(node));
	numNodes--;
	resetNodeColors();
}

void NodeContainer::drawNodes()
{

}

void NodeContainer::drawNode(Node* node)
{

}

NodeContainer::NodeContainer()
{
	numNodes = 0;
}


NodeContainer::~NodeContainer()
{

}
