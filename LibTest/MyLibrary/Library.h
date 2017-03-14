/**
 * @file	Library.h
 * @breif	ライブラリ全体の通り道のクラスヘッダ
 * @author	shibata
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#define DIRECTINPUT_VERSION 0x0800

#include "SearchMemoryLeak.h"
#include <dinput.h>
#include <d3dx9.h>

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

class DirectX9;
class InputManager;
class InputDevice;
class SoundInterface;
class Window;
class TextureFileManager;
class VerticesManager;
class SoundFileManager;
class XFileManager;
class CameraSetting;
class LightSetting;

enum SoundMode
{
	PLAY,
	LOOP,
	STOP,
	RESET,
	RESET_PLAY,
	RESET_STOP,
};

enum KeyState
{
	PUSH,
	RELEASE,
	ON,
	OFF
};

class Library
{
private:
	/**コンストラクタ*/
	Library();

public:		// Libraryクラスのパブリック関数
	/**デストラクタ*/
	~Library();

	/**
	 * ライブラリクラスのインスタンス取得関数
	 * return &library	ライブラリクラスのインスタンス
	 */
	static Library& Instace()
	{
		static Library library;
		return library;
	}

	/**
	 * ライブラリを使用できるようにする関数
	 * @param [in] titleName_		ゲームのタイトル
	 * @param [in] clientWidth_		画面横幅のサイズ
	 * @param [in] clientHeiht_		画面縦幅のサイズ
	 * @param [in] isFullScreen_	フルスクリーンにするかどうか
	 */
	void InitLibrary(const char* titleName_, int clientWidth_, int clientHeight_, bool isFullScreen_);

public:		// Windowクラスのパブリック関数
	bool Update();

public:		// DirectX9クラスのパブリック関数
	/**
	* 頂点フォーマットの設定関数
	* @param [in] fvf_ 頂点フォーマットの設定
	* @note デフォルトはD3DFVF_CUSTOMVERTEXの定義
	*/
	void SetFVF(DWORD fvf_ = D3DFVF_CUSTOMVERTEX);

	/**描画初めの関数*/
	void DrawStart();

	/**描画終わりの関数*/
	void DrawEnd();

	/**
	* 描画初期化関数
	* @note 3Dを描画するときに使用
	*/
	void Init3DDraw();

public:		// InputManagerクラスのパブリック関数
	/**DI系をすべて更新する関数*/
	void UpdateDI();

	/**キーだけを更新する関数*/
	void UpdateKey();

	/**
	* キーの状態を決める関数
	* @param [in]		dik_	どのキーを使うか
	* @return			state	キーの状態
	*/
	KeyState CheckKey(int dik_);


public:		// TextureFileManagerクラスのパブリック関数
	/**
	* 画像を読み込む関数
	* @param [in]	index_		読み込む画像の配列番号
	* @param [in]	filePath_	画像のファイルパス
	*/
	void LoadTextureFile(int index_, const char* filePath_);

	/**
	* 画像を詳細に読み込む関数
	* @param [in]	index_			読み込む画像の配列番号
	* @param [in]	filePath_		画像のファイルパス
	* @param [in]	alpha_			画像の透過の値
	* @param [in]	red_			画像の赤の値
	* @param [in]	green_			画像の緑の値
	* @param [in]	blue_			画像の青の値
	* @param [in]	isTowPower_		画像サイズの2の累乗がどうか
	* @note argbのデフォルトは
	* @note isTowPower_のデフォルトはtrue
	*/
	void LoadTextuerMoreInfo(int index_, const char* filePath_, int alpha_ = 255, int red_ = 255, int green_ = 255, int blue_ = 255, bool isTwoPower_ = true);

	/**全てのテクスチャの解放関数*/
	void ReleaseAllTexture();

	/**
	* 一部のテクスチャの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseTexture(int index_);

public:		// VerticesManagerのパブリック関数
	/**
	* 画像サイズの設定する関数
	* @param [in] index_	頂点情報の配列番号
	* @param [in] width_	描画の横幅
	* @param [in] height_	描画の縦幅
	* @param [in] depth_	描画の奥行き
	* @param [in] maxTu_	テクスチャの最大x座標
	* @param [in] maxTv_	テクスチャの最大y座標
	* @param [in] minTu_	テクスチャの最小x座標
	* @param [in] minTv_	テクスチャの最小y座標
	* @note depth_のデフォルト値は0.5f
	* @note maxTu, maxTvのデフォルト値は1.0f
	* @note minTu, minTvのデフォルト値は0.0f
	*/
	void SetTexSize(int index_, float width_, float height_, float depth_ = 0.5f, float maxTu_ = 1.0f, float maxTv_ = 1.0f, float minTu_ = 0.0f, float minTv_ = 0.0f);

	/**
	* 左上からの描画関数
	* @param [in] index_		頂点情報の配列番号
	* @param [in] posX_			x座標
	* @param [in] posY_			y座標
	*/
	void DrawLeftTop(int index_, float posX_, float posY_);

	/**
	* 中心からの描画関数
	* @param [in] index_		頂点情報の配列番号
	* @param [in] posX_			x座標
	* @param [in] posY_			y座標
	*/
	void DrawCenter(int index_, float posX_, float posY_);

	/**
	* 色の変更する関数
	* @param [in] index_	頂点情報の配列番号
	* @param [in] color_	変更したRGBAの最終的な値
	* @param [in] alpha_	変更する透過の値
	* @param [in] red_		変更する赤の値
	* @param [in] green_	変更する緑の値
	* @param [in] blue_	変更する青の値
	* @note rbgaのデフォルト値は255
	*/
	void SetColor(int index_, DWORD color_, int alpha_ = 255, int red_ = 255, int green_ = 255, int blue_ = 255);

	/**全ての頂点データの解放関数*/
	void ReleaseAllVirtices();

	/**
	* 一部の頂点データの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseVirtices(int index_);

public:		// SoundFileManagerクラスのパブリック関数
	/**
	* 音楽ファイル(wav)の読み込み関数
	* @param [in]	index_		読み込む音楽の配列番号
	* @param [in]	filePath_	音楽のファイルパス
	*/
	void LoadSoundFile(int index_, const char* filePath_);

	/**
	* 音楽の再生状態を決める関数
	* @param [in] index_		再生する音楽の配列番号
	* @pamra [in] soundMode_	音楽の再生状態
	*/
	void SoundState(int index_, SoundMode soundMode_);

	/**全てのサウンドデータの解放関数*/
	void ReleaseAllSoundData();

	/**
	* 一部のサウンドデータの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseSoundData(int index_);

public:		// XFileManagerクラスのパブリック関数
	/**
	* Xファイルの読み込み関数
	* @param [in]	index_		Xファイルの配列番号
	* @param [in]	filePath_	Xファイルのパス
	*/
	void LoadXFile(int index_, const char* filePath_);

	/**
	* Xファイルの描画関数
	* @param [in] index_
	*/
	void DrawXFile(int index_);

	/**全てのXファイルの解放関数*/
	void ReleaseAllXFile();

	/**
	* 一部のXファイルの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseXFile(int index_);

public:		// Fontクラスのパブリック関数
	/**
	* 文字を描画する関数
	* @param [in] pString_		描画する文字列
	* @param [in] posX_			描画する文字のX座標
	* @param [in] posY_			描画する文字のY座標
	* @param [in] format_		文字のフォーマット
	* @param [in] red_			文字のR値
	* @param [in] green_		文字のG値
	* @param [in] blue_			文字のB値
	* @note format_のデフォルト値は左寄せ
	* @note RGBのデフォルト値は255
	*/
	void DrawFont(const char* pString_, float posX_, float posY_, DWORD format_ = DT_LEFT, int red_ = 255, int green_ = 255, int blue_ = 255);

	/**
	* 文字を描画する関数
	* @param [in] width_		文字の幅
	* @param [in] height_		文字の高さ
	* @param [in] pString_		描画する文字列
	* @param [in] posX_			描画する文字のX座標
	* @param [in] posY_			描画する文字のY座標
	* @param [in] format_		文字のフォーマット
	* @param [in] red_			文字のR値
	* @param [in] green_		文字のG値
	* @param [in] blue_			文字のB値
	* @note format_のデフォルト値は左寄せ
	* @note RGBのデフォルト値は255
	*/
	void DrawFont(int width_, int height_, const char* pString_, float posX_, float posY_, DWORD format_ = DT_LEFT, int red_ = 255, int green_ = 255, int blue_ = 255);

public:		// CameraSettingクラスのパブリック関数
	/**
	* カメラ座標と射影を設定する関数
	* @param [in]	index_			配置するカメラID
	* @param [in]	eyePoint_		カメラの角度(レンズ)が正面を向いてる状態でのカメラの位置
	* @param [in]	lookAtPoint_	カメラの位置を元にレンズの角度を決めるベクトル(方向)
	* @param [in]	angle_			画角の広さ
	* @param [in]	nearZ_			カメラが移せる一番近い描画位置
	* @param [in]	farZ_			カメラが移せる一番遠い描画位置
	* @note nearZ_のデフォルト値は1.0f
	* @note farZ_のデフォルト値は10000.0f
	* @note angle_のデフォルト値は50.0f
	*/
	void TransformView(int index_, D3DXVECTOR3 eyePoint_, D3DXVECTOR3 lookAtPoint_, float angle_ = 50.0f, float nearZ_ = 1.0f, float farZ_ = 10000.0f);

	/**全てのカメラの解放関数*/
	void ReleaseAllCamera();

	/**
	* 一部のカメラの解放関数
	* @param [in] index_	解放するカメラID
	*/
	void ReleaseCamera(int index_);

public:		// Lightsettingクラスのパブリック関数
	/**
	* ライトの設定をする関数
	* @param [in]	index_		ライトを設置する場所
	* @param [in]	direction_	ワールド空間での光の指す方向
	* @note direction_のデフォルト値は(0.0f, 0.0f, 1.0f)
	* direction_は0.0fより大きな値を入れなければならない
	*/
	void Lighting(int index_, D3DXVECTOR3 direction_ = { 0.0f, 0.0f, 1.0f });

	/**全てのライトデータの解放関数*/
	void ReleaseAllLight();

	/**
	* 一部のライトデータの解放関数
	* @param [in] index_	解放する配列番号
	*/
	void ReleaseLight(int index_);

public:		// DebugSystemクラスのパブリック関数
	/**メモリリークを発見する関数*/
	void CheckMemoryLeaK();

private:
	DirectX9*				m_pDirectX9;
	InputDevice*			m_pInputDevice;
	SoundInterface*			m_pSoundInterface;
	InputManager*			m_pInputManager;
	Window*					m_pWindow;
	TextureFileManager*		m_pTextureFileManager;
	VerticesManager*		m_pVerticesManager;
	SoundFileManager*		m_pSoundFileManager;
	XFileManager*			m_pXFileManager;
	CameraSetting*			m_pCameraSetting;
	LightSetting*			m_pLightsetting;
};

#pragma comment(lib, "dsound.lib" )
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "Xinput.lib")

#endif // !LIBRARY_H