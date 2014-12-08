#pragma once

class TextureInfo
{
	friend class GeneralGLWindow;
public:
	GLuint textureID;
	int width;
	int height;

	bool operator() (const TextureInfo& lhs, const TextureInfo& rhs)
    {
        return lhs.textureID < rhs.textureID ;
    }
};