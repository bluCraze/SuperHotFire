#include "EngineManagerClass.h"

//Convert bytes to MB
#define DIV 1048576
EngineManagerClass::EngineManagerClass(){

}

EngineManagerClass::~EngineManagerClass(){
}

void EngineManagerClass::InitializeGame(){
	Input = std::make_unique<InputManagerClass>();
	
}

void EngineManagerClass::DestroyGame(){

}

void EngineManagerClass::StartGame(){

}
BOOL fDraw = FALSE;
POINT ptPrevious;

//Method to check no other instance is running, returns false if another instance is found.
bool EngineManagerClass::isOnlyInstance(LPCTSTR gameTitle) {
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


//Method to check if there is enough available storage, outputs to console the results.
bool EngineManagerClass::checkStorage(const DWORDLONG diskSpaceNeeded, HWND hWnd) {
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) {
		return 0;
	}
	else {
		return 1;
	}
}

//Method to check how much physical and virtual memory is available on the system.
void EngineManagerClass::checkMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded, HWND hWnd) {
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	if (status.ullAvailPhys < physicalRAMNeeded || status.ullAvailVirtual < virtualRAMNeeded) {
		int msgboxID3 = MessageBox(
			NULL,
			"Failed, Toss Comp.",
			"Check Memory",
			MB_ICONWARNING
		);
	}
	else {
		int msgboxID3 = MessageBox(
			NULL,
			"You have passed the requirements!",
			"Check Memory",
			MB_ICONWARNING
		);
		// create all other systems
		// enter the main loop:
		if (checkStorage(300000000, hWnd) == false)		{
			int msgboxID3 = MessageBox(
				hWnd,
				"checkStorage Failure : Not enough physical storage.",
				"Check Storage",
				MB_ICONWARNING
			);
		}

		else {
			int msgboxID4 = MessageBox(
				hWnd,
				"checkStorage Success: You got the cash!.",
				"Check Storage",
				MB_ICONWARNING
			);
		}
		checkMemory(1000 * DIV, 1000 * DIV, hWnd);
		checkCPUStats();
	}

	char p_memTest[100];
	sprintf_s(p_memTest, "You have : %d MB of available Physical Memory", status.ullAvailPhys / DIV);
	MessageBox(NULL, p_memTest, "CheckMemory", MB_OK);

	char v_memTest[100];
	sprintf_s(v_memTest, "You have : %d MB of available Virtual Memory", status.ullAvailVirtual / DIV);
	MessageBox(NULL, v_memTest, "CheckMemory", MB_OK);

}

//Displays the CPU speed and architecture to the console. 
void EngineManagerClass::checkCPUStats() {
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
	char cpu_speed[50];
	sprintf_s(cpu_speed, "The CPU Speed we get is : %d MegaHertz\n", dwMHz);
	MessageBox(NULL, cpu_speed, "CPU Speed Test", MB_OK);

	ArchNum = systemInfo.wProcessorArchitecture;
	switch (ArchNum) {
	case 0: MessageBox(NULL, "Intel x86\n", "Processor Architecture", MB_OK);
		break;
	case 5: MessageBox(NULL, "ARM\n", "Processor Architecture", MB_OK);
		break;
	case 6: MessageBox(NULL, "Intel Itanium based", "Processor Architecture", MB_OK);
		break;
	case 9: MessageBox(NULL, "x64(AMD or Intel)", "Processor Architecture", MB_OK);
		break;
	case 12: MessageBox(NULL, "ARM64\n", "Processor Architecture", MB_OK);
		break;
	default: MessageBox(NULL, "Unknown architecture", "Processor Architecture", MB_OK);
		break;
	}
}

LRESULT CALLBACK EngineManagerClass::MsgManager(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	char szWordBuffer[500];
	std::string textStr = "KEY: ";
	
	RECT rc;
	PAINTSTRUCT ps;
	HDC hdc;
	


	switch (uMsg) {
	case WM_PAINT: {
		hdc = BeginPaint(hWnd, &ps);

		GetClientRect(hWnd, &rc);
		SelectObject(hdc, GetStockObject(DEFAULT_GUI_FONT));
		FillRect(hdc, &ps.rcPaint, CreateSolidBrush(RGB(255,255,255)));
		EndPaint(hWnd, &ps);
		return 0;
	}

	// Key pressed
	case WM_KEYDOWN: {
		Input->OnKeyDown(wParam);
		textStr += Input->ReturnKeyPressed(wParam);

		InvalidateRect(hWnd, NULL, FALSE);
		hdc = BeginPaint(hWnd, &ps);

		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(0, 255, 0));
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 3));
		TextOut(hdc, 100, 100, textStr.c_str(), textStr.length());
		EndPaint(hWnd, &ps);
		return 0;
	}

	// Key released on mouse
	case WM_KEYUP: {
		Input->OnKeyUp(wParam);
		return 0;
	}

	// LMB pressed
	case WM_LBUTTONDOWN: {
		fDraw = TRUE;
		ptPrevious.x = LOWORD(lParam);
		ptPrevious.y = HIWORD(lParam);
		return 0L;
	}

	// LMB released
	case WM_LBUTTONUP: {
		if (fDraw)
		{
			hdc = GetDC(hWnd);
			MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL);
			LineTo(hdc, LOWORD(lParam), HIWORD(lParam));
			ReleaseDC(hWnd, hdc);
		}
		fDraw = FALSE;
		return 0L;
	}
	
	//M movement
	case WM_MOUSEMOVE:
		if (fDraw)
		{
			hdc = GetDC(hWnd);
			MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL);
			LineTo(hdc, ptPrevious.x = LOWORD(lParam),
				ptPrevious.y = HIWORD(lParam));
			ReleaseDC(hWnd, hdc);
		}
		return 0L;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}