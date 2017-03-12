/**
 * @file	DirectX9.h
 * @breif	DirectXの初期化クラスヘッダ
 * @author	shibata
 */

#ifndef DIRECTX9_H
#define DIRECTX9_H

#include <d3dx9.h>

class DirectX9
{
private:
	/**コンストラクタ*/
	DirectX9();

public:
	/**デストラクタ*/
	~DirectX9();

	/**
	 * DirectX9のインスタンス取得関数
	 * return	directX9	DirectX9のインスタンス
	 */
	static DirectX9& Instance()
	{
		static DirectX9 directX9;
		return directX9;
	}

	/**
	 * DirectXの初期化関数
	 * @param [in]	hWnd_			ウィンドウハンドル
	 * @param [in]	clientWidth_	画面横幅のサイズ
	 * @param [in]	clientHeight_	画面縦幅のサイズ
	 * @param [in]	isFullScreen_	フルスクリーンにするかどうか
	 * @retval		true			初期化成功
	 * @retval		false			初期化失敗
	 */
	bool InitDirectX(HWND hWnd_, int clientWidth_, int clientHeight_, bool isFullScreen_);

	/**
	 * 頂点フォーマットの設定関数
	 * @param [in] fvf_ 頂点フォーマットの設定
	 * @note デフォルトはD3DFVF_CUSTOMVERTEXの定義
	 */
	void SetFVF(DWORD fvf_);

	/**描画初めの関数*/
	void DrawStart();

	/**描画終わりの関数*/
	void DrawEnd();

	/**
	 * 描画初期化関数
	 * @note 3Dを描画するときに使用
	 */
	void Init3DDraw();

	/**
	 * デバイスの取得関数
	 * @return	m_pD3Device	デバイス情報
	 */
	LPDIRECT3DDEVICE9 GetDevice()
	{
		return m_pD3Device;
	}

private:
	/**描画初期化関数*/
	void InitDraw();

private:
	LPDIRECT3D9			m_pDirect3D;	//!< DirectXのインターフェイス
	LPDIRECT3DDEVICE9	m_pD3Device;	//!< DirectXのデバイス
};

#endif // !DIRECTX9_H