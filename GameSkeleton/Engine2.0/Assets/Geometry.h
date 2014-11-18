#pragma once
#include "../BinReader.h"
#include "ShapeData.h"
class GeometryInfo;
#include "ExportHeader.h"

class DECL_DLL_EXPORT Geometry
{
public:
	static Geometry* Cube();
	static Geometry* Plane(uint dimensions);
	static Geometry* Sphere(uint tesselations);
	static Geometry* Cone();
	static Geometry* Cylinder();
	static Geometry* Teapot(uint tess);
	static Geometry* Torus(uint tess);
	static Geometry* WireframePlane(uint dimensions);
	static Geometry* Arrow();
private:
	static Geometry* setupPreset(Neumont::ShapeData geoData);
public:
	GeometryInfo* info;
	Geometry()
	{
		info = NULL;
	}
	Geometry(char* filename);
	Geometry(GeometryInfo* info)
	{
		this->info = info;
	}
};

