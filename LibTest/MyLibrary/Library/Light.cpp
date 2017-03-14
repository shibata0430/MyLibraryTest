/**
 * @file	Light.cpp
 * @breif	ライトの設定をするクラス実装
 * @author	shibata
 */

#include "Light.h"
#include "DirectX9.h"

Light::Light() : 
m_pGraphicsdevice(DirectX9::Instance().GetDevice())
{

}

Light::~Light()
{

}

void Light::Lighting(D3DXVECTOR3 direction_)
{
	ZeroMemory(&m_light, sizeof(D3DLIGHT9));
	m_light.Type = D3DLIGHT_DIRECTIONAL;
	m_light.Diffuse.r = 1.0f;
	m_light.Diffuse.g = 1.0f;
	m_light.Diffuse.b = 1.0f;
	m_light.Specular.r = 1.0f;
	m_light.Specular.g = 1.0f;
	m_light.Specular.b = 1.0f;
	m_light.Direction = direction_;
	D3DXVec3Normalize((D3DXVECTOR3*)&m_light.Direction, &direction_);
	m_light.Range = 500.0f;
	m_pGraphicsdevice->SetLight(0, &m_light);
	m_pGraphicsdevice->LightEnable(0, TRUE);
}