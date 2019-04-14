#pragma once
#include "EngineManager.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Start(sf::RenderWindow* _window, InputManager* _inputManager, PhysicsManager* _physicsManager, AudioManager* _audioManager, SceneManager* _sceneManager);

private:
	void Update();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	GameState m_gameState;
	sf::RenderWindow* m_mainWindow;
	InputManager* m_inputManager;
	PhysicsManager* m_physicsManager;
	AudioManager* m_audioManager;
	SceneManager* m_sceneManager;

	sf::Texture m_ssTexture;
	sf::Sprite m_ssSprite;

	GameObject* m_scene;
	Player m_player;
	std::vector<GameObject*> m_listOfPhysicsObjs;
	std::vector<GameObject*> m_listOfAudioObjs;
};

