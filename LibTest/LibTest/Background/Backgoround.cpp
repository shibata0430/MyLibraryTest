/**
* @file		Background.h
* @breif	”wŒi‚ð•`‰æ‚·‚éƒNƒ‰ƒXŽÀ‘•
* @author	shibata
*/

#include "Backgoround.h"
#include <Library.h>

Background::Background() : 
m_kWidth(1280.0f),
m_kHeight(720.0f),
m_kPosX(0.0f),
m_kPosY(0.0f)
{
	m_rlibrary.LoadTextureFile(BACKGROUND_TEX, "Resource/Texture/Background.png");
	m_rlibrary.SetTexSize(BACKGROUND_TEX, m_kWidth, m_kHeight);
}

Background::~Background()
{
}

void Background::Control()
{

}

void Background::Draw()
{
	m_rlibrary.DrawLeftTop(BACKGROUND_TEX, m_kPosX, m_kPosY);
}