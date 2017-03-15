/**
 * @file	ObjectManager.cpp
 * @breif	オブジェクトを管理しているクラス実装
 * @author	shibata
 */

#include "ObjectManager.h"
#include "Object.h"
#include "../Background/Backgoround.h"
#include "../Meet/Meet.h"
#include "../Player/Player.h"
#include <Library.h>

ObjectManager::ObjectManager() : 
m_rLibrary(Library::Instace())
{
	m_pObject.emplace_back(New Background);
	m_pObject.emplace_back(New Player);
	m_pObject.emplace_back(New Meet);
	m_rLibrary.LoadSoundFile(BGM, "Resource/Sound/bgm.wav");
	m_rLibrary.SoundState(BGM, LOOP);

}

ObjectManager::~ObjectManager()
{
	m_rLibrary.SoundState(BGM, STOP);
	m_rLibrary.ReleaseAllSoundData();

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