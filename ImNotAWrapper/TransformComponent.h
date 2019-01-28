#pragma once
#include "BaseComponent.h"
#include <SFML/Graphics/Transform.hpp>

class TransformComponent :
	public BaseComponent
{
public:
	TransformComponent();
	~TransformComponent();

	void setTransform(sf::Transform &matrix) { localTransform = matrix; }
	sf::Transform GetTransform() { return localTransform; }
	sf::Transform GetWorldTransform() { return worldTransform; }

private:
	sf::Transform worldTransform;
	sf::Transform localTransform;
};

