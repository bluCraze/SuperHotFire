#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "PhysicsManager.h"

class Player:
	public GameObject
{
public:
	Player();
	Player(sf::Texture* texture, float speed);
	~Player();

	void Update(float deltaTime, sf::RenderWindow* _window, int direction);
	
	

	sf::Vector2f GetPosition() { return m_body.getPosition(); }
	//PhysicsManager GetCollider() {	return PhysicsManager(m_body); }

private:
	enum direction { NORTH = 0, EAST, SOUTH, WEST };
	float m_speed;
	sf::Vector2f m_movement;
	
};