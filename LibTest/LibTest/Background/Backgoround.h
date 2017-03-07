/**
 * @file	Background.h
 * @breif	�w�i��`�悷��N���X�w�b�_
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