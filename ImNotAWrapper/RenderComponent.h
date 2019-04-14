#pragma once
#include "BaseComponent.h"
#include <SFML/Graphics.hpp>
class RenderComponent:
	public BaseComponent	
{
public:
	RenderComponent();
	~RenderComponent();

	void Draw(sf::RenderWindow* _window, sf::RectangleShape _body);
};

