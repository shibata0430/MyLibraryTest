/**
 * @file	Chart.cpp
 * @breif	������@���L�q����N���X����
 * @author	shibata
 */

#include "Chart.h"
#include <Library.h>

Chart::Chart()
{

}

Chart::~Chart()
{

}

void Chart::Draw()
{
	m_rLibrary.DrawFont("�L�[����\", 0.0f, 0.0f);
	m_rLibrary.DrawFont("�v���C���[(�l)�̑���L�[", 0.0f, 20.0f);
	m_rLibrary.DrawFont("W:�� S:�� D:�E A:��", 0.0f, 40.0f);
	m_rLibrary.DrawFont("�v���C���[�̉�]�̃L�[", 0.0f, 70.0f);
}
