/**
* @file		Background.h
* @breif	�w�i��`�悷��N���X����
* @author	shibata
*/

#include "Backgoround.h"
#include <Library.h>

Background::Background()
{
	m_rlibrary.LoadTextureFile(BACKGROUND_TEX, "Resource\Texture\Background.png");
}

Background::~Background()
{

}

void Background::Run()
{

}

void Background::Draw()
{

}