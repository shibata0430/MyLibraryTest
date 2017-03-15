/**
 * @file	Light.h
 * @breif	���C�g�̐ݒ������N���X�w�b�_
 * @author	shibata
 */

#ifndef LIGHT_H
#define LIGHT_H

#include <d3dx9.h>

class Light
{
public:
	/**�R���X�g���N�^*/
	Light();
	/**�f�X�g���N�^*/
	~Light();

	/**
	 * ���C�g�̐ݒ������֐�
	 * @param [in] direction_ ���[���h��Ԃł̌��̎w������
	 * @note direction_�̃f�t�H���g�l��(0.0f, 0.0f, 1.0f)
	 * direction_��0.0f���傫�Ȓl�����Ȃ���΂Ȃ�Ȃ�
	 */
	void Lighting(const D3DXVECTOR3& direction_);

private:
	D3DLIGHT9				m_light;			//!< ���C�g�ݒ������\����
	LPDIRECT3DDEVICE9		m_pGraphicsdevice;	//!< DirectX9�������Ă����f�o�C�X
};

#endif // !LIGHT_H