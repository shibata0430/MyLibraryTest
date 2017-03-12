/**
 * @file	Camera.cpp
 * @breif	カメラの設定をするクラス実装
 * @author	shibata
 */

#include "Camera.h"
#include "DirectX9.h"

Camera::Camera() : 
m_pGraphicsDevice(DirectX9::Instance().GetDevice())
{

}

Camera::~Camera()
{

}

void Camera::TransformView(D3DXVECTOR3 eyePoint_, D3DXVECTOR3 lookAtPoint_, float aspect_, float angle_, float nearZ_, float farZ_)
{

	D3DXMATRIXA16 matView;
	{
		D3DXVECTOR3 vecUpVec(0.0f, 1.0f, 0.0f);	//カメラの上下の向きを決める

		// 左手座標系の座標をもとにカメラを設置してくれる関数
		/*
		* 第二引数：カメラ(視点)の位置の座標を入れる
		* 第三引数：カメラで見る上下左右の角度のベクトル(方向)を決める
		* 第四引数：上方位置　※特に値を返る必要は現状なし
		*/
		D3DXMatrixLookAtLH(&matView, &eyePoint_, &lookAtPoint_, &vecUpVec);
		m_pGraphicsDevice->SetTransform(D3DTS_VIEW, &matView);
	}

	{
		// プロジェクショントランスフォーム（射影変換）
		D3DXMATRIXA16 matProj;

		D3DXMatrixIdentity(&matProj);

		//画角
		/*
		* 主にズームイン。アウトで使われる
		* 画角を狭くするとモデルは大きく見えようになり、画角を広くするとモデルは小さく見えるようになる
		*/
		float viewAngle = D3DXToRadian(angle_);

		// アスペクト比
		/*
		* レンダリングターゲットの縦横比の設定に使用する　比率の求め方は 横 / 縦
		* レンダリングターゲットとは簡単に言うと最終的に画面に描画されているものだと思う
		*/
		float aspect = aspect_;

		// 奥行き方向をどこからどこまで描画するかの設定
		// 一番近い描画位置
		float nearZ = nearZ_;

		//一番遠い描画位置
		float farZ = farZ_;

		// 今まで設定した画角、アスペクト比などを元に左手座標系パースペクティブ射影行列の作成をする関数
		// パースペクティブ:遠近法、透視図法、見取り図
		D3DXMatrixPerspectiveFovLH(&matProj, viewAngle, aspect, nearZ, farZ);
		m_pGraphicsDevice->SetTransform(D3DTS_PROJECTION, &matProj);
	}
}
