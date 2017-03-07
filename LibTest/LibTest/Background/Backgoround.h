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

	virtual void Run();

private:
	void Draw();
};

#endif // !BACKGROUND_H