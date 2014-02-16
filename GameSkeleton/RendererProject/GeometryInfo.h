#pragma once

class GeometryInfo
{
	friend class GeneralGLWindow;
	GLuint vertexArrayID;
	GLuint numIndices;
	GLenum indexingMode;
};