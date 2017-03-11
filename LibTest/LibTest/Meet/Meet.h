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
};


#endif // !MEET_H