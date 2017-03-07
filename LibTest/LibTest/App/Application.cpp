/**
 * @file	Application.cpp
 * @breif	アプリケーションの基点クラス実装
 * @author	shibata
 */

#include "Application.h"
#include <Library.h>

Application::Application() : 
m_rLibrary(Library::Instace()),
m_isGameEnd(false)
{

}

Application::~Application()
{

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
}

void Application::Render()
{
	m_rLibrary.SetFVF();
	m_rLibrary.DrawStart();


	m_rLibrary.DrawEnd();
}