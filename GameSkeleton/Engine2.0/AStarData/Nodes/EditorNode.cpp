//#include "EditorNode.h"
//#include "..\..\MathTools\Random.h"
//
//bool EditorNode::connectedToNode(EditorNode* n)
//{
//	return(findConnection(n)!=-1);
//}
//
//int EditorNode::findConnection(EditorNode* n)
//{
//	bool foundNode = false;
//	int index = -1;
//	for(int i = 0; i<numConnections&& !foundNode; i++)
//	{
//		if(connections[i]->node==n)
//		{
//			foundNode = true;
//			index = i;
//		}
//	}
//	return index;
//}
//
//void EditorNode::toggleConnection(EditorNode* n)
//{
//	if(findConnection(n)!=-1)
//	{
//		removeConnection(n);
//	}
//	else
//	{
//		addConnection(n, glm::length(position-n->position));
//	}
//}
//
//void EditorNode::addConnection(EditorNode* n, float cost)
//{
//	ConnectingNode* cn = new ConnectingNode();
//	cn->node = n;
//	cn->arrowInfo = DebugShapes::addVectorArrow(position, n->position);
//	cn->cost = cost;
//	connections.push_back(cn);
//	numConnections++;
//}
//
//void EditorNode::removeConnection(EditorNode* n)
//{
//	n->nodeInfo->color = vec3(0.6f,0,1);
//	int i = findConnection(n);
//	connections[i]->arrowInfo->head->renderables[0]->visible = false;
//	connections[i]->arrowInfo->stem->renderables[0]->visible = false;
//	connections[i]->arrowInfo->head->remainingLife = 0;
//	connections[i]->arrowInfo->stem->remainingLife = 0;
//	connections.removeAt(i);
//	numConnections--;
//}
//
//EditorNode* EditorNode::getRandomConnection()
//{
//	int randomIndex = (int)Random::getInstance().randomFloatRange(0, numConnections-1);
//	EditorNode* randomNode = connections.at(randomIndex)->node;
//	
//	return randomNode;
//}
//
//void EditorNode::hideConnections()
//{
//	for(int i = 0; i<numConnections; i++)
//	{
//		connections[i]->arrowInfo->head->renderables[0]->visible = false;
//		connections[i]->arrowInfo->stem->renderables[0]->visible = false;
//	}
//}
//
//void EditorNode::highlightAllConnections(vec3 color)
//{
//	for(int i = 0; i<numConnections; i++)
//	{
//		connections[i]->node->nodeInfo->color = color;
//		connections[i]->arrowInfo->head->renderables[0]->visible = true;
//		connections[i]->arrowInfo->stem->renderables[0]->visible = true;
//	}
//}
//
//void EditorNode::highlight(vec3 color)
//{
//	nodeInfo->color = color;
//}
//void EditorNode::highlightConnection(EditorNode* n,vec3 color)
//{
//	int connectionIndex = findConnection(n);
//	if(connectionIndex!=-1)
//	{
//		connections[connectionIndex]->arrowInfo->head->renderables[0]->visible = true;
//		connections[connectionIndex]->arrowInfo->stem->renderables[0]->visible = true;
//		connections[connectionIndex]->arrowInfo->head->color = color;
//		connections[connectionIndex]->arrowInfo->stem->color = color;
//	}
//}
//
//void EditorNode::setVisible(bool isVisible)
//{
//	nodeInfo->renderables[0]->visible = isVisible;
//}
//
//void EditorNode::clearConnections()
//{
//	for(int i = 0; i<numConnections; i++)
//	{
//		connections[i]->arrowInfo->head->renderables[0]->visible = false;
//		connections[i]->arrowInfo->stem->renderables[0]->visible = false;
//		connections[i]->arrowInfo->head->remainingLife = 0;
//		connections[i]->arrowInfo->stem->remainingLife = 0;
//	}
//	connections.clear();
//}