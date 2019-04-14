#pragma once
#include <SFML/Graphics.hpp>
#include "BaseComponent.h"
class PhysicsComponent:
	public BaseComponent
{
public:
	PhysicsComponent(float _push);
	~PhysicsComponent();

	void Move(float dx, float dy, sf::RectangleShape* _body) { _body->move(dx, dy); }


	sf::Vector2f GetPosition(sf::RectangleShape _body) { return _body.getPosition(); }
	sf::Vector2f GetHalfSize(sf::RectangleShape _body) { return _body.getSize() / 2.0f; }
	float GetPush() { return m_push; }

private:
	float m_push = 1;
};

