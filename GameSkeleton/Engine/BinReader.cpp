#include "BinReader.h"
#include <iostream>
#include <fstream>
using namespace std;

BinReader::ShapeData BinReader::readInShape(char* filename)
{
	ifstream binFile;
	binFile.open(filename, ios::in | ios::binary);
	if(binFile.fail())
	{ 
		cout << "Unable to open file." << endl;
		cout << filename << endl;
		cerr << "Error: " << strerror(errno);
	}
	int header [2];

	binFile.read(reinterpret_cast<char *>(&header), 8);
	int numVertices = header[0];
	int numIndices = header[1];
	int vertexDataSize = numVertices*(sizeof(Vertex));
	int indexDataSize = numIndices*(sizeof(unsigned short));
	
	char* data = new char [vertexDataSize+indexDataSize];
	binFile.read(data, vertexDataSize+indexDataSize);
	binFile.close();
	Vertex* vertexData = reinterpret_cast<Vertex*>(data);
	unsigned short* indexData = reinterpret_cast<unsigned short*>(data + vertexDataSize);

	BinReader::ShapeData shape;
	shape.indices = indexData;
	shape.indexDataSize = indexDataSize;
	shape.numIndices = numIndices;
	shape.vertices = vertexData;
	shape.vertexDataSize = vertexDataSize;
	shape.numVertices = numVertices;
	return shape;
}