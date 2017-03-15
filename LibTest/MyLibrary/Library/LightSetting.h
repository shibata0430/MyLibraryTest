/**
 * @file	LightSetting.h
 * @breif	���C�g��ݒu����N���X�w�b�_
 * @author	shibata
 */

#ifndef LIGHTSETTING_H
#define LIGHTSETTING_H

#include <vector>
#include <d3dx9.h>

class Light;

class LightSetting
{
public:
	LightSetting();
	~LightSetting();

	/**
	* ���C�g�̐ݒ������֐�
	* @param [in]	index_		���C�g��ݒu����ꏊ
	* @param [in]	direction_	���[���h��Ԃł̌��̎w������
	* @note direction_�̃f�t�H���g�l��(0.0f, 0.0f, 1.0f)
	* direction_��0.0f���傫�Ȓl�����Ȃ���΂Ȃ�Ȃ�
	*/
	void Lighting(int index_, const D3DXVECTOR3& direction_);

	/**�S�Ẵ��C�g�f�[�^�̉���֐�*/
	void ReleaseAllLight();

	/**
	 * �ꕔ�̃��C�g�f�[�^�̉���֐�
	 * @param [in] index_	�������z��ԍ�
	 */
	void ReleaseLight(int index_);

private:
	std::vector<Light*> m_pLight;
};

#endif // !LIGHTSETTING_H
