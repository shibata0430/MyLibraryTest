/**
 * @file	Meet.h
 * @breif	�A�C�e��(��)�̕`��N���X�w�b�_
 * @author	shibata
 */

#ifndef MEET_H
#define MEET_H

#include "../Object/Object.h"

class Meet : public Object
{
public:
	Meet();
	~Meet();

	virtual void Control();
	virtual void Draw();

private:
	int			m_moveCount;
	bool		m_isUp;
	const float m_kWidth;
	const float m_kHeight;
	const float m_posX;
	const float m_upPosY;
	const float m_downPosY;
};


#endif // !MEET_H