#pragma once

#include "../../Material.h"
#include "../../../Renderer/GeneralGLWindow.h"

class __declspec(dllexport) PassThroughMat : public Material
{
public:

	PassThroughMat()
	{
		shader = GeneralGLWindow::getInstance().createShaderInfo("../../Resources/Shaders/PassThroughVertexShader.glsl", "../../Resources/Shaders/PassThroughFragmentShader.glsl");
	}
};

