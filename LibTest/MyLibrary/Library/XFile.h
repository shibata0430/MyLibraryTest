/**
* @file		XFile.h
* @breif	Xファイルを読み込みと描画クラスヘッダ
* @author	shibata
*/

#ifndef XFILE_H
#define XFILE_H

#include <d3dx9.h>

class XFile
{
public:
	XFile();
	~XFile();

	/**
	 * Xファイルの読み込み関数
	 * @param [in]	filePath_		Xファイルのパス
	 * @retval		true			読み込み成功
	 * @retval		false			読み込み失敗
	 */
	bool LoadXFile(const char* filePath_);

	/**Xファイルの描画関数*/
	void DrawXFile();

	/**
	 * メッシュデータの取得関数
	 * @return m_pMesh メッシュデータ
	 */
	LPD3DXMESH GetMeshData() const
	{
		return m_pMesh;
	}

private:
	LPDIRECT3DDEVICE9		m_pD3Device;			//!< Graphicsdeviceから取ってきたデバイス
	LPD3DXMESH				m_pMesh;				//!< Xファイルメのッシュを操作する時のインターフェイス
	D3DMATERIAL9*			m_pMeshMaterials;		//!< Xファイルのマテリアル設定をする構造体
	LPDIRECT3DTEXTURE9*		m_pMeshTextures;		//!< Xファイルのメッシュに貼るテクスチャ
	DWORD					m_dwNumMaterials;		//!< マテリアルの数を格納する変数
};

#endif // !XFILE_H