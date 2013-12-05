#ifndef _INPUT_H_
#define _INPUT_H_

#include "Core.h"

namespace Core
{

class CORE_SHARED Input
{
public:

	static const int KEY_LEFT	= VK_LEFT;
	static const int KEY_RIGHT	= VK_RIGHT;
	static const int KEY_UP		= VK_UP;
	static const int KEY_DOWN	= VK_DOWN;
	static const int KEY_ESCAPE	= VK_ESCAPE;
	static const int BUTTON_LEFT	= VK_LBUTTON;
	static const int BUTTON_RIGHT	= VK_RBUTTON;
	static const int BUTTON_ENTER = VK_RETURN;
	static const int BUTTON_SPACE = VK_SPACE;


	static bool IsPressed( int key );
	static void GetMousePos( int& x, int& y );
	static int GetMouseX();
	static int GetMouseY();
};

} // namespace Engine

#endif // _INPUT_H_