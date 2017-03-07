/**
 * @file	Object.cpp
 * @breif	テストに出てくるオブジェクトの親クラス実装
 * @author	shibata
 */

#include "Object.h"
#include <Library.h>

Object::Object() : 
m_rlibrary(Library::Instace())
{

}

Object::~Object()
{

}

void Object::Run()
{

}