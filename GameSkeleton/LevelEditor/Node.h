#pragma once

#include <list>
#include <glm\glm.hpp>

using std::list;
using glm::vec3;

class Node
{
public:
	list<Node*> attachedNodes;
	vec3 position;
	int numAttachedNodes;

	void addAttachedNode(Node* n);
	void removeAttachedNode(Node* n);
	//Node* getRandomAttachedNode();

	Node(vec3 location)
	{
		position = location;
		numAttachedNodes = 0;
	}
	~Node();
};

