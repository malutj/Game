#include <Windows.h>
#include "Game.h"

bool InitMainWindow(HINSTANCE hInstance, int cmdShow);
LRESULT CALLBACK MsgDelegate(HWND, UINT, WPARAM, LPARAM);

HWND hwnd = NULL;

const int WIDTH = 800;
const int HEIGHT = 600;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int cmdShow)
{
	// initialize window
	if (!InitMainWindow(hInstance, cmdShow))
		return 1;

	// create game instance
	Game g(hwnd);

	// main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			
		}
	}


	return static_cast<int>(msg.wParam);
}

bool InitMainWindow(HINSTANCE hInstance, int cmdShow)
{
	WNDCLASSEX w;
	w.cbSize = sizeof(w);
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;
	w.lpfnWndProc = MsgDelegate;
	w.hInstance = hInstance;
	w.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	w.lpszClassName = L"GameWindow";
	w.lpszMenuName = NULL;
	w.hIconSm = LoadIcon(NULL, IDI_WINLOGO);


	if (!RegisterClassEx(&w))
		return false;

	hwnd = CreateWindow(
		L"GameWindow",
		L"Polar Frog",
		WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION,
		GetSystemMetrics(SM_CXSCREEN) / 2 - WIDTH / 2,
		GetSystemMetrics(SM_CYSCREEN) / 2 - HEIGHT / 2,
		WIDTH,
		HEIGHT,
		(HWND)NULL,
		(HMENU)NULL,
		hInstance,
		(LPVOID*)NULL);

	if (!hwnd)
		return false;

	ShowWindow(hwnd, cmdShow);

	return true;
}

LRESULT CALLBACK MsgDelegate(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CHAR:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			return 0;
		}
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}