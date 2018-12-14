#pragma once
#include <windows.h>

class InputManagerClass
{
public:
	InputManagerClass();
	~InputManagerClass();

	void OnKeyDown(unsigned int kcode); // Key pressed

	void OnKeyUp(unsigned int kcode);   // Key released

	bool HasKeyBeenPressed(unsigned int kcode);

	bool GetKeyStates();

	char ReturnKeyPressed(WPARAM kcode);

	float ReturnMouseX(POINT point);

	float ReturnMouseY(POINT point);

private:
	bool keyStates[256]; // all characters
};
