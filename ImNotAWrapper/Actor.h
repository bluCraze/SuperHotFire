#pragma once
#include "GameObject.h"
class Actor :
	public GameObject
{
public:
	Actor();
	~Actor();

	void moveLeft();
	void moveRight();
};

