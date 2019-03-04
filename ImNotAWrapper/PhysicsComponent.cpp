#include "pch.h"
#include "PhysicsComponent.h"


PhysicsComponent::PhysicsComponent(float _push):BaseComponent(PHYSICS)
{
	m_push = _push;
}


PhysicsComponent::~PhysicsComponent()
{
}
