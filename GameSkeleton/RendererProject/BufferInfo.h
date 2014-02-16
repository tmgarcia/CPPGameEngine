#pragma once

class BufferInfo
{
	friend class GeneralGLWindow;
	GLuint glBufferID;
	GLuint remainingSize; 
};