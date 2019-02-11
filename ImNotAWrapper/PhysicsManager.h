#pragma once
#include <SFML/Graphics.hpp>

class PhysicsManager
{
public:
	PhysicsManager(sf::RectangleShape& body);
	~PhysicsManager();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(PhysicsManager& other, float push);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;
};

