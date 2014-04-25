#include "NodeContainer.h"
#include <glm\gtx\projection.hpp>

#include "DebugShapes.h"
#include "Random.h"


float nodeRadius = 0.25f;
vec3 nodeColor = vec3(0.6f,0,1);
vec3 sourceNodeColor = vec3(1,0,0);
vec3 destinationnodeColor = vec3(0,1,0);

#define R_CS(a) reinterpret_cast<char*>(&a), sizeof(a)
#define R_C(t,a) reinterpret_cast<t>(a)//cast a to t
#define NODE_FILE_ADDRESS(nodeIndex) NODE_DATA_BASE + nodeIndex * SERIALIZED_NODE_SIZE
uint SERIALIZED_NODE_SIZE = sizeof(vec3) + sizeof(int) + sizeof(uint);
uint SERIALIZED_CONNECTION_SIZE = sizeof(float) + sizeof(uint);

void NodeContainer::loadInNodes(uint numNodes, char* nodeData)
{
	//nodes = vec3, int num connections, uint where connections start
	//connections = float, uint
	//selectedNode->toggleAttachedNode(clickedNode);
	for(uint i = 0; i < numNodes; i++)
	{
		uint positionData = i * SERIALIZED_NODE_SIZE;
		vec3 position = *(R_C(vec3*, nodeData + positionData));
		cout << position.x << "," << position.y << "," << position.z << endl;
		addNode(position);

		uint attachedNodeData = positionData + sizeof(vec3);
		int numAttachedNodes = (R_C(int, nodeData + attachedNodeData));

		uint connectionFileOffsetData = attachedNodeData + sizeof(int);

		uint connectionFileOffset = (R_C(uint, nodeData + connectionFileOffsetData));
		for(int j = 0; j<numAttachedNodes; j++)
		{

		}

	}
}

void NodeContainer::clearAllNodes()
{
	nodes.clear();
}

ofstream* NodeContainer::serializeNodes(ofstream *stream, uint NODE_DATA_BASE)
{
	uint NODE_DATA_BYTE_SIZE = numNodes * SERIALIZED_NODE_SIZE;
	uint CONNECTION_DATA_BASE = NODE_DATA_BASE + NODE_DATA_BYTE_SIZE;
	uint currentBits;
	uint connectionFileOffset = CONNECTION_DATA_BASE;
	for(int i = 0; i < numNodes; i++)
	{
		stream->write(R_CS(nodes[i]->position));
		currentBits = nodes[i]->numAttachedNodes;	
		stream->write(R_CS(currentBits));
		stream->write(R_CS(connectionFileOffset));//where connections start
		connectionFileOffset += nodes[i]->numAttachedNodes * SERIALIZED_CONNECTION_SIZE;//Where next node's connections will start
	}
	uint fileAdress;
	float cost;
	for(int i = 0; i < numNodes; i++)
	{
		for(int j = 0; j < nodes[i]->numAttachedNodes; i++)
		{
			cost = nodes[i]->attachedNodes[j]->cost;
			fileAdress = NODE_FILE_ADDRESS(nodes.indexOf(nodes[i]->attachedNodes[j]->node));
			stream->write(R_CS(cost));
			stream->write(R_CS(fileAdress));
		}
	}
	return stream;
}

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

NodeContainer::NodeContainer()
{
	numNodes = 0;
}


NodeContainer::~NodeContainer()
{

}
