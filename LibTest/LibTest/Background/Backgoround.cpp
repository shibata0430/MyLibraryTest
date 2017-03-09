/**
* @file		Background.h
* @breif	”wŒi‚ð•`‰æ‚·‚éƒNƒ‰ƒXŽÀ‘•
* @author	shibata
*/

#include "Backgoround.h"
#include <Library.h>

namespace
{
	const float kWidth  = 1280.0f;
	const float kHeight = 720.0f;
	const float kPosX   = 0.0f;
	const float kPosY   = 0.0f;
}

Background::Background()
{
	m_rlibrary.LoadTextureFile(BACKGROUND_TEX, "Resource/Texture/Background.png");
	m_rlibrary.SetTexSize(BACKGROUND_TEX, kWidth, kHeight);
}

Background::~Background()
{
	m_rlibrary.ReleaseTexture(BACKGROUND_TEX);
	m_rlibrary.ReleaseVirtices(BACKGROUND_TEX);
}

void Background::Control()
{

}

void Background::Draw()
{
	m_rlibrary.DrawLeftTop(BACKGROUND_TEX, kPosX, kPosY);
}