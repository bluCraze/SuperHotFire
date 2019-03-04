#pragma once
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "TransformComponent.h"
#include "Render.h"
#include "PhysicsComponent.h"

class GameObject
{
public:
	GameObject(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	GameObject();
	~GameObject(); 

	BaseComponent *GetComponent(ComponentName id);
	void AddComponent(BaseComponent *component);
	bool HasComponent(ComponentName id);

	/*void setTransform(sf::Transform &matrix) { localTransform = matrix;}
	sf::Transform GetTransform() { return localTransform; }
	sf::Transform GetWorldTransform() { return worldTransform; }*/

	void SetParent(GameObject* _parent);
	void AddChild(GameObject* _child);

	virtual void Update(float _msec, sf::RenderWindow& _window);

	//void Draw(sf::RenderWindow& window);
	//PhysicsManager GetCollider() { return PhysicsManager(m_body); }
	sf::RectangleShape m_body;
private:
	GameObject* parent;
	TransformComponent myTransformComponent;
	std::vector<GameObject*> children;
	std::vector<BaseComponent*> componentList;
};

