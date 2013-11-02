#ifndef _INPUT_H_
#define _INPUT_H_

#include "Core.h"

namespace Core
{

class CORE_SHARED Input
{
public:
	
	static const int KEY_W = VK_W;
	static const int KEY_A = VK_A;
	static const int KEY_S = VK_S;
	static const int KEY_D = VK_D;

	static const int KEY_1 = VK_1;
	static const int KEY_2 = VK_2;
	static const int KEY_3 = VK_3;
	static const int KEY_4 = VK_4;
	static const int KEY_5 = VK_5;
	static const int KEY_6 = VK_6;
	static const int KEY_7 = VK_7;
	static const int KEY_8 = VK_8;
	static const int KEY_9 = VK_9;
	static const int KEY_0 = VK_0;

	static const int KEY_LEFT	= VK_LEFT;
	static const int KEY_RIGHT	= VK_RIGHT;
	static const int KEY_UP		= VK_UP;
	static const int KEY_DOWN	= VK_DOWN;
	static const int KEY_ESCAPE	= VK_ESCAPE;
	static const int KEY_TAB = VK_TAB;
	static const int BUTTON_LEFT	= VK_LBUTTON;
	static const int BUTTON_RIGHT	= VK_RBUTTON;


	static bool IsPressed( int key );
	static void GetMousePos( int& x, int& y );
	static int GetMouseX();
	static int GetMouseY();
};

} // namespace Engine

#endif // _INPUT_H_