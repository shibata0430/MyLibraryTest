/**
 * @file	Player.h
 * @breif	プレイヤークラスヘッダ
 * @author	shibata
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "../Object/Object.h"

enum State
{
	STAY,
	MOVE
};

class Player : public Object
{
public:
	Player();
	~Player();

	virtual void Control() override;
	virtual void Draw();

private:
	bool Move();

	void DrawStay();
	void DrawMove();

private:
	const float m_kWidth;
	const float m_kHeight;
	float		m_posX;
	float		m_posY;
	float		m_depth;
	float		m_maxTu;
	float		m_maxTv;
	float		m_minTu;
	float		m_minTv;
	int			m_animaCount;
	State		m_playerState;
};

#endif // !PLAYER_H
