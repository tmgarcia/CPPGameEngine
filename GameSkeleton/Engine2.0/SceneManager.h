#pragma once
#include <GL\glew.h>
#include "Camera.h"
#include <glm\glm.hpp>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\transform.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;

#include "ExportHeader.h"

class DECL_DLL_EXPORT SceneManager
{
private:
	SceneManager()
	{
		LIGHT_POSITION= vec3();
		LIGHT_DIFFUSIONINTENSITY = 0;
		LIGHT_SPECULARCOLOR = vec4();
		LIGHT_SPECULAREXPONENT = 0;
		LIGHT_AMBIENTCOLOR=vec3();
	}
	SceneManager(SceneManager const&);
	SceneManager& operator = (SceneManager const&);
	static SceneManager* theInstance;
	~SceneManager();

public:
	static SceneManager& getInstance();
	static void cleanup();

	GLuint WINDOW_WIDTH;
	GLuint WINDOW_HEIGHT;

	Camera camera;
	vec3 EYE_POSITION;
	mat4 VIEW_TO_PROJECTION;
	mat4 WORLD_TO_VIEW;
	mat4 WORLD_TO_PROJECTION;

	vec3 LIGHT_POSITION;
	float LIGHT_DIFFUSIONINTENSITY;
	vec4 LIGHT_SPECULARCOLOR;
	float LIGHT_SPECULAREXPONENT;
	vec3 LIGHT_AMBIENTCOLOR;
	//vec3 overridingObjectColor;

	void update();
};

