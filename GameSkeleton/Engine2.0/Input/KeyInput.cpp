#include "KeyInput.h"
#include "../DebugTools/ConsolePrinter.h"
void KeyInput::update()
{
	activeActions = 0;
	int possibleAction = 1;
	while(possibleAction != maxAction)
	{
		int key = keyMap->getKeyFor(possibleAction);
		if(GetAsyncKeyState(key))
		{
			activeActions |= possibleAction;
		}
		possibleAction <<= 1;
	}
}
bool KeyInput::actionsActive(int actions) const
{
	return activeActions & actions;
}

KeyInput* KeyInput::theInstance;

KeyInput& KeyInput::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new KeyInput();
	}
	return *theInstance;
}