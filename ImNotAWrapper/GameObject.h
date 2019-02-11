#pragma once
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics.hpp>
#include "PhysicsManager.h"
#include <vector>
#include "TransformComponent.h"

class GameObject
{
public:
	GameObject(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	GameObject();
	~GameObject();

	/*void setTransform(sf::Transform &matrix) { localTransform = matrix;}
	sf::Transform GetTransform() { return localTransform; }
	sf::Transform GetWorldTransform() { return worldTransform; }*/

	void SetParent(GameObject* _parent);
	void AddChild(GameObject* _child);

	virtual void Update(float _msec);

	void Draw(sf::RenderWindow& window);
	PhysicsManager GetCollider() { return PhysicsManager(body); }
private:
	sf::RectangleShape body;
	GameObject* parent;
	/*sf::Transform worldTransform;
	sf::Transform localTransform;*/
	TransformComponent myTransformComponent;
	std::vector<GameObject*> children;
	std::vector<BaseComponent*> componentList;
};

