/**
 * @file	ObjectManager.cpp
 * @breif	オブジェクトを管理しているクラス実装
 * @author	shibata
 */

#include "ObjectManager.h"
#include "Object.h"
#include "../Background/Backgoround.h"
#include <Library.h>

ObjectManager::ObjectManager() : 
m_pBackground(New Background)
{

}

ObjectManager::~ObjectManager()
{
	delete m_pBackground;
}

void ObjectManager::Control()
{
	Object* pObjectList[1] = { m_pBackground };

	for (int i = 0; i < 1; i++)
	{
		pObjectList[i]->Control();
	}
}

void ObjectManager::Draw()
{
	Object* pObjectList[1] = { m_pBackground };

	for (int i = 0; i < 1; i++)
	{
		pObjectList[i]->Draw();
	}
}