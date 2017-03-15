/**
 * @file	TextureFileManager.h
 * @breif	画像の読み込みを管理しているクラスヘッダ
 * @author	shibata
 */

#ifndef TEXTUREFILEMANAGER_H
#define TEXTUREFILEMANAGER_H

#include <vector>
#include <d3dx9.h>

class TextureFile;

class TextureFileManager
{
public:
	/**コンストラクタ*/
	TextureFileManager();
	/**デストラクタ*/
	~TextureFileManager();

	/**
	* 画像を読み込む関数
	* @param [in]	index_		読み込む画像の配列番号
	* @param [in]	filePath_	画像のファイルパス
	*/
	void LoadTextureFile(int index_, const char* filePath_);

	/**
	* 画像を詳細に読み込む関数
	* @param [in]	index_			読み込む画像の配列番号
	* @param [in]	filePath_		画像のファイルパス
	* @param [in]	alpha_			画像の透過の値
	* @param [in]	red_			画像の赤の値
	* @param [in]	green_			画像の緑の値
	* @param [in]	blue_			画像の青の値
	* @param [in]	isTowPower_		画像サイズの2の累乗がどうか
	* @note argbのデフォルトは255
	* @note isTowPower_のデフォルトはtrue
	*/
	void LoadTextuerMoreInfo(int index_, const char* filePath_, int alpha_, int red_, int green_, int blue_, bool isTwoPower_);

	/**
	* 画像データの取得関数
	* @param [in]	index_		画像データの配列番号
	* @return		m_pTexture	画像データ
	*/
	LPDIRECT3DTEXTURE9 GetTextureFileData(int index_) const;

	/**全てのテクスチャの解放関数*/
	void ReleaseAllTexture();

	/**
	 * 一部のテクスチャの解放関数
	 * @param [in] index_	解放する配列番号
	 */
	void ReleaseTexture(int index_);

private:
	std::vector<TextureFile*> m_pTextureFile;
};

#endif // !TEXTUREFILEMANAGER_H