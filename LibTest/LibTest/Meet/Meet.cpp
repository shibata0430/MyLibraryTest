/**
 * @file	Meet.cpp
 * @breif	アイテム(肉)の描画クラス実装
 * @author	shibata
 */

#include "Meet.h"
#include <Library.h>

Meet::Meet() : 
m_moveCount(0),
m_isUp(false),
m_kWidth(64.0f),
m_kHeight(32.0f),
m_posX(300.0f),
m_upPosY(600.0f),
m_downPosY(602.0f)
{
	m_rlibrary.LoadTextureFile(MEET_TEX, "Resource/Texture/meet.png");
	m_rlibrary.SetTexSize(MEET_TEX, m_kWidth, m_kHeight);
}

Meet::~Meet()
{
}

void Meet::Control()
{
	m_moveCount++;
	if (m_moveCount > 30)
	{
		m_isUp = true;

		if (m_moveCount > 60)
		{
			m_moveCount = 0;
		}
	}
	else
	{
		m_isUp = false;
	}

}

void Meet::Draw()
{
	if (m_isUp)
	{
		m_rlibrary.DrawCenter(MEET_TEX, m_posX, m_upPosY);
	}
	else
	{
		m_rlibrary.DrawCenter(MEET_TEX, m_posX, m_downPosY);
	}
}
