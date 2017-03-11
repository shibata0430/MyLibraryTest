/**
 * @file	Font.cpp
 * @breif	フォントの設定・描画するクラス実装
 * @author	shibata
 */

#include "Font.h"
#include "DirectX9.h"

Font::Font() : 
m_pFont(NULL),
m_pGraphicsDevice(DirectX9::Instance().GetDevice())
{
	if (FAILED(D3DXCreateFont(
		m_pGraphicsDevice,
		20,
		10,
		FW_REGULAR,
		NULL,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		TEXT("ＭＳ　Ｐゴシック"),
		&m_pFont)))
	{
		MessageBox(NULL, "フォントクラスが作成されませんでした", NULL, MB_OK);
	}
}

Font::Font(int width_, int height_) : 
m_pFont(NULL),
m_pGraphicsDevice(DirectX9::Instance().GetDevice())
{
	if (FAILED(D3DXCreateFont(
		m_pGraphicsDevice,
		height_,
		width_,
		FW_REGULAR,
		NULL,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		TEXT("ＭＳ　Ｐゴシック"),
		&m_pFont)))
	{
		MessageBox(NULL, "フォントクラスが作成されませんでした", NULL, MB_OK);
	}
}

Font::~Font()
{
	if (m_pFont != NULL)
	{
		m_pFont->Release();
		m_pFont = NULL;
	}
}

void Font::DrawFont(const char* pString_, D3DXVECTOR2 position_, DWORD format_, int red_, int green_, int blue_)
{
	RECT rect;
	{
		D3DXFONT_DESC desc;
		m_pFont->GetDesc(&desc);

		rect.left = (LONG)position_.x;
		rect.top = (LONG)position_.y;
		rect.right = (LONG)position_.x + desc.Width * strlen(pString_);
		rect.bottom = (LONG)position_.y + desc.Height * strlen(pString_);
	}

	m_pFont->DrawText(
		NULL,
		pString_,
		-1,
		&rect,
		format_,
		D3DCOLOR_XRGB(red_, green_, blue_)
		);

}