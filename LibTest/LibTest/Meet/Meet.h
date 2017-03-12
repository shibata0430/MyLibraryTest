/**
 * @file	Meet.h
 * @breif	アイテム(肉)の描画クラスヘッダ
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