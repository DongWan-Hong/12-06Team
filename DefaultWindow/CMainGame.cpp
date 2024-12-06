#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"
#include "CLineMgr.h"
#include "CKeyMgr.h"
#include "CScrollMgr.h"
#include "CSceneMgr.h"

CMainGame::CMainGame()
	: m_dwTime(GetTickCount64()), m_iFPS(0), m_hDC(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	// 오브젝트 매니저를 통해 겟인스텐스를 불러온다음 그안에 플레이어를 저장한다.
	CSceneMgr::Get_Instance()->Initialize();
	
}

void CMainGame::Update()
{
	CSceneMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	
	//CObjMgr::Get_Instance()->Late_Update();
	//CKeyMgr::Get_Instance()->Update();

}


void CMainGame::Render()
{
#pragma region  FPS 출력
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount64())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);

		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount64();
	}
#pragma endregion
	
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	//
	//CLineMgr::Get_Instance()->Render(m_hDC);
	//
	//CObjMgr::Get_Instance()->Render(m_hDC);

	CSceneMgr::Get_Instance()->Render(m_hDC);

}

void CMainGame::Release()
{
	//CScrollMgr::Destroy_Instance();
	//CKeyMgr::Destroy_Instance();
	//CLineMgr::Destroy_Instance();
	//CObjMgr::DestroyInstance();
	//ReleaseDC(g_hWnd, m_hDC);
}
