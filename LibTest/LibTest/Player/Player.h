/**
 * @file	Player.h
 * @breif	���삷��v���C���[�N���X�w�b�_
 * @author	shibata
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "../Object/Object.h"

class Player : public Object
{
public:
	Player();
	~Player();

	virtual void Control();
	virtual void Draw();
};

#endif // !PLAYER_H