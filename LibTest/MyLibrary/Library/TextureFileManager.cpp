/**
 * @file	TextureFileManager.cpp
 * @breif	画像の読み込みを管理しているクラス実装
 * @author	shibata
 */

#include "TextureFileManager.h"
#include "TextureFile.h"
#include "../SearchMemoryLeak.h"

TextureFileManager::TextureFileManager()
{

}

TextureFileManager::~TextureFileManager()
{
	ReleaseAllTexture();
}

void TextureFileManager::LoadTextureFile(int index_, const char* filePath_)
{
	m_pTextureFile.emplace_back(New TextureFile);
	m_pTextureFile[index_]->LoadTextureFile(filePath_);
}

void TextureFileManager::LoadTextuerMoreInfo(int index_, const char* filePath_, int alpha_, int red_, int green_, int blue_, bool isTwoPower_)
{
	m_pTextureFile.emplace_back(New TextureFile);
	m_pTextureFile[index_]->LoadTextuerMoreInfo(filePath_, (red_, green_, blue_, alpha_), isTwoPower_);
}

LPDIRECT3DTEXTURE9 TextureFileManager::GetTextureFileData(int index_)
{
	return m_pTextureFile[index_]->GetTextureFileData();
}

void TextureFileManager::ReleaseAllTexture()
{
	for (unsigned int i = 0; i < m_pTextureFile.size(); i++)
	{
		delete m_pTextureFile[i];
	}
	std::vector<TextureFile*>().swap(m_pTextureFile);
}