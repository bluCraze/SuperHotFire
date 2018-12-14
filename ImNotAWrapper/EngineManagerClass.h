#pragma once
#include <windows.h>
#include <direct.h>
#include <memory>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <sstream>
#include "atltypes.h"
#include "InputManagerClass.h"


class EngineManagerClass
{
public:

	EngineManagerClass();
	~EngineManagerClass();

	LRESULT CALLBACK MsgManager(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	void InitializeGame();
	void DestroyGame();
	void StartGame();
	//LONGLONG MBToB(LONGLONG MB); LONGLONG bToMB(LONGLONG B);

	void checkCPUStats();

	bool checkStorage(const DWORDLONG diskSpaceNeeded, HWND hWnd);

	void checkMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded, HWND hWnd);

	bool isOnlyInstance(LPCTSTR gameTitle);

private:
	std::unique_ptr<InputManagerClass> Input = nullptr;
	//std::unique_ptr<GameLoop> MainGameLoop = nullptr;
	// add other systems
};
