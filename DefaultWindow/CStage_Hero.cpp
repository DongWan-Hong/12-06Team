#include "pch.h"
#include "CStage_Hero.h"
#include "CStage_Hong.h"
#include "CScene.h"
#include "CObjMgr.h"
#include "CAbstractFactory.h"
#include "CLineMgr.h"
#include "CKeyMgr.h"

CStage_Hero::CStage_Hero()
{
}

CStage_Hero::~CStage_Hero()
{
}

void CStage_Hero::Initialize()
{
	//��� �Ŵ����� �ҷ��� ���͵� �� �̴ϼȶ�����
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	CLineMgr::Get_Instance()->Initialize();
}

void CStage_Hero::Update()
{
	// ��� ������Ʈ���� ��ȸ�ϸ鼭 ������Ʈ
	CObjMgr::Get_Instance()->Update();
}

void CStage_Hero::LateUpdate()
{
	CObjMgr::Get_Instance()->Late_Update();
	CKeyMgr::Get_Instance()->Update();
}

void CStage_Hero::Release()
{
	//���� ��������
	for (UINT i = 0; i < (UINT)GROUP_TYPE::OBJ_END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++i)
		{
			delete m_arrObj[i][j];
		}

	}
}

void CStage_Hero::Render(HDC _hDC)
{
	Rectangle(_hDC, 0, 0, WINCX, WINCY);

	CLineMgr::Get_Instance()->Render(_hDC);

	CObjMgr::Get_Instance()->Render(_hDC);
}

void CStage_Hero::Exit()
{
}
