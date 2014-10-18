#pragma once
#pragma warning( disable : 4251 )

#include <glm\glm.hpp>
using glm::vec3;

class __declspec(dllexport) NodeContainer
{
public:
	int numNodes;
protected:
	#define R_CS(a) reinterpret_cast<char*>(&a), sizeof(a)
	#define R_C(t,a) reinterpret_cast<t>(a)//cast a to t

	float nodeRadius;
	vec3 nodeColor;
	vec3 sourceNodeColor;
	vec3 destinationnodeColor;

	unsigned int SERIALIZED_NODE_SIZE;
	unsigned int SERIALIZED_CONNECTION_SIZE;

	NodeContainer()
	{
		numNodes = 0;
		SERIALIZED_NODE_SIZE = sizeof(vec3) + sizeof(unsigned int) + sizeof(unsigned int);
		SERIALIZED_CONNECTION_SIZE = sizeof(float) + sizeof(unsigned int);
		nodeRadius = 0.25f;
		nodeColor = vec3(0.6f,0,1);
		sourceNodeColor = vec3(1,0,0);
		destinationnodeColor = vec3(0,1,0);
	}
	~NodeContainer(){}
};

