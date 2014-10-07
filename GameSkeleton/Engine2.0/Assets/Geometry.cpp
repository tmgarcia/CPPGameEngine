#include "Geometry.h"
#include "../Renderer/GeneralGLWindow.h"
#include "../Renderer/GeometryInfo.h"

Geometry::Geometry(char* filename)
{
	BinReader binReader;
	BinReader::ShapeData data = binReader.readInShape(filename);
	info = GeneralGLWindow::getInstance().addGeometry(data.vertices, data.vertexDataSize, data.indices, data.numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(info, 0, PT_VEC3, BinReader::POSITION_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(info, 1, PT_VEC3, BinReader::TANGENT_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(info, 2, PT_VEC3, BinReader::NORMAL_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(info, 3, PT_VEC2, BinReader::UV_OFFSET, BinReader::STRIDE);
}

Geometry* Geometry::Cube()
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makeCube();
	return setupPreset(geoData);
}
Geometry* Geometry::Plane(uint dimensions)
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makePlane(dimensions);
	return setupPreset(geoData);
}
Geometry* Geometry::Sphere(uint tesselations)
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makeSphere(tesselations);
	return setupPreset(geoData);
}
Geometry* Geometry::Cone()
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makeCone();
	return setupPreset(geoData);
}
Geometry* Geometry::Cylinder()
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makeCylinder();
	return setupPreset(geoData);
}
Geometry* Geometry::Teapot(uint tess)
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makeTeapot(tess, mat4());
	return setupPreset(geoData);
}
Geometry* Geometry::Torus(uint tess)
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makeTorus(10);
	return setupPreset(geoData);
}
Geometry* Geometry::WireframePlane(uint dimensions)
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makeWireframePlane(dimensions);
	return setupPreset(geoData);
}
Geometry* Geometry::Arrow()
{
	Neumont::ShapeData geoData = Neumont::ShapeGenerator::makeArrow();
	return setupPreset(geoData);
}
Geometry* Geometry::setupPreset(Neumont::ShapeData geoData)
{
	GeometryInfo* info = GeneralGLWindow::getInstance().addGeometry(geoData.verts, geoData.vertexBufferSize(), geoData.indices, geoData.numIndices, GL_TRIANGLES);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(info, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(info, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(info, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(info, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);

	Geometry* g = new Geometry();
	g->info = info;
	return g;
}
