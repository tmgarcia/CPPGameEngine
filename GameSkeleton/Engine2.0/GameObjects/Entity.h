#pragma once
#include <GL\glew.h>
#include "Transform.h"

class Component;
class __declspec(dllexport) Entity
{

	static const GLuint NUM_MAX_COMPONENTS = 10;

	Component* components[NUM_MAX_COMPONENTS];
	GLuint numComponents;

	public:
		Transform transform;
		Entity();
		void addComponent(Component* c);
		void update(mat4 worldToProjectionMatrix);
		template<class T>
		T* getComponent() const;
		void cleanup();
};

template<class T>
T* Entity::getComponent() const
{
	for(GLuint i = 0; i < numComponents; i++)
	{
		T* ret = dynamic_cast<T*>(components[i]);
		if(ret != 0)
			return ret;
	}
	return 0;
}