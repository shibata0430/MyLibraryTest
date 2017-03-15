/**
 * @file	TextureFile.h
 * @breif	画像ファイルの読み込みクラスヘッダ
 * @author	shibata
 */

#ifndef TEXTUREFILE_H
#define TEXTUREFILE_H

#include <d3dx9.h>


class TextureFile
{
public:
	/**コンストラクタ*/
	TextureFile();
	/**デストラクタ*/
	~TextureFile();

	/**
	 * 画像を読み込む関数
	 * @param [in]	filePath_	画像のファイルパス
	 * @retval		true		読み込み成功
	 * @retval		false		読み込み失敗
	 */
	bool LoadTextureFile(const char* filePath_);

	/**
	 * 画像を詳細に読み込む関数
	 * @param [in]	filePath_		画像のファイルパス
	 * @param [in]	clor			RGBAの色設定
	 * @param [in]	isTowPower_		画像サイズの2の累乗がどうか
	 * @retval		true			読み込み成功
	 * @retval		false			読み込み失敗
	 * @note colorのデフォルトは255
	 * @note isTowPower_のデフォルトはtrue
	 */
	bool LoadTextuerMoreInfo(const char* filePath_, const D3DXCOLOR& color, bool isTwoPower_);

	/**
	 * 画像データの取得関数
	 * @return m_pTexture 画像データ
	 */
	LPDIRECT3DTEXTURE9 GetTextureFileData() const
	{
		return m_pTexture;
	}

private:
	LPDIRECT3DTEXTURE9	m_pTexture;			//!< DirectXのテクスチャインターフェイス
	LPDIRECT3DDEVICE9	m_pGraphicsDevice;	//!< DirectX9から取ってきたデバイス
};

#endif // !TEXTUREFILE_H