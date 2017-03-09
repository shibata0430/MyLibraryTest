/**
 * @file	Application.cpp
 * @breif	アプリケーションの基点クラス実装
 * @author	shibata
 */

#include "Application.h"
#include "../Object/ObjectManager.h"
#include <Library.h>

Application::Application() : 
m_rLibrary(Library::Instace()),
m_pObjectManager(New ObjectManager),
m_isGameEnd(false)
{

}

Application::~Application()
{
	delete m_pObjectManager;
}

bool Application::Run()
{
	Control();
	Render();

	return m_isGameEnd;
}

void Application::Control()
{
	m_rLibrary.UpdateDI();

	m_pObjectManager->Control();
}

void Application::Render()
{
	m_rLibrary.SetFVF();
	m_rLibrary.DrawStart();

	m_pObjectManager->Draw();

	m_rLibrary.DrawEnd();
}