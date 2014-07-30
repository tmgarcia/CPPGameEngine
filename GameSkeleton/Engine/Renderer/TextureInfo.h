#pragma once

class TextureInfo
{
	friend class GeneralGLWindow;
public:
	GLuint textureID;
	int width;
	int height;
};