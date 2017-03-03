/**
* @file		SoundInterface.cpp
* @breif	サウンドの初期化クラス実装
* @author	shibata
*/

#include "SoundInterface.h"

SoundInterface::SoundInterface() :
m_pDsound8(NULL)
{

}

SoundInterface::~SoundInterface()
{
	if (m_pDsound8 != NULL)
	{
		m_pDsound8->Release();
		m_pDsound8 = NULL;
	}
}

bool SoundInterface::InitSound(HWND hWnd_)
{
	if (FAILED(DirectSoundCreate8(NULL, &m_pDsound8, NULL)))			// オブジェクトの生成と初期化
	{
		MessageBox(NULL, "オブジェクトが生成できませんでした。", NULL, MB_OK);
		return false;
	}

	if (FAILED(m_pDsound8->SetCooperativeLevel(hWnd_, DSSCL_PRIORITY)))		// 協調レベルの設定
	{
		MessageBox(NULL, "協調レベルが設定できませんでした。", NULL, MB_OK);
		return false;
	}

	return true;
}