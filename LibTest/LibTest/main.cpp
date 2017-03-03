#include <Windows.h>
#include <Library.h>
#include "Application.h"

#define CLIENT_WIDTH	1280
#define CLIENT_HEIGHT	720
#define TITLE_TEXT		("LibTest")
#define GAME_FPS		(1000/60)

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow)
{
	Library*		pLibrary = &Library::Instace();
	Application*	pApp = NULL;

	pLibrary->CheckMemoryLeaK();

#ifdef _DEBUG
	pLibrary->InitLibrary(TITLE_TEXT, CLIENT_WIDTH, CLIENT_HEIGHT, false);
#else
	pLibrary->InitLibrary(TITLE_TEXT, CLIENT_WIDTH, CLIENT_HEIGHT, true);
#endif

	pApp = New Application;

	DWORD currentTime;
	DWORD oldTime = timeGetTime();

	while (!pLibrary->Update())
	{
		currentTime = timeGetTime();
		if (currentTime - oldTime >= GAME_FPS)
		{
			if (pApp->Run())
			{
				break;
			}
			oldTime = timeGetTime();
		}
	}
	
	delete pApp;
	return 0;
}