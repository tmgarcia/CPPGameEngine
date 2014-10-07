//#include "EditorNodeContainer.h"
//
//#include <glm\gtx\projection.hpp>
//
//#include "..\..\DebugTools\DebugShapes.h"
//#include "..\..\MathTools\Random.h"
//
//
//EditorNode* EditorNodeContainer::getRandomNode()
//{
//	int randomIndex = int(Random::getInstance().randomFloatRange(0, numNodes-1));
//	return nodes[randomIndex];
//}
//
//
//void EditorNodeContainer::loadInNodes(uint numNodes, char* nodeData)
//{
//	//nodes = vec3, int num connections, uint where connections start
//	//connections = float, uint
//	//selectedNode->toggleAttachedNode(clickedNode);
//	for(uint i = 0; i < numNodes; i++)
//	{
//		uint positionData = i * SERIALIZED_NODE_SIZE;
//		vec3 position = *(R_C(vec3*, nodeData + positionData));
//		addNode(position);
//	}
//
//	for(uint i = 0; i < numNodes; i++)
//	{
//		uint positionData = i * SERIALIZED_NODE_SIZE;
//
//		uint attachedNodeData = positionData + sizeof(vec3);
//
//		uint numConnections = *(R_C(uint*, nodeData + attachedNodeData));
//
//		uint nodeConnectionsDataOffsetPosition = attachedNodeData + sizeof(uint);
//
//		uint nodeConnectionsDataOffset = *(R_C(uint*, nodeData + nodeConnectionsDataOffsetPosition));
//
//		uint currentConnectionOffset = nodeConnectionsDataOffset;
//
//		for(int j = 0; j< numConnections; j++)
//		{
//			float cost = *R_C(float*, nodeData + currentConnectionOffset);
//			uint targetAddress = *(R_C(uint*, nodeData + currentConnectionOffset + sizeof(float)));
//			uint targetIndex = targetAddress;
//			nodes[i]->addConnection(nodes[targetIndex], cost);
//
//			currentConnectionOffset += SERIALIZED_CONNECTION_SIZE;
//		}
//	}
//	resetNodeColors();
//}
//
//void EditorNodeContainer::clearAllNodes()
//{
//	nodes.clear();
//	numNodes = 0;
//}
//
//ofstream* EditorNodeContainer::serializeNodes(ofstream *stream, uint NODE_DATA_BASE)
//{
//	uint NODE_DATA_BYTE_SIZE = numNodes * SERIALIZED_NODE_SIZE;
//	uint CONNECTION_DATA_BASE = NODE_DATA_BYTE_SIZE;
//	uint currentBits;
//	uint connectionFileOffset = CONNECTION_DATA_BASE;
//	for(int i = 0; i < numNodes; i++)
//	{
//		stream->write(R_CS(nodes[i]->position));
//		currentBits = nodes[i]->numConnections;
//		stream->write(R_CS(currentBits));
//		stream->write(R_CS(connectionFileOffset));//where connections start
//		connectionFileOffset += nodes[i]->numConnections * SERIALIZED_CONNECTION_SIZE;//Where next node's connections will start
//	}
//	uint fileAdress;
//	float cost;
//	for(int i = 0; i < numNodes; i++)
//	{
//		for(int j = 0; j < nodes[i]->numConnections; j++)
//		{
//			cost = nodes[i]->connections[j]->cost;
//			stream->write(R_CS(cost));
//
//			fileAdress = (nodes.indexOf(nodes[i]->connections[j]->node));
//			stream->write(R_CS(fileAdress));
//		}
//	}
//	return stream;
//}
//
//bool EditorNodeContainer::nodeRightClicked(vec3 clickDirection, vec3 clickOrigin)
//{
//	bool nodeClicked = false;
//	resetNodeColors();
//	if(nodeHasBeenClicked(clickDirection, clickOrigin))
//	{
//		nodeClicked = true;
//		selectedNode = clickedNode;
//		selectedNode->nodeInfo->color = sourceNodeColor;
//		if(selectedNode->numConnections>0)
//			selectedNode->highlightAllConnections(destinationnodeColor);
//	}
//	return nodeClicked;
//}
//
//void EditorNodeContainer::nodeLeftClicked(vec3 clickDirection, vec3 clickOrigin)
//{
//	if(nodeHasBeenClicked(clickDirection, clickOrigin))
//	{
//		if(clickedNode->position != selectedNode->position)
//		{
//			clickedNode->nodeInfo->color = destinationnodeColor;
//			selectedNode->toggleConnection(clickedNode);
//		}
//	}
//}
//
//bool EditorNodeContainer::nodeHasBeenClicked(vec3 clickDirection, vec3 clickOrigin)
//{
//	bool foundClickedNode = false;
//	if(numNodes>0)
//	{
//		for(int i = 0; i<numNodes && !foundClickedNode; i++)
//		{
//			vec3 sphereOrigin = nodes[i]->position;
//			float sphereRadius = nodeRadius;
//			vec3 cVec = clickOrigin-sphereOrigin;
//			float cVal = glm::length(cVec);
//			vec3 eVec = glm::proj(cVec, clickDirection);
//			float eVal = glm::length(eVec);
//			float b = glm::sqrt(glm::pow(cVal,2.0f) - glm::pow(eVal, 2.0f));
//			if(b<=sphereRadius)
//			{
//				foundClickedNode = true;
//				clickedNode = nodes[i];
//			}
//		}
//	}
//	return foundClickedNode;
//}
//
//void EditorNodeContainer::addNode(vec3 position)
//{
//	EditorNode* n = new EditorNode(position);
//	numNodes++;
//	mat4 modelToWorld = glm::translate(position) * glm::scale(vec3(nodeRadius,nodeRadius,nodeRadius));
//
//	vec3 color = nodeColor;
//	bool enableDepth = true;
//	float lifeTime = 10000;
//	n->nodeInfo = DebugShapes::getInstance().addNodeSphere(modelToWorld, color, enableDepth, lifeTime);
//	nodes.push_back(n);
//}
//
//void EditorNodeContainer::deleteSelectedNode()
//{
//	removeNode(selectedNode);
//}
//
//void EditorNodeContainer::resetNodeColors()
//{
//	for(int i = 0; i<numNodes; i++)
//	{
//		nodes[i]->nodeInfo->color = nodeColor;
//		nodes[i]->hideConnections();
//	}
//}
//
//void EditorNodeContainer::highlightAllNodes(vec3 color)
//{
//	for(int i = 0; i<numNodes; i++)
//	{
//		nodes[i]->setVisible(true);
//		nodes[i]->highlight(color);
//	}
//}
//void EditorNodeContainer::hideAllNodes()
//{
//	for(int i = 0; i<numNodes; i++)
//	{
//		nodes[i]->setVisible(false);
//	}
//}
//
//void EditorNodeContainer::removeNode(EditorNode* node)
//{
//	for(int i = 0; i<numNodes; i++)
//	{
//		if(nodes[i]->connectedToNode(node))
//		{
//			nodes[i]->toggleConnection(node);
//		}
//	}
//	node->clearConnections();
//	node->nodeInfo->remainingLife = 0;
//	node->nodeInfo->renderables[0]->visible = false;
//	nodes.removeAt(nodes.indexOf(node));
//	numNodes--;
//	resetNodeColors();
//}
//
//EditorNodeContainer::EditorNodeContainer()
//{
//	numNodes = 0;
//}
//
//
//EditorNodeContainer::~EditorNodeContainer()
//{
//
//}
