#pragma once
#include "GeneralGLWindow.h"

class ShaderUniformParameter
{
	friend class GeneralGLWindow;
	const char* name;
	GeneralGLWindow::ParameterType parameterType;
	const float* value;
};