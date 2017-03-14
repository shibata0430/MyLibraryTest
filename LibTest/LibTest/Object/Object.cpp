/**
 * @file	Object.cpp
 * @breif	テストに出てくるオブジェクトの親クラス実装
 * @author	shibata
 */

#include "Object.h"
#include <Library.h>

Object::Object() : 
m_rLibrary(Library::Instace())
{

}

Object::~Object()
{
	m_rLibrary.ReleaseAllTexture();
	m_rLibrary.ReleaseAllVirtices();

}

void Object::Control()
{

}

void Object::TransformWorld(D3DXVECTOR3 localPos_, float angle_)
{
	D3DXMATRIXA16 matWorld;
	D3DXMATRIXA16 matPosition;
	D3DXMATRIXA16 matRotation;

	// 単位行列を作る関数
	/*
	* ワールドトランスフォームを最初の単位行列で「初期化」している
	*/
	D3DXMatrixIdentity(&matWorld);

	// 平行移動行列を作る関数
	/*
	* 第二、第三、第四引数のベクトル(座標)をもとに第一引数を初期化している
	*/
	D3DXMatrixTranslation(&matPosition, localPos_.x, localPos_.y, localPos_.z);

	// Y軸をの中心にメッシュを回転させる関数
	/*
	* 第二引数：初期化した行列
	* 第二引数：メッシュの回転する角度
	*/
	D3DXMatrixRotationY(&matRotation, angle_);

	// 行列を結合する関数
	/*
	* 第二、第三引数の行列をかけて(×)第一引数に計算結果を入れている
	* 2つをかけない(×)と座標系が画面に反映されないから
	*/
	D3DXMatrixMultiply(&matWorld, &matRotation, &matPosition);

	/*
	* 第一引数：ワールドトランスフォームを指定してる
	* 第二引数：ワールドトランスフォームをどの行列によって行うかを決めている
	*/
	m_rLibrary.GetDevice()->SetTransform(D3DTS_WORLD, &matWorld);
}