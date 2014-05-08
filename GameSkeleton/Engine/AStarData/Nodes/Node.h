#pragma once

#include <glm\glm.hpp>

using glm::vec3;

class __declspec(dllexport) Node
{
public:
	vec3 position;
	int numConnections;

	Node(vec3 location)
	{
		position = location;
		numConnections = 0;
	}
	~Node(){}
};

