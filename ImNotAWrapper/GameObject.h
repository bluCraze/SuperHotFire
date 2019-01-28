#pragma once
#include <SFML/Graphics/Transform.hpp>
#include <vector>
#include "TransformComponent.h"

class GameObject
{
public:
	GameObject() {}
	~GameObject();

	void setTransform(sf::Transform &matrix) { localTransform = matrix;}
	sf::Transform GetTransform() { return localTransform; }
	sf::Transform GetWorldTransform() { return worldTransform; }

	void SetParent(GameObject* _parent);
	void AddChild(GameObject* _child);

	virtual void Update(float _msec);

private:
	GameObject* parent;
	sf::Transform worldTransform;
	sf::Transform localTransform;
	std::vector<GameObject*> children;
	std::vector<BaseComponent*> componentList;
};

