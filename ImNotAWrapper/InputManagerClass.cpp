#include "InputManagerClass.h"

InputManagerClass::InputManagerClass()
{
	for (int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
	}
}

InputManagerClass::~InputManagerClass()
{

}

void InputManagerClass::OnKeyDown(unsigned int kcode)
{
	keyStates[kcode] = true;
}

void InputManagerClass::OnKeyUp(unsigned int kcode)
{
	keyStates[kcode] = false;
}

bool InputManagerClass::HasKeyBeenPressed(unsigned int kcode)
{
	return keyStates[kcode];
}

bool InputManagerClass::GetKeyStates()
{
	return keyStates;
}

char InputManagerClass::ReturnKeyPressed(WPARAM keyCode)
{
	return keyCode;
}

float InputManagerClass::ReturnMouseX(POINT point)
{
	float x = 0;
	x = point.x;
	return x;
}

float InputManagerClass::ReturnMouseY(POINT point)
{
	float y = 0;
	y = point.y;
	return y;
}