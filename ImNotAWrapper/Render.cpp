#include "pch.h"
#include "Render.h"


Render::Render():BaseComponent(RENDERER)
{

}


Render::~Render()
{
}

void Render::Draw(sf::RenderWindow & _window, sf::RectangleShape _body)
{
	_window.draw(_body);
}
