/**
 * @file	ObjectManager.h
 * @breif	オブジェクトを管理するクラスヘッダ
 * @author	shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class Background;
class Meet;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

private:
	Background*		m_pBackground;
	Meet*			m_pMeet;

};

#endif // !OBJECTMANAGER_H