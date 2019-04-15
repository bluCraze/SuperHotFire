#include "pch.h"
#include "PhysicsManager.h"


PhysicsManager::PhysicsManager()
{
}

//PhysicsManager::PhysicsManager(sf::RectangleShape& body) :
//	body(body)
//{
//}


PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::Update(float dt, GameObject* player, std::vector<GameObject*> scene)
{
	for (auto &gameObject : scene) {
		 for (auto &otherObject : scene){
			 if (gameObject != otherObject && otherObject != player)
				CheckCollision(gameObject, otherObject);
		}
		
	}
}

bool PhysicsManager::CheckCollision(GameObject* _player, GameObject* _other)
{
	PhysicsComponent* playerPhysics = (PhysicsComponent *)_player->GetComponent(PHYSICS);
	PhysicsComponent* otherPhysics = (PhysicsComponent *)_other->GetComponent(PHYSICS);

	sf::Vector2f playerPosition = playerPhysics->GetPosition(_player->m_body);
	sf::Vector2f playerHalfSize = playerPhysics->GetHalfSize(_player->m_body);
	sf::Vector2f otherPosition = otherPhysics->GetPosition(_other->m_body);
	sf::Vector2f otherHalfSize = otherPhysics->GetHalfSize(_other->m_body);

	float deltaX = otherPosition.x - playerPosition.x;
	float deltaY = otherPosition.y - playerPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + playerHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + playerHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		float _push = std::min(std::max(otherPhysics->GetPush(), 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				playerPhysics->Move(intersectX * (1.0f - _push), 0.0f,&_player->m_body);
				otherPhysics->Move(-intersectX * _push, 0.0f,&_other->m_body);
			}
			else
			{
				playerPhysics->Move(-intersectX * (1.0f - _push), 0.0f,&_player->m_body);
				otherPhysics->Move(intersectX * _push, 0.0f, &_other->m_body);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				playerPhysics->Move(0.0f, intersectY * (1.0f - _push), &_player->m_body);
				otherPhysics->Move(0.0f, -intersectY * _push, &_other->m_body);
			}
			else
			{
				playerPhysics->Move(0.0f, -intersectY * (1.0f - _push), &_player->m_body);
				otherPhysics->Move(0.0f, intersectY * _push, &_other->m_body);
			}
		}

		return true;
	}

	return false;
}

//bool PhysicsManager::CheckCollision(PhysicsManager& other, float push)
//{
//	sf::Vector2f otherPosition = other.GetPosition();
//	sf::Vector2f otherHalfSize = other.GetHalfSize();
//	sf::Vector2f thisPosition = GetPosition();
//	sf::Vector2f thisHalfSize = GetHalfSize();
//
//	float deltaX = otherPosition.x - thisPosition.x;
//	float deltaY = otherPosition.y - thisPosition.y;
//	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
//	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
//
//	if (intersectX < 0.0f && intersectY < 0.0f)
//	{
//		push = std::min(std::max(push, 0.0f), 1.0f);
//
//		if (intersectX > intersectY)
//		{
//			if (deltaX > 0.0f)
//			{
//				Move(intersectX * (1.0f - push), 0.0f);
//				other.Move(-intersectX * push, 0.0f);
//			}
//			else
//			{
//				Move(-intersectX * (1.0f - push), 0.0f);
//				other.Move(intersectX * push, 0.0f);
//			}
//		}
//		else
//		{
//			if (deltaY > 0.0f)
//			{
//				Move(0.0f, intersectY * (1.0f - push));
//				other.Move(0.0f, -intersectY * push);
//			}
//			else
//			{
//				Move(0.0f, -intersectY * (1.0f - push));
//				other.Move(0.0f, intersectY * push);
//			}
//		}
//
//		return true;
//	}
//
//	return false;
//}
