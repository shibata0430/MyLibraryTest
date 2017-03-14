/**
 * @file	Chart.cpp
 * @breif	操作方法を記述するクラス実装
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
	m_rLibrary.DrawFont("キー操作表", 0.0f, 0.0f);
	m_rLibrary.DrawFont("プレイヤー(人)の操作キー", 0.0f, 20.0f);
	m_rLibrary.DrawFont("W:上 S:下 D:右 A:左", 0.0f, 40.0f);
	m_rLibrary.DrawFont("プレイヤーの回転のキー", 0.0f, 70.0f);
}
