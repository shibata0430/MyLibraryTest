/**
 * @file	VerticesManager.h
 * @breif	頂点情報を管理しているクラスヘッダ
 * @author	shibata
 */

#ifndef VERTICESMANAGER_H
#define VERTICESMANAGER_H

#include <vector>
#include <d3dx9.h>

class Vertices;

class VerticesManager
{
public:
	/**コンストラクタ*/
	VerticesManager();
	/**デストラクタ*/
	~VerticesManager();

	/**
	* 画像サイズの設定する関数
	* @param [in] index_	頂点情報の配列番号
	* @param [in] width_	描画の横幅
	* @param [in] height_	描画の縦幅
	* @param [in] depth_	描画の奥行き
	* @param [in] maxTu_	テクスチャの最大x座標
	* @param [in] maxTv_	テクスチャの最大y座標
	* @param [in] minTu_	テクスチャの最小x座標
	* @param [in] minTv_	テクスチャの最小y座標
	* @note depth_のデフォルト値は0.5f
	* @note maxTu, maxTvのデフォルト値は1.0f
	* @note minTu, minTvのデフォルト値は0.0f
	*/
	void SetTexSize(int index_, float width_, float height_, float depth_, float maxTu_, float maxTv_, float minTu_, float minTv_);

	/**
	* 左上からの描画関数
	* @param [in] index_		頂点情報の配列番号
	* @param [in] posX_			x座標
	* @param [in] posY_			y座標
	* @param [in] pTextureData_	テクスチャデータ
	* @note Libraryでテクスチャデータを取得する
	*/
	void DrawLeftTop(int index_, float posX_, float posY_, const LPDIRECT3DTEXTURE9 pTextureData_);

	/**
	* 中心からの描画関数
	* @param [in] index_		頂点情報の配列番号
	* @param [in] posX_			x座標
	* @param [in] posY_			y座標
	* @param [in] pTextureData_	テクスチャデータ
	* @note Libraryでテクスチャデータを取得する
	*/
	void DrawCenter(int index_, float posX_, float posY_, const LPDIRECT3DTEXTURE9 pTextureData_);

	/**
	* 色の変更する関数
	* @param [in] index_	頂点情報の配列番号
	* @param [in] color_	変更したRGBAの最終的な値
	* @param [in] alpha_	変更する透過の値
	* @param [in] red_		変更する赤の値
	* @param [in] green_	変更する緑の値
	* @param [in] blue_	変更する青の値
	* @note rbgaのデフォルト値は255
	*/
	void SetColor(int index_, DWORD color_, int alpha_, int red_, int green_, int blue_);

	/**全ての頂点データの解放関数*/
	void ReleaseAllVirtices();

	/**
	 * 一部の頂点データの解放関数
	 * @param [in] index_	解放する配列番号
	 */
	void ReleaseVirtices(int index_);

private:
	std::vector<Vertices*>	m_pVertices;
};

#endif // !VERTICESMANAGER_H