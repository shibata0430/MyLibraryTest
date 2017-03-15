/**
 * @file	Vertices.h
 * @breif	頂点情報を決めるクラスヘッダ
 * @author	shibata
 */

#ifndef VERTICES_H
#define VERTICES_H

#include <d3dx9.h>

struct CUSTOMVERTEX
{
	FLOAT x;		//!< 画面座標のx軸
	FLOAT y;		//!< 画面座標のy軸
	FLOAT z;		//!< 画面座標のz軸
	FLOAT rhw;		//!< 同次座標
	DWORD color;	//!< 色指定
	FLOAT tu;		//!< テクスチャ座標のx軸
	FLOAT tv;		//!< テクスチャ座標のy軸
};

class Vertices
{
public:
	/**コンストラクタ*/
	Vertices();
	/**デストラクタ*/
	~Vertices();

	/**
	 * 画像サイズの設定する関数
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
	void SetTexSize(float width_, float height_, float depth_, float maxTu_, float maxTv_, float minTu_, float minTv_);

	/**
	 * 左上からの描画関数
	 * @param [in] position_		xy座標
	 * @param [in] pTextureData_	テクスチャデータ
	 * @note Libraryでテクスチャデータを取得する
	 */
	void DrawLeftTop(const D3DXVECTOR2& position_, const LPDIRECT3DTEXTURE9 pTextureData_);

	/**
	* 中心からの描画関数
	* @param [in] position_		xy座標
	* @param [in] pTextureData_	テクスチャデータ
	* @note Libraryでテクスチャデータを取得する
	*/
	void DrawCenter(const D3DXVECTOR2& position_, const LPDIRECT3DTEXTURE9 pTextureData_);

	/**
	 * 色の変更する関数
	 * @param [in] color_	変更したRGBAの最終的な値
	 * @param [in] alpha_	変更する透過の値
	 * @param [in] red_		変更する赤の値
	 * @param [in] green_	変更する緑の値
	 * @param [in] blue_	変更する青の値
	 * @note rbgaのデフォルト値は255
	 */
	void SetColor(DWORD& color_, int alpha_, int red_, int green_, int blue_);

private:
	LPDIRECT3DDEVICE9	m_pGraphicsDevice;	//!< DirectX9から取ってきたデバイス
	DWORD				m_colors[4];		//!< テクスチャの色
	float				m_texWidth;			//!< テクスチャの幅
	float				m_texHeight;		//!< テクスチャの高さ
	float				m_texDepth;			//!< テクスチャの奥行き
	float				m_texMaxTu;			//!< テクスチャのX軸最大座標
	float				m_texMaxTv;			//!< テクスチャのY軸最大座標
	float				m_texMinTu;			//!< テクスチャのX軸最小座標
	float				m_texMinTv;			//!< テクスチャのY軸最小座標
};

#endif // !VERTICES_H