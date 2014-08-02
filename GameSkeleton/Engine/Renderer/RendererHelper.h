#pragma once

#include "GeneralGLWindow.h"
#include "../GameObjects/GameObject.h"
#include <Qt\QString.h>
#include <Qt\qlist.h>
#include "../BinReader.h"

class __declspec(dllexport) RendererHelper
{
public:
	RendererHelper()
	{
		lightPosition= vec3();
		diffusionIntensity = 0;
		specularColor = vec4();
		specularExponent = 0;
		eyePosition = vec3();
		overridingObjectColor=vec3();
		ambientLight=vec3();
	}

	vec3 lightPosition;
	float diffusionIntensity;
	vec4 specularColor;
	float specularExponent;
	vec3 eyePosition;
	vec3 overridingObjectColor;
	vec3 ambientLight;

	static RendererHelper& getInstance();
	enum NUShapes
	{
		NU_CUBE,
		NU_SPHERE,
		NU_PLANE,
		NU_CONE,
		NU_CYLINDER,
		NU_TEAPOT,
		NU_TORUS,
		NU_WIREFRAMEPLANE,
		NU_ARROW
	};
	enum ShaderType
	{
		SHADER_LIGHTING_TEXTURE,
		SHADER_LIGHTING,
		SHADER_TEXTURE,
		SHADER_PASSTHROUGH
	};

	ShaderInfo* addShader(const char* vertexFile, const char* fragmentFile, ShaderType shaderType, QString name="");
	void addShader(ShaderInfo* shader, ShaderType shaderType, QString name="");

	GeometryInfo* addNUGeo(NUShapes shape, QString name="");
	GeometryInfo* addGeoFromBin(char* fileName, QString name="");
	void addGeometry(GeometryInfo* geometry, QString name);
	
	GameObject* addGameObject(vec3 _position, vec3 _scale, float xRotation, float yRotation, float zRotation, mat4 worldToProjectionMatrix, QString name="", bool project=true);
	void addGameObject(GameObject* object, QString name="");

	//void setupGameObjectRenderable(GameObject* object, GeometryInfo* geo, ShaderInfo* shader, bool visible, PriorityLevel priority, bool depth, DiffuseMapInfo* diffuseMap, AlphaMapInfo* alphaMap, NormalMapInfo* normalMap);
	
	void setupGameObjectRenderable(GameObject* object, QString geometryName, QString shaderName, bool visible, PriorityLevel priorityLevel, bool depth, QString diffuseMapName, QString alphaMapName, QString normalMapName, QString ambientOcclusionMapName, QString cubeMapName);
	GameObject* setupGameObjectRenderable(QString gameObjectName, QString geometryName, QString shaderName, bool visible, PriorityLevel priorityLevel, bool depth, QString diffuseMapName, QString alphaMapName, QString normalMapName, QString ambientOcclusionMapName, QString cubeMapName);
	
	TextureInfo* addTexture(const char* fileName, QString name="");
	TextureInfo* addTexture(const uchar* bytes, uint width, uint height, QString name="");
	void addTexture(TextureInfo* diffuseMap, QString name="");
	
	GeometryInfo* getGeometry(QString name);
	GameObject* getGameObject(QString name);
	ShaderInfo* getShader(QString name);
	TextureInfo* getTexture(QString name);

	void updateShaderInfo(mat4 worldToProjectionMatrix);

#pragma region Structs
	struct Object
	{
		GameObject* gameObject;
		QString name;
	};
	struct Geometry
	{
		GeometryInfo* geoInfo;
		QString name;
	};
	struct Texture
	{
		TextureInfo* textureInfo;
		QString name;
	};
	struct Shader
	{
		ShaderInfo* info;
		ShaderType type;
		QString name;
	};
#pragma endregion

private:
	void setupNUGeoVertexArrayInfo(GeometryInfo* geometry);
	void setupReadInGeoVertexArrayInfo(GeometryInfo* geometry);
	void addLightingAndTextureShaderUniforms(GameObject* gameObject);
	void addPassThroughShaderUniforms(GameObject* gameObject);
	void addTextureShaderUniforms(GameObject* gameObject);

	ShaderType getShaderType(QString shaderName);

	BinReader binReader;

	QList<Object> gameObjects;
	QList<Geometry> geometries;
	QList<Shader> shaders;
	QList<Texture> textures;
};

