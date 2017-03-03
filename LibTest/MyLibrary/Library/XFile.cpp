/**
 * @file	XFile.cpp
 * @breif	Xファイルの読み込みと描画クラス実装
 * @author	shibata
 */

#include "XFile.h"
#include "DirectX9.h"

XFile::XFile() : 
m_pD3Device(DirectX9::Instance().GetDevice()),
m_pMesh(NULL),
m_pMeshMaterials(NULL),
m_pMeshTextures(NULL),
m_dwNumMaterials(NULL)
{

}

XFile::~XFile()
{
	delete[] m_pMeshMaterials;
	m_pMeshMaterials = NULL;

	delete[] m_pMeshTextures;
	m_pMeshTextures = NULL;

	m_pMesh->Release();
	m_pMesh = NULL;
}

bool XFile::LoadXFile(const char* filePath_)
{
	LPD3DXBUFFER pD3DXMtrlBuffer = NULL;

	if (FAILED(D3DXLoadMeshFromX(
		filePath_,
		D3DXMESH_MANAGED,
		m_pD3Device,
		NULL,					// 隣接データ：あまり使わないのでNULLで大丈夫
		&pD3DXMtrlBuffer,		// マテリアルが２つ以上設定されているので、ポインタ
		NULL,					// エフェクトというもの。現在は触れないでいいのでNULLで大丈夫
		&m_dwNumMaterials,		// 隣接データのマテリアルの数が返ってくる
		&m_pMesh)))				// メッシュインターフェイスの情報
	{
		MessageBox(NULL, "Xファイルの読み込みに失敗しました", NULL, MB_OK);
		return false;
	}

	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();		// マテリアル・バッファのポインタを適切な初期化する
	m_pMeshMaterials = new D3DMATERIAL9[m_dwNumMaterials];									// マテリアルの分だけメモリを確保する
	m_pMeshTextures = new LPDIRECT3DTEXTURE9[m_dwNumMaterials];								// メッシュに貼るテクスチャのメモリを確保する
	// メッシュ:簡単に言うと3Dモデル

	for (DWORD i = 0; i < m_dwNumMaterials; i++)
	{						  // マテリアルデータ
		m_pMeshMaterials[i] = d3dxMaterials[i].MatD3D;
		m_pMeshMaterials[i].Ambient = m_pMeshMaterials[i].Diffuse;
		m_pMeshTextures[i] = NULL;
		if (d3dxMaterials[i].pTextureFilename != NULL &&
			lstrlen(d3dxMaterials[i].pTextureFilename) > 0)
		{
			if (FAILED(D3DXCreateTextureFromFile(m_pD3Device,
				d3dxMaterials[i].pTextureFilename,
				&m_pMeshTextures[i])))
			{
				MessageBox(NULL, "テクスチャの読み込みに失敗しました", NULL, MB_OK);
				return false;
			}
		}
	}

	pD3DXMtrlBuffer->Release();
	return true;
}

void XFile::DrawXFile()
{
	for (DWORD i = 0; i < m_dwNumMaterials; i++)
	{
		m_pD3Device->SetMaterial(&m_pMeshMaterials[i]);
		m_pD3Device->SetTexture(0, m_pMeshTextures[i]);
		m_pMesh->DrawSubset(i);
	}
}