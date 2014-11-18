#pragma once
#include <GL\glew.h>
#include "Transform.h"

class Component;
#include "ExportHeader.h"

class DECL_DLL_EXPORT Entity
{
	static const GLuint NUM_MAX_COMPONENTS = 10;

	Component* components[NUM_MAX_COMPONENTS];
	GLuint numComponents;

	public:
		Transform transform;
		Entity();
		void addComponent(Component* c);
		void update();
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