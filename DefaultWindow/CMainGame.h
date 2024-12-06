#pragma once

#include "Define.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CMouse.h"
#include "CScene.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	HDC			m_hDC;

	DWORD		m_dwTime;
	int			m_iFPS;
	TCHAR		m_szFPS[16];

};

// ������ ���� : �ڵ��� �������� ������ ���·� ����� �����ϱ� �����ϰ� ���� ����
// https://refactoring.guru/ko/design-patterns

//1. �߻� ���丮 ���� : ���� ������ �� ������� �ν��Ͻ��� ����� ������ �߻�ȭ��Ų ����
//2. �ݺ��� ���� : ���� ǥ�� ����� �������� �ʰ� �������� ���� ����� �����ϴ� ����
//3. ������(�޵�����) ���� : ��ȣ�ۿ��ϴ� ��ü���� ���� ������ ���踦 �ΰ� ���� ��� ������ �������� �����Ͽ� �����ϴ� ��ü�� �δ� ����
//4. �̱��� ���� : ��, �ϳ��� �ν��Ͻ�(��ü)�� �����Ͽ� ����ϴ� ����, �ν��Ͻ��� �ʿ��� �� �Ȱ��� ������ �ν��Ͻ��� ����� ���� �ƴ϶� ������ �ν��Ͻ��� �ҷ��ͼ� ����ϴ� ����