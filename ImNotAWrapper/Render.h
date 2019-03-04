#pragma once
#include "BaseComponent.h"
#include <SFML/Graphics.hpp>
class Render:
	public BaseComponent	
{
public:
	Render();
	~Render();

	void Draw(sf::RenderWindow& _window, sf::RectangleShape _body);
};

