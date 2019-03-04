#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <direct.h>
#include <string>
#include "InputManager.h"
#include "PhysicsManager.h"
#include "AudioManager.h"

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

	 int numberOfManagers;
	

//Public Methods
public:
	EngineManager();
	~EngineManager();
	 void Start();
	 void Initialize();
	 void GameLoop();

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

