#include "pch.h"
#include "CSceneMgr.h"
#include "CScene_Start.h"
#include "CStage_Chae.h"
#include "CStage_Hong.h"
#include "CStage_Hero.h"
#include "CStage_Moo.h"
#include "CStage_Silver.h"

int g_CurrentStage = (int)SCENE_TYPE::STAGE_START; // �⺻�� START

CSceneMgr* CSceneMgr::m_pInstance = nullptr; // ����ƽ ������ CPP���� �ʱ�ȭ���ֱ�, 

void CSceneMgr::Set_Scene(SCENE_TYPE eType)
{
	if (m_pCurScene)
		m_pCurScene->Exit();

	m_pCurScene = m_arrScene[(UINT)eType];
	g_CurrentStage = (int)eType; // ���� �������� ������Ʈ
	m_pCurScene->Initialize();
}

CSceneMgr::CSceneMgr()
	: m_arrScene{}
	,m_pCurScene(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{
	/// �� ��� ����
	for (UINT i = 0; i < (UINT)SCENE_TYPE::SCENE_END; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneMgr::Initialize() // Scene ����
{
	m_arrScene[(UINT)SCENE_TYPE::STAGE_START] = new CScene_Start;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_START]->SetName(L"Start Game");

	m_arrScene[(UINT)SCENE_TYPE::STAGE_Chae] = new CStage_Chae;     // ä�� ��������
	m_arrScene[(UINT)SCENE_TYPE::STAGE_Hero] = new CStage_Hero;     // ���� ��������
	m_arrScene[(UINT)SCENE_TYPE::STAGE_Hong] = new CStage_Hong;     // ȫ���� ��������
	m_arrScene[(UINT)SCENE_TYPE::STAGE_Silver] = new CStage_Silver; // ���� ��������
	m_arrScene[(UINT)SCENE_TYPE::STAGE_Moo] = new CStage_Moo;       // ���� ��������

	
	Set_Scene(SCENE_TYPE::STAGE_START);// ù Scene ����
}


void CSceneMgr::Update()
{
	m_pCurScene->Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pCurScene->Render(hDC);
}



