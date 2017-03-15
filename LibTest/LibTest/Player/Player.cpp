/**
 * @file	Player.cpp
 * @breif	プレイヤークラス実装
 * @author	shibata
 */

#include "Player.h"
#include <Library.h>

namespace
{
	const float moveSpeed		= 5.0f;
	const int	animationSwith	= 30;
	const int   InitswithCount	= 60;

}

Player::Player() : 
m_kWidth(128.0f),
m_kHeight(128.0f),
m_posX(720.0f),
m_posY(360.0f),
m_depth(0.5f),
m_maxTu(0.5f),
m_maxTv(0.5f),
m_minTu(0.0f),
m_minTv(0.0f),
m_playerState(STAY),
m_animaCount(0)
{
	m_rLibrary.LoadTextureFile(PLAYER, "Resource/Texture/player.png");
	m_rLibrary.SetTexSize(PLAYER, m_kWidth, m_kHeight, m_depth, m_maxTu, m_maxTv, m_minTu, m_minTv);
}

Player::~Player()
{

}

void Player::Control()
{
	if (Move())
	{
		m_playerState = MOVE;
	}
	else
	{
		m_playerState = STAY;
	}
}

void Player::Draw()
{
	m_animaCount++;
	switch (m_playerState)
	{
	case STAY:
		DrawStay();
		break;

	case MOVE:
		DrawMove();
		break;
	}
}

bool Player::Move()
{

	if (m_rLibrary.CheckKey(DIK_LEFT) == ON)
	{
		m_posX -= moveSpeed;
		return true;
	}
	if (m_rLibrary.CheckKey(DIK_RIGHT) == ON)
	{
		m_posX += moveSpeed;
		return true;
	}
	if (m_rLibrary.CheckKey(DIK_UP) == ON)
	{
		m_posY -= moveSpeed;
		return true;
	}
	if (m_rLibrary.CheckKey(DIK_DOWN) == ON)
	{
		m_posY += moveSpeed;
		return true;
	}
	return false;
}

void Player::DrawStay()
{
	if (m_animaCount > animationSwith)
	{
		m_maxTu = 1.0f;
		m_maxTv = 0.5f;
		m_minTu = 0.5f;
		m_minTv = 0.0f;
		m_rLibrary.SetTexSize(PLAYER, m_kWidth, m_kHeight, m_depth, m_maxTu, m_maxTv, m_minTu, m_minTv);

		if (m_animaCount > InitswithCount)
		{
			m_animaCount = 0;
		}
	}
	else
	{
		m_maxTu = 0.5f;
		m_maxTv = 0.5f;
		m_minTu = 0.0f;
		m_minTv = 0.0f;
		m_rLibrary.SetTexSize(PLAYER, m_kWidth, m_kHeight, m_depth, m_maxTu, m_maxTv, m_minTu, m_minTv);
	}
	m_rLibrary.DrawCenter(PLAYER, m_posX, m_posY);

}

void Player::DrawMove()
{
	if (m_animaCount > animationSwith)
	{
		m_maxTu = 1.0f;
		m_maxTv = 1.0f;
		m_minTu = 0.5f;
		m_minTv = 0.5f;
		m_rLibrary.SetTexSize(PLAYER, m_kWidth, m_kHeight, m_depth, m_maxTu, m_maxTv, m_minTu, m_minTv);

		if (m_animaCount > InitswithCount)
		{
			m_animaCount = 0;
		}
	}
	else
	{
		m_maxTu = 0.5f;
		m_maxTv = 1.0f;
		m_minTu = 0.0f;
		m_minTv = 0.5f;
		m_rLibrary.SetTexSize(PLAYER, m_kWidth, m_kHeight, m_depth, m_maxTu, m_maxTv, m_minTu, m_minTv);
	}
	m_rLibrary.DrawCenter(PLAYER, m_posX, m_posY);
}
