/**
 * @file	DebugSystem.cpp
 * @breif	デバッグ機能が使用できるクラスヘッダ
 * @author	shibata
 */

#include "DebugSystem.h"
#include <crtdbg.h>

DebugSystem::DebugSystem()
{

}

DebugSystem::~DebugSystem()
{

}

void DebugSystem::CheckMemoryLeaK()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}
