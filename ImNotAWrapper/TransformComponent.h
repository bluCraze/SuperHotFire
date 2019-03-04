#pragma once
#include "BaseComponent.h"
#include <SFML/Graphics/Transformable.hpp>

class TransformComponent :
	public BaseComponent
{
public:
	TransformComponent();
	~TransformComponent();

	void setTransform(sf::Transformable matrix) { localTransform = matrix; }
	void setWorldTransform(sf::Transformable matrix) { worldTransform = matrix; }
	sf::Transformable GetTransform() { return localTransform; }
	sf::Transformable GetWorldTransform() { return worldTransform; }

private:
	sf::Transformable worldTransform;
	sf::Transformable localTransform;
};

