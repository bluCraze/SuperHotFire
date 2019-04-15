#include "pch.h"
#include "RenderComponent.h"


RenderComponent::RenderComponent():BaseComponent(RENDERER)
{

}


RenderComponent::~RenderComponent()
{
}

void RenderComponent::Draw(sf::RenderWindow* _window, sf::RectangleShape _body)
{
	_window->draw(_body);
}

void RenderComponent::Draw(sf::RenderWindow* _window, sf::CircleShape _body)
{
	_window->draw(_body);
}
