// include the basic windows header file
#include <windowsx.h>
#include <Windows.h>
#include <direct.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "EngineManagerClass.h"




// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam);

std::unique_ptr<EngineManagerClass> BuildManager = std::make_unique<EngineManagerClass>();

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	BuildManager->InitializeGame();
	// the handle for the window, filled by function
	HWND hWnd;
	// this struct holds information for the window class
	WNDCLASSEX WindowClass;

	// clear out the window class
	ZeroMemory(&WindowClass, sizeof(WNDCLASSEX));

	// fill in the struct with needed info
	WindowClass.cbSize = sizeof(WNDCLASSEX);
	WindowClass.style = CS_HREDRAW | CS_VREDRAW;
	WindowClass.lpfnWndProc = WindowProc;
	WindowClass.hInstance = hInstance;
	WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WindowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	//WindowClass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
	WindowClass.lpszClassName = "NewWindow";

	// register the window class
	RegisterClassEx(&WindowClass);

	// create the window and use the result as the handle
	hWnd = CreateWindowEx(NULL,
		"NewWindow",    // name of the window class
		"ImNotAWrapper",   // title of the window
		WS_OVERLAPPEDWINDOW,    // window style
		300,    // x-position of the window
		300,    // y-position of the window
		500,    // width of the window
		400,    // height of the window
		NULL,    // we have no parent window, NULL
		NULL,    // we aren't using menus, NULL
		hInstance,    // application handle
		NULL);    // used with multiple windows, NULL


	// display the window on the screen
	ShowWindow(hWnd, nCmdShow);

	// this struct holds Windows event messages
	MSG msg;

	// wait for the next message in the queue, store the result in 'msg'
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// translate keystroke messages into the right format
		TranslateMessage(&msg);

		// send the message to the WindowProc function
		DispatchMessage(&msg);

		UpdateWindow(hWnd);
		RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_INTERNALPAINT);
	}

	// return this part of the WM_QUIT message to Windows
	return msg.wParam;

}


// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;

	// sort through and find what code to run for the message given
	switch (message)
	{
	case WM_CREATE:

		CreateWindow(TEXT("button"), TEXT("Colour"),
			WS_VISIBLE | WS_CHILD,
			390, 300, 60, 50,
			hWnd, (HMENU) 1, NULL, NULL
		);

		break;

	case WM_COMMAND:

		if (LOWORD(wParam) == 1) {

			InvalidateRect(hWnd, NULL, FALSE);
			hdc = BeginPaint(hWnd, &ps);
			GetClientRect(hWnd, &rc);
			SelectObject(hdc, GetStockObject(DEFAULT_GUI_FONT));
			FillRect(hdc, &ps.rcPaint, CreateSolidBrush(RGB(rand()%255, rand()%255, rand()%255)));
			EndPaint(hWnd, &ps);
			return 0;
	}
		break;
		// this message is read when the window is closed
	case WM_DESTROY:
		// close the application entirely
		PostQuitMessage(0);
		return 0;
	default:
		return BuildManager->MsgManager(hWnd, message, wParam, lParam);
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}