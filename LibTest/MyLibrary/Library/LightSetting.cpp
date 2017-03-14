/**
 * @file	LightSetting.cpp
 * @breif	ライトを設置するクラス実装
 * @author	shibata
 */

#include "LightSetting.h"
#include "Light.h"
#include "../SearchMemoryLeak.h"

LightSetting::LightSetting()
{

}

LightSetting::~LightSetting()
{
	ReleaseAllLight();
}

void LightSetting::Lighting(int index_, D3DXVECTOR3 direction_)
{
	m_pLight.emplace_back(New Light);
	m_pLight[index_]->Lighting(direction_);
}

void LightSetting::ReleaseAllLight()
{
	for (unsigned int i = 0; i < m_pLight.size(); i++)
	{
		delete m_pLight[i];
	}
	m_pLight.clear();
	m_pLight.shrink_to_fit();
}

void LightSetting::ReleaseLight(int index_)
{
	if (m_pLight[index_] != NULL)
	{
		delete m_pLight[index_];
		m_pLight[index_] = NULL;
	}
}
