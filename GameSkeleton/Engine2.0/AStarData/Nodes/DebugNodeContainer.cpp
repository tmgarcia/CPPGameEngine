//#include "DebugNodeContainer.h"
//
//#include <glm\gtx\projection.hpp>
//
//#include "..\..\DebugTools\DebugShapes.h"
//#include "..\..\MathTools\Random.h"
//
//
//DebugNodeContainer* DebugNodeContainer::theInstance;
//
//DebugNodeContainer& DebugNodeContainer::getInstance()
//{
//	if(theInstance == 0)
//	{
//		theInstance = new DebugNodeContainer();
//	}
//	return *theInstance;
//}
//
//DebugNode* DebugNodeContainer::getRandomNode()
//{
//	int randomIndex = int(Random::getInstance().randomFloatRange(0, numNodes-1));
//	return nodes[randomIndex];
//}
//
//
//void DebugNodeContainer::loadInNodes(uint numNodes, char* nodeData)
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
//void DebugNodeContainer::clearAllNodes()
//{
//	for(int i = 0; i < numNodes; i++)
//	{
//		nodes[i]->clearConnections();
//	}
//	nodes.clear();
//	numNodes = 0;
//}
//
//DebugNode* DebugNodeContainer::getNode(int index)
//{
//	return nodes[index];
//}
//
//void DebugNodeContainer::addNode(vec3 position)
//{
//	DebugNode* n = new DebugNode(position);
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
//
//void DebugNodeContainer::resetNodeColors()
//{
//	for(int i = 0; i<numNodes; i++)
//	{
//		nodes[i]->nodeInfo->color = nodeColor;
//		nodes[i]->hideConnections();
//	}
//}
//
//void DebugNodeContainer::highlightAllNodes(vec3 color)
//{
//	for(int i = 0; i<numNodes; i++)
//	{
//		nodes[i]->setVisible(true);
//		nodes[i]->highlight(color);
//	}
//}
//void DebugNodeContainer::hideAllNodes()
//{
//	for(int i = 0; i<numNodes; i++)
//	{
//		nodes[i]->setVisible(false);
//	}
//}
//
//void DebugNodeContainer::removeNode(DebugNode* node)
//{
//	for(int i = 0; i<numNodes; i++)
//	{
//		if(nodes[i]->connectedToNode(node))
//		{
//			nodes[i]->removeConnection(node);
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
//
//DebugNodeContainer::~DebugNodeContainer()
//{
//
//}
