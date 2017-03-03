/**
 * @file	InputManager.h
 * @breif	入力機器の管理をしているクラスヘッダ
 * @author	shibata
 */

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "InputKey.h"

class InputManager
{
public:
	/// キーの状態
	enum KeyState
	{
		KEY_PUSH,
		KEY_RELEASE,
		KEY_ON,
		KEY_OFF,
	};

	/**コンストラクタ*/
	InputManager();
	/**デストラクタ*/
	~InputManager();

	/**DI系をすべて更新する関数*/
	void UpdateDI();

	/**キーだけを更新する関数*/
	void UpdateKey();

	/**
	 * キーの状態を決める関数
	 * @param [in]		dik_	どのキーを使うか
	 * @return			state	キーの状態
	 */
	KeyState CheckKey(int dik_);

private:
	InputKey*	m_pInputKey;
};

#endif // !INPUTMANAGER_H