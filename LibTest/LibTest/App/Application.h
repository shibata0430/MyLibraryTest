/**
 * @file	Application.h
 * @breif	アプリケーションの基点クラスヘッダ
 * @author	shibata
 */

#ifndef APPLICATION_H
#define APPLICATION_H

class Library;
class ObjectManager;

class Application
{
public:
	Application();
	~Application();

	bool Run();

private:
	void Control();
	void Render();

private:
	Library&			m_rLibrary;
	ObjectManager*		m_pObjectManager;
	bool				m_isGameEnd;
};

#endif // !APPLICATION_H