/**
 * @file	ObjectManager.cpp
 * @breif	オブジェクトを管理しているクラス実装
 * @author	shibata
 */

#include "ObjectManager.h"
#include "Object.h"
#include "../Background/Backgoround.h"
#include "../Meet/Meet.h"
#include <Library.h>

ObjectManager::ObjectManager()
{
	m_pObject.emplace_back(New Background);
	m_pObject.emplace_back(New Meet);
}

ObjectManager::~ObjectManager()
{
	for (auto itr = m_pObject.begin(); itr != m_pObject.end(); ++itr)
	{
		delete (*itr);
	}
}

void ObjectManager::Control()
{
	for (auto itr = m_pObject.begin(); itr != m_pObject.end(); itr++)
	{
		(*itr)->Control();
	}
}

void ObjectManager::Draw()
{
	for (auto itr = m_pObject.begin(); itr != m_pObject.end(); ++itr)
	{
		(*itr)->Draw();
	}
}