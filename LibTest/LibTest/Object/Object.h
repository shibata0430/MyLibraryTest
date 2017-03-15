/**
 * @file	Object.h
 * @breif	テストに出てくるオブジェクトの親クラス
 * @author	shibata
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <d3dx9.h>

class Library;

enum Texture
{
	BACKGROUND,
	PLAYER,
	MEET,
};

enum Sound
{
	BGM,
};

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Control();
	virtual void Draw()    = 0;

protected:
	Library&				m_rLibrary;
};

#endif // !OBJECT_H