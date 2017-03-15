/**
 * @file	Font.h
 * @breif	フォントの設定・描画するクラスヘッダ
 * @author	shibata
 */

#ifndef FONT_H
#define FONT_H

#include <d3dx9.h>

class Font
{
public:
	/**コンストラクタ*/
	Font();

	/**
	 * コンストラクタ
	 * @param [in]	width_	文字の幅
	 * @param [in]	height_	文字の高さ
	 */
	Font(int width_, int height_);

	/**デストラクタ*/
	~Font();

	/**
	 * 文字を描画する関数
	 * @param [in] pString_		描画する文字列
	 * @param [in] position_	描画する文字の座標
	 * @param [in] format_		文字のフォーマット
	 * @param [in] red_			文字のR値
	 * @param [in] green_		文字のG値
	 * @param [in] blue_		文字のB値
	 * @note format_のデフォルト値は左寄せ
	 * @note RGBのデフォルト値は255
	 */
	void DrawFont(const char* pString_, const D3DXVECTOR2& position_, DWORD format_ = DT_LEFT, int red_ = 255, int green_ = 255, int blue_ = 255);

private:
	LPD3DXFONT				m_pFont;			//!< フォントのインターフェイス
	LPDIRECT3DDEVICE9		m_pGraphicsDevice;	//!< Graphicsdeviceから取ってきたデバイス

};


#endif // !FONT_H