/**
 * @file	Object.cpp
 * @breif	テストに出てくるオブジェクトの親クラス実装
 * @author	shibata
 */

#include "Object.h"
#include <Library.h>

Object::Object() : 
m_rLibrary(Library::Instace())
{
}

Object::~Object()
{
	m_rLibrary.ReleaseAllTexture();
	m_rLibrary.ReleaseAllVirtices();
}

void Object::Control()
{

}