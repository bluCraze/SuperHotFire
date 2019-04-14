#include "pch.h"
#include "GameObject.h"


GameObject::GameObject(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	m_body.setSize(size);
	m_body.setOrigin(size / 2.0f);
	m_body.setTexture(texture);
	m_body.setPosition(position);
	parent = nullptr;
	sf::Transformable temp;
	temp.setPosition(position);
	myTransformComponent.setTransform(temp);
	componentList.push_back(&(BaseComponent)myTransformComponent);
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	for (unsigned int i = 0; i < children.size(); i++) {
		delete children[i];
	}
}

BaseComponent * GameObject::GetComponent(ComponentName id)
{
	for (const auto& element : componentList)
	{
		if (element->m_componentName == id)
			return element;
	}
	return nullptr;
}

void GameObject::AddComponent(BaseComponent * component)
{
	componentList.push_back(component);
}

bool GameObject::HasComponent(ComponentName id)
{
	for (const auto& components : componentList)
	{
		if (components->m_componentName == id)
			return true;
	}

	return false;
}

void GameObject::SetParent(GameObject * _parent)
{
	parent = _parent;
}

void GameObject::AddChild(GameObject * _child)
{
	children.push_back(_child);
	_child->parent = this;
}

void GameObject::Update(float _msec, sf::RenderWindow* _window)
{
	//if (parent) {//This node has a parent
	//	myTransformComponent.setWorldTransform(parent->myTransformComponent.GetWorldTransform * myTransformComponent.GetTransform);
	//}
	//else {//This is the Root Node, world == local
	//	myTransformComponent.setWorldTransform(myTransformComponent.GetTransform);
	//}

	if (HasComponent(RENDERER)) {
		RenderComponent* tempRend = (RenderComponent*)GetComponent(RENDERER);
		tempRend->Draw(_window, m_body);
	}

	if (HasComponent(PHYSICS)) {
		PhysicsComponent* tempPhys = (PhysicsComponent*)GetComponent(PHYSICS);
		//tempPhys->CheckCollision()
	}

	for (std::vector<GameObject*>::iterator i = children.begin(); i != children.end(); i++) {
		(*i)->Update(_msec, _window);
	}
}

//void GameObject::Draw(sf::RenderWindow& window)
//{
//	window.draw(body);
//}
