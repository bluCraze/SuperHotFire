#pragma once
#include <string>
#include "GameObject.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void LoadScene(std::string _scenePath, GameObject* _sceneNode, std::vector<GameObject*>* _listOfPhysicsObjs, std::vector<GameObject*>* _listOfAudioObjs, sf::RenderWindow* _window);

private:

	char* m_jsonScene;
};

