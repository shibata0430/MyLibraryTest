/**
 * @file	ObjectManager.h
 * @breif	オブジェクトを管理するクラスヘッダ
 * @author	shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>

class Background;
class Meet;
class Object;

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
	std::vector<Object*>	m_pObject;

};

#endif // !OBJECTMANAGER_H