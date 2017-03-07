/**
 * @file	Object.h
 * @breif	テストに出てくるオブジェクトの親クラス
 * @author	shibata
 */

#ifndef OBJECT_H
#define OBJECT_H

class Library;

enum
{
	BACKGROUND_TEX,
};

class Object
{
public:
	Object();
	~Object();

	virtual void Run() = 0;

protected:
	Library&	m_rlibrary;
};

#endif // !OBJECT_H