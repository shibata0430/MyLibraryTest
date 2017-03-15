/**
 * @file	CameraSetting.cpp
 * @breif	カメラを配置するクラス実装
 * @author	shibata
 */

#include "CameraSetting.h"
#include "Camera.h"
#include "../SearchMemoryLeak.h"

CameraSetting::CameraSetting()
{
}

CameraSetting::~CameraSetting()
{
	ReleaseAllCamera();
}

void CameraSetting::TransformView(int index_, const D3DXVECTOR3& eyePoint_, const D3DXVECTOR3& lookAtPoint_, float aspect_, float angle_, float nearZ_, float farZ_)
{
	m_pCamera.emplace_back(New Camera);

	m_pCamera[index_]->TransformView(eyePoint_, lookAtPoint_, aspect_, angle_, nearZ_, farZ_);
}

void CameraSetting::ReleaseAllCamera()
{
	for (unsigned int i = 0; i < m_pCamera.size(); i++)
	{
		delete m_pCamera[i];
	}
	m_pCamera.clear();
	m_pCamera.shrink_to_fit();
}

void CameraSetting::ReleaseCamera(int index_)
{
	if (m_pCamera[index_] != NULL)
	{
		delete m_pCamera[index_];
		m_pCamera[index_] = NULL;
	}
}
