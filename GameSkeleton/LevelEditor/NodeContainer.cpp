#include "NodeContainer.h"

#include "DebugShapes.h"

void NodeContainer::addNode(vec3 position)
{
	/*if(numActiveTroops<MAX_ENEMIES)
	{
		troops.push_back(new Enemy(position));
		numActiveTroops++;
	}*/
	nodes.push_back(new Node(position));
	numNodes++;

	//DebugShapes::getInstance().addSphere(modeltoworld, color, enable depth, lifetime)
	mat4 modelToWorld = glm::translate(position) * glm::scale(vec3(0.5f,0.5f,0.5f));
	vec3 color = vec3(1,1,1);
	bool enableDepth = true;
	float lifeTime = 10000;
	DebugShapes::getInstance().addSphere(modelToWorld, color, enableDepth, lifeTime);
}

void NodeContainer::removeNode(Node* node)
{
	nodes.removeAt(nodes.indexOf(node));
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
