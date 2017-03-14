/**
 * @file	CameraSetting.h
 * @breif	カメラを配置するクラスヘッダ
 * @author	shibata
 */

#ifndef CAMERASETTING_H
#define CAMERASETTING_H

#include <d3dx9.h>
#include <vector>

class Camera;

class CameraSetting
{
public:
	CameraSetting();
	~CameraSetting();

	/**
	* カメラ座標と射影を設定する関数
	* @param [in]	index_			配置するカメラID
	* @param [in]	eyePoint_		カメラの角度(レンズ)が正面を向いてる状態でのカメラの位置
	* @param [in]	lookAtPoint_	カメラの位置を元にレンズの角度を決めるベクトル(方向)
	* @param [in]	aspect_			アスペクト比
	* @param [in]	angle_			画角の広さ
	* @param [in]	nearZ_			カメラが移せる一番近い描画位置
	* @param [in]	farZ_			カメラが移せる一番遠い描画位置
	* @note nearZ_のデフォルト値は1.0f
	* @note farZ_のデフォルト値は10000.0f
	* @note angle_のデフォルト値は50.0f
	*/
	void TransformView(int index_, const D3DXVECTOR3& eyePoint_, const D3DXVECTOR3& lookAtPoint_, float aspect_, float angle_, float nearZ_, float farZ_);

	/**全てのカメラの解放関数*/
	void ReleaseAllCamera();

	/**
	 * 一部のカメラの解放関数
	 * @param [in] index_	解放するカメラID
	 */
	void ReleaseCamera(int index_);

private:
	std::vector<Camera*> m_pCamera;
};

#endif // !CAMERASETTING_H