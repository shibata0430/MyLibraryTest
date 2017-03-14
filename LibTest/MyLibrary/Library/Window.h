/**
 * @file	WindowCreate.h
 * @breif	ウィンドウを生成するクラスヘッダ
 * @author	shibata
 */

#ifndef WINDOWCREATE_H
#define WINDOWCREATE_H

#include <Windows.h>

class Window
{
public:
	/**コンストラクタ*/
	Window();
	/**デストラクタ*/
	~Window();

	/**
	 * ウィンドウの生成関数
	 * @param [in] titleName_		ゲームのタイトル
	 * @param [in] clientWidth_		画面横幅のサイズ
	 * @param [in] clientHeiht_		画面縦幅のサイズ
	 * @param [in] isFullScreen_	フルスクリーンにするかどうか
	 */
	void Create(const char* titleName_, int clientWidth_, int clientHeight_, bool isFullScreen_);

	bool Update();

	/**
	 * ウィンドウハンドルの取得関数
	 * @return m_hWnd ウィンドウハンドルのデータ
	 */
	HWND GetHwnd()
	{
		return m_hWnd;
	}

	float GetAspect()
	{
		return (m_clientWidth / m_clientHeight);
	}

private:
	float	m_clientWidth;
	float	m_clientHeight;
	HWND	m_hWnd; //!< ウィンドウハンドル
	MSG		m_msg;
};

#endif // !WINDOWCREATE_H