/**
 * @file	SoundFileManager.h
 * @breif	音楽の読み込みと再生を管理しているクラスヘッダ
 * @author	shibata
 */

#ifndef SOUNDFILEMANAGER_H
#define SOUNDFILEMANAGER_H

#include <vector>

class SoundFile;

class SoundFileManager
{
public:
	enum SoundMode
	{
		PLAY,
		LOOP,
		STOP,
		RESET,
		RESET_PLAY,
		RESET_STOP,
	};

	/**コンストラクタ*/
	SoundFileManager();
	/**デストラクタ*/
	~SoundFileManager();

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

private:
	std::vector<SoundFile*>	m_pSoundFile;
};

#endif // !SOUNDFILEMANAGER_H