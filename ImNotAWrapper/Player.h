#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsManager.h"

class Player
{
public:
	Player(sf::Texture* texture, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	PhysicsManager GetCollider() {	return PhysicsManager(body); }

private:
	sf::RectangleShape body;
	float speed;
};