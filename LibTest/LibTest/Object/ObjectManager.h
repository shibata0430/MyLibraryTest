/**
 * @file	ObjectManager.h
 * @breif	オブジェクトを管理するクラスヘッダ
 * @author	shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>

class Object;
class Library;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

private:
	std::vector<Object*>	m_pObject;
	Library&				m_rLibrary;
};

#endif // !OBJECTMANAGER_H