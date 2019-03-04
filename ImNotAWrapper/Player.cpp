#include "pch.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Texture* texture, float _speed)
{
	m_speed = _speed;
	m_body.setSize(sf::Vector2f(100.0f, 150.0f));
	m_body.setOrigin(m_body.getSize() / 2.0f);
	m_body.setPosition(206.0f, 206.0f);
	m_body.setTexture(texture);
	m_movement = sf::Vector2f (0.0f, 0.0f);
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::RenderWindow & window, int direction)
{
	m_movement = sf::Vector2f(0.0f, 0.0f);
	if (direction == WEST)
		m_movement.x -= m_speed * deltaTime;
	if (direction == EAST)
		m_movement.x += m_speed * deltaTime;
	if (direction == NORTH)
		m_movement.y -= m_speed * deltaTime;
	if (direction == SOUTH)
		m_movement.y += m_speed * deltaTime;

	m_body.move(m_movement);
	window.draw(m_body);
}

//void Player::Draw(sf::RenderWindow & window)
//{
//	window.draw(m_body);
//}


