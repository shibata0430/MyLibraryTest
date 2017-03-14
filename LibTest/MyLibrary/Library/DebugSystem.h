/**
 * @file	DebugSystem.h
 * @breif	デバッグ機能が使用できるクラスヘッダ
 * @author	shibata
 */

#ifndef DEBUGSYSTEM_H
#define DEBUGSYSTEM_H

class DebugSystem
{
public:
	DebugSystem();
	~DebugSystem();

	void CheckMemoryLeaK();
};

#endif // !DEBUGSYSTEM_H