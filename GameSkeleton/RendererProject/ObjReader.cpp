#include "ObjReader.h"
#include <iostream>
#include <fstream>
using namespace std;

ObjReader::ShapeData ObjReader::readInShape(char* filename)
{
	ifstream binFile;
	binFile.open(filename, ios::in | ios::binary);
	if(binFile.fail())
	{
		cout << "Unable to open file." << endl;
	}
	int header [2];

	binFile.read(reinterpret_cast<char *>(&header), 8);
	cout << header[0] << " " << header[1] << endl;
	int numVertices = header[0];
	int numIndices = header[1];
	int vertexDataSize = numVertices*(sizeof(Vertex));
	int indexDataSize = numIndices*(sizeof(unsigned short));
	
	char* data = new char [vertexDataSize+indexDataSize];
	binFile.read(data, vertexDataSize+indexDataSize);

	Vertex* vertexData = reinterpret_cast<Vertex*>(data);
	unsigned short* indexData = reinterpret_cast<unsigned short*>(data + vertexDataSize);

	for(int i = 0; i< numIndices; i++)
	{
		cout << indexData[i] << endl;
	}

	ObjReader::ShapeData shape;
	shape.indices = indexData;
	shape.indexDataSize = indexDataSize;
	shape.numIndices = numIndices;
	shape.vertices = vertexData;
	shape.vertexDataSize = vertexDataSize;
	shape.numVertices = numVertices;
	
	return shape;
}