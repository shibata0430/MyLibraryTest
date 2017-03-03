/**
 * @file	InputKey.h
 * @breif	キーボード関連のクラス実装
 * @author	shibata
 */

#include "InputKey.h"
#include "InputDvice.h"

InputKey::InputKey() : 
m_pKeyDevice(InputDevice::Instance().GetKeyDevice())
{
	for (int i = 0; i < 256; i++)
	{
		m_oldKeyKind[i] = { KEY_OFF };
		m_keyKind[i]    = { KEY_OFF };
	}
}

InputKey::~InputKey()
{

}

void InputKey::UpdateKey()
{
	HRESULT result = m_pKeyDevice->Acquire();

	if ((result == DI_OK) || (result == S_FALSE))
	{
		m_pKeyDevice->GetDeviceState(sizeof(m_directInputKeys), &m_directInputKeys);
	}
}

InputKey::State InputKey::CheckKey(int dik_)
{
	if (m_directInputKeys[dik_] & 0x80)
	{
		if (m_oldKeyKind[dik_] == KEY_OFF)
		{
			m_keyKind[dik_] = KEY_PUSH;
		}
		else
		{
			m_keyKind[dik_] = KEY_ON;
		}
		m_oldKeyKind[dik_] = KEY_ON;
	}
	else
	{
		if (m_oldKeyKind[dik_] == KEY_ON)
		{
			m_keyKind[dik_] = KEY_RELEASE;
		}
		else
		{
			m_keyKind[dik_] = KEY_OFF;
		}
		m_oldKeyKind[dik_] = KEY_OFF;
	}

	return m_keyKind[dik_];
}