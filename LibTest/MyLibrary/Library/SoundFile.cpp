/**
 * @file		SoundFile.cpp
 * @breif		音楽の読み込みと再生をするクラス実装
 * @author		shibata
 * @attention	再生できるファイルはwavファイルのみ
 */

#include "SoundFile.h"
#include "SoundInterface.h"
#include <tchar.h>

SoundFile::SoundFile() :
m_pDsound8(SoundInterface::Instance().GetSoundData()),
m_pDsoundBuffer(NULL)
{
}

SoundFile::~SoundFile()
{
	if (m_pDsoundBuffer != NULL)
	{
		m_pDsoundBuffer->Release();
		m_pDsoundBuffer = NULL;
	}
}

bool SoundFile::LoadSoundFile(const char* filePath_)
{
	char *pWaveData = NULL;

	{
		WAVEFORMATEX waveFormat;
		DWORD waveSize = NULL;

		if (!OpenWave((char*)filePath_, waveFormat, &pWaveData, waveSize))
		{
			return false;
		}

		DSBUFFERDESC			DSBufferDesc;											// 新しいバッファオブジェクトの特性を書いておく構造体
		DSBufferDesc.dwSize          = sizeof(DSBUFFERDESC);
		DSBufferDesc.dwFlags         = 0;
		DSBufferDesc.dwBufferBytes   = waveSize;
		DSBufferDesc.dwReserved      = 0;												//0でなければならない
		DSBufferDesc.lpwfxFormat     = &waveFormat;										//WAVEFORMATEXのアドレス
		DSBufferDesc.guid3DAlgorithm = GUID_NULL;										//デフォルトのアルゴリズムを使う

		IDirectSoundBuffer* ptempBuf = NULL;											// プライマリバッファの場合は使う必要がある
		m_pDsound8->CreateSoundBuffer(&DSBufferDesc, &ptempBuf, NULL);
		ptempBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)&m_pDsoundBuffer);
		ptempBuf->Release();
	}

	// セカンダリバッファにWaveデータ書き込み
	{
		LPVOID lpvwrite = NULL;
		DWORD dwlength = NULL;
		if (DS_OK == m_pDsoundBuffer->Lock(0, 0, &lpvwrite, &dwlength, NULL, NULL, DSBLOCK_ENTIREBUFFER))
		{
			memcpy(lpvwrite, pWaveData, dwlength);
			m_pDsoundBuffer->Unlock(lpvwrite, dwlength, NULL, 0);
		}
	}

	delete[] pWaveData;
	return true;
}

void SoundFile::SoundState(SoundFile::Mode soundMode_)
{
	switch (soundMode_)
	{
	case PLAY:
		m_pDsoundBuffer->Play(0, 0, 0);
		break;

	case LOOP:
		m_pDsoundBuffer->Play(0, 0, DSBPLAY_LOOPING);
		break;

	case STOP:
		m_pDsoundBuffer->Stop();
		break;

	case RESET:
		m_pDsoundBuffer->SetCurrentPosition(0);
		break;

	case RESET_PLAY:
		m_pDsoundBuffer->SetCurrentPosition(0);
		m_pDsoundBuffer->Play(0, 0, 0);
		break;

	case RESET_STOP:
		m_pDsoundBuffer->SetCurrentPosition(0);
		m_pDsoundBuffer->Stop();
		break;
	}
}

bool SoundFile::OpenWave(char* filePath_, WAVEFORMATEX& waveFormat_, char** ppData_, DWORD& dataSize_)
{
	HMMIO hmmio = NULL;

	{
		MMIOINFO mmioinfo;			//ファイルをオープンするときはゼロで初期化して渡す必要がある

		// Waveファイルオープン
		memset(&mmioinfo, NULL, sizeof(MMIOINFO));
		hmmio = mmioOpen(filePath_, &mmioinfo, MMIO_READ);
		if (!hmmio)
		{
			MessageBox(NULL, "ファイルのオープンに失敗しました。", NULL, MB_ICONWARNING);
			return false; // ファイルオープン失敗
		}
	}

	// RIFFチャンク検索
	MMRESULT mmres;
	MMCKINFO riffchunk;
	{
		riffchunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
		mmres = mmioDescend(hmmio, &riffchunk, NULL, MMIO_FINDRIFF);
		if (mmres != MMSYSERR_NOERROR)
		{
			mmioClose(hmmio, 0);
			return false;
		}

		// フォーマットチャンク検索
		MMCKINFO formatchunk;
		formatchunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
		mmres = mmioDescend(hmmio, &formatchunk, &riffchunk, MMIO_FINDCHUNK);
		if (mmres != MMSYSERR_NOERROR)
		{
			mmioClose(hmmio, 0);
			return false;
		}
		DWORD fmsize = formatchunk.cksize;
		DWORD size = mmioRead(hmmio, (HPSTR)&waveFormat_, fmsize);
		if (size != fmsize)
		{
			mmioClose(hmmio, 0);
			return false;
		}

		mmioAscend(hmmio, &formatchunk, 0);

		// データチャンク検索
		MMCKINFO datachunk;
		datachunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
		mmres = mmioDescend(hmmio, &datachunk, &riffchunk, MMIO_FINDCHUNK);
		if (mmres != MMSYSERR_NOERROR)
		{
			mmioClose(hmmio, 0);
			return false;
		}


		*ppData_ = new char[datachunk.cksize];
		size = mmioRead(hmmio, (HPSTR)*ppData_, datachunk.cksize);
		if (size != datachunk.cksize)
		{
			delete[] * ppData_;
			return false;
		}

		dataSize_ = size;
	}

	// ハンドルクローズ
	mmioClose(hmmio, 0);

	return true;
}