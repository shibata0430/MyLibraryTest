/**
 * @file	Vertices.cpp
 * @breif	頂点情報を決めるクラスヘッダ
 * @author	shibata
 */

#include "Vertices.h"
#include "DirectX9.h"

Vertices::Vertices() :
m_pGraphicsDevice(DirectX9::Instance().GetDevice()),
m_texWidth(NULL),
m_texHeight(NULL),
m_texDepth(NULL),
m_texMaxTu(NULL),
m_texMaxTv(NULL),
m_texMinTu(NULL),
m_texMinTv(NULL)
{
	for (int i = 0; i < 4; i++)
	{
		m_colors[i] = 0xffffffff;
	}
}

Vertices::~Vertices()
{

}

void Vertices::SetTexSize(float width_, float height_, float depth_, float maxTu_, float maxTv_, float minTu_, float minTv_)
{
	m_texWidth  = width_;
	m_texHeight = height_;
	m_texDepth  = depth_;
	m_texMaxTu  = maxTu_;
	m_texMaxTv  = maxTv_;
	m_texMinTu  = minTu_;
	m_texMinTv  = minTv_;
}

void Vertices::DrawLeftTop(const D3DXVECTOR2& position_, const LPDIRECT3DTEXTURE9 pTextureData_)
{
	CUSTOMVERTEX vertex[4] =
	{
		{		 0.0f,		  0.0f, m_texDepth, 1.0f, m_colors[0], m_texMinTu, m_texMinTv },
		{  m_texWidth,		  0.0f, m_texDepth, 1.0f, m_colors[1], m_texMaxTu, m_texMinTv },
		{  m_texWidth, m_texHeight, m_texDepth, 1.0f, m_colors[2], m_texMaxTu, m_texMaxTv },
		{		 0.0f, m_texHeight, m_texDepth, 1.0f, m_colors[3], m_texMinTu, m_texMaxTv },
	};

	for (int i = 0; i < 4; i++)
	{
		vertex[i].x += position_.x;
		vertex[i].y += position_.y;
	}

	m_pGraphicsDevice->SetTexture(0, pTextureData_);
	m_pGraphicsDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}

void Vertices::DrawCenter(const D3DXVECTOR2& position_, const LPDIRECT3DTEXTURE9 pTextureData_)
{
	CUSTOMVERTEX vertex[4] =
	{
		{ -m_texWidth / 2.0f, -m_texHeight / 2.0f, m_texDepth, 1.0f, m_colors[0], m_texMinTu, m_texMinTv },
		{  m_texWidth / 2.0f, -m_texHeight / 2.0f, m_texDepth, 1.0f, m_colors[1], m_texMaxTu, m_texMinTv },
		{  m_texWidth / 2.0f,  m_texHeight / 2.0f, m_texDepth, 1.0f, m_colors[2], m_texMaxTu, m_texMaxTv },
		{ -m_texWidth / 2.0f,  m_texHeight / 2.0f, m_texDepth, 1.0f, m_colors[3], m_texMinTu, m_texMaxTv },
	};

	for (int i = 0; i < 4; i++)
	{
		vertex[i].x += position_.x;
		vertex[i].y += position_.y;
	}

	m_pGraphicsDevice->SetTexture(0, pTextureData_);
	m_pGraphicsDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));

}

void Vertices::SetColor(DWORD& color_, int alpha_, int red_, int green_, int blue_)
{
	{
		DWORD preColor = D3DCOLOR_ARGB(alpha_, red_, green_, blue_);

		color_ = preColor;
	}

	for (int i = 0; i < 4; i++)
	{
		m_colors[i] = color_;
	}
}