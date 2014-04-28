#include "EditorNodeContainer.h"

#include <glm\gtx\projection.hpp>

#include "..\DebugTools\DebugShapes.h"
#include "..\MathTools\Random.h"

float nodeRadius = 0.25f;
vec3 nodeColor = vec3(0.6f,0,1);
vec3 sourceNodeColor = vec3(1,0,0);
vec3 destinationnodeColor = vec3(0,1,0);

EditorNode* EditorNodeContainer::getRandomNode()
{
	int randomIndex = int(Random::getInstance().randomFloatRange(0, numNodes-1));
	return nodes[randomIndex];
}

#define R_CS(a) reinterpret_cast<char*>(&a), sizeof(a)
#define R_C(t,a) reinterpret_cast<t>(a)//cast a to t
#define NODE_FILE_ADDRESS(nodeIndex) nodeIndex * SERIALIZED_NODE_SIZE
uint SERIALIZED_NODE_SIZE = sizeof(vec3) + sizeof(uint) + sizeof(uint);
uint SERIALIZED_CONNECTION_SIZE = sizeof(float) + sizeof(uint);

void EditorNodeContainer::loadInNodes(uint numNodes, char* nodeData)
{
	//nodes = vec3, int num connections, uint where connections start
	//connections = float, uint
	//selectedNode->toggleAttachedNode(clickedNode);
	cout << "-- loading nodes --"<< endl;
	for(uint i = 0; i < numNodes; i++)
	{
		uint positionData = i * SERIALIZED_NODE_SIZE;
		cout << "positionData " << positionData << endl;
		vec3 position = *(R_C(vec3*, nodeData + positionData));
		cout << "node " << i << endl;
		cout << position.x << "," << position.y << "," << position.z << endl;
		addNode(position);
	}

	cout << "-- loading connections --"<< endl;
	for(uint i = 0; i < numNodes; i++)
	{
		cout << "node " << i << endl;
		uint positionData = i * SERIALIZED_NODE_SIZE;

		uint attachedNodeData = positionData + sizeof(vec3);
		cout << "attachedNodeData " << attachedNodeData << endl;

		uint numAttachedNodes = *(R_C(uint*, nodeData + attachedNodeData));
		cout << numAttachedNodes << " connections" << endl;

		uint nodeConnectionsDataOffsetPosition = attachedNodeData + sizeof(uint);
		cout << "connectionDataOffset position " << nodeConnectionsDataOffsetPosition << endl;

		uint nodeConnectionsDataOffset = *(R_C(uint*, nodeData + nodeConnectionsDataOffsetPosition));
		cout << "node's connections offset " << nodeConnectionsDataOffset << endl;

		uint currentConnectionOffset = nodeConnectionsDataOffset;
		cout << "current Connection Offset " << currentConnectionOffset << endl;

		for(int j = 0; j< numAttachedNodes; j++)
		{
			cout << "connection " << j << endl;
			float cost = *R_C(float*, nodeData + currentConnectionOffset);
			cout << "cost " << cost << endl;
			uint targetAddress = *(R_C(uint*, nodeData + currentConnectionOffset + sizeof(float)));
			uint targetIndex = targetAddress;
			cout << "target index " << targetIndex << endl;
			nodes[i]->addAttachedNode(nodes[targetIndex], cost);

			currentConnectionOffset += SERIALIZED_CONNECTION_SIZE;
		}
	}
	resetNodeColors();
}

void EditorNodeContainer::clearAllNodes()
{
	nodes.clear();
	numNodes = 0;
}

ofstream* EditorNodeContainer::serializeNodes(ofstream *stream, uint NODE_DATA_BASE)
{
	cout << "-- saving nodes --"<< endl;
	cout << "num nodes" << numNodes<< endl;
	uint NODE_DATA_BYTE_SIZE = numNodes * SERIALIZED_NODE_SIZE;
	uint CONNECTION_DATA_BASE = NODE_DATA_BYTE_SIZE;
	uint currentBits;
	uint connectionFileOffset = CONNECTION_DATA_BASE;
	for(int i = 0; i < numNodes; i++)
	{
		cout << "node" << i << endl;
		stream->write(R_CS(nodes[i]->position));
		currentBits = nodes[i]->numAttachedNodes;
		stream->write(R_CS(currentBits));
		cout << nodes[i]->numAttachedNodes << " connections" << endl;
		stream->write(R_CS(connectionFileOffset));//where connections start
		connectionFileOffset += nodes[i]->numAttachedNodes * SERIALIZED_CONNECTION_SIZE;//Where next node's connections will start
	}
	uint fileAdress;
	float cost;
	for(int i = 0; i < numNodes; i++)
	{
		cout << "i="<< i << endl;
		for(int j = 0; j < nodes[i]->numAttachedNodes; j++)
		{
			cout << "j="<< j << endl;
			cout << "-- saving connections --"<< endl;
			cost = nodes[i]->attachedNodes[j]->cost;
			cout << "cost "<< cost << endl;
			stream->write(R_CS(cost));

			fileAdress = (nodes.indexOf(nodes[i]->attachedNodes[j]->node));
			stream->write(R_CS(fileAdress));
			cout << "target index "<< fileAdress << endl;
		}
	}
	return stream;
}

bool EditorNodeContainer::nodeRightClicked(vec3 clickDirection, vec3 clickOrigin)
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

void EditorNodeContainer::nodeLeftClicked(vec3 clickDirection, vec3 clickOrigin)
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

bool EditorNodeContainer::nodeHasBeenClicked(vec3 clickDirection, vec3 clickOrigin)
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

void EditorNodeContainer::addNode(vec3 position)
{
	EditorNode* n = new EditorNode(position);
	numNodes++;
	mat4 modelToWorld = glm::translate(position) * glm::scale(vec3(nodeRadius,nodeRadius,nodeRadius));

	vec3 color = nodeColor;
	bool enableDepth = true;
	float lifeTime = 10000;
	n->nodeInfo = DebugShapes::getInstance().addNodeSphere(modelToWorld, color, enableDepth, lifeTime);
	nodes.push_back(n);
}

void EditorNodeContainer::deleteSelectedNode()
{
	removeNode(selectedNode);
}

void EditorNodeContainer::resetNodeColors()
{
	for(int i = 0; i<numNodes; i++)
	{
		nodes[i]->nodeInfo->color = nodeColor;
		nodes[i]->hideAttachedNodes();
	}
}

void EditorNodeContainer::removeNode(EditorNode* node)
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

EditorNodeContainer::EditorNodeContainer()
{
	numNodes = 0;
}


EditorNodeContainer::~EditorNodeContainer()
{

}
