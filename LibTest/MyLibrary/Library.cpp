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
#include "Library\Font.h"
#include "Library\CameraSetting.h"
#include "Library\LightSetting.h"

Library::Library() :
m_pDirectX9(NULL),
m_pInputDevice(NULL),
m_pSoundInterface(NULL),
m_pInputManager(NULL),
m_pWindow(NULL),
m_pTextureFileManager(NULL),
m_pVerticesManager(NULL),
m_pSoundFileManager(NULL),
m_pXFileManager(NULL),
m_pCameraSetting(NULL),
m_pLightsetting(NULL)
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
	delete m_pCameraSetting;
	delete m_pLightsetting;
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

	m_pInputManager			= New InputManager;
	m_pTextureFileManager	= New TextureFileManager;
	m_pVerticesManager		= New VerticesManager;
	m_pXFileManager			= New XFileManager;
	m_pSoundFileManager		= New SoundFileManager;
	m_pCameraSetting		= New CameraSetting;
	m_pLightsetting			= New LightSetting;
}

//---------------------Windowクラスのパブリック関数----------------------------------
bool Library::Update()
{
	bool isUpdate = m_pWindow->Update();
	return isUpdate;
}

//---------------------DirectX9クラスのパブリック関数--------------------------------
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

LPDIRECT3DDEVICE9 Library::GetDevice()
{
	return m_pDirectX9->GetDevice();
}

//---------------------InputManagerクラスのパブリック関数----------------------------
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

//---------------------TextureFileManagerクラスのパブリック関数----------------------
void Library::LoadTextureFile(int index_, const char* filePath_)
{
	m_pTextureFileManager->LoadTextureFile(index_, filePath_);
}

void Library::LoadTextuerMoreInfo(int index_, const char* filePath_, int alpha_, int red_, int green_, int blue_, bool isTwoPower_)
{
	m_pTextureFileManager->LoadTextuerMoreInfo(index_, filePath_, alpha_, red_, green_, blue_, isTwoPower_);
}

void Library::ReleaseAllTexture()
{
	m_pTextureFileManager->ReleaseAllTexture();
}

void Library::ReleaseTexture(int index_)
{
	m_pTextureFileManager->ReleaseTexture(index_);
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

void Library::ReleaseAllVirtices()
{
	m_pVerticesManager->ReleaseAllVirtices();
}

void Library::ReleaseVirtices(int index_)
{
	m_pVerticesManager->ReleaseVirtices(index_);
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

void Library::ReleaseAllSoundData()
{
	m_pSoundFileManager->ReleaseAllSoundData();
}

void Library::ReleaseSoundData(int index_)
{
	m_pSoundFileManager->ReleaseSoundData(index_);
}

//---------------------XFileManagerクラスのパブリック関数------------------------------
void Library::LoadXFile(int index_, const char* filePath_)
{
	m_pXFileManager->LoadXFile(index_, filePath_);
}

void Library::DrawXFile(int index_)
{
	m_pXFileManager->DrawXFile(index_);
}

void Library::ReleaseAllXFile()
{
	m_pXFileManager->ReleaseAllXFile();
}

void Library::ReleaseXFile(int index_)
{
	m_pXFileManager->ReleaseXFile(index_);
}

//---------------------Fontクラスのパブリック関数----------------------------------------
void Library::DrawFont(const char* pString_, float posX_, float posY_, DWORD format_, int red_, int green_, int blue_)
{
	Font font;
	font.DrawFont(pString_, D3DXVECTOR2(posX_, posY_), format_, red_, green_, blue_);
}

void Library::DrawFont(int width_, int height_, const char* pString_, float posX_, float posY_, DWORD format_, int red_, int green_, int blue_)
{
	Font font(width_, height_);
	font.DrawFont(pString_, D3DXVECTOR2(posX_, posY_), format_, red_, green_, blue_);
}

//----------------------CameraSettingクラスのパブリック関数-----------------------------
void Library::TransformView(int index_, D3DXVECTOR3 eyePoint_, D3DXVECTOR3 lookAtPoint_, float angle_, float nearZ_, float farZ_)
{
	m_pCameraSetting->TransformView(index_, eyePoint_, lookAtPoint_, static_cast<float>(m_pWindow->GetAspect()), angle_, nearZ_, farZ_);
}

void Library::ReleaseAllCamera()
{
	m_pCameraSetting->ReleaseAllCamera();
}

void Library::ReleaseCamera(int index_)
{
	m_pCameraSetting->ReleaseCamera(index_);
}

//-----------------------Lightsettingクラスのパブリック関数-----------------------------
void Library::Lighting(int index_, D3DXVECTOR3 direction_)
{
	m_pLightsetting->Lighting(index_, direction_);
}

void Library::ReleaseAllLight()
{
	m_pLightsetting->ReleaseAllLight();
}

void Library::ReleaseLight(int index_)
{
	m_pLightsetting->ReleaseLight(index_);
}

//----------------------DebugSystemクラスのパブリック関数-------------------------------
void Library::CheckMemoryLeaK()
{
	DebugSystem debugSystem;
	debugSystem.CheckMemoryLeaK();
}