#pragma once

class GeometryInfo
{
	friend class GeneralGLWindow;
public:
	GLuint vertexArrayID;
	GLuint numIndices;
	GLuint indexDataOffset;
	GLenum indexingMode;
};