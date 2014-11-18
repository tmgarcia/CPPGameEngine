#pragma once
#pragma warning( disable : 4251 )

#include <glm\glm.hpp>

using glm::vec3;
#include "ExportHeader.h"

class DECL_DLL_EXPORT Node
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

