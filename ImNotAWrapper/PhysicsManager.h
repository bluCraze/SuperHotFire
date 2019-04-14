#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class PhysicsManager
{
public:
	PhysicsManager();
	~PhysicsManager();

	
	void Update(float dt, GameObject *player, std::vector<GameObject*> scene);

	bool CheckCollision(GameObject* _player, GameObject* _scene);

	

private:
	
};

