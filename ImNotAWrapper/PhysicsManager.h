#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class PhysicsManager
{
public:
	PhysicsManager();
	//PhysicsManager(sf::RectangleShape& body);
	~PhysicsManager();

	//void Move(float dx, float dy) { body.move(dx, dy); }
	void Update(float dt, GameObject *player, std::vector<GameObject*> scene);
	
	//bool CheckCollision(PhysicsManager& other, float push);
	bool CheckCollision(GameObject* _player, GameObject* _scene);

	//sf::Vector2f GetPosition() { return body.getPosition(); }
	//sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	//sf::RectangleShape& body;
};

