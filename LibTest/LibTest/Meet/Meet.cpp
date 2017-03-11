#include "Meet.h"
#include <Library.h>

namespace
{
	const float kWidth	= 64;
	const float kHeight = 32;
	const float kPosX	= 300;
	const float kPosY	= 400;

}

Meet::Meet()
{
	m_rlibrary.LoadTextureFile(MEET_TEX, "Resource/Texture/meet.png");
	m_rlibrary.SetTexSize(MEET_TEX, kWidth, kHeight);
}

Meet::~Meet()
{
}

void Meet::Control()
{
}

void Meet::Draw()
{
	m_rlibrary.DrawCenter(MEET_TEX, kPosX, kPosY);
}
