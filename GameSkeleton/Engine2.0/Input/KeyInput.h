#pragma once
#include "IKeyMapper.h"
#include "Windows.h"
class __declspec(dllexport) KeyInput
{
	IKeyMapper* keyMap;
	int maxAction;
	int activeActions;

	KeyInput(){}
	KeyInput(KeyInput const&);
	KeyInput& operator = (KeyInput const&);
	static KeyInput* theInstance;
public:
	static KeyInput& getInstance();

	void initialize(IKeyMapper* keyMapper, int max)
	{
		keyMap = keyMapper;
		maxAction = max;
	}
	void update();
	bool actionsActive(int actions) const;

	static const int MOUSE_LEFT = 0x01;
	static const int MOUSE_RIGHT = 0x02;
	static const int KEY_A = 0x41;
	static const int KEY_D = 0x44;
	static const int KEY_F = 0x46;
	static const int KEY_R = 0x52;
	static const int KEY_S = 0x53;
	static const int KEY_W = 0x57;
	static const int ARROW_LEFT = 0x25;
	static const int ARROW_UP = 0x26;
	static const int ARROW_RIGHT = 0x27;
	static const int ARROW_DOWN = 0x28;
};

