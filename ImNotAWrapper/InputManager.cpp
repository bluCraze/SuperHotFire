#include "pch.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::KeyInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{

	}
}

void InputManager::Update(float dt)
{
	InputListener();
}

void InputManager::InputListener()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_moveDirection = WEST;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_moveDirection = SOUTH;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_moveDirection = EAST;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_moveDirection = NORTH;
	}

	//for (auto &inputCallback : m_callbacks) // access by reference to avoid copying
	//{
	//	inputCallback(moveDirection);
	//}
}
