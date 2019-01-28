#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <direct.h>
#include <string>

class EngineManager
{
//Private Members
private:
	enum GameState {Uninitialized, ShowingSplash, Paused,ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

//Public Methods
public:
	EngineManager();
	~EngineManager();
	static void Start();
	static void Initialize();

//Private Methods
private:
	static void checkCPUStats();
	static void checkStorage(const DWORDLONG diskSpaceNeeded);
	static void checkMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	static bool isOnlyInstance(LPCTSTR gameTitle);
	static bool IsExiting();
	static void GameLoop();
};

