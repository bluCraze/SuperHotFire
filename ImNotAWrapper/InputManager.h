#pragma once
#include <vector>
#include <string>
enum direction { NORTH = 0, EAST, SOUTH, WEST };
class InputManager
{
public:
	InputManager();
	~InputManager();
	void KeyInput();

	typedef void(*InputCallback) (std::string*);
	void Update(float dt);
	void InputListener();

	int m_moveDirection;

	//std::vector<InputCallback> m_callbacks;
};

