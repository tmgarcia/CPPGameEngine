#pragma once
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"

class ObjReader
{
public:
	static const unsigned int POSITION_OFFSET = 0;
	static const unsigned int NORMAL_OFFSET = sizeof(glm::vec3);
	static const unsigned int UV_OFFSET = 2*sizeof(glm::vec3);
	static const unsigned int STRIDE = 8*sizeof(float);
	struct Vertex
	{
	public:
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 textureCoord;
	};

	struct ShapeData
	{
	public:
		unsigned int numVertices;
		unsigned int numIndices;
		unsigned int vertexDataSize;
		unsigned int indexDataSize;
		Vertex* vertices;
		unsigned short* indices;
	};

	ShapeData readInShape(char* filename);
};

