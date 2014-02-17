#pragma once
#include "ParameterType.h"
class ShaderUniformParameter
{
	friend class GeneralGLWindow;
	const char* name;
	ParameterType parameterType;
	const float* value;
};