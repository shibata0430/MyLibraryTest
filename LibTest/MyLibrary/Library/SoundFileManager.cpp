/**
 * @file	SoundFileManager.cpp
 * @breif	音楽の読み込みと再生を管理しているクラス実装
 * @author	shibata
 */

#include "SoundFileManager.h"
#include "SoundFile.h"
#include "../SearchMemoryLeak.h"

SoundFileManager::SoundFileManager()
{

}

SoundFileManager::~SoundFileManager()
{
	ReleaseAllSoundData();
}

void SoundFileManager::LoadSoundFile(int index_, const char* filePath_)
{
	m_pSoundFile.emplace_back(New SoundFile);
	m_pSoundFile[index_]->LoadSoundFile(filePath_);
}

void SoundFileManager::SoundState(int index_, SoundMode soundMode_)
{
	switch (soundMode_)
	{
	case SoundMode::PLAY:
		m_pSoundFile[index_]->SoundState(SoundFile::Mode::PLAY);
		break;

	case SoundMode::LOOP:
		m_pSoundFile[index_]->SoundState(SoundFile::Mode::LOOP);
		break;

	case SoundMode::STOP:
		m_pSoundFile[index_]->SoundState(SoundFile::Mode::STOP);
		break;

	case SoundMode::RESET:
		m_pSoundFile[index_]->SoundState(SoundFile::Mode::RESET);
		break;

	case SoundMode::RESET_PLAY:
		m_pSoundFile[index_]->SoundState(SoundFile::Mode::RESET_PLAY);
		break;

	case SoundMode::RESET_STOP:
		m_pSoundFile[index_]->SoundState(SoundFile::Mode::RESET_STOP);
		break;
	}
}

void SoundFileManager::ReleaseAllSoundData()
{
	for (unsigned int i = 0; i < m_pSoundFile.size(); i++)
	{
		delete m_pSoundFile[i];
	}
	std::vector<SoundFile*>().swap(m_pSoundFile);
}

void SoundFileManager::ReleaseSoundData(int index_)
{
	if (m_pSoundFile[index_] != NULL)
	{
		delete m_pSoundFile[index_];
		m_pSoundFile.clear();
		m_pSoundFile.shrink_to_fit();
	}
}