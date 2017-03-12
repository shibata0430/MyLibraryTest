/**
 * @file	Object.h
 * @breif	テストに出てくるオブジェクトの親クラス
 * @author	shibata
 */

#ifndef OBJECT_H
#define OBJECT_H

class Library;

enum Texture
{
	//PLAYER_TEX,
	BACKGROUND_TEX,
	MEET_TEX,

};

class Object
{
public:
	Object();
	~Object();

	virtual void Control() = 0;
	virtual void Draw()    = 0;

protected:
	Library&				m_rlibrary;
};

#endif // !OBJECT_H