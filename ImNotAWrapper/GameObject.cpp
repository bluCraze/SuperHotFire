#include "pch.h"
#include "GameObject.h"


GameObject::GameObject()
{
	parent = nullptr;
	TransformComponent localTransform2;
	componentList.push_back(localTransform2);
}


GameObject::~GameObject()
{
	for (unsigned int i = 0; i < children.size(); i++) {
		delete children[i];
	}
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

void GameObject::Update(float _msec)
{
	if (parent) {//This node has a parent
		worldTransform = parent->worldTransform * localTransform;
	}
	else {//This is the Root Node, world == local
		worldTransform = localTransform;
	}

	for (std::vector<GameObject*>::iterator i = children.begin(); i != children.end(); i++) {
		(*i)->Update(_msec);
	}
}
