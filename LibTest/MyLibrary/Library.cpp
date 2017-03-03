/**
 * @file	Library.cpp
 * @breif	ライブラリ全体の通り道のクラス実装
 * @author	shibata
 */

#include "Library.h"
#include "Library\DirectX9.h"
#include "Library\InputDvice.h"
#include "Library\SoundInterface.h"
#include "Library\InputManager.h"
#include "Library\Window.h"
#include "Library\TextureFileManager.h"
#include "Library\VerticesManager.h"
#include "Library\SoundFileManager.h"
#include "Library\XFileManager.h"
#include "Library\DebugSystem.h"

Library::Library() :
m_pDirectX9(NULL),
m_pInputDevice(NULL),
m_pSoundInterface(NULL),
m_pInputManager(NULL),
m_pWindow(NULL),
m_pTextureFileManager(NULL),
m_pVerticesManager(NULL),
m_pSoundFileManager(NULL),
m_pXFileManager(NULL)
{

}

Library::~Library()
{
	delete m_pWindow;
	delete m_pXFileManager;
	delete m_pInputManager;
	delete m_pSoundFileManager;
	delete m_pTextureFileManager;
	delete m_pVerticesManager;
}

void Library::InitLibrary(const char* titleName_, int clientWidth_, int clientHeight_, bool isFullScreen_)
{
	m_pWindow = New Window;
	m_pWindow->Create(titleName_, clientWidth_, clientHeight_, isFullScreen_);

	m_pDirectX9 = &DirectX9::Instance();
	m_pDirectX9->InitDirectX(m_pWindow->GetHwnd(), clientWidth_, clientHeight_, isFullScreen_);

	m_pInputDevice = &InputDevice::Instance();
	m_pInputDevice->InitInput();
	m_pInputDevice->InitInputKey(m_pWindow->GetHwnd());

	m_pSoundInterface = &SoundInterface::Instance();
	m_pSoundInterface->InitSound(m_pWindow->GetHwnd());

	m_pInputManager       = New InputManager;
	m_pTextureFileManager = New TextureFileManager;
	m_pVerticesManager    = New VerticesManager;
	m_pXFileManager       = New XFileManager;
	m_pSoundFileManager   = New SoundFileManager;
}

bool Library::Update()
{
	bool isUpdate = m_pWindow->Update();
	return isUpdate;
}

//-------------------------DirectX9クラスのパブリック関数----------------------------
void Library::SetFVF(DWORD fvf_)
{
	m_pDirectX9->SetFVF(fvf_);
}

void Library::DrawStart()
{
	m_pDirectX9->DrawStart();
}

void Library::DrawEnd()
{
	m_pDirectX9->DrawEnd();
}

void Library::Init3DDraw()
{
	m_pDirectX9->Init3DDraw();
}

//-------------------InputManagerクラスのパブリック関数------------------------------
void Library::UpdateDI()
{
	m_pInputManager->UpdateDI();
}

void Library::UpdateKey()
{
	m_pInputManager->UpdateKey();
}

KeyState Library::CheckKey(int dik_)
{
	KeyState keyState = static_cast<KeyState>(m_pInputManager->CheckKey(dik_));
	return keyState;
}

//-------------------TextureFileManagerクラスのパブリック関数------------------------
void Library::LoadTextureFile(int index_, const char* filePath_)
{
	m_pTextureFileManager->LoadTextureFile(index_, filePath_);
}

void Library::LoadTextuerMoreInfo(int index_, const char* filePath_, int alpha_, int red_, int green_, int blue_, bool isTwoPower_)
{
	m_pTextureFileManager->LoadTextuerMoreInfo(index_, filePath_, alpha_, red_, green_, blue_, isTwoPower_);
}

void Library::ReleaseTexture()
{
	m_pTextureFileManager->Release();
}

//---------------------VerticesManagerクラスのパブリック関数-------------------------
void Library::SetTexSize(int index_, float width_, float height_, float depth_, float maxTu_, float maxTv_, float minTu_, float minTv_)
{
	m_pVerticesManager->SetTexSize(index_, width_, height_, depth_, maxTu_, maxTv_, minTu_, minTv_);
}

void Library::DrawLeftTop(int index_, float posX_, float posY_)
{
	m_pVerticesManager->DrawLeftTop(index_, posX_, posY_, m_pTextureFileManager->GetTextureFileData(index_));
}

void Library::DrawCenter(int index_, float posX_, float posY_)
{
	m_pVerticesManager->DrawCenter(index_, posX_, posY_, m_pTextureFileManager->GetTextureFileData(index_));
}

void Library::SetColor(int index_, DWORD color_, int alpha_, int red_, int green_, int blue_)
{
	m_pVerticesManager->SetColor(index_, color_, alpha_, red_, green_, blue_);
}

void Library::ReleaseVertices()
{
	m_pVerticesManager->Release();
}

//---------------------SoundFileManagerクラスのパブリック関数--------------------------
void Library::LoadSoundFile(int index_, const char* filePath_)
{
	m_pSoundFileManager->LoadSoundFile(index_, filePath_);
}

void Library::SoundState(int index_, SoundMode soundMode_)
{
	m_pSoundFileManager->SoundState(index_, static_cast<SoundFileManager::SoundMode>(soundMode_));
}

void Library::ReleaseSound()
{
	m_pSoundFileManager->Release();
}

//-------------------XFileManagerクラスのパブリック関数--------------------------------
void Library::LoadXFile(int index_, const char* filePath_)
{
	m_pXFileManager->LoadXFile(index_, filePath_);
}

void Library::DrawXFile(int index_)
{
	m_pXFileManager->DrawXFile(index_);
}

void Library::ReleaseXFile()
{
	m_pXFileManager->Release();
}

void Library::CheckMemoryLeaK()
{
	DebugSystem debugSystem;
	debugSystem.CheckMemoryLeaK();
}