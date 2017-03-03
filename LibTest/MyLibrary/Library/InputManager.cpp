/**
 * @file	InputManager.cpp
 * @breif	入力機器の管理をしているクラス実装
 * @author	shibata
 */

#include "InputManager.h"
#include "InputKey.h"
#include "../SearchMemoryLeak.h"

InputManager::InputManager() : 
m_pInputKey(New InputKey)
{

}

InputManager::~InputManager()
{
	delete m_pInputKey;
}

void InputManager::UpdateDI()
{
	m_pInputKey->UpdateKey();
}

void InputManager::UpdateKey()
{
	m_pInputKey->UpdateKey();
}

InputManager::KeyState InputManager::CheckKey(int dik_)
{
	KeyState state = static_cast<InputManager::KeyState>(m_pInputKey->CheckKey(dik_));
	return state;
}