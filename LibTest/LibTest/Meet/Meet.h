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
};


#endif // !MEET_H