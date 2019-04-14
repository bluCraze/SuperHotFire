#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <direct.h>
#include <string>
#include "InputManager.h"
#include "PhysicsManager.h"
#include "AudioManager.h"
#include "SceneManager.h"

class EngineManager
{
//Private Members
private:
	enum GameState {Uninitialized, ShowingSplash, Paused,ShowingMenu, Playing, Exiting };

	 GameState m_gameState;
	 sf::RenderWindow m_mainWindow;
	 InputManager m_inputManager;
	 PhysicsManager m_physicsManager;
	 AudioManager m_audioManager;
	 SceneManager m_sceneManager;

	 int numberOfManagers;
	

//Public Methods
public:
	EngineManager();
	~EngineManager();
	 void Start();
	 void Initialize();

//Private Methods
private:
	typedef void(*RelayCallback) (std::string*);
	 void checkCPUStats();
	 void checkStorage(const DWORDLONG diskSpaceNeeded);
	 void checkMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	 bool isOnlyInstance(LPCTSTR gameTitle);
	 bool IsExiting();
	 //void relayTemp(std::string* temp);
	// std::vector<RelayCallback> m_callbacks;
	
};

