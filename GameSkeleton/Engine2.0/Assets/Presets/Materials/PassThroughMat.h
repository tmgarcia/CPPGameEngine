#pragma once

#include "../../Material.h"
#include "../../../Renderer/GeneralGLWindow.h"
#include "ExportHeader.h"

class DECL_DLL_EXPORT PassThroughMat : public Material
{
public:

	PassThroughMat()
	{
		shader = GeneralGLWindow::getInstance().createShaderInfo("Assets/Shaders/PassThroughVertexShader.glsl", "Assets/Shaders/PassThroughFragmentShader.glsl");
	}
};

