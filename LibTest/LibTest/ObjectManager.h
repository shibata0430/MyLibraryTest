/**
 * @file	ObjectManager.h
 * @breif	オブジェクトを管理するクラスヘッダ
 * @author	shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class Object;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Run();

private:
	void Control();
	void Draw();

private:
	Object*		m_pObject;
};

#endif // !OBJECTMANAGER_H