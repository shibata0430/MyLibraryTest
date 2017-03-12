/**
 * @file	Background.h
 * @breif	”wŒi‚ð•`‰æ‚·‚éƒNƒ‰ƒXƒwƒbƒ_
 * @author	shibata
 */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../Object/Object.h"

class Background : public Object
{
public:
	Background();
	~Background();

	virtual void Control();
	virtual void Draw();

private:
	const float m_kWidth;
	const float m_kHeight;
	const float m_kPosX;
	const float m_kPosY;
};

#endif // !BACKGROUND_H