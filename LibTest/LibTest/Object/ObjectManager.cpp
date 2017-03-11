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

ObjectManager::ObjectManager() : 
m_pBackground(New Background),
m_pMeet(New Meet)
{

}

ObjectManager::~ObjectManager()
{
	delete m_pBackground;
	delete m_pMeet;
}

void ObjectManager::Control()
{
	Object* pObjectList[2] = 
	{ 
		m_pBackground, m_pMeet
	};

	for (int i = 0; i < 2; i++)
	{
		pObjectList[i]->Control();
	}
}

void ObjectManager::Draw()
{
	Object* pObjectList[2] = 
	{
		m_pBackground, m_pMeet
	};

	for (int i = 0; i < 2; i++)
	{
		pObjectList[i]->Draw();
	}
}