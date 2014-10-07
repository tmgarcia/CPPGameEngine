#include "KeyMap.h"
#include "Input\KeyInput.h"
#include "InputActions.h"

int KeyMap::getKeyFor(int action) const
{
	int key = -1;
	switch(action)
	{
	case INPUT_ACT_ACCELERATE_X:
		key = KeyInput::ARROW_RIGHT;
		break;
	case INPUT_ACT_REVERSE_X:
		key = KeyInput::ARROW_LEFT;
		break;
	//case INPUT_ACT_ACCELERATE_Y:
	//	key = KeyInput::KEY_R;
	//	break;
	//case INPUT_ACT_REVERSE_Y:
	//	key = KeyInput::KEY_F;
	//	break;
	case INPUT_ACT_ACCELERATE_Z:
		key = KeyInput::ARROW_DOWN;
		break;
	case INPUT_ACT_REVERSE_Z:
		key = KeyInput::ARROW_UP;
		break;
	}
	return key;
}