#include "pch.h"
#include "TransformComponent.h"


TransformComponent::TransformComponent():BaseComponent(TRANSFORM)
{
	localTransform = sf::Transformable();
}


TransformComponent::~TransformComponent()
{
}
