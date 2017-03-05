/**
 * @file	windowCreate.cpp
 * @breif	ウィンドウの生成クラス実装
 * @author	shibata
 */

#include "Window.h"

Window::Window() :
m_hWnd(NULL)
{

}

Window::~Window()
{

}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (static_cast<CHAR>(wParam))
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

void Window::Create(LPCTSTR titleName_, int clientWidth_, int clientHeiht_, bool isFullScreen_)
{
	// ウィンドウ登録クラス
	WNDCLASSEX windowClass;
	{
		windowClass.cbSize        = sizeof(windowClass);
		windowClass.style         = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc   = WindowProc;
		windowClass.cbClsExtra    = 0;
		windowClass.cbWndExtra    = 0;
		windowClass.hInstance     = GetModuleHandle(NULL);
		windowClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
		windowClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
		windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		windowClass.lpszMenuName  = NULL;
		windowClass.lpszClassName = titleName_;
		windowClass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

		RegisterClassEx(&windowClass);
	}

	if (isFullScreen_)
	{
		m_hWnd = CreateWindow(
			titleName_,
			titleName_,
			WS_POPUP | WS_VISIBLE,
			0,
			0,
			clientWidth_,
			clientHeiht_,
			NULL,
			NULL,
			GetModuleHandle(NULL),
			NULL
			);
	}
	else
	{
		m_hWnd = CreateWindow(
			titleName_,
			titleName_,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			clientWidth_,
			clientHeiht_,
			NULL,
			NULL,
			GetModuleHandle(NULL),
			NULL
			);

		// 正しい画面サイズを求めるための矩形を用意
		RECT clientRect;
		{
			GetClientRect(m_hWnd, &clientRect);

			clientWidth_ = clientWidth_ + (clientWidth_ - clientRect.right);
			clientHeiht_ = clientHeiht_ + (clientHeiht_ - clientRect.bottom);
		}

		MoveWindow(
			m_hWnd,
			0,
			0,
			clientWidth_,
			clientHeiht_,
			TRUE
			);
	}

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

 	ZeroMemory(&m_msg, sizeof(m_msg));
}

bool Window::Update()
{

	if (m_msg.message != WM_QUIT)
	{
		if (PeekMessage(&m_msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&m_msg);
			DispatchMessage(&m_msg);
		}
		return false;
	}

	return true;
}