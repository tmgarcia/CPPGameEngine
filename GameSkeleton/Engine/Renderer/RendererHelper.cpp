#include "RendererHelper.h"

#include "../DebugTools/ConsolePrinter.h"

#pragma region ShaderMethods
ShaderInfo* RendererHelper::addShader(const char* vertexFile, const char* fragmentFile, ShaderType shaderType, QString name)
{
	ShaderInfo* shaderInfo = GeneralGLWindow::getInstance().createShaderInfo(vertexFile, fragmentFile);
	Shader shader;
	shader.info = shaderInfo;
	shader.type = shaderType;
	if(name.isNull() || name.isEmpty())
	{
		shader.name = "shader" + QString::number(shaders.count());
	}
	else
	{
		shader.name = name;
	}
	shaders.append(shader);
	return shaderInfo;
}
void RendererHelper::addShader(ShaderInfo* shaderInfo, ShaderType shaderType, QString name)
{
	Shader shader;
	shader.info = shaderInfo;
	shader.type = shaderType;
	if(name.isNull() || name.isEmpty())
	{
		shader.name = "shader" + QString::number(shaders.count());
	}
	else
	{
		shader.name = name;
	}
	shaders.append(shader);
}
#pragma endregion

#pragma region GeometryMethods
GeometryInfo* RendererHelper::addNUGeo(NUShapes shape, QString name)
{
	Neumont::ShapeData geoData;
	switch(shape)
	{
	case(NU_CUBE):
		geoData = Neumont::ShapeGenerator::makeCube();
		break;
	case(NU_PLANE):
		geoData = Neumont::ShapeGenerator::makePlane(2);
		break;
	case(NU_SPHERE):
		geoData = Neumont::ShapeGenerator::makeSphere(10);
		break;
	case(NU_CONE):
		geoData = Neumont::ShapeGenerator::makeCone();
		break;
	case(NU_CYLINDER):
		geoData = Neumont::ShapeGenerator::makeCylinder();
		break;
	case(NU_TEAPOT):
		geoData = Neumont::ShapeGenerator::makeTeapot(10, mat4());
		break;
	case(NU_TORUS):
		geoData = Neumont::ShapeGenerator::makeTorus(10);
		break;
	case(NU_WIREFRAMEPLANE):
		geoData = Neumont::ShapeGenerator::makeWireframePlane(2);
		break;
	case(NU_ARROW):
		geoData = Neumont::ShapeGenerator::makeArrow();
		break;
	};
	GeometryInfo* geoInfo = GeneralGLWindow::getInstance().addGeometry(geoData.verts, geoData.vertexBufferSize(), geoData.indices, geoData.numIndices, GL_TRIANGLES);
	Geometry geo;
	geo.geoInfo = geoInfo;
	if(name.isNull() || name.isEmpty())
	{
		geo.name = "geometry" + QString::number(geometries.count());
	}
	else
	{
		geo.name = name;
	}
	geometries.append(geo);
	setupNUGeoVertexArrayInfo(geoInfo);
	return geoInfo;
}
GeometryInfo* RendererHelper::addGeoFromBin(char* fileName, QString name)
{
	BinReader::ShapeData geoData = binReader.readInShape(fileName);
	GeometryInfo* geoInfo = GeneralGLWindow::getInstance().addGeometry(geoData.vertices, geoData.vertexDataSize, geoData.indices, geoData.numIndices, GL_TRIANGLES);
	Geometry geo;
	geo.geoInfo = geoInfo;
	if(name.isNull() || name.isEmpty())
	{
		geo.name = "geometry" + QString::number(geometries.count());
	}
	else
	{
		geo.name = name;
	}
	geometries.append(geo);
	setupReadInGeoVertexArrayInfo(geoInfo);
	return geoInfo;
}
//must have also have already set up vertex array info if passing in existing geometryinfo
void RendererHelper::addGeometry(GeometryInfo* geometry, QString name)
{
	Geometry geo;
	geo.geoInfo = geometry;
	if(name.isNull() || name.isEmpty())
	{
		geo.name = "geometry" + QString::number(geometries.count());
	}
	else
	{
		geo.name = name;
	}
	geometries.append(geo);
}
#pragma endregion

#pragma region GameObjectMethods
GameObject* RendererHelper::addGameObject(vec3 position, vec3 scale, float xRotation, float yRotation, float zRotation, mat4 worldToProjectionMatrix, QString name)
{
	GameObject* gameObject = new GameObject();
	gameObject->setupTransforms(position, scale, xRotation, yRotation, zRotation, worldToProjectionMatrix);
	Object object;
	object.gameObject = gameObject;
	if(name.isNull() || name.isEmpty())
	{
		object.name = "gameObject" + QString::number(gameObjects.count());
	}
	else
	{
		object.name = name;
	}
	gameObjects.append(object);
	return gameObject;
}
//Must have set up the transforms if passing in an existing game object
void RendererHelper::addGameObject(GameObject* gameObject, QString name)
{
	Object object;
	object.gameObject = gameObject;
	if(name.isNull() || name.isEmpty())
	{
		object.name = "gameObject" + QString::number(gameObjects.count());
	}
	else
	{
		object.name = name;
	}
	gameObjects.append(object);
}
void RendererHelper::setupGameObjectRenderable(GameObject* object, QString geometryName, QString shaderName, bool visible, PriorityLevel priorityLevel, bool depth, QString diffuseMapName, QString alphaMapName, QString normalMapName, QString ambientOcclusionMapName)
{
	object->renderable = GeneralGLWindow::getInstance().addRenderable(getGeometry(geometryName), object->modelToWorldMatrix, getShader(shaderName), true, PRIORITY_1, true, getDiffuseMap(diffuseMapName), getAlphaMap(alphaMapName), getNormalMap(normalMapName),getAmbientOcclusionMap(ambientOcclusionMapName));
	if(getShaderType(shaderName) == ShaderType::SHADER_LIGHTING_TEXTURE)
	{
		addLightingAndTextureShaderUniforms(object);
	}
	else if(getShaderType(shaderName) == ShaderType::SHADER_PASSTHROUGH)
	{
		addPassThroughShaderUniforms(object);
	}
}
GameObject* RendererHelper::setupGameObjectRenderable(QString gameObjectName, QString geometryName, QString shaderName, bool visible, PriorityLevel priorityLevel, bool depth, QString diffuseMapName, QString alphaMapName, QString normalMapName, QString ambientOcclusionMapName)
{
	GameObject* object = getGameObject(gameObjectName);
	object->renderable = GeneralGLWindow::getInstance().addRenderable(getGeometry(geometryName), object->modelToWorldMatrix, getShader(shaderName), true, PRIORITY_1, true, getDiffuseMap(diffuseMapName), getAlphaMap(alphaMapName), getNormalMap(normalMapName),getAmbientOcclusionMap(ambientOcclusionMapName));
	if(getShaderType(shaderName) == ShaderType::SHADER_LIGHTING_TEXTURE)
	{
		addLightingAndTextureShaderUniforms(object);
	}
	else if(getShaderType(shaderName) == ShaderType::SHADER_PASSTHROUGH)
	{
		addPassThroughShaderUniforms(object);
	}
	return object;
}
#pragma endregion

#pragma region DiffuseMethods
DiffuseMapInfo* RendererHelper::addDiffuseMap(const char* fileName, QString name)
{
	DiffuseMapInfo* mapInfo = GeneralGLWindow::getInstance().addDiffuseMap(fileName);
	DiffuseMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "diffuseMap" + QString::number(diffuseMaps.count());
	}
	else
	{
		map.name = name;
	}
	diffuseMaps.append(map);
	return mapInfo;
}
DiffuseMapInfo* RendererHelper::addDiffuseMap(const uchar* bytes, uint width, uint height, QString name)
{
	DiffuseMapInfo* mapInfo = GeneralGLWindow::getInstance().addDiffuseMap(bytes, width, height);
	DiffuseMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "diffuseMap" + QString::number(diffuseMaps.count());
	}
	else
	{
		map.name = name;
	}
	diffuseMaps.append(map);
	return mapInfo;
}
void RendererHelper::addDiffuseMap(DiffuseMapInfo* mapInfo, QString name)
{
	DiffuseMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "diffuseMap" + QString::number(diffuseMaps.count());
	}
	else
	{
		map.name = name;
	}
	diffuseMaps.append(map);
}
#pragma endregion

#pragma region AlphaMapMethods
AlphaMapInfo* RendererHelper::addAlphaMap(const char* fileName, QString name)
{
	AlphaMapInfo* mapInfo = GeneralGLWindow::getInstance().addAlphaMap(fileName);
	AlphaMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "alphaMap" + QString::number(alphaMaps.count());
	}
	else
	{
		map.name = name;
	}
	alphaMaps.append(map);
	return mapInfo;
}
AlphaMapInfo* RendererHelper::addAlphaMap(const uchar* bytes, uint width, uint height, QString name)
{
	AlphaMapInfo* mapInfo = GeneralGLWindow::getInstance().addAlphaMap(bytes, width, height);
	AlphaMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "alphaMap" + QString::number(alphaMaps.count());
	}
	else
	{
		map.name = name;
	}
	alphaMaps.append(map);
	return mapInfo;
}
void RendererHelper::addAlphaMap(AlphaMapInfo* mapInfo, QString name)
{
	AlphaMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "alphaMap" + QString::number(alphaMaps.count());
	}
	else
	{
		map.name = name;
	}
	alphaMaps.append(map);
}
#pragma endregion

#pragma region NormalMapMethods
NormalMapInfo* RendererHelper::addNormalMap(const char* fileName, QString name)
{
	NormalMapInfo* mapInfo = GeneralGLWindow::getInstance().addNormalMap(fileName);
	NormalMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "normalMap" + QString::number(normalMaps.count());
	}
	else
	{
		map.name = name;
	}
	normalMaps.append(map);
	return mapInfo;
}
NormalMapInfo* RendererHelper::addNormalMap(const uchar* bytes, uint width, uint height, QString name)
{
	NormalMapInfo* mapInfo = GeneralGLWindow::getInstance().addNormalMap(bytes, width, height);
	NormalMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "normalMap" + QString::number(normalMaps.count());
	}
	else
	{
		map.name = name;
	}
	normalMaps.append(map);
	return mapInfo;
}
void RendererHelper::addNormalMap(NormalMapInfo* mapInfo, QString name)
{
	NormalMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "normalMap" + QString::number(normalMaps.count());
	}
	else
	{
		map.name = name;
	}
	normalMaps.append(map);
}
#pragma endregion

#pragma region AmbientMapMethods
AmbientOcclusionMapInfo* RendererHelper::addAmbientOcclusionMap(const char* fileName, QString name)
{
	AmbientOcclusionMapInfo* mapInfo = GeneralGLWindow::getInstance().addAmbientOcclusionMap(fileName);
	AmbientOcclusionMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "ambientOcclusionMap" + QString::number(ambientOcclusionMaps.count());
	}
	else
	{
		map.name = name;
	}
	ambientOcclusionMaps.append(map);
	return mapInfo;
}
AmbientOcclusionMapInfo* RendererHelper::addAmbientOcclusionMap(const uchar* bytes, uint width, uint height, QString name)
{
	AmbientOcclusionMapInfo* mapInfo = GeneralGLWindow::getInstance().addAmbientOcclusionMap(bytes, width, height);
	AmbientOcclusionMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "ambientOcclusionMap" + QString::number(ambientOcclusionMaps.count());
	}
	else
	{
		map.name = name;
	}
	ambientOcclusionMaps.append(map);
	return mapInfo;
}
void RendererHelper::addAmbientOcclusionMap(AmbientOcclusionMapInfo* mapInfo, QString name)
{
	AmbientOcclusionMap map;
	map.mapInfo = mapInfo;
	if(name.isNull() || name.isEmpty())
	{
		map.name = "ambientOcclusionMap" + QString::number(ambientOcclusionMaps.count());
	}
	else
	{
		map.name = name;
	}
	ambientOcclusionMaps.append(map);
}
#pragma endregion

#pragma region RetrievalMethods
GeometryInfo* RendererHelper::getGeometry(QString name)
{
	GeometryInfo* geo = NULL;
	if(!name.isNull() && !name.isEmpty())
	{
		bool found = false;
		for(int i = 0; i < geometries.count() && !found; i++)
		{
			if(geometries[i].name == name)
			{
				found = true;
				geo = geometries[i].geoInfo;
			}
		}
		if(!found)
		{
			ConsolePrinter::getInstance().print(name, "CANNOT FIND GEOMETRY: ");
		}
	}
	else
	{
		ConsolePrinter::getInstance().print("NO GEOMETRY: ");
	}
	return geo;
}
GameObject* RendererHelper::getGameObject(QString name)
{
	GameObject* obj = NULL;
	if(!name.isNull() && !name.isEmpty())
	{
		bool found = false;
		for(int i = 0; i < gameObjects.count() && !found; i++)
		{
			if(gameObjects[i].name == name)
			{
				found = true;
				obj = gameObjects[i].gameObject;
			}
		}
		if(!found)
		{
			ConsolePrinter::getInstance().print(name, "CANNOT FIND GAME OBJECT: ");
		}
	}
	else
	{
		ConsolePrinter::getInstance().print("NO GAME OBJECT: ");
	}
	return obj;
}
ShaderInfo* RendererHelper::getShader(QString name)
{
	ShaderInfo* obj = NULL;
	if(!name.isNull() && !name.isEmpty())
	{
		bool found = false;
		for(int i = 0; i < shaders.count() && !found; i++)
		{
			if(shaders[i].name == name)
			{
				found = true;
				obj = shaders[i].info;
			}
		}
		if(!found)
		{
			ConsolePrinter::getInstance().print(name, "CANNOT FIND SHADER: ");
		}
	}
	else
	{
		ConsolePrinter::getInstance().print("NO SHADER: ");
	}
	return obj;
}
RendererHelper::ShaderType RendererHelper::getShaderType(QString shaderName)
{
	ShaderType type;
	if(!shaderName.isNull() && !shaderName.isEmpty())
	{
		bool found = false;
		for(int i = 0; i < shaders.count() && !found; i++)
		{
			if(shaders[i].name == shaderName)
			{
				found = true;
				type = shaders[i].type;
			}
		}
		if(!found)
		{
			ConsolePrinter::getInstance().print(shaderName, "CANNOT FIND SHADER: ");
		}
	}
	else
	{
		ConsolePrinter::getInstance().print("NO SHADER: ");
	}
	return type;
}
DiffuseMapInfo* RendererHelper::getDiffuseMap(QString name)
{
	DiffuseMapInfo* obj = NULL;
	if(!name.isNull() && !name.isEmpty())
	{
		bool found = false;
		for(int i = 0; i < diffuseMaps.count() && !found; i++)
		{
			if(diffuseMaps[i].name == name)
			{
				found = true;
				obj = diffuseMaps[i].mapInfo;
			}
		}
		if(!found)
		{
			ConsolePrinter::getInstance().print(name, "CANNOT FIND DIFFUSE MAP: ");
		}
	}
	else
	{
		//ConsolePrinter::getInstance().print("NO DIFFUSE MAP: ");
	}
	return obj;
}
AlphaMapInfo* RendererHelper::getAlphaMap(QString name)
{
	AlphaMapInfo* obj = NULL;
	if(!name.isNull() && !name.isEmpty())
	{
		bool found = false;
		for(int i = 0; i < alphaMaps.count() && !found; i++)
		{
			if(alphaMaps[i].name == name)
			{
				found = true;
				obj = alphaMaps[i].mapInfo;
			}
		}
		if(!found)
		{
			ConsolePrinter::getInstance().print(name, "CANNOT FIND ALPHA MAP: ");
		}
	}
	else
	{
		//ConsolePrinter::getInstance().print("NO ALPHA MAP: ");
	}
	return obj;
}
NormalMapInfo* RendererHelper::getNormalMap(QString name)
{
	NormalMapInfo* obj = NULL;
	if(!name.isNull() && !name.isEmpty())
	{
		bool found = false;
		for(int i = 0; i < normalMaps.count() && !found; i++)
		{
			if(normalMaps[i].name == name)
			{
				found = true;
				obj = normalMaps[i].mapInfo;
			}
		}
		if(!found)
		{
			ConsolePrinter::getInstance().print(name, "CANNOT FIND NORMAL MAP: ");
		}
	}
	else
	{
		//ConsolePrinter::getInstance().print("NO NORMAL MAP: ");
	}
	return obj;
}
AmbientOcclusionMapInfo* RendererHelper::getAmbientOcclusionMap(QString name)
{
	AmbientOcclusionMapInfo* obj = NULL;
	if(!name.isNull() && !name.isEmpty())
	{
		bool found = false;
		for(int i = 0; i < ambientOcclusionMaps.count() && !found; i++)
		{
			if(ambientOcclusionMaps[i].name == name)
			{
				found = true;
				obj = ambientOcclusionMaps[i].mapInfo;
			}
		}
		if(!found)
		{
			ConsolePrinter::getInstance().print(name, "CANNOT FIND AMBIENT OCCLUSION MAP: ");
		}
	}
	else
	{
		//ConsolePrinter::getInstance().print("NO AO MAP");
	}
	return obj;
}
#pragma endregion

void RendererHelper::updateShaderInfo(mat4 worldToProjectionMatrix)
{
	for(int i = 0; i < gameObjects.count(); i++)
	{
		gameObjects[i].gameObject->updateTransforms(worldToProjectionMatrix);
	}
}

void RendererHelper::setupNUGeoVertexArrayInfo(GeometryInfo* geometry)
{
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, Neumont::Vertex::POSITION_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 1, PT_VEC4, Neumont::Vertex::COLOR_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, Neumont::Vertex::NORMAL_OFFSET, Neumont::Vertex::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 3, PT_VEC2, Neumont::Vertex::UV_OFFSET, Neumont::Vertex::STRIDE);
}
void RendererHelper::setupReadInGeoVertexArrayInfo(GeometryInfo* geometry)
{
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 0, PT_VEC3, BinReader::POSITION_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 1, PT_VEC3, BinReader::TANGENT_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 2, PT_VEC3, BinReader::NORMAL_OFFSET, BinReader::STRIDE);
	GeneralGLWindow::getInstance().addShaderStreamedParameter(geometry, 3, PT_VEC2, BinReader::UV_OFFSET, BinReader::STRIDE);
}
void RendererHelper::addLightingAndTextureShaderUniforms(GameObject* gameObject)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "lightPosition", PT_VEC3, &lightPosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "diffusionIntensity", PT_FLOAT, &diffusionIntensity);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "specularColor", PT_VEC4, &specularColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "specularExponent", PT_FLOAT, &specularExponent);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "eyePosition", PT_VEC3, &eyePosition[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "overridingObjectColor", PT_VEC3, &overridingObjectColor[0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "ambientLight", PT_VEC3, &ambientLight[0]);
																 
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "fullTransformMatrix", PT_MAT4, &gameObject->fullTransformMatrix[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "rotationMatrix", PT_MAT4, &gameObject->rotationMatrix[0][0]);
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "modelToWorldMatrix", PT_MAT4, &gameObject->modelToWorldMatrix[0][0]);
}
void RendererHelper::addPassThroughShaderUniforms(GameObject* gameObject)
{
	GeneralGLWindow::getInstance().addRenderableUniformParameter(gameObject->renderable, "fullTransformMatrix", PT_MAT4, &gameObject->fullTransformMatrix[0][0]);
}