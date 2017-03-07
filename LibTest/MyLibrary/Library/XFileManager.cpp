﻿/**
 * @file	XFileManager/cpp
 * @breif	Xファイルの読み込みと描画を管理するクラス実装
 * @author	shibata
 */

#include "XFileManager.h"
#include "XFile.h"
#include "../SearchMemoryLeak.h"

XFileManager::XFileManager()
{

}

XFileManager::~XFileManager()
{
	Release();
}

void XFileManager::LoadXFile(int index_, const char* filePath_)
{
	m_pXFile.emplace_back(New XFile);
	m_pXFile[index_]->LoadXFile(filePath_);
}

void XFileManager::DrawXFile(int index_)
{
	m_pXFile[index_]->DrawXFile();
}

LPD3DXMESH XFileManager::GetMeshData(int index_)
{
	return m_pXFile[index_]->GetMeshData();
}

void XFileManager::Release()
{
	for (unsigned int i = 0; i < m_pXFile.size(); i++)
	{
		delete m_pXFile[i];
	}
	std::vector<XFile*>().swap(m_pXFile);
}