/**
 * @file	LightSetting.h
 * @breif	ライトを設置するクラスヘッダ
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
	* ライトの設定をする関数
	* @param [in]	index_		ライトを設置する場所
	* @param [in]	direction_	ワールド空間での光の指す方向
	* @note direction_のデフォルト値は(0.0f, 0.0f, 1.0f)
	* direction_は0.0fより大きな値を入れなければならない
	*/
	void Lighting(int index_, D3DXVECTOR3 direction_);

	/**全てのライトデータの解放関数*/
	void ReleaseAllLight();

	/**
	 * 一部のライトデータの解放関数
	 * @param [in] index_	解放する配列番号
	 */
	void ReleaseLight(int index_);

private:
	std::vector<Light*> m_pLight;
};

#endif // !LIGHTSETTING_H
