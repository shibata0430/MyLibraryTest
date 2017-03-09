/**
 * @file	VerticesManager.cpp
 * @breif	頂点情報を管理しているクラス実装
 * @author	shibata
 */

#include "VerticesManager.h"
#include "Vertices.h"
#include "../SearchMemoryLeak.h"

VerticesManager::VerticesManager()
{

}

VerticesManager::~VerticesManager()
{
	ReleaseAllVirtices();
}

void VerticesManager::SetTexSize(int index_, float width_, float height_, float depth_, float maxTu_, float maxTv_, float minTu_, float minTv_)
{
	m_pVertices.emplace_back(New Vertices);
	m_pVertices[index_]->SetTexSize(width_, height_, depth_, maxTu_, maxTv_, minTu_, minTv_);
}

void VerticesManager::DrawLeftTop(int index_, float posX_, float posY_, LPDIRECT3DTEXTURE9 pTextureData_)
{
	m_pVertices[index_]->DrawLeftTop({ posX_, posY_ }, pTextureData_);
}

void VerticesManager::DrawCenter(int index_, float posX_, float posY_, LPDIRECT3DTEXTURE9 pTextureData_)
{
	m_pVertices[index_]->DrawCenter({ posX_, posY_ }, pTextureData_);
}

void VerticesManager::SetColor(int index_, DWORD color_, int alpha_, int red_, int green_, int blue_)
{
	m_pVertices[index_]->SetColor(color_, alpha_, red_, green_, blue_);
}

void VerticesManager::ReleaseAllVirtices()
{
	for (unsigned int i = 0; i < m_pVertices.size(); i++)
	{
		delete m_pVertices[i];
	}
	std::vector<Vertices*>().swap(m_pVertices);
}

void VerticesManager::ReleaseVirtices(int index_)
{
	if (m_pVertices[index_] != NULL)
	{
		delete m_pVertices[index_];
		m_pVertices.clear();
		m_pVertices.shrink_to_fit();
	}
}