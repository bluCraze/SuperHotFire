#include "pch.h"
#include "EngineManager.h"
#include "atltypes.h"
#include <tchar.h>
#include <memory>
#include "GameObject.h"

//Convert bytes to MB
#define DIV 1048576

EngineManager::EngineManager()
{
}


EngineManager::~EngineManager()
{
}

void EngineManager::Start()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::WindowHandle myWind = window.getSystemHandle();
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	GameObject *scene;
	GameObject *sun;
	GameObject *earth;
	GameObject *moon;

	scene->AddChild(sun);
	sun->AddChild(earth);
	earth->AddChild(moon);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

void EngineManager::Initialize()
{
	printf("%d",isOnlyInstance("ImNotAWrapperWin32Debug.exe"));
	printf("\n");
	checkStorage(300000000);
	printf("\n");
	checkMemory(1000 * DIV, 1000 * DIV);
	printf("\n");
	checkCPUStats();
	
}

void EngineManager::checkCPUStats()
{
	int ArchNum;
	SYSTEM_INFO systemInfo;
	GetSystemInfo(&systemInfo);

	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0,
		KEY_READ,
		&hKey);
	if (lError == ERROR_SUCCESS) {
		// query the key:
		RegQueryValueEx(hKey,
			"~MHz",
			NULL,
			&type,
			(LPBYTE)&dwMHz,
			&BufSize);
	}

	printf("The CPU Speed we get is : %d MegaHertz\n", dwMHz);
	

	ArchNum = systemInfo.wProcessorArchitecture;
	switch (ArchNum) {
	case 0: printf("Intel x86\n");
		break;
	case 5: printf("ARM\n");
		break;
	case 6: printf("Intel Itanium based");
		break;
	case 9: printf("x64(AMD or Intel)");
		break;
	case 12: printf("ARM64\n");
		break;
	default: printf("Unknown architecture");
		break;
	}
}

void EngineManager::checkStorage(const DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) {
		printf("Not enough storage");
	}
	else {
		printf("Enough storage");
	}
}

void EngineManager::checkMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	if (status.ullAvailPhys < physicalRAMNeeded || status.ullAvailVirtual < virtualRAMNeeded) {
		printf("You do not pass the memory requirements\n");
	}
	else
		printf("You pass the memory requirements\n");

	printf("You have : %d MB of available Physical Memory\n", status.ullAvailPhys / DIV);
	printf("You have : %d MB of available Virtual Memory\n", status.ullAvailVirtual / DIV);
}

bool EngineManager::isOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			// display message
			int msgboxID = MessageBox(
				hWnd,
				"An instance of the application is already running",
				"Multiple Instances Detected",
				MB_ICONWARNING
				//WM_DESTROY
				//{
				//	 close the application entirely
				//	PostQuitMessage(0);
				//	return 0;
				//};
			);
			return false;
		}
	}
	return true;
}

bool EngineManager::IsExiting()
{
	return false;
}

void EngineManager::GameLoop()
{
}
