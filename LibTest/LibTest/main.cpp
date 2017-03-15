#include <Windows.h>
#include <Library.h>
#include "App\Application.h"

namespace
{
	const int	clientWidth		= 1280;
	const int	clientHeight	= 720;
	const char*	title			= "LibTest";
	const int	gameFPS			= (1000 / 60);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Library*		pLibrary = &Library::Instace();
	Application*	pApp = NULL;

	pLibrary->CheckMemoryLeaK();

	pLibrary->InitLibrary(title, clientWidth, clientHeight, false);

	pApp = New Application;

	DWORD currentTime;
	DWORD oldTime = timeGetTime();

	while (!pLibrary->Update())
	{
		currentTime = timeGetTime();
		if (currentTime - oldTime >= gameFPS)
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