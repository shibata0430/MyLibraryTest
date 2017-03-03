/**
 * @file	SoundInterface.h
 * @breif	サウンドの初期化クラスヘッダ
 * @author	shibata
 */

#ifndef SOUNDINTERFACE_H
#define SOUNDINTERFACE_H

#include <dsound.h>

class SoundInterface
{
private:
	/**コンストラクタ*/
	SoundInterface();

public:
	/**デストラクタ*/
	~SoundInterface();

	/**
	 * サウンドインターフェイスのインスタンス取得関数
	 * @return soundInterface サウンドインターフェイスのインスタンス
	 */
	static SoundInterface& Instance()
	{
		static SoundInterface soundInterface;
		return soundInterface;
	}

	/**
	 * サウンドの初期化関数
	 * @param [in]	hWnd_	ウィンドウハンドル
	 * @retval		true	初期化成功
	 * @retval		false	初期化失敗
	 */
	bool InitSound(HWND hWnd_);

	/**
	 * サウンドのインターフェイスの取得関数
	 * @return m_pDsound8 サウンドのインターフェイス
	 */
	inline IDirectSound8* GetSoundData()
	{
		return m_pDsound8;
	}

private:
	IDirectSound8* m_pDsound8;	//!< サウンドインターフェイス
};

#endif // !SOUNDINTERFACE_H