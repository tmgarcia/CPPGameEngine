#include "Node.h"
#include "Random.h"

void Node::addAttachedNode(Node* n)
{
	attachedNodes.push_back(n);
	numAttachedNodes++;
}
void Node::removeAttachedNode(Node* n)
{
	attachedNodes.remove(n);
	numAttachedNodes--;
	//int index = 0;
	//for(int i=0; i<numAttachedNodes; i++)
	//{

	//}
}

//Node* Node::getRandomAttachedNode()
//{
//	//int randomIndex = (int)Random::getInstance().randomFloatRange(0, numAttachedNodes);
//	//std::list<Node*>::iterator it;
//	//if (attachedNodes.size() > randomIndex)
//	//{
//	//	std::list<Node*>::iterator it = std::next(attachedNodes.begin(), randomIndex);
//	//}
//	//
//	//return ;
//}