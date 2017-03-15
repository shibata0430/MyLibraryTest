/**
 * @file		SoundFile.h
 * @breif		音楽の読み込みと再生をするクラスヘッダ
 * @author		shibata
 * @attention	再生できるファイルはwavファイルのみ
 */

#ifndef SOUNDFILE_H
#define SOUNDFILE_H

#include <dsound.h>

class SoundFile
{
public:
	/// 音楽の再生状態
	enum Mode
	{
		PLAY,
		LOOP,
		STOP,
		RESET,
		RESET_PLAY,
		RESET_STOP,
	};

	/**コンストラクタ*/
	SoundFile();
	/**デストラクタ*/
	~SoundFile();

	/**
	 * 音楽ファイル(wav)の読み込み関数
	 * @param [in]	filePath_	音楽のファイルパス
	 * @retval		true		読み込み成功
	 * @retval		false		読み込み失敗
	 */
	bool LoadSoundFile(const char* filePath_);

	/**
	 * 音楽の再生状態を決める関数
	 * @pamra [in] soundMode_	音楽の再生状態
	 */
	void SoundState(SoundFile::Mode soundMode_);

private:

	/**
	 * waveファイルを開く関数
	 * @param [in]	filePath_		音楽のファイルパス
	 * @param [out]	waveFormat_		waveフォーマット
	 * @param [out]	ppData_			waveのデータサイズ
	 * @param [out]	dataSize_		データサイズ
	 * @retval		true			読み込み成功
	 * @retval		false			読み込み失敗
	 */
	bool OpenWave(char* filePath_, WAVEFORMATEX& waveFormat_, char** ppData_, DWORD& dataSize_);

private:
	IDirectSound8*			m_pDsound8;			//!< サウンドインターフェイス
	IDirectSoundBuffer8*	m_pDsoundBuffer;	//!< サウンドバッファ
};

#endif // !SOUNDFILE_H