/**
 * @file	InputKey
 * @breif	キーボード関係のクラスヘッダ
 * @author	shibata
 */

#ifndef INPUTKEY_H
#define INPUTKEY_H

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>

class InputKey
{
public:
	/// キーの状態
	enum State
	{
		KEY_PUSH,
		KEY_RELEASE,
		KEY_ON,
		KEY_OFF,
	};

	/**コンストラクタ*/
	InputKey();
	/**デストラクタ*/
	~InputKey();

	/**キー情報の更新する関数*/
	void UpdateKey();

	/**
	 * キーの状態を決める関数
	 * @param [in]	dik_			どのキーを使うか
	 * @return		m_keyKind[dik_]	キーの状態
	 */
	State CheckKey(int dik_);

private:
	LPDIRECTINPUTDEVICE8	m_pKeyDevice;				//!< キーボード用デバイス
	State					m_keyKind[256];				//!< どのキーが押されたかを格納している変数
	BYTE					m_oldKeyKind[256];			//!< 前のキーの状態を格納する変数
	BYTE					m_directInputKeys[256];		//!< DIKを格納する変数
};

#endif // !INPUTKEY_H